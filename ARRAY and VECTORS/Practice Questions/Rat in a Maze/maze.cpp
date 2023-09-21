/*
    This problem is called Rat in a Maze Problem

    PROBLEM: Consider a rat is placed at position (0,0) in a marix
    of order N*N. It has to reach the destination (N-1,N-1).
    Find all the paths that the rat can take in order to reach the destination
    It can move in 4 directions U(up),D(down),R(right),L(left)
    Value 0 in a matrix cell means that rat cannot move here
    Value 1 in a matrix cell means that rat can move here
                          x---->
                        y
                        ^
                        |
                        |


*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool isSafe(int newx, int newy, vector<string> &ans, vector<vector<int>> &visited, vector<vector<int>> maze, int n)
    {
        if ((newx >= 0 && newy >= 0) && (newx < n && newy < n) && (maze[newx][newy] == 1) && (visited[newx][newy] == 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void solve(vector<vector<int>> maze, vector<vector<int>> &visited, int x,
               int y, int n, string path, vector<string> &ans)
    {
        // Base Case:
        if ((x == n - 1) && (y == n - 1))
        {
            ans.push_back(path);
            cout<<"End point reaeched"<<endl;
            return;
        }

        visited[x][y] = 1;
        int newx;
        int newy;

        // FOR 'D' down:

        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy, ans, visited, maze, n))
        {
            path.push_back('D');
            solve(maze, visited, newx, newy, n, path, ans); // recursively chack how down it can go
            path.pop_back();                                // We remove the last item from the vector bcz when returnning back
                             // from recursive call it should remove this D so that new path
                             // can be correctly entered
        }

        // FOR 'U' up:

        newx = x;
        newy = y - 1;
        if (isSafe(newx, newy, ans, visited, maze, n))
        {
            path.push_back('U');
            solve(maze, visited, newx, newy, n, path, ans);
            path.pop_back();
        }

        // FOR 'L' left:

        newx = x - 1;
        newy = y;
        if (isSafe(newx, newy, ans, visited, maze, n))
        {
            path.push_back('L');
            solve(maze, visited, newx, newy, n, path, ans);
            path.pop_back();
        }

        // FOR 'R' right:

        newx = x + 1;
        newy = y;
        if (isSafe(newx, newy, ans, visited, maze, n))
        {
            path.push_back('R');
            solve(maze, visited, newx, newy, n, path, ans);
            path.pop_back();
        }

        visited[x][y] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>> &maze, int n)
    {
        vector<string> ans;
        if (maze[0][0] == 0)
        {
            return ans;
        }

        int x = 0;
        int y = 0;
        vector<vector<int>> visited = maze;
        //    Initializing the visited array with 0 means that it hasnot been visited
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }

        string path = " ";
        solve(maze, visited, x, y, n, path, ans);

        return ans;
    }
};

int main()
{
    int n; // Size of the maze (N * N)
    cout << "Enter the size of the maze (N * N): ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));

    cout << "Enter the maze matrix (0s and 1s):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }

    Solution solution;
    vector<string> paths = solution.findPath(maze, n);

    if (paths.empty())
    {
        cout << "No paths found to reach the destination (N-1, N-1)." << endl;
    }
    else
    {
        cout << "Paths to reach the destination (N-1, N-1):\n";
        for (string path : paths)
        {
            cout << path << endl;

        }
    }

    return 0;
}