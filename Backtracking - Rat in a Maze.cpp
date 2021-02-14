#include<bits/stdc++.h>

using namespace std;

void printPath(int n, vector<vector<int>> path)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << path[i][j] << " ";
        }

        cout << "\n";
    }

    cout << "\n";
}

bool isPossible(vector<vector<int>> maze, vector<vector<int>> path, int n, int a, int b)
{
    if(a>=0 && b>=0 && a<n && b<n && maze[a][b]!=0 && path[a][b]!=1)
    {
        return true;
    }

    return false;
}

void rat(vector<vector<int>> maze, vector<vector<int>> path, int n, int x, int y)
{
    path[x][y] = 1;

    if(x == n-1 && y == n-1)
    {
        printPath(n, path);
        return;
    }

    // up
    if(isPossible(maze, path, n, x-1, y))
    {
        rat(maze, path, n, x-1, y);
    }

    // right
    if(isPossible(maze, path, n, x, y+1))
    {
        rat(maze, path, n, x, y+1);
    }

    // down
    if(isPossible(maze, path, n, x+1, y))
    {
        rat(maze, path, n, x+1, y);
    }

    // left
    if(isPossible(maze, path, n, x, y-1))
    {
        rat(maze, path, n, x, y-1);
    }

    path[x][y] = 0;
    return;
}

int main()
{
    int n = 3;

    vector<vector<int>> maze = {
        {1, 1, 0},
        {1, 1, 1},
        {1, 1, 1}
    };

    vector<vector<int>> path = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    rat(maze, path, n, 0, 0);

    return 0;
}
