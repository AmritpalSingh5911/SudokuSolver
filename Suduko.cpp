#include <iostream.h>
#include <conio.h>
#include <vector>

using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &box, int value)
{
    for (int i = 0; i < 9; i++)
    {
        if (box[row][i] == value)
        {
            return false;
        }
        if (box[i][col] == value)
        {
            return false;
        }
        if (box[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3])
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &box)
{
    int row, col;
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (box[row][col] == 0)
            {
                for (int val = 1; val < 9; val++)
                {
                    if (isSafe(row, col, box, val))
                    {
                        box[row][col] = val;

                        bool checkPossiblity = solve(box);
                        if (checkPossiblity)
                        {
                            return true;
                        }
                        else
                        {
                            box[row][col] == 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void SudukoSolver(vector<vector<int>> &Suduko)
{
    solve(Suduko);
}