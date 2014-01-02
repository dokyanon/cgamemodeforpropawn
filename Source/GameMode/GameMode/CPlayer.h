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

#include "Config.h"

typedef void (*logprintf_t)(char* format, ...);
extern logprintf_t logprintf;

struct Position { 
	float x, y, z;
};

set<int> OnlinePlayers;

class CPlayer {
public:
	CPlayer () {}
	CPlayer (int playerid) {
		m_PlayerId = playerid;
		OnlinePlayers.insert (m_PlayerId);
	}

	~CPlayer() {
		Disconnect(); 
	}

	void Disconnect () {
		auth = false;
		Money = 0;
		name[0] = '\0';
		Skin = 0;
		OnlinePlayers.erase (m_PlayerId);
	}

	void Spawn() {
		g_Invoke->callNative(&PAWN::SpawnPlayer, m_PlayerId);
	}

	void Kick () {
		g_Invoke->callNative(&PAWN::Kick, m_PlayerId);
	}

	void GiveMoney (int money) {
		g_Invoke->callNative(&PAWN::GivePlayerMoney, m_PlayerId, money);
	}

	void SetSkin (int skin) {
		g_Invoke->callNative(&PAWN::SetPlayerSkin, m_PlayerId, skin);
	}

	const char *GetName () {
		g_Invoke->callNative(&PAWN::GetPlayerName, m_PlayerId, name);
		return name;
	}

	int SendPlayerMessage (unsigned int color, const char *message) {
		int ret = g_Invoke->callNative(&PAWN::SendClientMessage, m_PlayerId, color, message);
#ifdef DEBUG
		logprintf ("[CPlayer::SendPlayerMessage]: Returned: %d", ret);
#endif
		return ret;
	}

	void SpawnInfo (float x, float y, float z, float a, int weapon1 = -1, int weapon1_ammo = -1, int weapon2 = -1, int weapon2_ammo = -1, int weapon3 = -1, int weapon3_ammo = -1) {
		g_Invoke->callNative (&PAWN::SetSpawnInfo, m_PlayerId, 1, Skin, x, y, z, a, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
	}

	void ShowDialog (int dialogid, int style, char* caption, const char* source, char* button_1, char* button_2) {
		g_Invoke->callNative (&PAWN::ShowPlayerDialog, m_PlayerId, dialogid, style, caption, source, button_1, button_2);
	}

	void SetScore (int score) {
		g_Invoke->callNative (&PAWN::SetPlayerScore, m_PlayerId, score);
	}

	Position& GetPos() {
		g_Invoke->callNative(&PAWN::GetPlayerPos, m_PlayerId, &POS.x, &POS.y, &POS.z);
		return POS;
	}

	void SetPos (Position&  pos) {
		g_Invoke->callNative(&PAWN::SetPlayerPos, m_PlayerId, pos.x, pos.y, pos.z);
	}

	int Money;
	int Level;
	int Skin;
	bool auth;
	char name [24];
	int m_PlayerId;
	Position POS;
}; array<CPlayer, MAX_PLAYERS> Player;
