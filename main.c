#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

int main(void) {
	while (1) {
		system("clear");
		char buff[64];
		printf("TFM\n\n");
		printf("enter \"q\" to quit or \"help\" to see commands\n");
		fgets(buff, sizeof(buff), stdin);
		buff[strcspn(buff, "\n")] = '\0'; // remove trailing newline
		runcmd(buff); // runs all the commands
	}
	return 0;
}
