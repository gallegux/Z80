/*___________________________________________________________________________
|                                                                            |
|  GEMUX-CPC - Amstrad CPC emulator                                          |
|  Generic input/output implementation                                       |
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

#include "log.h"
#include "tipos.h"
#include "io_device.h"
#include "io.h"
#include "z80.h"


// https://www.cpcwiki.eu/index.php/I/O_Port_Summary
// https://www.cpcwiki.eu/index.php/8255
// https://i0.wp.com/auamstrad.es/wp-content/uploads/2019/11/image-2.png?w=1000&ssl=1
// https://auamstrad.es/cursos-tutoriales/8bp-arquitectura-y-memoria/
// https://cpcrulez.fr/applications_coding-control_del_psg-amstrad_personal.htm
// https://www.cpcwiki.eu/imgs/d/df/PPI_M5L8255AP-5.pdf



Z80IO:: Z80IO() {
    for (BYTE i = 0; i < MAX_DISPOSITIVOS; i++)  dispositivos[i] = nullptr;
}



bool Z80IO:: addDevice(IODevice* d) {
    for (BYTE i = 0; i < MAX_DISPOSITIVOS; i++) {
        if (dispositivos[i] == nullptr) {
            dispositivos[i] = d;
            numDispositivos++;
            return true;
        }
    }
    return false;
}


bool Z80IO:: removeDevice(IODevice* d) {
    for (u8 i = 0; i < MAX_DISPOSITIVOS; i++) {
        if (dispositivos[i] == d) {
            dispositivos[i] = nullptr;
            numDispositivos--;
			return true;
        }
    }
	return false;
}



void Z80IO:: reset() {
    for (BYTE i = 0; i < MAX_DISPOSITIVOS; i++) {
        if (dispositivos[i] != nullptr) {
            dispositivos[i]->reset();
        }
    }
}



void Z80IO:: OUT(WORD puerto, BYTE dato) {
    for (BYTE i = 0; i < numDispositivos; i++) {
        if (dispositivos[i] != nullptr) {
            if (dispositivos[i]->OUT(puerto, dato)) return;
        }
    }
}


BYTE Z80IO:: IN(WORD puerto) {
    BYTE dato;
    bool r;

    for (u8 i = 0; i < numDispositivos; i++) {
        //printf("\nNumDis %d ", i);
        if (dispositivos[i] != nullptr) {
            if (dispositivos[i]->IN(puerto, &dato)) return dato;
        }
    }
    return 0xFF;
}


void Z80IO:: update(u8 ciclos) {
    for (BYTE i = 0; i < MAX_DISPOSITIVOS; i++) {
        if (dispositivos[i] != nullptr) {
            dispositivos[i]->update(ciclos);
        }
    }
}
