
class CfgMagazines {
	class 30Rnd_556x45_Stanag;
	class 30Rnd_556x45_Stanag_Tracer_Red;
	class 20Rnd_762x51_Mag;
	
	class ACE_30Rnd_556x45_Stanag_M995_AP_mag: 30Rnd_556x45_Stanag {
		displayName = "5.56mm M995 AP (ACE)";
	};
	class ACE_30Rnd_556x45_Stanag_Mk262_mag: 30Rnd_556x45_Stanag {
		displayName = "5.56mm Mk262 (ACE)";
	};
	class ACE_30Rnd_556x45_Stanag_Mk318_mag: 30Rnd_556x45_Stanag {
		displayName = "5.56mm Mk318 (ACE)";
	};
	class ACE_30Rnd_556x45_Stanag_Tracer_Dim: 30Rnd_556x45_Stanag_Tracer_Red {
		displayName = "5.56mm IR-DIM (ACE)";
	};
	class ACE_20Rnd_762x51_M118LR_Mag: 20Rnd_762x51_Mag {
		displayName = "7.62mm M118LR (ACE)";
	};
	class ACE_20Rnd_762x51_M993_AP_Mag: 20Rnd_762x51_Mag {
		displayName = "7.62mm M993 AP (ACE)";
	};
	class ACE_20Rnd_762x51_Mag_SD: 20Rnd_762x51_Mag {
		displayName = "7.62mm SD (ACE)";
	};
	class ACE_20Rnd_762x51_Mk316_Mod_0_Mag: 20Rnd_762x51_Mag {
		displayName = "7.62mm Mk316 Mod 0 (ACE)";
	};
	class ACE_20Rnd_762x51_Mk319_Mod_0_Mag: 20Rnd_762x51_Mag {
		displayName = "7.62mm Mk319 Mod 0 (ACE)";
	};
	
	class 1Rnd_HE_Grenade_shell;
	class 1Rnd_RPG_Grenade_shell: 1Rnd_HE_Grenade_shell {
		allowedSlots[] = {901};
		ammo = "R_PG7_F";
		author = "Phil";
		descriptionShort = "RPG hhhhhhhhhhhh";
		displayName = "PG-7VM HEAT";
		displayNameShort = "PG-7VM";
		initSpeed = 80;
		mass = 40;
		model = "\A3\Weapons_F_Exp\Launchers\RPG7\rocket_rpg7_item.p3d";
		picture = "\A3\Weapons_F_Exp\Launchers\RPG7\Data\UI\icon_rocket_RPG7_CA.paa";
	};
	
	class rhsusf_5Rnd_00Buck;
	class rhsusf_5Rnd_doomsday_Buck: rhsusf_5Rnd_00Buck {
		scope = 2;
		scopeArsenal = 2;
	};
	class rhsusf_8Rnd_doomsday_Buck: rhsusf_5Rnd_doomsday_Buck {
		initSpeed = 403;
	};
	class rhsusf_5Rnd_dragon_breath: rhsusf_5Rnd_00Buck {
		ammo = "B_12Gauge_Pellets_Submunition_Dagon_Breath";
		author = "Phil";
		descriptionShort = "Dagon Breath";
		displayName = "5rnd Dagon Breath";
		displayNameShort = "Dagon Breath";
		tracersEvery = 1;
		typicalSpeed = 195;
	};
	class rhsusf_8Rnd_dragon_breath: rhsusf_5Rnd_dragon_breath {
		count = 8;
		displayName = "8rnd Dagon Breath";
		initSpeed = 403;
		mass = 8.8;
	};
	class rhsusf_5Rnd_shrapnel: rhsusf_5Rnd_00Buck {
		ammo = "B_12Gauge_Pellets_Submunition_Shrapnel";
		author = "Phil";
		descriptionShort = "Shrapnel";
		displayName = "5rnd Shrapnel";
		displayNameShort = "Shrapnel";
		tracersEvery = 1;
		typicalSpeed = 195;
	};
	class rhsusf_8Rnd_shrapnel: rhsusf_5Rnd_shrapnel {
		count = 8;
		displayName = "8rnd Shrapnel";
		initSpeed = 403;
		mass = 8.8;
	};
};