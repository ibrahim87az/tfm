#include "commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void runcmd(const char *input) {  // runs what the command is
		if(strcmp(input, "wfile") == 0) { // write to a file
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

                if(strcmp(input, "afile") == 0) { // append to a file
                        char name[255], contents[255], c;
                        printf("enter the name of the file\n");
                        fgets(name, sizeof(input), stdin);
                        name[strcspn(name, "\n")] = '\0'; // removes trailing newline
                        printf("enter the contents to append to this file (just press enter for a blank file)\n");
                        fgets(contents, sizeof(contents), stdin);
                        contents[strcspn(contents, "\n")] = '\0'; // also removes trailing newline
                        printf("are you sure you want to create this file? y/n\n");
                        c = getchar();
                        if(c == 'n' || c == 'N') {
                                return ;
                        }

                        /* FILE MAKING */
                        FILE *file = fopen(name, "a");
                        if(file == NULL) {
                                printf("error\n");
                        }
                        else {
                                fprintf(file, "%s", contents);
                                fclose(file);
                        }

                }

		if(strcmp(input, "q") == 0) {  // exits the program
			exit(EXIT_SUCCESS);
		}

		// TODO: add rfile (read file) and help command
}
