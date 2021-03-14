params ["_veh"];
private ["_whitelist"];
_whiteList = call (_veh getVariable ["whitelist", {[]}]);
if (count _whiteList == 0 or (typeOf player in _whitelist)) then {
	if (_veh in synchronizedObjects PVM) then {
		[_veh, player] remoteExecCall ["PVM_fnc_claimVehServer", 2];
	}
	else {
		[_veh, player] remoteExecCall ["PVM_fnc_reclaimOther"];
	};
}
else {
	cutText [Format ["此载具仅限%1使用", _whitelist select 0], "PLAIN", 0.5];
};