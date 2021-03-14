class CfgAmmo {
	class BulletBase;
	class B_556x45_Ball;
	class B_762x54_Ball;
	
	class rhs_ammo_556x45_M855_Ball: B_556x45_Ball {
		caliber = 0.8;
	};
	class rhs_ammo_556x45_M855A1_Ball: B_556x45_Ball {
		caliber = 0.869565;
	};
	class rhs_ammo_556x45_Mk262_Ball: B_556x45_Ball {
		caliber = 0.869565;
	};
	class rhs_ammo_556x45_Mk318_Ball: B_556x45_Ball {
		caliber = 0.869565;
	};
	
	class rhs_ammo_762x51_M80_Ball: BulletBase {
		caliber = 1.6;
		hit = 12;
	};
	class rhs_ammo_762x51_M118_Special_Ball: rhs_ammo_762x51_M80_Ball {
		caliber = 1.85;
		hit = 12;
	};
	class rhs_ammo_762x51_M61_AP: rhs_ammo_762x51_M80_Ball {
		caliber = 2.2;
	}
	class rhs_ammo_762x51_M62_tracer: rhs_ammo_762x51_M80_Ball {
		caliber = 1.6;
		hit = 12;
	};
	class rhs_ammo_762x51_M80A1EPR_Ball: rhs_ammo_762x51_M80_Ball {
		caliber = 1.95;
		hit = 11;
	};
	class rhs_ammo_762x51_M993_Ball: rhs_ammo_762x51_M80_Ball {
		caliber = 2.2;
		hit = 12;
	};
	
	class rhsusf_B_300winmag: B_762x54_Ball {
		caliber = 1.8;
	};
};