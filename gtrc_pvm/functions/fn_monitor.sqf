scopeName "main";
params ["_veh"];
_veh setVariable ["monitor", true];
private _time = PVM_emptyTime;
while {_time > 0} do {
	sleep 20;
	if (!alive _veh or !(_veh getVariable ["monitor", false])) then {
		_veh setVariable ["monitor", false];
		breakOut "main"
	};
	if (count ((crew _veh) select {isPlayer _x}) > 0 or _veh == getConnectedUAV player) then {
		_time = PVM_emptyTime;
	}
	else {
		_time = _time - 20;
		if (!unitIsUAV _veh) then {
			private _deserted = true;
			{
				if ((_veh distance _x) < PVM_desertedDistance) then {_deserted = false;};
			} forEach (allPlayers - entities "HeadlessClient_F");
			if (_deserted) then {_time = 0};
		};
		if ((_time%60) == 0) then {systemChat format ["你的%1将会在%2分钟后被归位", getText (configfile >> "CfgVehicles" >> typeof _veh >> "displayName") , _time/60];};
	};
};
deleteVehicle _veh;