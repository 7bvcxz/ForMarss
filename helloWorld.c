#include <stdlib.h>
#include <stdio.h>
#include "ptlcalls.h"

int main(int argc, char **argv){
	char* chk_name=getenv("CHECKPOINT_NAME");
	if(chk_name != NULL) {
		printf("Creating checkpoint with name %s\n", chk_name);
		ptlcall_checkpoint_and_shutdown(chk_name);
	}
    printf("Hello World\n");
	ptlcall_kill();
	return EXIT_SUCCESS;
}

