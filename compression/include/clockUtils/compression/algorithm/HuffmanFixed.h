/*
 * clockUtils
 * Copyright (2015) Michael Baer, Daniel Bonrath, All rights reserved.
 *
 * This file is part of clockUtils; clockUtils is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/**
 * \addtogroup clockutils
 * @{
 */

#ifndef __CLOCKUTILS_COMPRESSION_ALGORITHM_HUFFMANFIXED_H__
#define __CLOCKUTILS_COMPRESSION_ALGORITHM_HUFFMANFIXED_H__

#include <map>

#include "clockUtils/compression/algorithm/HuffmanBase.h"

namespace clockUtils {
namespace compression {
namespace algorithm {

	/**
	 * \brief class for Huffman compression using a fixed dictionary
	 */
	class CLOCK_COMPRESSION_API HuffmanFixed : public HuffmanBase {
	public:
		/**
		 * \brief compresses the given string and returns result
		 */
		static std::string compress(const std::string & text);

		/**
		 * \brief decompresses the given string and returns result
		 */
		static std::string decompress(const std::string & text);

	private:
		/**
		 * \brief the tree in fixed Huffman is always the same, so it can be stored as static member during whole lifetime
		 */
		static std::shared_ptr<Tree> tree;

		/**
		 * \brief because the tree in fixed Huffman stays always the same, also the mappings are constant
		 */
		static std::map<unsigned char, std::pair<size_t, std::vector<uint8_t>>> mappings;
		
		/**
		 * \brief converts the text into a bit sequence using the mappings, if possible and otherwise filling the mappings
		 */
		static void convert(const std::string & text, size_t index, std::string & result);
	};

} /* namespace algorithm */
} /* namespace compression */
} /* namespace clockUtils */

#endif /* __CLOCKUTILS_COMPRESSION_ALGORITHM_HUFFMANFIXED_H__ */

/**
 * @}
 */
