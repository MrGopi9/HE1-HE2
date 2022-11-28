#include<stdio.h>
#include<stdlib.h>

void printMenu(void);
int setBit(int data,int bit);
int clearBit(int data,int bit);
int complimentBit(int data,int bit);


void printBinary(int d)
{
	int b;
	printf("\nbinary:");
	for(b=31;b>=0;b--)
		printf("%d",(d>>b)&1);

	printf("\n");
}

int reverseBits(int var)
{
	int i;
	int rev=0;
	for(i=0;i<=31;i++)
	{
		if((var>>i) &1)
		{
			rev=rev|(1<<(31-i));

		}
	}
	///the var remains unchanged. and rev contains reverse equivalent of var.
	return rev;
}



int main()
{
	//typedef int (*fp)(int ,int);
	int (*p[3])(int , int);
	int data,bit;
	int choice;
	int res;
	p[0]=setBit;
	p[1]=clearBit;
	p[2]=complimentBit;
	//	p[3]=printBinary(data);
	//	p[4]=reverseBits(data);
	while(1)
	{
		printMenu();
		scanf("%d",&data);
		__fpurge(stdin);
		scanf("%d",&bit);
		
		printf("in main %d   %d \n",data,bit);

		printf("enter choice :- ");
		__fpurge(stdin);
		scanf("%d",&choice);
		res=p[choice-1](data,bit);
		printf("data is %d, bit is %d and result is :- %3d\n", data,bit,res);
	}

}
int setBit(int data,int bit)
{
	printf("in fun %d\n",data);
	data=data|(1<<bit);
	return data;
}
int clearBit(int data, int bit)
{
	return (data&= ~(1<<bit));
}
int complimentBit(int data,int bit)
{
	data^=(1<<bit);
	return data;
}
void printMenu(void)
{
	printf("\nMENU\n");
	printf("1:set bit\n");
	printf("2:clear bit\n");
	printf("3: compliment bit\n");
//	printf("4:input again\n");
//	printf("r:reverse bits\n");
//	printf("p: print data\n");
//	printf("q:quit\n");
//	printf("enter your choice\n");
}
