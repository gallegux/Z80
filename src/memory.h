/*___________________________________________________________________________
|                                                                            |
|  Basic RAM implementation                                                  |
|                                                                            |
|  Copyright (c) 2024 Gallegux (gallegux@gmail.com)                          |
|                                                                            |
|  This program is free software: you can redistribute it and/or modify      |
|  it under the terms of the GNU General Public License as published by      |
|  the Free Software Foundation, either version 3 of the License, or         |
|  any later version.                                                        |
|                                                                            |
|  This program is distributed in the hope that it will be useful, but       |
|  WITHOUT ANY WARRANTY; without even the implied warranty of                |
|  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the              |
|  GNU General Public License for more details.                              |
|                                                                            |
|  You should have received a copy of the GNU General Public License         |
|  along with this program; if not, see <http://www.gnu.org/licenses/>.      |
|                                                                            |
|  If you use this code, please attribute the original source by mentioning  |
|  the author and providing a link to the original repository.               |
|___________________________________________________________________________*/

#pragma once


#include "tipos.h"


#define RAM_SIZE 64536


class Memory
{
	BYTE ram[RAM_SIZE];

public:
    Memory();
    ~Memory();

    void reset();

    void writeByte(DIR posicion, BYTE dato);
    void writeWord(DIR posicion, WORD dato);
    
    void readByte(DIR posicion, BYTE *dato);
    void readWord(DIR posicion, WORD *dato);

};

