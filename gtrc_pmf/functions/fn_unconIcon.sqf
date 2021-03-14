if (!isNil "PMF_XEH_unconIcon") then {
	["ace_unconscious", PMF_XEH_unconIcon] call CBA_fnc_removeEventHandler;
	PMF_XEH_unconIcon = nil;
};

PMF_XEH_unconIcon = ["ace_unconscious", {
	params ["_unit", "_uncon"];
	
	private _module = getAssignedCuratorLogic player;
	if (isNull _module) exitWith {};
	if (!isPlayer _unit) exitWith {};
	
	if (_uncon) then {
		_unit setVariable ["PMF_downedTime", time];
		private _id = [_module, ["", [1,0,0,1], getPos _unit, 1, 1, 0, 
		format ["%1", round (time - (_unit getVariable "PMF_downedTime"))], 
		2, 0.033, "RobotoCondensed", "center", false]] call BIS_fnc_addCuratorIcon;
		_unit setVariable ["PMF_downedId", _id];
	} else {
		[_module, _unit getVariable "PMF_downedId"] call BIS_fnc_removeCuratorIcon;
		_unit setVariable ["PMF_downedTime", nil];
		_unit setVariable ["PMF_downedId", nil];
	};

}] call CBA_fnc_addEventHandler;