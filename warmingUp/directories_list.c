#include "directories_list.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

BOOL directories_open(char *pDir) { //Open directory to read
	dirPointer = opendir(pDir);	//points directory pointer to path in func parameter
	if (dirPointer != NULL) {	//if directory can be opened
		return true;
	} else {
		perror("Error");	//prints error log
		return false;
	}
}

BOOL directories_list() { //reads directory content and lists it
	struct stat statStructure;	//structure which contains size of file/folder

	while (dirStruct = readdir(dirPointer)){ //while directory pointer is not null

	stat(dirStruct -> d_name, &statStructure);
	if (	dirStruct -> d_type == DT_DIR	//if directory is a directory (and not a file)
		&& strcmp(".", dirStruct -> d_name) != 0 //and if directory is not "."
		&& strcmp("..", dirStruct -> d_name) != 0) { //and if directory is not ".."
	printf("%s (%ld)\n", dirStruct -> d_name, statStructure.st_size); //prints directory name
	}								  //and directory size

	if (dirStruct == 0) {	//if directory can be read
		return true;
	} else {
		perror("Error");	//print error log
		return false;
	}
}

BOOL directories_close(){
	if (closedir(dirPointer) == 0) { //closes directory reader
		return true;	//true if successfully closed
	} else {
		perror("Error"); //prints error log
		return false;
	}
}
