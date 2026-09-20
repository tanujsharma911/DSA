/*

Largest Subsquare Surrounded by X

Given a square matrix mat[][] of size n × n, where each cell contains either 'X' or 'O'. 
Find the size of the largest square submatrix whose boundary is completely surrounded by 'X'. 
The cells inside the submatrix can contain either 'X' or 'O'. Only the four sides of the submatrix 
must contain 'X'.

Return side length of the largest such square submatrix.


Note: A square of size 1 is valid if its only cell is 'X'. If no such square submatrix exists, 
return 0.

*/

#include <iostream>

using namespace std;

class Solution {
  public:
    int largestSubsquare(vector<vector<char>> &mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<vector<int>> down(rows, vector<int>(cols, 0));
        vector<vector<int>> right(rows, vector<int>(cols, 0));
        
        for(int r = rows - 1; r >= 0; r--){
            for(int c = cols - 1; c >= 0; c--){
                if(mat[r][c] == 'O') continue;
                    
                right[r][c] = 1;
                down[r][c] = 1;
                
                if(r < rows - 1) down[r][c] += down[r + 1][c];
                if(c < cols - 1) right[r][c] += right[r][c + 1];
            }
        }
        
        int ans = 0;
        
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                int max_k = min(right[r][c], down[r][c]);
                
                for(int k = max_k - 1; k >= max(0, ans); k--){
                    if(down[r][c + k] > k && right[r + k][c] > k){
                        ans = max(ans, k + 1);
                    }
                }
            }
        }
        
        return ans;
    }
};

int main() {
   
   cout << endl;
   return 0;
}