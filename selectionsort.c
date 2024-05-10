
#include<stdio.h>
void main()
{
int a[50],i,n,min,loc,t,j;
printf("\n Enter the size of Array:");
scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("\n Enter the elements:");
	scanf("%d",&a[i]);
	}

for(i=0;i<n-1;i++)
{
min=a[i];
loc=i;
	for(j=i+1;j<n;j++)
	{
		if(min>a[j])
		{
			min=j;
			loc=j+1;
		}
	}
t=a[i];
a[i]=a[loc];
a[loc]=t;
}

for(i=0;i<n;i++)
{
	printf("\n %d",a[i]);
}
}