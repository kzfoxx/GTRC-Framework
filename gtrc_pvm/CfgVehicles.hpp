
class CfgVehicles {
	class Air;
	class Plane: Air {
		class ACE_SelfActions {
			class PVM_LoadAutoPilot {
				displayName = "Load Autopilot";
				condition = "(_player ==  driver _target) && !(_target getVariable ['PVM_autoPilotLoaded', false])";
				statement = "[_target] call PVM_fnc_loadAutoPilot";
			};
		};
	};
	class Helicopter: Air {
		class ACE_SelfActions {
			class PVM_LoadAutoPilot {
				displayName = "Load Autopilot";
				condition = "(_player ==  driver _target) && !(_target getVariable ['PVM_autoPilotLoaded', false])";
				statement = "[_target] call PVM_fnc_loadAutoPilot";
			};
		};
	};
};