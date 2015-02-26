#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int main(void)
{
	int n; //this IS A VARIABLE
	int i, j, k, count;
	bool state=true;
	int answer=0, pre;
	int ans[MAX];
	int data[MAX];
	int check[MAX];
	scanf("%d", &n);

	for( i=0; i<n; i++)
	{
		scanf("%d", &data[i]);
	}
	for( i=0; i<n; i++)
	{


		for(k=data[i]-1; k>0; k--)
		{
			for(j=1; j<=data[i]; j++)
			{
				check[j]=j;
			}
			state=true;
			count=data[i];
			pre=0;
			while(state)
			{
				answer=(count+pre)%k+1;
				answer=check[answer];
				if(answer==data[i]&&count!=1)
					state=false;
				else if(count==1)
				{
					ans[i]=k;
				}
				for(j=answer; j<count; j++)
				{
					check[j]=check[j+1];
				}
				pre=check[answer];
				count--;
			}
		}

	}
	for(i=0; i<n; i++)
		printf("%d\n", ans[i]);
	system("pause");
	return 0;
}