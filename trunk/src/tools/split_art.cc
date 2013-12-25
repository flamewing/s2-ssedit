/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * Copyright (C) Flamewing 2013 <flamewing.sonic@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>

#include "getopt.h"
#include "comper.h"
#include "dplcfile.h"

struct Tile {
	unsigned char tiledata[32];
	bool read(std::istream &in) {
		for (size_t i = 0; i < sizeof(tiledata); i++) {
			tiledata[i] = in.get();
		}
		return true;
	}
	void write(std::ostream &out) {
		for (size_t i = 0; i < sizeof(tiledata); i++) {
			out.put(tiledata[i]);
		}
	}
};

static void usage(char *prog) {
	std::cerr << "Usage: " << prog << " --sonic=VER [-c|--compress] {input_art} {input_dplc} {output_prefix}" << std::endl;
	std::cerr << std::endl;
	std::cerr << "\t--sonic=VER  \tSpecifies the format of the input DPLC file." << std::endl;
	std::cerr << "\t             \tThe following values are accepted:" << std::endl;
	std::cerr << "\t             \tVER=1\tSonic 1 DPLC." << std::endl;
	std::cerr << "\t             \tVER=2\tSonic 2 DPLC." << std::endl;
	std::cerr << "\t             \tVER=3\tSonic 3 DPLC, as used by player objects." << std::endl;
	std::cerr << "\t             \tVER=4\tSonic 3 DPLC, as used by non-player objects." << std::endl;
	std::cerr << "\t-c,--compress\tOutput files are Comper-compressed." << std::endl << std::endl;
}

int main(int argc, char *argv[]) {
	static struct option long_options[] = {
		{"compress" , no_argument      , 0, 'c'},
		{"sonic"         , required_argument, 0, 'z'},
		{0, 0, 0, 0}
	};

	bool compress = false;
	int sonicver = 2;

	while (true) {
		int option_index = 0;
		int c = getopt_long(argc, argv, "c",
		                    long_options, &option_index);
		if (c == -1)
			break;

		switch (c) {
			case 'c':
				compress = true;
				break;
			case 'z':
				sonicver = strtoul(optarg, 0, 0);
				if (sonicver < 1 || sonicver > 4)
					sonicver = 2;
				break;
		}
	}

	if (argc - optind < 3) {
		usage(argv[0]);
		return 1;
	}

	std::ifstream inart(argv[optind + 0], std::ios::in | std::ios::binary),
	    indplc(argv[optind + 1], std::ios::in | std::ios::binary);

	if (!inart.good()) {
		std::cerr << "Input art file '" << argv[optind + 0] << "' could not be opened." << std::endl << std::endl;
		return 2;
	}

	if (!indplc.good()) {
		std::cerr << "Input DPLC file '" << argv[optind + 1] << "' could not be opened." << std::endl << std::endl;
		return 3;
	}

	inart.seekg(0, std::ios::end);
	size_t size = inart.tellg();
	inart.seekg(0);

	std::vector<Tile> tiles;
	tiles.resize(size / 32);

	for (size_t ii = 0; ii < tiles.size(); ii++) {
		tiles[ii].read(inart);
	}
	inart.close();
	
	dplc_file srcdplc;
	srcdplc.read(indplc, sonicver);
	indplc.close();
	
	for (size_t ii = 0; ii < srcdplc.size(); ii++) {
		std::stringstream buffer(std::ios::in | std::ios::out | std::ios::binary);
		frame_dplc const &frame = srcdplc.get_dplc(ii);
		for (size_t jj = 0; jj < frame.size(); jj++) {
			single_dplc const &dplc = frame.get_dplc(jj);
			for (size_t kk = 0; kk < dplc.get_cnt(); kk++) {
				tiles[dplc.get_tile() + kk].write(buffer);
			}
		}
		std::stringstream fname(std::ios::in | std::ios::out);
		fname << argv[optind + 2] << std::hex << std::setw(2)
		      << std::setfill('0') << ii << ".bin";
		std::ofstream fout(fname.str().c_str(),
		                   std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
		if (!fout.good()) {
			std::cerr << "Output file '" << fname.str() << "' could not be opened." << std::endl << std::endl;
			return 4;
		}
		if (compress) {
			comper::encode(buffer, fout);
		} else {
			fout << buffer.rdbuf();
		}
	}

	return 0;
}
