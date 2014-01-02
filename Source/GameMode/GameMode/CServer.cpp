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

#include "CServer.h"
#include <vector>

typedef void (*logprintf_t)(char* format, ...);
extern logprintf_t logprintf;
extern void *pAMXFunctions;
CServer Server;

void CServer::SetGameModeText (const char *gamename) {
	g_Invoke->callNative(&PAWN::SetGameModeText, gamename);
}

string CServer::string_format(const std::string fmt, ...) {
	int size = 100;
	std::string str;
	va_list ap;
	while (1) {
		str.resize(size);
		va_start(ap, fmt);
		int n = vsnprintf((char *)str.c_str(), size, fmt.c_str(), ap);
		va_end(ap);
		if (n > -1 && n < size) {
			str.resize(n);
			return str;
		}
		if (n > -1)
			size = n + 1;
		else
			size *= 2;
	}
	return str;
}

cell AMX_NATIVE_CALL Hook_OnPlayerConnnect(AMX* amx, cell* params) {
	Events::OnPlayerConnect (params[1]);
	return 1;
}

cell AMX_NATIVE_CALL Hook_OnPlayerSpawn(AMX* amx, cell* params) {
	Events::OnPlayerSpawn (params[1]);
	return 1;
}

cell AMX_NATIVE_CALL Hook_OnPlayerDisconnect(AMX* amx, cell* params) {
	Events::OnPlayerDisconnect (params[1], params[2]);
	return 1;
}

cell AMX_NATIVE_CALL Hook_OnGameModeExit(AMX* amx, cell* params) {
	Events::OnGameModeExit();
	return 1;
}

cell AMX_NATIVE_CALL Hook_OnGameModeInit(AMX* amx, cell* params) {
	Events::OnGameModeInit();
	return 1;
}

cell AMX_NATIVE_CALL Hook_OnDialogResponse(AMX *amx, cell *params) {
	int len;
	cell *addr = NULL;

	amx_GetAddr(amx, params[5], &addr); 
    amx_StrLen(addr, &len);
	len++;
	char* inputtext = new char[len];
	amx_GetString(inputtext, addr, 0, len);
	Events::OnDialogResponse (params[1], params[2], params[3], params[4], inputtext);
	delete[] inputtext;
	return 1;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
	g_Invoke = new Invoke;
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];
	return 1;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {

}

AMX_NATIVE_INFO projectNatives[] =
{
	{ "Hook_OnPlayerConnnect", Hook_OnPlayerConnnect },
	{ "Hook_OnPlayerDisconnect", Hook_OnPlayerDisconnect },
	{ "Hook_OnGameModeExit", Hook_OnGameModeExit },
	{ "Hook_OnGameModeInit", Hook_OnGameModeInit },
	{ "Hook_OnPlayerSpawn", Hook_OnPlayerSpawn },
	{ "Hook_OnDialogResponse", Hook_OnDialogResponse },
	{ 0, 0 }
};


PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
   return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx)
{
	logprintf ("\
----------------------------------\n\
Running Pro-Pawn.Ru GameMode\n\
	Coded By\n\
		��������\n\
----------------------------------\n\n\
\
Copyright (c) 2014, ��������. All rights reserved.\n\
This program is free software; you can redistribute it and/or modify\n\
it under the terms of the GNU General Public License as published by\n\
the Free Software Foundation; version 2 of the License.\n\
\n\
This program is distributed in the hope that it will be useful,\n\
but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\n\
GNU General Public License for more details.\n\
\n\
You should have received a copy of the GNU General Public License\n\
along with this program; if not, write to the Free Software\n\
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA\n\
\n\
Version: 0.1a\n\
	");
	g_Invoke->amx_list.push_back(amx);
	g_Invoke->getAddresses();
	return amx_Register(amx, projectNatives, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx)
{
	for(list<AMX *>::iterator i = g_Invoke->amx_list.begin(); i != g_Invoke->amx_list.end(); ++i)
    {
        if(*i == amx)
        {
            g_Invoke->amx_list.erase(i);
            break;
        }
    }
	if (g_Invoke) delete g_Invoke;
	logprintf ("GameMode for Pro-Pawn.Ru by �������� Unloaded!");
    return AMX_ERR_NONE;
}
