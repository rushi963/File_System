#include "file.h"
#include <iostream>
#include <string.h>
#include "stdlib.h"
#include "stdio.h"
using namespace std;

int main(int argc, char* argv[]){
	char temp[15];
	char per[2];


	int blk_size = atoi(argv[1]);
	assignBlkSize(blk_size);

	fFormat();

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

	//cout<<"\n\n\nRemoving file with name File1, File2.\n";
	//strcpy(temp,"File1");
	//fRemove(temp);								//check
	//strcpy(temp,"File2");
	//fRemove(temp);

	cout<<"\n\n\nListing all file:\n";			//check
	fList();

	strcpy(temp,"File3");
	strcpy(per,"w");
	cout<<"\n\n\nOpening File3 in write mode.\n";
	int descriptor = fOpen(temp,per);						//doubt

	char temp3[100];
	//strcpy(temp3,"In computing, a file system (or filesystem) is used to control how data is stored and retrieved. Without a file system, information placed in a storage area would be one large body of data with no way to tell where one piece of information stops and the next begins. By separating the data into individual pieces, and giving each piece a name, the information is easily separated and identified. Taking its name from the way paper-based information systems are named, each group of data is called a \"file\". The structure and logic rules used to manage the groups of information and their names is called a \"file system\".There are many different kinds of file systems. Each one has different structure and logic, properties of speed, flexibility, security, size and more. Some file systems have been designed to be used for specific applications. For example, the ISO 9660 file system is designed specifically for optical discs.File systems can be used on many different kinds of storage devices. Each storage device uses a different kind of media. The most common storage device in use today is a hard drive whose media is a disc that has been coated with a magnetic film. The film has ones and zeros 'written' on it by sending electrical pulses to a magnetic \"read-write\" head. Other media that are used are magnetic tape, optical disc, and flash memory. In some cases, such as with tmpfs, the computer's main memory (RAM) is used to create a temporary file system for short-term use.Some file systems are used on local data storage devices; others provide file access via a network protocol (for example, NFS, SMB, or 9P clients). Some file systems are \"virtual\", in that the \"files\" supplied are computed on request (e.g. procfs) or are merely a mapping into a different file system used as a backing store. The file system manages access to both the content of files and the metadata about those files. It is responsible for arranging storage space; reliability, efficiency, and tuning with regard to the physical storage medium are important design considerations. File systems allocate space in a granular manner, usually multiple physical units on the device. The file system is responsible for organizing files and directories, and keeping track of which areas of the media belong to which file and which are not being used. For example, in Apple DOS of the early 1980s, 256-byte sectors on 140 kilobyte floppy disk used a track/sector map. This results in unused space when a file is not an exact multiple of the allocation unit, sometimes referred to as slack space. For a 512-byte allocation, the average unused space is 256 bytes. For 64 KB clusters, the average unused space is 32 KB. The size of the allocation unit is chosen when the file system is created. Choosing the allocation size based on the average size of the files expected to be in the file system can minimize the amount of unusable space. Frequently the default allocation may provide reasonable usage. Choosing an allocation size that is too small results in excessive overhead if the file system will contain mostly very large files.In computing, a file system (or filesystem) is used to control how data is stored and retrieved. Without a file system, information placed in a storage area would be one large body of data with no way to tell where one piece of information stops and the next begins. By separating the data into individual pieces, and giving each piece a name, the information is easily separated and identified. Taking its name from the way paper-based information systems are named, each group of data is called a \"file\". The structure and logic rules used to manage the groups of information and their names is called a \"file system\".There are many different kinds of file systems. Each one has different structure and logic, properties of speed, flexibility, security, size and more. Some file systems have been designed to be used for specific applications. For example, the ISO 9660 file system is designed specifically for optical discs.File systems can be used on many different kinds of storage devices. Each storage device uses a different kind of media. The most common storage device in use today is a hard drive whose media is a disc that has been coated with a magnetic film. The film has ones and zeros 'written' on it by sending electrical pulses to a magnetic \"read-write\" head. Other media that are used are magnetic tape, optical disc, and flash memory. In some cases, such as with tmpfs, the computer's main memory (RAM) is used to create a temporary file system for short-term use.Some file systems are used on local data storage devices; others provide file access via a network protocol (for example, NFS, SMB, or 9P clients). Some file systems are \"virtual\", in that the \"files\" supplied are computed on request (e.g. procfs) or are merely a mapping into a different file system used as a backing store. The file system manages access to both the content of files and the metadata about those files. It is responsible for arranging storage space; reliability, efficiency, and tuning with regard to the physical storage medium are important design considerations. File systems allocate space in a granular manner, usually multiple physical units on the device. The file system is responsible for organizing files and directories, and keeping track of which areas of the media belong to which file and which are not being used. For example, in Apple DOS of the early 1980s, 256-byte sectors on 140 kilobyte floppy disk used a track/sector map. This results in unused space when a file is not an exact multiple of the allocation unit, sometimes referred to as slack space. For a 512-byte allocation, the average unused space is 256 bytes. For 64 KB clusters, the average unused space is 32 KB. The size of the allocation unit is chosen when the file system is created. Choosing the allocation size based on the average size of the files expected to be in the file system can minimize the amount of unusable space. Frequently the default allocation may provide reasonable usage. Choosing an allocation size that is too small results in excessive overhead if the file system will contain mostly very large files.");
	strcpy(temp3,"i am omkar");
	cout<<"\n\n\nWriting to File3\n";
	printf("Number of bytes = %ld\n",sizeof(temp3));
	int fw3 = fWrite(descriptor,temp3,sizeof(temp3));
	printf("write return value for file 3 : %d\n",fw3);

	cout<<"\n\n\nCloseing File3.\n";
	fClose(descriptor);

	strcpy(temp,"File2");
	strcpy(per,"w");
	cout<<"\n\n\nOpening File2 in write mode.\n";
	descriptor = fOpen(temp,per);						//doubt

	char temp2[200];
	memset(temp2,'o',sizeof(temp2));
	//strcpy(temp1,"In computing, a file system (or filesystem) is used to control how data is stored and retrieved. Without a file system, information placed in a storage area would be one large body of data with no way to tell where one piece of information stops and the next begins. By separating the data into individual pieces, and giving each piece a name, the information is easily separated and identified. Taking its name from the way paper-based information systems are named, each group of data is called a \"file\". The structure and logic rules used to manage the groups of information and their names is called a \"file system\".There are many different kinds of file systems. Each one has different structure and logic, properties of speed, flexibility, security, size and more. Some file systems have been designed to be used for specific applications. For example, the ISO 9660 file system is designed specifically for optical discs.File systems can be used on many different kinds of storage devices. Each storage device uses a different kind of media. The most common storage device in use today is a hard drive whose media is a disc that has been coated with a magnetic film. The film has ones and zeros 'written' on it by sending electrical pulses to a magnetic \"read-write\" head. Other media that are used are magnetic tape, optical disc, and flash memory. In some cases, such as with tmpfs, the computer's main memory (RAM) is used to create a temporary file system for short-term use.Some file systems are used on local data storage devices; others provide file access via a network protocol (for example, NFS, SMB, or 9P clients). Some file systems are \"virtual\", in that the \"files\" supplied are computed on request (e.g. procfs) or are merely a mapping into a different file system used as a backing store. The file system manages access to both the content of files and the metadata about those files. It is responsible for arranging storage space; reliability, efficiency, and tuning with regard to the physical storage medium are important design considerations. File systems allocate space in a granular manner, usually multiple physical units on the device. The file system is responsible for organizing files and directories, and keeping track of which areas of the media belong to which file and which are not being used. For example, in Apple DOS of the early 1980s, 256-byte sectors on 140 kilobyte floppy disk used a track/sector map. This results in unused space when a file is not an exact multiple of the allocation unit, sometimes referred to as slack space. For a 512-byte allocation, the average unused space is 256 bytes. For 64 KB clusters, the average unused space is 32 KB. The size of the allocation unit is chosen when the file system is created. Choosing the allocation size based on the average size of the files expected to be in the file system can minimize the amount of unusable space. Frequently the default allocation may provide reasonable usage. Choosing an allocation size that is too small results in excessive overhead if the file system will contain mostly very large files.");
//	strcpy(temp2,"i am writing in file 2");
	cout<<"\n\n\nWriting to File2\n";
	fWrite(descriptor,temp2,sizeof(temp2));

	cout<<"\n\n\nCloseing File2.\n";
	fClose(descriptor);


	strcpy(temp,"File1");
	strcpy(per,"w");
	cout<<"\n\n\nOpening File1 in write mode.\n";
	descriptor = fOpen(temp,per);						//doubt

	char temp1[100];
	//strcpy(temp1,"In computing, a file system (or filesystem) is used to control how data is stored and retrieved. Without a file system, information placed in a storage area would be one large body of data with no way to tell where one piece of information stops and the next begins. By separating the data into individual pieces, and giving each piece a name, the information is easily separated and identified. Taking its name from the way paper-based information systems are named, each group of data is called a \"file\". The structure and logic rules used to manage the groups of information and their names is called a \"file system\".There are many different kinds of file systems. Each one has different structure and logic, properties of speed, flexibility, security, size and more. Some file systems have been designed to be used for specific applications. For example, the ISO 9660 file system is designed specifically for optical discs.File systems can be used on many different kinds of storage devices. Each storage device uses a different kind of media. The most common storage device in use today is a hard drive whose media is a disc that has been coated with a magnetic film. The film has ones and zeros 'written' on it by sending electrical pulses to a magnetic \"read-write\" head. Other media that are used are magnetic tape, optical disc, and flash memory. In some cases, such as with tmpfs, the computer's main memory (RAM) is used to create a temporary file system for short-term use.Some file systems are used on local data storage devices; others provide file access via a network protocol (for example, NFS, SMB, or 9P clients). Some file systems are \"virtual\", in that the \"files\" supplied are computed on request (e.g. procfs) or are merely a mapping into a different file system used as a backing store. The file system manages access to both the content of files and the metadata about those files. It is responsible for arranging storage space; reliability, efficiency, and tuning with regard to the physical storage medium are important design considerations. File systems allocate space in a granular manner, usually multiple physical units on the device. The file system is responsible for organizing files and directories, and keeping track of which areas of the media belong to which file and which are not being used. For example, in Apple DOS of the early 1980s, 256-byte sectors on 140 kilobyte floppy disk used a track/sector map. This results in unused space when a file is not an exact multiple of the allocation unit, sometimes referred to as slack space. For a 512-byte allocation, the average unused space is 256 bytes. For 64 KB clusters, the average unused space is 32 KB. The size of the allocation unit is chosen when the file system is created. Choosing the allocation size based on the average size of the files expected to be in the file system can minimize the amount of unusable space. Frequently the default allocation may provide reasonable usage. Choosing an allocation size that is too small results in excessive overhead if the file system will contain mostly very large files.");
	strcpy(temp1,"i am writing in file 1");
	cout<<"\n\n\nWriting to File1\n";
	fWrite(descriptor,temp1,sizeof(temp1));

	cout<<"\n\n\nCloseing File1.\n";
	fClose(descriptor);



	cout<<"\n\n\nReading from File3\n";
	strcpy(per,"r");
	strcpy(temp,"File3");
	descriptor = fOpen(temp,per);
	
	char r3[100];
	int fr3 = fRead(descriptor,r3,sizeof(r3));
	cout<<r3<<"\n";
	printf("read call return cvalue : %d\n",fr3);


	fClose(descriptor);

	strcpy(temp,"File2");
	cout<<"\n\n\nReading from File2\n";
	descriptor = fOpen(temp,per);
	
	char r2[200];
	fRead(descriptor,r2,sizeof(r2));
	cout<<r2<<"\n";

	fClose(descriptor);



	strcpy(temp,"File1");
	cout<<"\n\n\nReading from File1\n";
	descriptor = fOpen(temp,per);
	char r1[100];
	fRead(descriptor,r1,sizeof(r1));
	cout<<r1<<"\n";

	fClose(descriptor);







/*
	cout<<"\n\n\nRenaming File3 to File1\n";
	strcpy(temp,"File3");
	strcpy(temp1,"File1");
	fRename(temp,temp1);
*/
	cout<<"\n\n\nListing all file:\n";
	fList();	
	return 0;
}