#include <stdlib.h>
#include <stdio.h>
#include "ptlcalls.h"

int main(int argc, char **argv){
    printf("Starting simulation\n");
	ptlcall_switch_to_sim();
	return EXIT_SUCCESS;
}

