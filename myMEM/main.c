#include "listMEM.h"

int main(int argc, char *argv[]){
	mem_openFile(argv[1]);	//opens file specified in first argument
	mem_print();	//prints results
	mem_closeFile();	//closes file

	return 0;
}
