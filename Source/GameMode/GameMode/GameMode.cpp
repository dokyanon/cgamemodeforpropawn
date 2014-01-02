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

#include "CPlayer.h"
#include "CServer.h"
#include "CObject.h"
#include "CMysql.h"
#include "md5.h"

typedef void (*logprintf_t)(char* format, ...);
logprintf_t logprintf;

void Events::OnGameModeInit() {
	Server.SetGameModeText("C++ Game Mode for Pro-Pawn.Ru");
	MySQL.Connect();
}

void Events::OnDialogResponse (int playerid, int dialogid, int response, int listitem, char* inputtext) {
	int len = strlen (inputtext);
	if (dialogid == 1) {
		if (response) {
			if (len < 4 || len > 16) {
				Player[playerid].SendPlayerMessage (0xFFFFFF00, "������ ������ �� ����� ���� ������ 4 � ������ 16 �������");
				Player[playerid].ShowDialog (1, 1, "{FFFFFF}�����������", Server.string_format("����� ���������� �� Pro-Pawn.Ru\n\n������� %s �� ���������������\n���������� ������ � ������� ���").c_str(), "����������", "�����");
				return;
			}
			MySQL.Query (Server.string_format("Insert Into `users` (Name, Password, Level, Money, Skin) Values ('%s', '%s', '1', '250', '23')", Player[playerid].GetName(), md5(inputtext).c_str()).c_str());
			Player[playerid].auth = true;
			Player[playerid].GiveMoney(Player[playerid].Money);
			Player[playerid].SetScore(Player[playerid].Level);
			Player[playerid].SetSkin(Player[playerid].Skin);
			Player[playerid].SendPlayerMessage (0xFFFFFF00, "�� ������� ������������������ �� ������� Pro-Pawn.Ru, �������� ����!");
			Player[playerid].SpawnInfo(1958.3783f, 1343.1572f, 15.3746f, 269.1425f);
			Player[playerid].Spawn();
		} else {
			Player[playerid].SendPlayerMessage (0xFFFFFF00, "���������� ������������������!");
			Player[playerid].Kick();
		}
	}
	if (dialogid == 2) {
		if (response) {
			if (len < 4 || len > 16) {
				Player[playerid].SendPlayerMessage (0xFFFFFF00, "������ ������ �� ����� ���� ������ 4 � ������ 16 �������");
				Player[playerid].ShowDialog (2, 1, "{FFFFFF}�����������", Server.string_format("����� ���������� �� Pro-Pawn.Ru\n\n������� %s ���������������\n������� ������ �� ��������").c_str(), "����������", "�����");
				return;
			}
			MySQL.Query (Server.string_format("Select * From `users` Where `Name` = \'%s\' And `Password` = \'%s\'", Player[playerid].GetName(), md5(inputtext).c_str()).c_str());
			MySQL.Store();
			if (MySQL.NumRows() == 0) {
				Player[playerid].SendPlayerMessage (0xFFFFFF00, "�� ����� �� ������ ������, ��������� �������!");
				Player[playerid].ShowDialog (2, 1, "{FFFFFF}�����������", Server.string_format("����� ���������� �� Pro-Pawn.Ru\n\n������� %s ���������������\n������� ������ �� ��������").c_str(), "����������", "�����");
				return;
			} else {
				if ((MySQL.row = mysql_fetch_row (MySQL.result)) != NULL) {
					Player[playerid].SetScore(Player[playerid].Level = atoi (MySQL.row[3]));
					Player[playerid].GiveMoney(Player[playerid].Money = atoi (MySQL.row[4]));
					Player[playerid].SetSkin(Player[playerid].Skin = atoi (MySQL.row[5]));
				}
				Player[playerid].auth = true;
				Player[playerid].SendPlayerMessage (0xFFFFFF00, "�� ������� �������������� �� ������� Pro-Pawn.Ru, �������� ����!");
				Player[playerid].SpawnInfo(1958.3783f, 1343.1572f, 15.3746f, 269.1425f);
				Player[playerid].Spawn();
			}
			MySQL.Free();
		} else {
			Player[playerid].SendPlayerMessage (0xFFFFFF00, "���������� ��������������!");
			Player[playerid].Kick();
		}
	}
}

void Events::OnGameModeExit() {
	for (set<int>::iterator itr = OnlinePlayers.begin(); itr != OnlinePlayers.end(); ++itr) {
		Player [*itr].Disconnect();
	}
	MySQL.Close();
}

void Events::OnPlayerConnect (int playerid) {
	Player[playerid].SendPlayerMessage (0xFFFFFF00, Server.string_format("��������� %s ������������ ��� �� ������� Pro-Pawn.Ru", Player[playerid].GetName()).c_str());

	MySQL.Query (Server.string_format("Select `Name` From `users` Where `Name` = \'%s\'", Player[playerid].GetName()).c_str());
	MySQL.Store();
	if (MySQL.NumRows () == 1) {
		Player[playerid].ShowDialog (2, 1, "{FFFFFF}�����������", Server.string_format("����� ���������� �� Pro-Pawn.Ru\n\n������� %s ���������������\n������� ������ �� ��������").c_str(), "����������", "�����");
	} else {
		Player[playerid].ShowDialog (1, 1, "{FFFFFF}�����������", Server.string_format("����� ���������� �� Pro-Pawn.Ru\n\n������� %s �� ���������������\n���������� ������ � ������� ���").c_str(), "����������", "�����");
	}
	MySQL.Free();
}

void Events::OnPlayerSpawn (int playerid) {
	if (!Player[playerid].auth) {
		Player[playerid].SendPlayerMessage (0xFFFFFF00, "���������� ��������������!");
		Player[playerid].Kick();
	}
}

void Events::OnPlayerDisconnect (int playerid, int reason) {
	Player[playerid].Disconnect();
}
