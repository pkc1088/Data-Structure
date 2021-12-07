#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fill(int (*board)[10], int i, int j) //board[][10]µµ °¡´É 
{
	if(board[--i][j]==2)
	{
		board[i][j]=1;
		fill(board, i, j);
	}
	if(board[++i][j]==2)
	{
		board[i][j]=1;
		fill(board, i, j);
	}
	if(board[i][++j]==2)
	{
		board[i][j]=1;
		fill(board, i, j);
	}
	if(board[i][--j]==2)
	{
		board[i][j]=1;
		fill(board, i, j);
	}
	
/*	
	for(j=0; j<100; j++)
		if(board[0][j]==2)
			board[0][j]=1;
*/		
	return board[i][j];		
}

int main(void)
{
	int board[10][10]={0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,
					   0,0,0,2,2,2,2,0,0,0,
					   0,0,0,0,2,2,2,0,0,0,
					   0,0,0,0,2,2,2,0,0,0,
					   0,0,0,0,1,2,2,2,0,0,
					   0,0,0,0,2,0,0,0,0,0,
					   0,0,0,0,2,0,0,0,0,0,
					   0,0,0,0,2,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,};
	fill(board, 5, 4);
	
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
			printf("%d ", board[i][j]);
		printf("\n");
    }
	
	return 0;
}

