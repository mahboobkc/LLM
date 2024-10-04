#include <stdio.h>
#include <stdlib.h>

#define max 2
int opt=0,count =-1;
int buff [max];


void  producer () {
if (count < -1 )
	count =0;


if (count < max ){
	 int n;
	 
	 printf (" enter an item/data :");
	 scanf ("%d",&n);
	 count++;
	 buff[count] = n;
	 
	printf("the produce %d\n " ,buff[count]);
	}
else {
		printf("BUFFER FULL\n");
}
	 

}

void consumer (){

if (count >= 0){
	printf ("the value %d\n ",buff[count]);
	count--;
	 
}
else {
	printf ( "buffer empty\n"); 
}



}
void display ()
{

	if (count == -1)
		return;

	printf("Buffer: ");
	int i;
	for (i = 0; i != count; i++)
		printf("%d ", buff[i]);
	printf("%d\n", buff[i]);

}


int main () {

while(1)
	{	printf("1. Produce\n2. Consume\n3. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &opt);
		printf("\n");

		switch (opt)
		{
		case 1:
			producer();
			display ();
			
			break;
		case 2:
			consumer();
			display ();
			break;
		case 3:
			printf("Exiting...\n");
			exit(0);
		default:
			printf("Invalid choice\n");
			break;
		}
	}
	return 0;







}
