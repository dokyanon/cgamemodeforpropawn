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

#include "include/mysql.h"

class CMySQL {
public:
	MYSQL_RES *result;
	MYSQL_ROW row;
	MYSQL_FIELD *field;
	MYSQL *connection, mysql;
	int state;

	void Query (const char* query);
	void Connect ();
	void Close ();
	void Store ();
	my_ulonglong NumRows ();
	void Free ();
}; extern CMySQL MySQL;