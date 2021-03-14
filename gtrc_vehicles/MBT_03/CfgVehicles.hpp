class CfgVehicles {
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
		class EventHandlers;
	};
	
	class MBT_03_base_F: Tank_F {};
	class B_GTRC_MBT_03_base_F: MBT_03_base_F {
		crew = "B_crew_F";
		driverWeaponsInfoType = "RscOptics_MBT_01_Driver";
		faction = "GTRC";
		hiddenSelections[] = {
			"Camo1",
			"Camo2",
			"Camo3"
		};
		hiddenSelectionsTextures[] = {
			"gtrc_vehicles\MBT_03\data\mbt_03_ext01_blufor_co.paa",
			"gtrc_vehicles\MBT_03\data\mbt_03_ext02_blufor_co.paa",
			"gtrc_vehicles\MBT_03\data\mbt_03_rcws_blufor_co.paa"
		};
		side = 1;
		typicalCargo[] = {"B_Soldier_F"};
		class TextureSources {
			class Blufor {
				displayName = "BLUFOR";
				author = "Nightmare515";
				textures[] = {
					"gtrc_vehicles\MBT_03\data\mbt_03_ext01_blufor_co.paa",
					"gtrc_vehicles\MBT_03\data\mbt_03_ext02_blufor_co.paa",
					"gtrc_vehicles\MBT_03\data\mbt_03_rcws_blufor_co.paa"
				};
				factions[] = {"GTRC"};
			};
			class GTRC {
				displayName = "GTRC";
				author = "Phil0rd";
				textures[] = {
					"gtrc_vehicles\MBT_03\data\mbt_03_ext01_gtrc_co.paa",
					"gtrc_vehicles\MBT_03\data\mbt_03_ext02_gtrc_co.paa",
					"gtrc_vehicles\MBT_03\data\mbt_03_rcws_gtrc_co.paa"
				};
				factions[] = {"GTRC"};
			};
			class Pink {
				displayName = "Pink";
				author = "Phil0rd";
				textures[] = {
					"gtrc_vehicles\MBT_03\data\mbt_03_ext01_pink_co.paa",
					"gtrc_vehicles\MBT_03\data\mbt_03_ext02_pink_co.paa",
					"gtrc_vehicles\MBT_03\data\mbt_03_rcws_pink_co.paa"
				};
				factions[] = {"GTRC"};
			};
			class Lava {
				displayName = "Lava";
				author = "Phil0rd";
				textures[] = {
					"gtrc_vehicles\MBT_03\data\mbt_03_ext01_lava_co.paa",
					"gtrc_vehicles\MBT_03\data\mbt_03_ext02_lava_co.paa",
					"gtrc_vehicles\MBT_03\data\mbt_03_rcws_lava_co.paa"
				};
				factions[] = {"GTRC"};
			};
		};
		class TransportItems {
			class _xx_FirstAidKit {
				name = FirstAidKit;
				count = 10;
			};
			class _xx_ToolKit {
				name = ToolKit;
				count = 1;
			};
		};
		class Turrets: Turrets {
			class MainTurret: MainTurret {
				class Turrets: Turrets {
					class CommanderOptics: CommanderOptics {
						weapons[] = {
							"HMG_127_APC",
							"SmokeLauncher",
							"Laserdesignator_mounted"
						};
						magazines[] = {
							"500Rnd_127x99_mag_Tracer_Red",
							"500Rnd_127x99_mag_Tracer_Red",
							"SmokeLauncherMag",
							"SmokeLauncherMag",
							"Laserbatteries"
						};
					};
				};
				weapons[] = {
					"cannon_120mm_long",
					"ACE_LMG_coax_MAG58_mem3"
				};
				magazines[] = {
					"28Rnd_120mm_APFSDS_shells_Tracer_Red",
					"14Rnd_120mm_HE_shells_Tracer_Red",
					"2000Rnd_762x51_Belt_Red",
					"2000Rnd_762x51_Belt_Red"
				};
			};
		};
	};
	class B_GTRC_MBT_03_cannon_F: B_GTRC_MBT_03_base_F {
		author = "Phil0rd";
		_generalMacro = "B_GTRC_MBT_03_cannon_F";
		scope = 2;
		scopeCurator = 2;
		displayName = $STR_GTRC_Vehicles_MBT_03_Name;
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\I_MBT_03_cannon_F.jpg";
	};
};