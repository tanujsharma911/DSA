/*

2267. Check if There Is a Valid Parentheses String Path

A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.
You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:

The path starts from the upper left cell (0, 0).
The path ends at the bottom-right cell (m - 1, n - 1).
The path only ever moves down or right.
The resulting parentheses string formed by the path is valid.
Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.

*/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> dr = {0, 1};
    vector<int> dc = {1, 0};

    bool dfs(int r, int c, int balance, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp){
        int rows = grid.size();
        int cols = grid[0].size();

        if(r == rows - 1 && c == cols - 1)
            return balance == 0;

        if(balance < 0)
            return false;

        if(dp[r][c][balance] != -1) return dp[r][c][balance];

        bool has_valid_path = false;

        for(int i = 0; i < 2; i++){
            int new_r = r + dr[i];
            int new_c = c + dc[i];
            
            if(new_r < rows && new_c < cols){
                int change = grid[new_r][new_c] == '(' ? 1 : -1;

                if(dfs(new_r, new_c, balance + change, grid, dp)){
                    has_valid_path = true;
                }
            }
        }

        return dp[r][c][balance] = has_valid_path;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if(grid[0][0] == ')') return false;
        if(grid[rows - 1][cols - 1] == '(') return false;

        vector<vector<vector<int>>> dp(
            rows,
            vector<vector<int>>(
                cols, vector<int>(rows + cols + 1, -1)
            )
        );

        return dfs(0, 0, 1, grid, dp);
    }
};

int main() {
   
   cout << endl;
   return 0;
}