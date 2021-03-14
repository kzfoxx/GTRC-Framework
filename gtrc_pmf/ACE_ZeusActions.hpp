
class ACE_ZeusActions {
	class PlayerOptions {
		condition = "true";
		displayName = "玩家";
		icon = "\A3\UI_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
		class respawnAll {
			condition = "true";
			displayName = "全体复活";
			statement = "remoteExecCall ['PMF_fnc_instantRespawn', 0];"
		};
		class healAll {
			condition = "true";
			displayName = "全体治疗";
			statement = "{[player, _x] call (call Achilles_fnc_getAceMedicalFunction);} forEach allPlayers;"
		};
		class respawnTime {
			condition = "true";
			displayName = "重生时间设置";
			class respawnTime30 {
				condition = "true";
				displayName = "30秒";
				statement = "PMF_respawnTimeMax = 30; publicVariable 'PMF_respawnTimeMax';"
			};
			class respawnTime60 {
				condition = "true";
				displayName = "1分钟";
				statement = "PMF_respawnTimeMax = 60; publicVariable 'PMF_respawnTimeMax';"
			};
			class respawnTime150 {
				condition = "true";
				displayName = "2分30秒";
				statement = "PMF_respawnTimeMax = 150; publicVariable 'PMF_respawnTimeMax';"
			};
			class respawnTime300 {
				condition = "true";
				displayName = "5分钟";
				statement = "PMF_respawnTimeMax = 300; publicVariable 'PMF_respawnTimeMax';"
			};
			class respawnTime500 {
				condition = "true";
				displayName = "10分钟";
				statement = "PMF_respawnTimeMax = 600; publicVariable 'PMF_respawnTimeMax';"
			};
		};
	};
	class ZeusTeleport {
		condition = "true";
		displayName = $STR_PMF_Teleport;
		icon = "\A3\UI_F_Curator\Data\CfgMPGameTypes\zsc_ca.paa";
		class zeusPlayer {
			condition = "true";
			displayName = $STR_PMF_Zeus;
			icon = "\A3\UI_F_Curator\Data\Displays\RscDisplayCurator\modeUnits_ca.paa";
			statement = "[0] call PMF_fnc_teleport;"
		};
		class allPlayers {
			condition = "true";
			displayName = $STR_PMF_AllPlayers;
			icon = "\A3\UI_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
			statement = "[1] call PMF_fnc_teleport;"
		};
		class respawnedPlayers {
			condition = "!(getMarkerPos 'PMF_respawn' isEqualTo [0, 0, 0])";
			displayName = $STR_PMF_RespawnedPlayers;
			icon = "\A3\UI_F_Curator\Data\RscCommon\RscAttributeRespawnPosition\guer_ca.paa";
			statement = "[2] call PMF_fnc_teleport;"
		};
	};
	class VcomAI {
		condition = "(!isNil 'VcomAI_UnitInit') && (count (curatorSelected select 0) > 0)";
		displayName = "Vcom AI";
		class disable {
			condition = "true";
			displayName = $STR_PMF_VcomDisable;
			icon = "\A3\UI_F_Curator\Data\default_ca.paa";
			statement = "{_x setvariable ['VCOM_NOAI', true, true]; _x setvariable ['NOAI', true, true];} forEach (curatorSelected select 0);"
		};
		class passive {
			condition = "true";
			displayName = $STR_PMF_VcomPassive;
			statement = "{_x setvariable ['VCOM_NOAI', false, true]; _x setvariable ['NOAI', false, true]; _x setvariable ['VCOM_NOPATHING_Unit', true, true]} forEach (curatorSelected select 0);"
		};
		class normal {
			condition = "true";
			displayName = $STR_PMF_VcomNormal;
			statement = "{_x setvariable ['VCOM_NOAI', false, true]; _x setvariable ['VCOM_NOPATHING_Unit', false, true]} forEach (curatorSelected select 0);"
		};
	};
	class zeusSide {
		condition = "true";
		displayName = "AI Faction";
		class switchSide {
			condition = "true";
			displayName = "Switch BLUFOR/OPFOR";
			statement = "[0] call PMF_fnc_zeusSide";
		};
		class BLUFOR {
			condition = "true";
			displayName = "All BLUFOR";
			statement = "[1] call PMF_fnc_zeusSide";
		};
		class OPFOR {
			condition = "true";
			displayName = "All OPFOR";
			statement = "[2] call PMF_fnc_zeusSide";
		};
		class independent {
			condition = "true";
			displayName = "All Independent";
			statement = "[3] call PMF_fnc_zeusSide";
		};
		class civilian {
			condition = "true";
			displayName = "All Civilian";
			statement = "[4] call PMF_fnc_zeusSide";
		};
		class reset {
			condition = "true";
			displayName = "Reset";
			statement = "[-1] call PMF_fnc_zeusSide";
		};
	};
	class TransferOwner {
		condition = "(count (curatorSelected select 0) > 0)";
		displayName = "Transfer Ownership";
		class toLocal {
			condition = "true";
			displayName = "To Local";
			statement = "[curatorSelected, 0] remoteExecCall ['PMF_fnc_transferOwner', 2]";
		};
		class toHC {
			condition = "(hcOwner != 2)";
			displayName = "To HC";
			statement = "[curatorSelected, 1] remoteExecCall ['PMF_fnc_transferOwner', 2]";
		};
		class toServer {
			condition = "true";
			displayName = "To Server";
			statement = "[curatorSelected, 2] remoteExecCall ['PMF_fnc_transferOwner', 2]";
		};
	};
};