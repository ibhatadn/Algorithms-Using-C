#define N 4
#include <stdio.h>
int isSafe(int board[N][N], int row, int col)
{
	int i, j;
	// Check this row on left side
	for (i = 0; i < col; i++)
		if (board[row][i])
			return 0;
	// Check upper diagonal on left side
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return 0;
	// Check lower diagonal on left side
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return 0;
	return 1;
}
int solveNQUtil(int board[N][N], int col)
{
	if (col >= N)
		return 1;

	for (int i = 0; i < N; i++) {
		
		if (isSafe(board, i, col)) {
			

			board[i][col] = 1;

			if (solveNQUtil(board, col + 1))
				return 1;

			board[i][col] = 0; // BACKTRACK
		}
	}

	return 0;
}
int solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (solveNQUtil(board, 0) == 0) {
		printf("Solution does not exist");
		return 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(board[i][j])
				printf("Q ");
			else
				printf(". ");
		}
		printf("\n");
	}
    printf("The sequence is as follows : \t");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if(board[i][j])
				printf("%d\t ",j+1);
	}
	return 1;
}

// Driver program to test above function
int main()
{
	solveNQ();
	return 0;
}
