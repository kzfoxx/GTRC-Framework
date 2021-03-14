if (!isServer) exitWith {};

params ["_vehStatic", "_claimer"];
private ["_vehOld", "_vehNew", "_vehOldSource", "_pos", "_dir"];
if (PVM_separateAir && _vehStatic isKindOf "Air") then {
	_vehOld = missionNamespace getVariable [format ["PVM_%1_air", getPlayerUID _claimer], objNull];
}
else{
	_vehOld = missionNamespace getVariable [format ["PVM_%1_veh", getPlayerUID _claimer], objNull];
};
deleteVehicle _vehOld;

_pos = getPosWorld _vehStatic;
_dir = getDir _vehStatic;
_vehStatic setPosWorld [0, 0, 10000];
_vehStatic hideObjectGlobal true;
_vehNew = createVehicle [typeOf _vehStatic, _pos, [], 0, "CAN_COLLIDE"];


if (PVM_separateAir && _vehStatic isKindOf "Air") then {
	missionNamespace setVariable [format ["PVM_%1_air", getPlayerUID _claimer], _vehNew];
}
else{
	missionNamespace setVariable [format ["PVM_%1_veh", getPlayerUID _claimer], _vehNew];
};


_vehNew setVariable ["source", _vehStatic];
_vehNew setVariable ["claimer", getPlayerUID _claimer];
_vehNew setVariable ["whitelist", _vehStatic getVariable ["whitelist", {[]}], true];
_vehNew addEventHandler ["Deleted", {
	private _source = _this select 0 getVariable ["source", objNull];
	_source hideObjectGlobal false;
	_source setPosWorld (_source getVariable "initPos");
}];
_vehNew addMPEventHandler ["MPKilled", {if (isServer) then {[_this select 0] spawn PVM_fnc_killed;};}];
{_x addCuratorEditableObjects [[_vehNew], false]} forEach allCurators;

[_vehStatic, _vehNew] call PVM_fnc_copySkin;
[_vehStatic, _vehNew] call PVM_fnc_copyLoadout;

_vehNew setDir _dir;
_vehNew setPosWorld _pos;

if (_vehNew isKindOf "Helicopter" && !isNil "ace_fastroping_fnc_equipFRIES") then {
	[_vehNew] call ace_fastroping_fnc_equipFRIES;
};

if (unitIsUAV _vehNew) then {
	private _grp = createGroup [west, true];
	createVehicleCrew _vehNew;
	crew _vehNew joinSilent _grp;
	_grp setGroupOwner remoteExecutedOwner;
	units _grp call PMF_fnc_addEditable;
};

if (_vehStatic getVariable ["PMF_medicalVehicle", true]) then {
	_vehNew setVariable ["ace_medical_medicClass", 1, true];
};

[_vehNew] remoteExecCall ["PVM_fnc_claimVeh", remoteExecutedOwner];