#include <dirent.h>

DIR *dirPointer;	//pointer at directory
struct dirent *dirStruct;	//archive structure given by dirent.h
typedef enum {false, true} BOOL;	//defines custom boolean

///// Prototypes /////
BOOL directories_open(char *pDir);
BOOL directories_list();
BOOL directories_close();
