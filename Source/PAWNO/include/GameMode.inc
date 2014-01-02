#include <a_samp>

native Hook_OnPlayerConnnect(playerid);
native Hook_OnPlayerDisconnect(playerid, reason);
native Hook_OnPlayerSpawn(playerid);
native Hook_OnGameModeExit();
native Hook_OnGameModeInit();
native Hook_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);

public OnPlayerConnect(playerid) {
	Hook_OnPlayerConnnect(playerid);
	#if	defined	CGame_OnPlayerConnect
		CGame_OnPlayerConnect();
	#endif
	return 1;
}

#if	defined	_ALS_OnPlayerConnect
	#undef	OnPlayerConnect
#else
	#define	_ALS_OnPlayerConnect
#endif
#define	OnPlayerConnect	CGame_OnPlayerConnect
#if defined CGame_OnPlayerConnect
	forward	CGame_OnPlayerConnect();
#endif

public OnPlayerSpawn(playerid) {
	Hook_OnPlayerSpawn(playerid);
	#if	defined	CGame_OnPlayerSpawn
		CGame_OnPlayerSpawn();
	#endif
	return 1;
}

#if	defined	_ALS_OnPlayerSpawn
	#undef	OnPlayerSpawn
#else
	#define	_ALS_OnPlayerSpawn
#endif
#define	OnPlayerSpawn	CGame_OnPlayerSpawn
#if defined CGame_OnPlayerSpawn
	forward	CGame_OnPlayerSpawn();
#endif

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
	Hook_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#if	defined	CGame_OnDialogResponse
		CGame_OnDialogResponse();
	#endif
	return 1;
}

#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif
#define	OnDialogResponse	CGame_OnDialogResponse
#if defined CGame_OnDialogResponse
	forward	CGame_OnDialogResponse();
#endif

public OnGameModeInit() {
    Hook_OnGameModeInit();
	#if	defined	CGame_OnGameModeInit
		CGame_OnGameModeInit();
	#endif
    return 1;
}

#if	defined	_ALS_OnGameModeInit
	#undef	OnGameModeInit
#else
	#define	_ALS_OnGameModeInit
#endif
#define	OnGameModeInit	CGame_OnGameModeInit
#if defined CGame_OnGameModeInit
	forward	CGame_OnGameModeInit();
#endif

public OnGameModeExit() {
    Hook_OnGameModeExit();
	#if	defined	CGame_OnGameModeExit
		CGame_OnGameModeExit();
	#endif
	return 1;
}

#if	defined	_ALS_OnGameModeExit
	#undef	OnGameModeExit
#else
	#define	_ALS_OnGameModeExit
#endif
#define	OnGameModeExit	CGame_OnGameModeExit
#if defined CGame_OnGameModeExit
	forward	CGame_OnGameModeExit();
#endif

public OnPlayerDisconnect(playerid,reason) {
    Hook_OnPlayerDisconnect(playerid,reason);
	#if	defined	CGame_OnPlayerDisconnect
		CGame_OnPlayerDisconnect();
	#endif
	return 1;
}

#if	defined	_ALS_OnPlayerDisconnect
	#undef	OnPlayerDisconnect
#else
	#define	_ALS_OnPlayerDisconnect
#endif
#define	OnPlayerDisconnect	CGame_OnPlayerDisconnect
#if defined CGame_OnPlayerDisconnect
	forward	CGame_OnPlayerDisconnect();
#endif

forward public InvokeFunction();
public InvokeFunction()
{
    new Float:fVar;
    new Var[ 256 ];
    new iVar;

    // a_samp.inc
    SendClientMessage(0, 0, "");
    SendClientMessageToAll(0, "");
    SendDeathMessage(0, 0, 0);
    GameTextForAll("", 0, 0);
    GameTextForPlayer(0, "", 0, 0);
    GetTickCount();
    GetMaxPlayers();
    SetGameModeText("");
    SetTeamCount(0);
    AddPlayerClass(0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
    AddPlayerClassEx(0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
    AddStaticVehicle(0, 0.0, 0.0, 0.0, 0.0, 0, 0);
    AddStaticVehicleEx(0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0);
    AddStaticPickup(0, 0, 0.0, 0.0, 0.0);
    ShowNameTags(0);
    ShowPlayerMarkers(0);
    GameModeExit();
    SetWorldTime(0);
    GetWeaponName(0, Var, sizeof( Var ) );
    EnableTirePopping(0);
    AllowInteriorWeapons(0);
    SetWeather(0);
    SetGravity(0.0);
    AllowAdminTeleport(0);
    SetDeathDropAmount(0);
    CreateExplosion(0.0, 0.0, 0.0, 0, 0.0);
    //SetDisabledWeapons();
    EnableZoneNames(0);
    IsPlayerAdmin(0);
    Kick(0);
    Ban(0);
    SendRconCommand("");
    ShowPlayerDialog(0,0,0,"lol","lol","lol","lol");

    // a_players.inc
    SetSpawnInfo(0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0,0);
    SpawnPlayer(0);
    SetPlayerPos(0, 0.0, 0.0, 0.0);
    SetPlayerPosFindZ(0, 0.0, 0.0, 0.0);
    GetPlayerPos(0, fVar, fVar, fVar);
    SetPlayerFacingAngle(0,0.0);
    GetPlayerFacingAngle(0,fVar);
    SetPlayerInterior(0,0);
    GetPlayerInterior(0);
    SetPlayerHealth(0, 0.0);
    GetPlayerHealth(0, fVar);
    SetPlayerArmour(0, 0.0);
    GetPlayerArmour(0, fVar);
    SetPlayerAmmo(0, 0,0);
    GetPlayerAmmo(0);
    SetPlayerTeam(0,0);
    GetPlayerTeam(0);
    SetPlayerScore(0,0);
    GetPlayerScore(0);
    SetPlayerColor(0,0);
    GetPlayerColor(0);
    SetPlayerSkin(0,0);
    GivePlayerWeapon(0, 0,0);
    ResetPlayerWeapons(0);
    GetPlayerWeaponData(0, 0, iVar, iVar );
    GivePlayerMoney(0,0);
    ResetPlayerMoney(0);
    SetPlayerName(0, "");
    GetPlayerMoney(0);
    GetPlayerState(0);
    GetPlayerIp(0, Var, sizeof( Var ));
    GetPlayerPing(0);
    GetPlayerWeapon(0);
    GetPlayerKeys(0,iVar,iVar,iVar);
    GetPlayerName(0, Var, sizeof( Var ));
    PutPlayerInVehicle(0, 0,0);
    GetPlayerVehicleID(0);
    RemovePlayerFromVehicle(0);
    TogglePlayerControllable(0,0);
    PlayerPlaySound(0, 0, 0.0, 0.0,0.0);
    SetPlayerCheckpoint(0, 0.0, 0.0, 0.0,0.0);
    DisablePlayerCheckpoint(0);
    SetPlayerRaceCheckpoint(0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,0.0);
    DisablePlayerRaceCheckpoint(0);
    SetPlayerWorldBounds(0,0.0,0.0,0.0,0.0);
    SetPlayerMarkerForPlayer(0, 0,0);
    ShowPlayerNameTagForPlayer(0, 0,0);
    SetPlayerMapIcon(0, 0, 0.0, 0.0, 0.0, 0,0);
    RemovePlayerMapIcon(0,0);
    SetPlayerCameraPos(0,0.0, 0.0, 0.0);
    SetPlayerCameraLookAt(0, 0.0, 0.0, 0.0);
    SetCameraBehindPlayer(0);
    AllowPlayerTeleport(0,0);
    IsPlayerConnected(0);
    IsPlayerInVehicle(0,0);
    IsPlayerInAnyVehicle(0);
    IsPlayerInCheckpoint(0);
    IsPlayerInRaceCheckpoint(0);
    SetPlayerTime(0, 0,0);
    TogglePlayerClock(0,0);
    SetPlayerWeather(0,0);
    GetPlayerTime(0,iVar,iVar);
    SetPlayerVirtualWorld(0,0);
    GetPlayerVirtualWorld(0);

	GetPlayerVelocity(0,fVar,fVar,fVar);
	GetPlayerAnimationIndex(0);
	GetAnimationName(0,Var, sizeof Var,Var, sizeof Var);
	GetVehicleVelocity(0,fVar,fVar,fVar);
	GetPlayerSpecialAction(0);
	GetPlayerSurfingVehicleID(0);
	

    // a_vehicle.inc
    CreateVehicle(0,0.0,0.0,0.0,0.0,0,0,0);
    DestroyVehicle(0);
    GetVehiclePos(0,fVar,fVar,fVar);
    SetVehiclePos(0,0.0,0.0,0.0);
    GetVehicleZAngle(0,fVar);
    SetVehicleZAngle(0,0.0);
    SetVehicleParamsForPlayer(0,0,0,0);
    SetVehicleToRespawn(0);
    LinkVehicleToInterior(0,0);
    AddVehicleComponent(0,0);
    ChangeVehicleColor(0,0,0);
    ChangeVehiclePaintjob(0,0);
    SetVehicleHealth(0,0.0);
    GetVehicleHealth(0,fVar);
    AttachTrailerToVehicle(0, 0);
    DetachTrailerFromVehicle(0);
    IsTrailerAttachedToVehicle(0);
    GetVehicleModel(0);
    SetVehicleNumberPlate(0,"");
    SetVehicleVirtualWorld(0,0);
    GetVehicleVirtualWorld(0);

    ApplyAnimation(0,"","",1.0,0,0,0,0,0);

    // a_objects.inc
    CreateObject(0,0.0,0.0,0.0,0.0,0.0,0.0);
    SetObjectPos(0,0.0,0.0,0.0);
    GetObjectPos(0,fVar,fVar,fVar);
    SetObjectRot(0,0.0,0.0,0.0);
    GetObjectRot(0,fVar,fVar,fVar);
    IsValidObject(0);
    DestroyObject(0);
    MoveObject(0,0.0,0.0,0.0,0.0);
    StopObject(0);
    CreatePlayerObject(0,0,0.0,0.0,0.0,0.0,0.0,0.0);
    SetPlayerObjectPos(0,0,0.0,0.0,0.0);
    GetPlayerObjectPos(0,0,fVar,fVar,fVar);
    GetPlayerObjectRot(0,0,fVar,fVar,fVar);
    SetPlayerObjectRot(0,0,0.0,0.0,0.0);
    IsValidPlayerObject(0,0);
    DestroyPlayerObject(0,0);
    MovePlayerObject(0,0,0.0,0.0,0.0,0.0);
    StopPlayerObject(0,0);

    // Menu's
    CreateMenu("", 0, 0.0, 0.0, 0.0, 0.0);
    DestroyMenu(Menu:0);
    AddMenuItem(Menu:0, 0, "");
    SetMenuColumnHeader(Menu:0, 0, "");
    ShowMenuForPlayer(Menu:0, 0);
    HideMenuForPlayer(Menu:0, 0);
    IsValidMenu(Menu:0);
    DisableMenu(Menu:0);
    DisableMenuRow(Menu:0,0);

    // Textdraw
    TextDrawCreate(0.0,0.0,"");
    TextDrawDestroy(Text:0);
    TextDrawLetterSize(Text:0, 0.0,0.0);
    TextDrawTextSize(Text:0, 0.0,0.0);
    TextDrawAlignment(Text:0, 0);
    TextDrawColor(Text:0,0);
    TextDrawUseBox(Text:0, 0);
    TextDrawBoxColor(Text:0, 0);
    TextDrawSetShadow(Text:0, 0);
    TextDrawSetOutline(Text:0, 0);
    TextDrawBackgroundColor(Text:0,0);
    TextDrawFont(Text:0, 0);
    TextDrawSetProportional(Text:0, 0);
    TextDrawShowForPlayer(0, Text:0);
    TextDrawHideForPlayer(0, Text:0);
    TextDrawShowForAll(Text:0);
    TextDrawHideForAll(Text:0);

    // Others
    funcidx("");
    gettime(iVar,iVar,iVar);
    getdate(iVar,iVar,iVar);
    tickcount(iVar);

    return 1;
}
