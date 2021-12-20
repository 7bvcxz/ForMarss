/*
 * DO NOT MODIFY
 * This file is atuomatically generated by Marss Builder.
 * If you want to make any changes to this configuration please make
 * changes to '.conf' file which was used to generate this.
 * 
 * conf file:  
 */



#include <globals.h>
#include <ptlsim.h>
#include <memoryHierarchy.h>
#include <memoryRequest.h>
#include <cacheLines.h>

namespace Memory {

#define L2_2M_MESI_LATENCY 5
#define L2_2M_MESI_WRITE_PORTS 2
#define L2_2M_MESI_ASSOC 8
#define L2_2M_MESI_READ_PORTS 2
#define L2_2M_MESI_LINE_SIZE 64
#define L2_2M_MESI_SIZE 2M
#define L2_2M_MESI_SETS 4096

typedef CacheLines<L2_2M_MESI_SETS, L2_2M_MESI_ASSOC, L2_2M_MESI_LINE_SIZE, L2_2M_MESI_LATENCY> L2_2M_MESI_CacheLines;

#define L2_2M_LATENCY 5
#define L2_2M_WRITE_PORTS 2
#define L2_2M_ASSOC 8
#define L2_2M_READ_PORTS 2
#define L2_2M_LINE_SIZE 64
#define L2_2M_SIZE 2M
#define L2_2M_SETS 4096

typedef CacheLines<L2_2M_SETS, L2_2M_ASSOC, L2_2M_LINE_SIZE, L2_2M_LATENCY> L2_2M_CacheLines;

#define L2_2M_WT_LATENCY 5
#define L2_2M_WT_WRITE_PORTS 2
#define L2_2M_WT_ASSOC 8
#define L2_2M_WT_READ_PORTS 2
#define L2_2M_WT_LINE_SIZE 64
#define L2_2M_WT_SIZE 2M
#define L2_2M_WT_SETS 4096

typedef CacheLines<L2_2M_WT_SETS, L2_2M_WT_ASSOC, L2_2M_WT_LINE_SIZE, L2_2M_WT_LATENCY> L2_2M_WT_CacheLines;

#define L3_8M_LATENCY 8
#define L3_8M_WRITE_PORTS 2
#define L3_8M_ASSOC 8
#define L3_8M_READ_PORTS 2
#define L3_8M_LINE_SIZE 64
#define L3_8M_SIZE 8M
#define L3_8M_SETS 16384

typedef CacheLines<L3_8M_SETS, L3_8M_ASSOC, L3_8M_LINE_SIZE, L3_8M_LATENCY> L3_8M_CacheLines;

#define L2_2M_MOESI_LATENCY 5
#define L2_2M_MOESI_WRITE_PORTS 2
#define L2_2M_MOESI_ASSOC 8
#define L2_2M_MOESI_READ_PORTS 2
#define L2_2M_MOESI_LINE_SIZE 64
#define L2_2M_MOESI_SIZE 2M
#define L2_2M_MOESI_SETS 4096

typedef CacheLines<L2_2M_MOESI_SETS, L2_2M_MOESI_ASSOC, L2_2M_MOESI_LINE_SIZE, L2_2M_MOESI_LATENCY> L2_2M_MOESI_CacheLines;

#define L1_128K_MESI_LATENCY 2
#define L1_128K_MESI_WRITE_PORTS 1
#define L1_128K_MESI_ASSOC 8
#define L1_128K_MESI_READ_PORTS 2
#define L1_128K_MESI_LINE_SIZE 64
#define L1_128K_MESI_SIZE 128K
#define L1_128K_MESI_SETS 256

typedef CacheLines<L1_128K_MESI_SETS, L1_128K_MESI_ASSOC, L1_128K_MESI_LINE_SIZE, L1_128K_MESI_LATENCY> L1_128K_MESI_CacheLines;

#define L1_256K_LATENCY 2
#define L1_256K_WRITE_PORTS 1
#define L1_256K_ASSOC 8
#define L1_256K_READ_PORTS 2
#define L1_256K_LINE_SIZE 64
#define L1_256K_SIZE 256K
#define L1_256K_SETS 512

typedef CacheLines<L1_256K_SETS, L1_256K_ASSOC, L1_256K_LINE_SIZE, L1_256K_LATENCY> L1_256K_CacheLines;

#define L1_128K_WT_LATENCY 2
#define L1_128K_WT_WRITE_PORTS 1
#define L1_128K_WT_ASSOC 8
#define L1_128K_WT_READ_PORTS 2
#define L1_128K_WT_LINE_SIZE 64
#define L1_128K_WT_SIZE 128K
#define L1_128K_WT_SETS 256

typedef CacheLines<L1_128K_WT_SETS, L1_128K_WT_ASSOC, L1_128K_WT_LINE_SIZE, L1_128K_WT_LATENCY> L1_128K_WT_CacheLines;

#define L1_128K_MOESI_LATENCY 2
#define L1_128K_MOESI_WRITE_PORTS 1
#define L1_128K_MOESI_ASSOC 8
#define L1_128K_MOESI_READ_PORTS 2
#define L1_128K_MOESI_LINE_SIZE 64
#define L1_128K_MOESI_SIZE 128K
#define L1_128K_MOESI_SETS 256

typedef CacheLines<L1_128K_MOESI_SETS, L1_128K_MOESI_ASSOC, L1_128K_MOESI_LINE_SIZE, L1_128K_MOESI_LATENCY> L1_128K_MOESI_CacheLines;

#define L1_128K_LATENCY 2
#define L1_128K_WRITE_PORTS 1
#define L1_128K_ASSOC 8
#define L1_128K_READ_PORTS 2
#define L1_128K_LINE_SIZE 64
#define L1_128K_SIZE 128K
#define L1_128K_SETS 256

typedef CacheLines<L1_128K_SETS, L1_128K_ASSOC, L1_128K_LINE_SIZE, L1_128K_LATENCY> L1_128K_CacheLines;

#define L2_1M_MESI_LATENCY 5
#define L2_1M_MESI_WRITE_PORTS 2
#define L2_1M_MESI_ASSOC 8
#define L2_1M_MESI_READ_PORTS 2
#define L2_1M_MESI_LINE_SIZE 64
#define L2_1M_MESI_SIZE 1M
#define L2_1M_MESI_SETS 2048

typedef CacheLines<L2_1M_MESI_SETS, L2_1M_MESI_ASSOC, L2_1M_MESI_LINE_SIZE, L2_1M_MESI_LATENCY> L2_1M_MESI_CacheLines;


CacheLinesBase* get_cachelines(int cache_type)
{
	switch(cache_type) {

        case L2_2M_MESI:
            return new L2_2M_MESI_CacheLines(L2_2M_MESI_READ_PORTS, L2_2M_MESI_WRITE_PORTS);

        case L2_2M:
            return new L2_2M_CacheLines(L2_2M_READ_PORTS, L2_2M_WRITE_PORTS);

        case L2_2M_WT:
            return new L2_2M_WT_CacheLines(L2_2M_WT_READ_PORTS, L2_2M_WT_WRITE_PORTS);

        case L3_8M:
            return new L3_8M_CacheLines(L3_8M_READ_PORTS, L3_8M_WRITE_PORTS);

        case L2_2M_MOESI:
            return new L2_2M_MOESI_CacheLines(L2_2M_MOESI_READ_PORTS, L2_2M_MOESI_WRITE_PORTS);

        case L1_128K_MESI:
            return new L1_128K_MESI_CacheLines(L1_128K_MESI_READ_PORTS, L1_128K_MESI_WRITE_PORTS);

        case L1_256K:
            return new L1_256K_CacheLines(L1_256K_READ_PORTS, L1_256K_WRITE_PORTS);

        case L1_128K_WT:
            return new L1_128K_WT_CacheLines(L1_128K_WT_READ_PORTS, L1_128K_WT_WRITE_PORTS);

        case L1_128K_MOESI:
            return new L1_128K_MOESI_CacheLines(L1_128K_MOESI_READ_PORTS, L1_128K_MOESI_WRITE_PORTS);

        case L1_128K:
            return new L1_128K_CacheLines(L1_128K_READ_PORTS, L1_128K_WRITE_PORTS);

        case L2_1M_MESI:
            return new L2_1M_MESI_CacheLines(L2_1M_MESI_READ_PORTS, L2_1M_MESI_WRITE_PORTS);
		default: assert(0);
	}
}
};
