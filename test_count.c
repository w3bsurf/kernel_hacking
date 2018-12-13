// Calls getreadcount to get the number of
// times a tracked syscall has been called.
// Currently tracked syscall can be changed by
// giving the number of the new syscall to track.
// Argument -r will reset counter.
#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
	int i = 0;
	if (argc == 1) {
		// Gets counter for currently tracked syscall
		i = getreadcount(0, 0);
	} else if (argc == 2) {
		if (strcmp(argv[1], "-r") == 0) { // Resets counter
			i = getreadcount(0, 1);
		} else {
			// Changes currently tracked syscall
			i = getreadcount(atoi(argv[1]), 0);
		}
	} else if (argc == 3) {
		if (strcmp(argv[2], "-r") == 0) { // Resets counter
			i = getreadcount(atoi(argv[1]), 1);
		} else {
			// Changes currently tracked syscall
			i = getreadcount(atoi(argv[1]), 0); 
		}
	} else {
		printf(1, "test_count: [syscalls[num]] [-r to reset counter]\n");
		exit();
	}
	
	printf(1, "Count: %d\n", i);
	exit();
}