/*
 * DO NOT MODIFY
 * This file is atuomatically generated by Marss Builder.
 * If you want to make any changes to this configuration please make
 * changes to '.conf' file which was used to generate this.
 * 
 * conf file:  
 */


enum {
	L2_2M_MESI,
	L2_2M,
	L2_2M_WT,
	L3_8M,
	L2_2M_MOESI,
	L1_128K_MESI,
	L1_256K,
	L1_128K_WT,
	L1_128K_MOESI,
	L1_128K,
	L2_1M_MESI,
};

namespace Memory {
    struct CacheLinesBase;
    CacheLinesBase* get_cachelines(int type);
};
