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

/**
https://www.cpcwiki.eu/index.php/Standard_Memory_Expansions
https://cpctech.cpc-live.com/docs/rampage.html
https://www.cpcwiki.eu/index.php/Gate_Array#ROM_configuration_selection
https://www.cpcwiki.eu/index.php/Upper_ROM_Bank_Number

la memoria se divide en paginas, cada pagina tiene 4 bancos de 16kb
**/


#include <fstream>
#include <stdio.h>
#include <string>
#include <cstring> // Para memset
#include "log.h"
#include "tipos.h"
#include "memory.h"



//------------------------------------------------------------------------

Memory::Memory() {
	reset();
}


Memory::~Memory() {}


void Memory::reset() {
	for (u16 x = 0; x < RAM_SIZE; ram[x++] = 0);
}




void Memory::writeByte(DIR posicion, BYTE dato) {
	ram[posicion] = dato;
}

void Memory::writeWord(DIR posicion, WORD dato) {
    writeByte(  posicion, dato.b.l);
    writeByte(++posicion, dato.b.h);
}


void Memory::readByte(DIR posicion, BYTE *dato) {
	*dato = ram[posicion];
}



void Memory::readWord(DIR posicion, WORD *dato) {
    readByte(posicion, &dato->b.l );
	readByte(++posicion, &dato->b.h );
}

