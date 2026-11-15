/*

1140. Stone Game II

Alice and Bob continue their games with piles of stones. There are a number of piles arranged in
a row, and each pile has a positive integer number of stones piles[i]. The objective of the game
is to end with the most stones.

Alice and Bob take turns, with Alice starting first.

On each player's turn, that player can take all the stones in the first X remaining piles,
where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

Example 1:

Input: piles = [2,7,9,4,4]

Output: 10

Explanation:

If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again.
Alice can get 2 + 4 + 4 = 10 stones in total.
If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case,
Alice get 2 + 7 = 9 stones in total.
So we return 10 since it's larger.


Example 2:

Input: piles = [1,2,3,4,5,100]

Output: 104

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> suffix;
    vector<vector<int>> memo;

    int helper(int i, int M)
    {
        int n = suffix.size() - 1;

        if (i >= n)
            return 0;

        if (2 * M >= n - i)
            return suffix[i];
        if (memo[i][M] != -1)
            return memo[i][M];

        int best = 0;

        for (int X = 1; X <= 2 * M; X++)
        {
            best = max(best, suffix[i] - helper(i + X, max(M, X)));
        }

        return memo[i][M] = best;
    }
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();

        memo.assign(n, vector<int>(n + 1, -1));
        suffix.assign(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        return helper(0, 1);
    }
};

/*


piles  = [ 2, 7, 9,4,4]
suffix = [26,24,17,8,4]

*/

int main()
{

    cout << endl;
    return 0;
}