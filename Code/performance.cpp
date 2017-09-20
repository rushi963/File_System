/*Author : Omkar Damle*/
/*Date : 9th April 2017*/

#include "file.h"
#include <iostream>
#include <string.h>
#include<stdio.h>
#include<math.h>
#include<omp.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
//  Using the MONOTONIC clock 
#define CLK CLOCK_MONOTONIC

using namespace std;



/* Function to compute the difference between two points in time */
struct timespec diff(struct timespec start, struct timespec end);

/* 
   Function to computes the difference between two time instances

   Taken from - http://www.guyrutenberg.com/2007/09/22/profiling-code-using-clock_gettime/ 

   Further reading:
http://stackoverflow.com/questions/6749621/how-to-create-a-high-resolution-timer-in-linux-to-measure-program-performance
http://stackoverflow.com/questions/3523442/difference-between-clock-realtime-and-clock-monotonic
 */
struct timespec diff(struct timespec start, struct timespec end){
	struct timespec temp;
	if((end.tv_nsec-start.tv_nsec)<0){
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	}
	else{
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	return temp;
}


int main(int argc, char* argv[]){




	struct timespec start_e2e, end_e2e, start_alg, end_alg, e2e, alg;
	/* Should start before anything else */


	char temp[15];
	char per[2];

	int blk_size = atoi(argv[1]);
//	printf("%d\n",blk_size);
	assignBlkSize(blk_size);
	// fFormat();
		


/*
	cout<<"Creating file with name File1, File2, File3.\n";
	strcpy(temp,"File1");
	if(fCreate(temp)==0)
		cout<<"File 1 is already present.\n";				//or no space available.
	strcpy(temp,"File2");
	if(fCreate(temp)==0)
		cout<<"File 2 is already present.\n";
	strcpy(temp,"File3");
	if(fCreate(temp)==0)
		cout<<"File 3 is already present.\n";

	cout<<"\n\n\nListing all file:\n";
	fList();
*/

	fFormat();
	strcpy(temp,"File3");
	fCreate(temp);
	fList();

	strcpy(per,"w");
//	cout<<"\n\n\nOpening File3 in write mode.\n";
	int descriptor = fOpen(temp,per);						//doubt

//	cout<<"\n\n\nWriting to File3\n";

	char temp1[100000];
	char cc='a';
	memset(temp1,cc,100000);			//1kb
	clock_gettime(CLK, &start_e2e);

	int ret;
	for(int j=0;j<10;j++){
		ret = fWrite(descriptor,temp1,sizeof(temp1));		
	}
	fClose(descriptor);

	strcpy(per,"r");

	descriptor= fOpen(temp,per);

	for(int j=0;j<10;j++){
		fRead(descriptor,temp1,sizeof(temp1));
	}


	/* Should end before anything else (printing comes later) */
	clock_gettime(CLK, &end_e2e);
	e2e = diff(start_e2e, end_e2e);
	
	printf("return value of write call : %d\n",ret);

/*
	cout<<"\n\n\nCloseing File3.\n";
	fClose(descriptor);

	strcpy(temp,"File2");
	strcpy(per,"w");
	cout<<"\n\n\nOpening File2 in write mode.\n";
	descriptor = fOpen(temp,per);						//doubt

	char temp2[100];
	//strcpy(temp1,"In computing, a file system (or filesystem) is used to control how data is stored and retrieved. Without a file system, information placed in a storage area would be one large body of data with no way to tell where one piece of information stops and the next begins. By separating the data into individual pieces, and giving each piece a name, the information is easily separated and identified. Taking its name from the way paper-based information systems are named, each group of data is called a \"file\". The structure and logic rules used to manage the groups of information and their names is called a \"file system\".There are many different kinds of file systems. Each one has different structure and logic, properties of speed, flexibility, security, size and more. Some file systems have been designed to be used for specific applications. For example, the ISO 9660 file system is designed specifically for optical discs.File systems can be used on many different kinds of storage devices. Each storage device uses a different kind of media. The most common storage device in use today is a hard drive whose media is a disc that has been coated with a magnetic film. The film has ones and zeros 'written' on it by sending electrical pulses to a magnetic \"read-write\" head. Other media that are used are magnetic tape, optical disc, and flash memory. In some cases, such as with tmpfs, the computer's main memory (RAM) is used to create a temporary file system for short-term use.Some file systems are used on local data storage devices; others provide file access via a network protocol (for example, NFS, SMB, or 9P clients). Some file systems are \"virtual\", in that the \"files\" supplied are computed on request (e.g. procfs) or are merely a mapping into a different file system used as a backing store. The file system manages access to both the content of files and the metadata about those files. It is responsible for arranging storage space; reliability, efficiency, and tuning with regard to the physical storage medium are important design considerations. File systems allocate space in a granular manner, usually multiple physical units on the device. The file system is responsible for organizing files and directories, and keeping track of which areas of the media belong to which file and which are not being used. For example, in Apple DOS of the early 1980s, 256-byte sectors on 140 kilobyte floppy disk used a track/sector map. This results in unused space when a file is not an exact multiple of the allocation unit, sometimes referred to as slack space. For a 512-byte allocation, the average unused space is 256 bytes. For 64 KB clusters, the average unused space is 32 KB. The size of the allocation unit is chosen when the file system is created. Choosing the allocation size based on the average size of the files expected to be in the file system can minimize the amount of unusable space. Frequently the default allocation may provide reasonable usage. Choosing an allocation size that is too small results in excessive overhead if the file system will contain mostly very large files.");
	strcpy(temp2,"i am writing in file 2");
	cout<<"\n\n\nWriting to File2\n";
	fWrite(descriptor,temp2,sizeof(temp2));

	cout<<"\n\n\nCloseing File2.\n";
	fClose(descriptor);


	strcpy(temp,"File1");
	strcpy(per,"w");
	cout<<"\n\n\nOpening File1 in write mode.\n";
	descriptor = fOpen(temp,per);						//doubt

	char temp3[100];
	//strcpy(temp1,"In computing, a file system (or filesystem) is used to control how data is stored and retrieved. Without a file system, information placed in a storage area would be one large body of data with no way to tell where one piece of information stops and the next begins. By separating the data into individual pieces, and giving each piece a name, the information is easily separated and identified. Taking its name from the way paper-based information systems are named, each group of data is called a \"file\". The structure and logic rules used to manage the groups of information and their names is called a \"file system\".There are many different kinds of file systems. Each one has different structure and logic, properties of speed, flexibility, security, size and more. Some file systems have been designed to be used for specific applications. For example, the ISO 9660 file system is designed specifically for optical discs.File systems can be used on many different kinds of storage devices. Each storage device uses a different kind of media. The most common storage device in use today is a hard drive whose media is a disc that has been coated with a magnetic film. The film has ones and zeros 'written' on it by sending electrical pulses to a magnetic \"read-write\" head. Other media that are used are magnetic tape, optical disc, and flash memory. In some cases, such as with tmpfs, the computer's main memory (RAM) is used to create a temporary file system for short-term use.Some file systems are used on local data storage devices; others provide file access via a network protocol (for example, NFS, SMB, or 9P clients). Some file systems are \"virtual\", in that the \"files\" supplied are computed on request (e.g. procfs) or are merely a mapping into a different file system used as a backing store. The file system manages access to both the content of files and the metadata about those files. It is responsible for arranging storage space; reliability, efficiency, and tuning with regard to the physical storage medium are important design considerations. File systems allocate space in a granular manner, usually multiple physical units on the device. The file system is responsible for organizing files and directories, and keeping track of which areas of the media belong to which file and which are not being used. For example, in Apple DOS of the early 1980s, 256-byte sectors on 140 kilobyte floppy disk used a track/sector map. This results in unused space when a file is not an exact multiple of the allocation unit, sometimes referred to as slack space. For a 512-byte allocation, the average unused space is 256 bytes. For 64 KB clusters, the average unused space is 32 KB. The size of the allocation unit is chosen when the file system is created. Choosing the allocation size based on the average size of the files expected to be in the file system can minimize the amount of unusable space. Frequently the default allocation may provide reasonable usage. Choosing an allocation size that is too small results in excessive overhead if the file system will contain mostly very large files.");
	strcpy(temp3,"i am writing in file 1");
	cout<<"\n\n\nWriting to File1\n";
	fWrite(descriptor,temp3,sizeof(temp3));

	cout<<"\n\n\nCloseing File1.\n";
	fClose(descriptor);



	cout<<"\n\n\nReading from File3\n";
	descriptor = fOpen(temp,per);
	
	fRead(descriptor,temp1,sizeof(temp1));
	cout<<temp1<<"\n";

	fClose(descriptor);

	strcpy(temp,"File2");
	cout<<"\n\n\nReading from File2\n";
	descriptor = fOpen(temp,per);
	
	fRead(descriptor,temp2,sizeof(temp2));
	cout<<temp2<<"\n";

	fClose(descriptor);



	strcpy(temp,"File1");
	cout<<"\n\n\nReading from File1\n";
	descriptor = fOpen(temp,per);
	
	fRead(descriptor,temp3,sizeof(temp3));
	cout<<temp3<<"\n";

	fClose(descriptor);



	cout<<"\n\n\nRenaming File3 to File1\n";
	strcpy(temp,"File3");
	strcpy(temp1,"File1");
	fRename(temp,temp1);
*/

//	cout<<"\n\n\nListing all file:\n";
//	fList();











	/* problem_name,approach_name,n,p,e2e_sec,e2e_nsec,alg_sec,alg_nsec
	   Change problem_name to whatever problem you've been assigned
	   Change approach_name to whatever approach has been assigned
	   p should be 0 for serial codes!! 
	 */
	printf("%d,%ld\n", e2e.tv_sec, e2e.tv_nsec);





	return 0;
}