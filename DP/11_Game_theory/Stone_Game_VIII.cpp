/*

1872. Stone Game VIII

Alice and Bob take turns playing a game, with Alice starting first.

There are n stones arranged in a row. On each player's turn, while the number of stones
is more than one, they will do the following:

Choose an integer x > 1, and remove the leftmost x stones from the row.
Add the sum of the removed stones' values to the player's score.
Place a new stone, whose value is equal to that sum, on the left side of the row.
The game stops when only one stone is left in the row.

The score difference between Alice and Bob is (Alice's score - Bob's score). Alice's goal
is to maximize the score difference, and Bob's goal is the minimize the score difference.

Given an integer array stones of length n where stones[i] represents the value of the ith
stone from the left, return the score difference between Alice and Bob if they both play optimally.

*/

#include <iostream>

using namespace std;

class Solution
{
public:
  vector<int> prefix;
  int helper(int i, vector<int> &stones, vector<int> &memo)
  {
    int n = stones.size();

    if (i == n - 1)
      return prefix[n];

    if (memo[i] != -1)
      return memo[i];

    int go = helper(i + 1, stones, memo);
    int stop = prefix[i + 1] - helper(i + 1, stones, memo);

    return memo[i] = max(go, stop);
  }
  int stoneGameVIII(vector<int> &stones)
  {
    int n = stones.size();

    int sum = 0;
    prefix.push_back(sum);
    for (auto x : stones)
    {
      sum += x;
      prefix.push_back(sum);
    }

    // vector<int> memo(n, -1);

    // return helper(1, stones, memo);

    vector<int> dp(n, 0);

    dp[n - 1] = prefix[n];

    for (int i = n - 2; i >= 1; i--)
    {
      int go = dp[i + 1];
      int stop = prefix[i + 1] - dp[i + 1];

      dp[i] = max(go, stop);
    }

    return dp[1];
  }
};

int main()
{

  cout << endl;
  return 0;
}