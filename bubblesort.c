#include<stdio.h>
#include<conio.h>
void main()
{
int a[50],i,n,j,t;
	printf("\n Enter the Size of Array:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n enter the elements:");
		scanf("%d",&a[i]);
	}

	for(i=0;i<n-1;i++)
	{
		for(j=i-1;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[i];
				a[i]=a[j+1];
				a[j+1]=t;
			}
		}
	}
for(i=0;i<n;i++)
	{
	printf("\t%d",a[i]);
	}
getch();
}