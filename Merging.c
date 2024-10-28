#include <stdio.h>
void main()
{
int no[20],n,i,j,temp;
printf("no of elements [i-20]");
scanf("%d",&n);
//rr
for (i=0;i<n;++i)
scanf("%d",&no[i]);
//ss
for (i=0;i<n-1;++i)
for(j=i+1;j<n;++j)
if(no[i]>no[j])
{
temp=no[i];
no[i]=no[j];
no[j]=temp;
}
//dd
for(i=0;i<n;++i)
printf("%d ",no[i]);
}
