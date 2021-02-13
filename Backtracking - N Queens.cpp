#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> board;

bool isPossible(int n, int row, int col)
{
    for(int i=row-1; i>=0; i--)
    {
        if(board[i][col] == 1)
        {
            return false;
        }
    }

    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }

    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

void placeNQueens(int n, int row)
{
    if(row == n)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for(int k=0; k<n; k++)
    {
        if( isPossible(n, row, k) )
        {
            board[row][k] = 1;
            placeNQueens(n, row+1);
            board[row][k] = 0;
        }
    }

    return;
}

int main()
{
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        board.push_back({});
        for(int j=0; j<n; j++)
        {
            board[i].push_back(0);
        }
    }

    placeNQueens(n, 0);

    return 0;
}
