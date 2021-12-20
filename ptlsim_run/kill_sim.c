#include <stdlib.h>
#include <stdio.h>
#include "ptlcalls.h"

int main(int argc, char **argv){
    printf("Shutting down simulation and vm\n");
	ptlcall_kill();
	return EXIT_SUCCESS;
}

