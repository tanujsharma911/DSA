/*

Count Subsequences of Type a^i b^j c^k
Solved
Difficulty: MediumAccuracy: 51.33%Submissions: 36K+Points: 4
Given a string s consisting of lowercase English letters, count the number of subsequences that follow
the pattern a^i b^j c^k - some number of a's, followed by some number of b's, followed by some number
of c's, with i >= 1, j >= 1, k >= 1.

Note:

Two subsequences are considered different if the set of indices picked for them is different.
Since the answer can be very large, return it modulo 10^9+7.

Examples:

Input: s = "abbc"
Output: 3
Explanation: The string has one 'a' (index 0), two 'b's (indices 1 and 2), and one 'c' (index 3). The valid subsequences are:
- a(0) + b(1) + c(3) -> "abc"
- a(0) + b(2) + c(3) -> "abc"
- a(0) + b(1)b(2) + c(3) -> "abbc"
These are counted as 3 distinct subsequences since each uses a different set of indices, even though the first two look identical as strings.

*/

#include <iostream>

using namespace std;

class Solution
{
public:
  int mod = 1e9 + 7;
  int dp(int i, int prevStage, string &s, vector<vector<int>> &memo)
  {
    int n = s.length();

    if (i == n)
      return prevStage == 3 ? 1 : 0;

    if (memo[i][prevStage] != -1)
      return memo[i][prevStage];

    int ans = 0, stage = s[i] - 'a' + 1;

    ans = dp(i + 1, prevStage, s, memo) % mod;

    if (stage == prevStage + 1 || stage == prevStage)
      if (stage == 1 || stage == 2 || stage == 3)
        ans = (ans + dp(i + 1, stage, s, memo)) % mod;

    return memo[i][prevStage] = ans % mod;
  }
  int countSub(string &s)
  {
    int n = s.length();

    vector<vector<int>> memo(n, vector<int>(4, -1));

    return dp(0, 0, s, memo) % mod;
  }
};

int main()
{

  cout << endl;
  return 0;
}