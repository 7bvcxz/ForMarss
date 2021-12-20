#include <stdlib.h>
#include <stdio.h>
#include "ptlcalls.h"

int main(int argc, char **argv){
    printf("Stopping simulation\n");
	ptlcall_switch_to_native();
	return EXIT_SUCCESS;
}

