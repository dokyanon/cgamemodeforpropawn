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

#include "Config.h"

namespace Events {
	void OnGameModeInit ();
	void OnGameModeExit ();
	void OnPlayerDisconnect (int playerid, int reason);
	void OnPlayerConnect (int playerid);
	void OnPlayerSpawn (int playerid);
	void OnDialogResponse (int playerid, int dialogid, int response, int listitem, char* inputtext);
};

class CServer {
public:
	void SetGameModeText (const char *gamename);
	string string_format(const std::string fmt, ...);
}; extern CServer Server;
