if (!isServer) exitWith {};

params ["_unit", ["_index", 0]];

_zeus = PMF_list_zeus select _index;
unassignCurator _zeus;
_unit assignCurator _zeus;
_zeus addCuratorEditableObjects [allPlayers, true];
"你已成为宙斯，按Y键打开宙斯界面" remoteExec ["hintC", remoteExecutedOwner];