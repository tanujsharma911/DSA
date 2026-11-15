/*

1406. Stone Game III

Alice and Bob continue their games with piles of stones. There are several
stones arranged in a row, and each stone has an associated value which is an
integer given in the array stoneValue.

Alice and Bob take turns, with Alice starting first. On each player's turn, that
player can take 1, 2, or 3 stones from the first remaining stones in the row.

The score of each player is the sum of the values of the stones taken. The score
of each player is 0 initially.

The objective of the game is to end with the highest score, and the winner is
the player with the highest score and there could be a tie. The game continues
until all the stones have been taken.

Assume Alice and Bob play optimally.

Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will
end the game with the same score.

*/

#include <iostream>
using namespace std;

class Solution {
public:
  int helper(int i, vector<int> &stones, vector<int> &memo) {
    int n = stones.size();

    if (i >= n)
      return 0;

    if (memo[i] != -1)
      return memo[i];

    int picked_stones = stones[i];
    int diff = picked_stones - helper(i + 1, stones, memo);

    for (int k = 1; k < 3 && i + k < n; k++) {
      picked_stones += stones[i + k];
      diff = max(diff, picked_stones - helper(i + k + 1, stones, memo));
    }

    return memo[i] = diff;
  }
  string stoneGameIII(vector<int> &stoneValue) {
    int n = stoneValue.size();

    vector<int> memo(n, -1);

    int diff = helper(0, stoneValue, memo);

    return (diff > 0) ? "Alice" : (diff < 0) ? "Bob" : "Tie";
  }
};

int main() {

  cout << endl;
  return 0;
}
