
class CfgVehicles
{
	class LandVehicle; 
	class Tank: LandVehicle {
		class NewTurret;
		class Sounds;
		class HitPoints;
	};
	class Tank_F: Tank {
		class Turrets {
			class MainTurret: NewTurret {
				class Turrets {
					class CommanderOptics;
				};
			};
		}; 
		class AnimationSources;
		class ViewPilot;
		class ViewOptics;
		class ViewCargo;
		class HeadLimits; 
		class HitPoints: HitPoints {
			class HitHull;
			class HitEngine;
			class HitLTrack;
			class HitRTrack;
		}; 
		class Sounds: Sounds {
			class Engine;
			class Movement;
		};
	}; 
	class APC_Tracked_03_base_F: Tank_F {};
	class I_APC_tracked_03_base_F: APC_Tracked_03_base_F {};
	class I_APC_tracked_03_cannon_F: I_APC_tracked_03_base_F {}; 
	class B_GTRC_APC_tracked_03_cannon_F: I_APC_tracked_03_cannon_F {
		author = "Phil0rd";
		_generalMacro = "B_GTRC_MBT_03_cannon_F";
		displayName = $STR_GTRC_Vehicles_APC_Tracked_03_Name;
		driverWeaponsInfoType = "RscOptics_MBT_01_Driver";
		faction = "GTRC";
		crew = "B_crew_F";
		scope = 2;
		scopeCurator = 2;
		side = 1;
		typicalCargo[] = {"B_Soldier_F"};
		hiddenSelections[] = {
			"Camo1",
			"Camo2"
		}; 
		hiddenSelectionsTextures[] = {
			"gtrc_vehicles\APC_Tracked_03\data\apc_tracked_03_ext_blufor_co.paa",
			"gtrc_vehicles\APC_Tracked_03\data\apc_tracked_03_ext2_blufor_co.paa"
		}; 
		class TextureSources {
			class Blufor {
				displayName = "BLUFOR";
				author = "Nightmare515";
				textures[] = {
					"gtrc_vehicles\APC_Tracked_03\data\apc_tracked_03_ext_blufor_co.paa",
					"gtrc_vehicles\APC_Tracked_03\data\apc_tracked_03_ext2_blufor_co.paa"
				};
				factions[] = {"GTRC"};
			};
			class GTRC {
				displayName = "GTRC";
				author = "Phil0rd";
				textures[] = {
					"gtrc_vehicles\APC_Tracked_03\data\apc_tracked_03_ext_gtrc_co.paa",
					"gtrc_vehicles\APC_Tracked_03\data\apc_tracked_03_ext2_gtrc_co.paa"
				};
				factions[] = {"GTRC"};
			};
			class Pink {
				displayName = "Pink";
				author = "Phil0rd";
				textures[] = {
					"gtrc_vehicles\APC_Tracked_03\data\apc_tracked_03_ext_pink_co.paa",
					"gtrc_vehicles\APC_Tracked_03\data\apc_tracked_03_ext2_pink_co.paa"
				};
				factions[] = {"GTRC"};
			};
		};
		class Turrets: Turrets {
			class MainTurret: MainTurret {
				weapons[] = {
					"autocannon_30mm",
					"ACE_LMG_coax_L94A1_mem3"
				}; 
				magazines[] = {
					"140Rnd_30mm_MP_shells_Tracer_Red",
					"60Rnd_30mm_APFSDS_shells_Tracer_Red",
					"1000Rnd_762x51_Belt_Red",
					"1000Rnd_762x51_Belt_Red"
				};
				class Turrets: Turrets {
					class CommanderOptics: CommanderOptics {
						weapons[] += {"Laserdesignator_mounted"};
						magazines[] += {"Laserbatteries"};
					};
				};
			};
		};
		class TransportItems {
			class _xx_FirstAidKit {
				name = "FirstAidKit";
				count = 10;
			};
			class _xx_TookKit {
				name = "TookKit";
				count = 1;
			};
		};
	};
};