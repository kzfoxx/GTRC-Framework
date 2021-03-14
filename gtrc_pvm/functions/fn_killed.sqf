if (!isServer) exitWith {};
params ["_vehKilled"];
private ["_source"];
_vehKilled removeAllEventHandlers "Deleted";
_source = _vehKilled getVariable ["source", objNull]; 
sleep PVM_respawnDelay;
if (PVM_deleteWreck) then deleteVehicle _vehKilled;
_source hideObjectGlobal false;
_source setPosWorld (_source getVariable "initPos");