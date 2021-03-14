params ["_obj"];
if (!isNil "_obj") then {
	_obj addAction ["传送到前线基地",{
		titleText ["正在传送", "BLACK" , 0.5];
		sleep 1.5;
		player setPos (fobArsenal getRelPos [3, 180]);
		player setDir getDir fobArsenal;
		titleFadeOut 0.5;
	}, nil, 100, true, true, "", "!isNull fobArsenal", 5]
};

if (!isNil "FOB_fnc_setup") exitWith {};

FOB_fnc_spawn =
{
	params ["_veh", ["_distance", 2500]];
	private ["_spawnPos", "_dropPos"];
	
	waitUntil {!(getWPPos [group driver _veh, currentWaypoint group driver _veh] isEqualTo [0, 0, 0])};
	_spawnPos = getPos _veh;
	_dropPos = getWPPos [group driver _veh, 1];
	_baseVec = _dropPos vectorFromTo [_spawnPos select 0, _spawnPos select 1, 0];
	_veh setPos [(_dropPos select 0) + (_baseVec select 0)*_distance, (_dropPos select 1) + (_baseVec select 1)*_distance, _spawnPos select 2];
	_veh flyInHeight 120;
	_veh setVelocity (vectorDir _veh vectorMultiply 200);
	_veh forceSpeed 110;
	sleep 120;
	{deleteVehicle _x} forEach crew _veh;
	deleteVehicle _veh;
};

FOB_fnc_flare =
{
	if (isNull _this) exitWith {};
	_flare = "F_40mm_Yellow" createVehicle position _this;
	_flare attachTo [_this,[0,0,0.4]];
	_flare setVectorDirAndUp [[0,0,-1],[0,-1,0]];
};
FOB_fnc_smoke =
{
	if (isNull _this) exitWith {};
	_smoke = "SmokeShellYellow" createVehicle position _this;
	_smoke attachTo [_this,[0,0,0.45]];
	titleFadeOut 0.5;
};
FOB_fnc_addActions = 
{
	if (!hasInterface) exitWith {};
	
	private _id = [];
	_id pushBack (_this addAction ["捡起",{
		params ["_box", "_unit"];
		_unit playMoveNow "AmovPercMstpSnonWnonDnon";
		sleep 2.2;
		//_box attachTo [_unit, [0, 0.65, 0.1], "head"];
		_box attachTo [_unit, [0, -0.31, 0.5], "Spine3"];
		_box setVectorUp [0,0.5,0.5];
		_unit switchMove "AcinPercMstpSnonWnonDnon";
		_unit setVariable ["carryBox", _box];
		_unit addAction ["放下", {
			params ["_unit", "", "_id"];
			private _box = _unit getVariable "carryBox";
			detach _box;
			_box setPos (_unit getRelPos [1, 0]);
			_unit switchMove "AmovPercMstpSnonWnonDnon_AmovPercMstpSrasWrflDnon";
			_unit removeAction _id;
		}, nil, 100];
	}, nil, 100, true, true, "", "isNull attachedTo _target", 2]);
	
	_id pushBack (_this addAction ["设立前线基地", {
		player playAction "PutDown";
		sleep 1.2;
		[_this select 0] remoteExec ["FOB_fnc_setup", 2];
	}, nil, 99, true, true, "", "isNull attachedTo _target", 2]);
	_this setVariable ["fobActions", _id];
};

FOB_fnc_removeActions =
{
	{_this removeAction _x} forEach (_this getVariable ["fobActions", []]);
};

FOB_fnc_drop = 
{
	params ["_box", ["_signal", true]];
	
	if (!isNil "dropBox") then {
		deleteVehicle dropBox;
	};
	dropBox = _box;
	publicVariable "dropBox";
	_box remoteExec ["FOB_fnc_addActions", 0];
	
	_box allowDamage false;
	
	if (_signal) then {
		_box call FOB_fnc_smoke;
		_box call FOB_fnc_flare;
		sleep 11;
		_box call FOB_fnc_flare;
	};
};

FOB_fnc_setup = 
{
	if (!isServer) exitWith {};
	params ["_box"];
	private ["_pos", "_dir", "_bunker", "_arsenal", "_marker", "_objList"];
	
	if (!isNil "fobArsenal") then {
		{deleteVehicle _x} forEach (fobArsenal getVariable "objList");
		deleteMarker "fobMarker";
		(fobArsenal getVariable "respawn") call BIS_fnc_removeRespawnPosition;
	};
	
	_pos = _box getRelPos [1.5, 0];
	_dir = getDir _box;
	{deleteVehicle _x} forEach attachedObjects _box;
	deleteVehicle _box;
	
	_bunker = createVehicle ["Land_BagBunker_Small_F", _pos, [], 0, "NONE"];
	_bunker setDir (_dir + 180);
	_arsenal = createVehicle ["Box_NATO_Equip_F", _bunker getRelPos [0.5, 0], [], 0, "CAN_COLLIDE"];
	_arsenal setDir _dir;
	["AmmoboxInit",[_arsenal, true, {true}]] spawn BIS_fnc_arsenal;
	_objList = [_arsenal, _bunker];
	{
		_x allowDamage false;
		_x enableSimulationGlobal false;
		_x setPos [getPos _x select 0, getPos _x select 1, 0];
	} forEach _objList;
	_arsenal setVariable ["objList", _objList];
	
	fobArsenal = _arsenal;
	publicVariable "fobArsenal";
	
	_marker = createMarker ["fobMarker", _arsenal];
	_marker setMarkerType "b_installation";
	_marker setMarkerText "FOB";
	
	_arsenal setVariable ["respawn", ([missionNamespace, _arsenal getRelPos [3, 180], "前线基地"] call BIS_fnc_addRespawnPosition)];
};

if (hasInterface && didJIP && !isNil "dropBox") then {
	if (!isNull dropBox) then {
		dropBox call FOB_fnc_addActions;
	};
};