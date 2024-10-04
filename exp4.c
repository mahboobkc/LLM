#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

void main()
{
	int p1,p2;
	char s[100];
	for(int i=0;i<sizeof(s);i++)
	{
		s[i]=' ';
	}
	p1=open("input.txt",O_RDWR);
	printf("First File  read\n");
	read(p1,s,sizeof(s));
	close(p1);
	
	
	printf("second File opend\n");
	
	p2=open("output.txt", O_RDWR);
	write(p2,s,sizeof(s));
	printf("data copied from first file to second file\n");
	close(p2);

	
}
