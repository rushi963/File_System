#ifndef _DISK_H_
#define _DISK_H_

#define DISK_BLOCKS  10752
//#define BLOCK_SIZE   512

int isDiskCreated(char *name);
int make_disk(char *name,int blk_size);				//make a file which acts as the virtual disk and initialise it with 0s
int open_disk(char *name);				//initialises the static variables of disk
int close_disk();

int block_write(int block, char *buf);	//basic block write using lseek
int block_read(int block, char *buf);

#endif
