#include "commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include <dirent.h>

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

		if(strcmp(input, "q") == 0) {  // exits the program (and clears the screen)
			system("clear");
			exit(EXIT_SUCCESS);
		}

		// TODO: add rfile (read file) and help command
}

void pwd(void) { // prints the current working directory
	char cwd[PATH_MAX];
	if(getcwd(cwd, sizeof(cwd)) != NULL) {
		printf("cwd: %s\n", cwd);
	}
	else {
		printf("error getting cwd :(\n");
	}
}

const char *cwd(void) { // returns the current working directory
        static char cwd[PATH_MAX];
        if(getcwd(cwd, sizeof(cwd)) != NULL) {
                return cwd;
        }
        else {
                return NULL; // for failure
        }
}

void ls(void) {
	struct dirent *de = NULL; // directory entry
	DIR *dr = opendir(".");

	if(dr == NULL) {
		printf("error opening cwd :(\n");
		return ;
	}

	while((de = readdir(dr)) != NULL) {
		printf("%s\t", de->d_name); // prints the insides of the cwd
	}

	closedir(dr);
}
