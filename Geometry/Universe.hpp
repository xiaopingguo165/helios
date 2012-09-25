/*
 Copyright (c) 2012, Esteban Pellegrino
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.
 * Neither the name of the <organization> nor the
 names of its contributors may be used to endorse or promote products
 derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef UNIVERSE_HPP_
#define UNIVERSE_HPP_

#include <vector>

#include "../Common.hpp"

namespace Helios {

class Universe {

	/* Static counter, incremented by one each time a surface is created */
	static size_t counter;
	/* Internal identification of this universe */
	InternalUniverseId int_univid;
	/* A vector of cell */
	std::vector<Cell*> cells;
	/* Cell id choose by the user */
	UniverseId univid;

protected:

	Universe(const UniverseId& univid) : univid(univid) {/* */};
	/* Prevent copy */
	Universe(const Universe& uni);
	Universe& operator=(const Universe& uni);

public:

	/* Add a neighbor cell of this surface */
	void addCell(Cell* cell) {cells.push_back(cell);};
	/* Get neighbor cells of this surface */
	const std::vector<Cell*>& getCells() const {return cells;};

	/* Return the user ID associated with this surface. */
	const UniverseId& getUserId() const {return univid;}
	/* Return the internal ID associated with this surface. */
	const InternalUniverseId& getInternalId() const {return int_univid;}

	virtual ~Universe() {/* */};
};

	class UniverseFactory {

		/* Static instance of the factory */
		static UniverseFactory factory;

		/* Prevent construction or copy */
		UniverseFactory() {/* */};
		UniverseFactory& operator= (const UniverseFactory& other);
		UniverseFactory(const UniverseFactory&);
		virtual ~UniverseFactory() {/* */}

	public:
		/* Access the factory, reference to the static singleton */
		static UniverseFactory& access() {return factory;}

		/* Create a new surface */
		Universe* createUniverse(const UniverseId& univid) const {
			return new Universe(univid);
		}

	};
} /* namespace Helios */
#endif /* UNIVERSE_HPP_ */
