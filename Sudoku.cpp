#include<iostream>
#include <bits/stdc++.h>

using namespace std;
#define N 9



class SudokuGame
{
public:

bool Safe(int row, int col, int board[N][N], int val)
{
	for(int i=0; i<N; i++)
	{
		if(board[row][i] == val)
		{
			return false;
		}
		
		if(board[i][col] == val)
		{
			return false;
		}
		
		if(board[3*(row/3) + i/3][3*(col/3) + i%3]== val)
		{
			return false;
		}
		
	}
	return true;
}
bool solve(int board[N][N])
{
	for(int row =0; row<N; row++)
	{
		for(int col =0; col<N; col++)
		{
			if(board[row][col] == 0)
			{
				for(int val =1; val<=9; val++)
				{
					if(Safe(row, col, board, val))
					{
						board[row][col]=val;
					
					bool nextSolution = solve(board);
					if(nextSolution)
						return true;
					else
					{
						board[row][col] = 0;
					}
				}
			}
			return false;
		}
	}
}
	return true;
}


void SudokuSolver(int board[N][N])
{
	solve(board);
	
}

void print(int grid[N][N])
{
   for (int i = 0; i < N; i++)
     {
       for (int j = 0; j < N; j++)
           cout << grid[i][j] << " ";
           cout << endl;
     }
}
};

int main()
{
	
	SudokuGame s;
   int grid[N][N] = { { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
                      { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
                      { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
                      { 2, 6, 3, 0, 1, 5, 9, 8, 7 },
                      { 9, 7, 4, 8, 6, 0, 1, 2, 5 },
                      { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
                      { 1, 3, 8, 0, 4, 7, 2, 0, 6 },
                      { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
                      { 7, 4, 5, 0, 8, 6, 3, 1, 0 } };
                      
                      
   s.SudokuSolver(grid);  
  
   s.print(grid);                
                       
}
