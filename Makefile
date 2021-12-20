#Makefile
all: start_sim stop_sim kill_sim helloWorld
start_sim: start_sim.c ptlcalls.h
	gcc -std=gnu99 -D_GNU_SOURCE -O3 -o $@ start_sim.c
stop_sim: stop_sim.c ptlcalls.h
	gcc -std=gnu99 -D_GNU_SOURCE -O3 -o $@ stop_sim.c
kill_sim: kill_sim.c ptlcalls.h
	gcc -std=gnu99 -D_GNU_SOURCE -O3 -o $@ kill_sim.c
helloWorld: helloWorld
	gcc -std=gnu99 -D_GNU_SOURCE -O3 -o $@ helloWorld.c
clean:
	-rm -f start_sim stop_sim kill_sim helloWorld *~
