PMF_fnc_arbPrepare = {
	params ["_unit", ["_veh", objNull]];
	
	if (isNull _veh) then {
		_veh = vehicle _unit;
	};
	if (typeOf _veh != "B_T_VTOL_01_infantry_F") exitWith {};
	
	private _dropList = units group _unit select {vehicle _x == _veh};
	if (count _dropList > 10) exitWith {
		hint "人数过多，最多支持10人排队跳伞";
	};
	
	{
		[_x, _forEachIndex, _veh, false] call PMF_fnc_arbStandPos;
	} forEach _dropList;
	
	_veh setVariable ["PMF_arbDropList", _dropList];
	_veh animateDoor ['Door_1_source', 1];
};

PMF_fnc_arbStart = {
	params ["_veh"];
	if (_veh isKindOf "man") then {
		_veh = _veh getVariable "PMF_arbVeh";
	};
	{
		[_x, _veh, true] remoteExecCall ["PMF_fnc_arbJump", _x];
	} forEach (_veh getVariable ["PMF_arbDropList", []]);
};

PMF_fnc_arbStandPos = {
	params ["_unit",  "_index", ["_veh", objNull], ["_continue", true]];
	
	if (!local _unit) exitWith {
		_this remoteExecCall ["PMF_fnc_arbStandPos", _unit];
	};
	
	if (isNull _veh) then {
		_veh = _unit getVariable ["PMF_arbVeh", objNull];
	} else {
		_unit setVariable ["PMF_arbVeh", _veh];
	};
	
	if (!alive _unit or !alive _veh) exitWith {
		detach _unit;
		_unit setVariable ["PMF_arbVeh", nil];
		_unit setVariable ["PMF_arbPosX", nil];
		_unit setVariable ["PMF_arbPosY", nil];
	};
	
	private ["_posX", "_posY", "_indexRow", "_waitTime"];
	if (_index >= 0) then {
		if (_index % 2 == 0) then {
			_posX = -0.65;
			_indexRow = _index / 2;
		} else {
			_posX = 0.65;
			_indexRow = (_index - 1) / 2;
		};
		_posY = _indexRow * 1.5 - 2;
		_unit setVariable ["PMF_arbPosX", _posX];
		_unit setVariable ["PMF_arbPosY", _posY];
		unassignVehicle _unit;
		moveOut _unit;
		_unit action ["SWITCHWEAPON", _unit, _unit, -1];
		_waitTime = 1 + 0.5 * _index;
		_unit setVariable ["PMF_arbWaitTime", _waitTime];
	} else {
		_posX = _unit getVariable ["PMF_arbPosX", -1000];
		_posY = _unit getVariable ["PMF_arbPosY", -1000];
		_posY = _posY - 1.5;
		_unit setVariable ["PMF_arbPosX", _posX];
		_unit setVariable ["PMF_arbPosY", _posY];
		
	};
	
	if (_posY == -1000) exitWith {};
	
	_unit attachTo [_veh, [_posX, _posY, -5.7]];
	_unit setVectorDirAndUp [[0,-1,0],[0,0,1]];
	
	if (_continue) then {
		[PMF_fnc_arbJump, [_unit, _veh, _posX], _waitTime] call CBA_fnc_waitAndExecute;
	};
};

PMF_fnc_arbJump = {
	params ["_unit", "_veh", ["_wait", false]];
	
	if (!local _unit) exitWith {
		_this remoteExecCall ["PMF_fnc_arbJump", _unit];
	};
	if (_wait) exitWith {
		[PMF_fnc_arbJump, [_unit, _veh, false], (_unit getVariable ["PMF_arbWaitTime", 0])] call CBA_fnc_waitAndExecute;
	};
	
	private _vel = velocity _unit vectorMultiply 0.5;
	private _dir = getDir _unit;
	_unit allowDamage false;
	_unit attachTo [_veh, [(_unit getVariable ["PMF_arbPosX", 0]), -3.5, -6]];
	
	[{
		params ["_unit", "_vel", "_dir"];
		
		detach _unit;
		_unit setDir (_dir + 180);
		_unit setVelocity _vel;
		
		_unit setVariable ["PMF_arbVeh", nil];
		_unit setVariable ["PMF_arbPosX", nil];
		_unit setVariable ["PMF_arbPosY", nil];
	}, [_unit, _vel, _dir]] call CBA_fnc_execNextFrame;
	
	[{_this allowDamage true}, _unit, 2] call CBA_fnc_waitAndExecute;
};

if (hasInterface) then {
	private _arbPrepare = ["arbPrepare", "准备跳伞", "", {[player, vehicle player] call PMF_fnc_arbPrepare}, {typeOf vehicle player == "B_T_VTOL_01_infantry_F"}] call ace_interact_menu_fnc_createAction;
	private _arbStart = ["arbStart", "开始跳伞", "", {player call PMF_fnc_arbStart}, {!isNull (player getVariable ["PMF_arbVeh", objNull])}] call ace_interact_menu_fnc_createAction;

	["CAManBase", 1, ["ACE_SelfActions"], _arbPrepare, true] call ace_interact_menu_fnc_addActionToClass;
	["CAManBase", 1, ["ACE_SelfActions"], _arbStart, true] call ace_interact_menu_fnc_addActionToClass;
};