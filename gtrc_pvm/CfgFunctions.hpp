
class CfgFunctions {
	class PVM {
		class init {
			file = "gtrc_pvm\init";
			class init {postInit = 1;};
		};
		class functions {
			file = "gtrc_pvm\functions";
			class claimVeh {};
			class claimVehServer {};
			class copyLoadout {};
			class copySkin {};
			class halt {};
			class killed {};
			class lock {};
			class monitor {};
			class reclaimOther {};
			class tryClaim {};
			class unclaim {};
			class unclaimOther {};
		};
	};
};