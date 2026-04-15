#include "commands.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>

void runcmd(const char *input) { // runs what the command is
	if(strcmp(input, "wfile") == 0) {
		char name[255], contents[255], c;
		printf("enter the name of the file\n");
		fgets(name, sizeof(input), stdin);
		name[strcspn(name, "\n")] = '\0'; // removes trailing newline
		printf("enter the contents of the file (just press enter for a blank file)\n");
		fgets(contents, sizeof(contents), stdin);
		contents[strcspn(contents, "\n")] = '\0'; // also removes trailing newline
		printf("are you sure you want to create this file? y/n\n");
		c = getchar();
		if(c == 'n' || c == 'N') {
			return ;
		}

		/* FILE MAKING */
		FILE *file = fopen(name, "w");
		if(file == NULL) {
			printf("error\n");
		}
		else {
			fprintf(file, "%s", contents);
			fclose(file);
		}
	}
}
