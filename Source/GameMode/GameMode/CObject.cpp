/*
	Copyright (c) 2014, Пельмень. All rights reserved.
	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; version 2 of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

#include "CObject.h"
CObject *Object;

void CObject::Create (int modelid, float x, float y, float z, float rx, float ry, float rz, float drawDistance) {
	g_Invoke->callNative(&PAWN::CreateObject, modelid, x, y, z, rx, ry, rz, drawDistance);
}

void CObject::Destroy (int objectid) {
	g_Invoke->callNative(&PAWN::DestroyObject, objectid);
}