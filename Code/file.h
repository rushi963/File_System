#ifndef _FILE_H_
#define _FILE_H_

#define DISK_BLOCKS  10752
#define MAX_BLOCK_SIZE   20000

struct superBlock{
	unsigned short int startFatTable;
	unsigned short int startDirectoryBlock;
	unsigned short int startDataBlock;
	unsigned short int numberOfFiles;
};

struct fatTable{
	short int blockContent;
	// empty block = -2
	// end of file = -1
	// else index of next block
};

struct directory{
	char fileName[22];
	unsigned short int startBlock;
	int numberBlocks;
	int valid;
};

struct fileDescriptor{ //range from 0 to 31
	char fName[20];
	char mode[2];			// r or w or rw
	unsigned short int currentBlock;
	char ptr[MAX_BLOCK_SIZE];				///acts as a buffer
	char *currentptr;
	int valid;
};

void assignBlkSize(int blk_size);

int fFormat();		//makes a new 'virtual disk'. Initialises super block and FAT table and directory table. Writes super block and FAT table and directory table to disk
int assignTables();			// brings the FAT table and directory table from disk into memory
int saveTables();

int fCreate(char *name);			//returns 1 or 0..Makes an entry in the directory table about the file and assigns one block to it.
int fRemove(char *name);			//returns 1 or 0

int fOpen(char *name, char* permissions);			//returns -1 or unique fileDescriptor
int fClose(int descriptor);			//returns -1 or unique fileDescriptor

int fRead(int fDescriptor, char *buf, int size);			//returns 1 or 0
int fWrite(int fDescriptor, char *buf, int size);			//returns 1 or 0

int fRename(char *oldName, char *newName);			//returns 1 or 0
int fList();					//return -1 or number of files

#endif
