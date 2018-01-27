#include<stdio.h>
#include<stdlib.h>
#define n 5
//int n=10;

int fin[n][n];
int m[n][n];
int blockone(int m[][n] ,int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<n&&m[x][y]==1)
		return 1;
	return 0;
}
int movex(int m[][n],int x,int y,int fin[][n])
{
	if(x==n-1&&y==n-1)
	{
		fin[x][y]=1;
		return 1;
	}
	if(blockone(m,x,y)==1)
	{
		fin[x][y]=1;
		if(movex(m,x,y+1,fin)==1)
			return 1;
		if(movex(m,x+1,y,fin)==1)
			return 1;
		fin[x][y]=0;
		return 0;
	}
	//fin[x][y]=0;
	return 0;
}
void game(int nn)
{
		//m[n][n];
	 //fin[n][n];
	int i,j;
	for(i=0;i<nn;i++)
	{
		for(j=0;j<nn;j++)
		{
			fin[i][j]=0;
		}
	}
	//void inputm()
	{
		int ch;
		for(i=0;i<nn;i++)
		{
			for(j=0;j<nn;j++)
			{
				printf("(%d,%d)=",(i+1),(j+1));
				scanf("%d",&ch);
				m[i][j]=ch;
			}
		}
		//m[0][0]=m[nn-1][nn-1]=1;

printf("given maze is:-\n");
for(i=0;i<nn;i++)
		{
			for(j=0;j<nn;j++)
			{
				printf("%d  ",m[i][j]);
				//scanf("%d",&ch);
				//m[i][j]=ch;
			}
			printf("\n");
		}
		//m[0][0]=m[nn-1][nn-1]=1;
		printf("\n\nAND:\n\n");
	}




	if(movex(m,0,0,fin)==0)
		{
			printf("\t\t\tNO SOLUTION EXIST FOR THIS MAZE\n");
			exit(0);
		}
		printf("SOLUTION IS \n");
	for(i=0;i<nn;i++)
	{
		for(j=0;j<nn;j++)
		{
			//if(fin[i][j]!=1)
			//	printf(" \t");
			//else
			printf("%d  ",fin[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	//int n;
	//scanf("%d",&n);
	printf("ENTER THE MAZE BELOW:-\n");
	game(n);
	return 1;
}
