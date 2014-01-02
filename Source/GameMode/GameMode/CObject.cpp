/*
Copyright (C) 2014  Пельмень.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "CObject.h"
CObject *Object;

void CObject::Create (int modelid, float x, float y, float z, float rx, float ry, float rz, float drawDistance) {
	g_Invoke->callNative(&PAWN::CreateObject, modelid, x, y, z, rx, ry, rz, drawDistance);
}

void CObject::Destroy (int objectid) {
	g_Invoke->callNative(&PAWN::DestroyObject, objectid);
}
