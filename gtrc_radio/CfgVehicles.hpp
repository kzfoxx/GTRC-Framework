
class CfgVehicles {
	class B_Parachute;
	class B_Parachute_Radio: B_Parachute {
		ace_hasReserveParachute = 1;
		ace_reserveParachute = "tf_rt1523g_rhs";
		author = "Phil0rd";
		displayName = $STR_GTRC_Parachute_Radio;
		mass = 130;
		tf_dialog = "rt1523g_radio_dialog";
		tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode = "tf_west_radio_code";
		tf_hasLRradio = 1;
		tf_range = 20000;
		tf_subtype = "digital_lr";
	};
	class rhs_d6_Parachute_backpack: B_Parachute {
		displayName = $STR_GTRC_D6_Parachute;
		mass = 120;
	};
	class rhs_d6_Parachute_backpack_radio: rhs_d6_Parachute_backpack {
		ace_hasReserveParachute = 1;
		ace_reserveParachute = "tf_rt1523g_rhs";
		displayName = $STR_GTRC_D6_Parachute_Radio;
		mass = 130;
		tf_dialog = "rt1523g_radio_dialog";
		tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode = "tf_west_radio_code";
		tf_hasLRradio = 1;
		tf_range = 20000;
		tf_subtype = "digital_lr";
	};
	
	class Car_F;
	class LSV_01_base_F: Car_F {
		tf_hasLRradio = 1;
	};
};