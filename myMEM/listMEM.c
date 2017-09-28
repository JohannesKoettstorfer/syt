#include "listMEM.h"
#include <stdio.h>
#include <string.h>

FILE *fp;	//creates file pointer

char entryname[20];

long memtotal;
long memfree;
long swaptotal;
long swapfree;
long discardvalue;

bool mem_openFile(char *fName){
	fp = fopen(fName, "r");	//points file pointer at meminfo

	if(fp != NULL)	//if file can be opened without error
		return true;
	else
		perror("Error while opening file");
		return false;
}//mem_openFile

bool mem_print(){
		while(!feof(fp)){	//until end of file is reached
			fscanf(fp, "%s", entryname); //reads name of entry
			if(strcmp (entryname, "kB") != 0) {	//discards "kB" entry in list

				//checks if entry is...
				if(strcmp (entryname, "MemTotal:") == 0)//MemTotal
					fscanf(fp, "%ld", &memtotal);
				else if(strcmp (entryname, "MemFree:") == 0)//MemFree
					fscanf(fp, "%ld", &memfree);
				else if(strcmp (entryname, "SwapTotal:") == 0)//SwapTotal
					fscanf(fp, "%ld", &swaptotal);
				else if(strcmp (entryname, "SwapFree:") == 0)//SwapFree
					fscanf(fp, "%ld", &swapfree);
				else
					fscanf(fp, "%ld", &discardvalue); //discards unused value
				}//if
		}//while

		//print results
		if (	memtotal != 0
			&& memfree != 0
			&& swaptotal != 0
			&& swapfree != 0){	//if all values are filled

			printf("MemTotal:\t%ld kB\n", memtotal);
			printf("MemFree:\t%ld kB\n", memfree);
			printf("SwapTotal:\t%ld kB\n", swaptotal);
			printf("SwapFree:\t%ld kB\n", swapfree);

			return true;
		} else
			perror ("Error while reading file");
			return false;
}//mem_print

bool mem_closeFile(){	//closes file

	if(fclose(fp) == 0)	//if file can be successfully closed
		return true;
	else
		perror("Error while closing file");
		return false;
}//mem_closeFile
