class CfgMagazines {
	class 20Rnd_Rocket_03_AP_F;
	class PylonRack_20Rnd_Rocket_03_AP_F: 20Rnd_Rocket_03_AP_F {
		hardpoints[] = {"O_MISSILE_PYLON","O_SKYFIRE","B_AGM65_RAIL","I_AGM65_RAIL"};
	};
	class 20Rnd_Rocket_03_HE_F;
	class PylonRack_20Rnd_Rocket_03_HE_F: 20Rnd_Rocket_03_HE_F {
		hardpoints[] = {"O_MISSILE_PYLON","O_SKYFIRE","B_AGM65_RAIL","I_AGM65_RAIL"};
	};
	class 6Rnd_ACE_Hellfire_AGM114K;
	class PylonRack_3Rnd_ACE_Hellfire_AGM114K: 6Rnd_ACE_Hellfire_AGM114K {
		hardpoints[] = {"B_MISSILE_PYLON","UNI_SCALPEL","CUP_NATO_HELO_LARGE","B_AGM65_RAIL","I_AGM65_RAIL"};
	};
	class PylonRack_1Rnd_ACE_Hellfire_AGM114K: 6Rnd_ACE_Hellfire_AGM114K {
		hardpoints[] = {"B_MISSILE_PYLON","SCALPEL_1RND_EJECTOR","B_ASRRAM_EJECTOR","UNI_SCALPEL","CUP_NATO_HELO_SMALL","CUP_NATO_HELO_LARGE","RHS_HP_MELB","B_AGM65_RAIL","I_AGM65_RAIL","B_AMRAAM_D_INT"};
	};
	class PylonMissile_1Rnd_ACE_Hellfire_AGM114K: 6Rnd_ACE_Hellfire_AGM114K {
		hardpoints[] = {"SCALPEL_1RND","B_BIM9X","I_BIM9X"};
	};
	class 300Rnd_20mm_shells;
	class PylonWeapon_300Rnd_20mm_shells: 300Rnd_20mm_shells {
		hardpoints[] = {"B_A143_BUZZARD_CENTER_PYLON","20MM_TWIN_CANNON","B_AGM65_DUAL_RAIL","I_AGM65_DUAL_RAIL","B_AGM65_RAIL","I_AGM65_RAIL","B_BOMB_PYLON","B_MISSILE_PYLON"};
	};
	class magazine_Bomb_GBU12_x1;
	class PylonMissile_Bomb_GBU12_x1: magazine_Bomb_GBU12_x1 {
		hardpoints[] = {"B_GBU12","I_GBU12","B_AMRAAM_D_INT"};
	};
	class 2Rnd_Mk82;
	class PylonMissile_1Rnd_Mk82_F: 2Rnd_Mk82 {
		hardpoints[] = {"B_BOMB_PYLON","B_AMRAAM_D_INT"};
	};
};