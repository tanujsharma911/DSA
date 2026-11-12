/*

2167. Minimum Time to Remove All Cars Containing Illegal Goods

You are given a 0-indexed binary string s which represents a sequence of train cars. s[i] = '0' denotes that the ith car does not contain illegal goods and s[i] = '1' denotes that the ith car does contain illegal goods.

As the train conductor, you would like to get rid of all the cars containing illegal goods. You can do any of the following three operations any number of times:

Remove a train car from the left end (i.e., remove s[0]) which takes 1 unit of time.
Remove a train car from the right end (i.e., remove s[s.length - 1]) which takes 1 unit of time.
Remove a train car from anywhere in the sequence which takes 2 units of time.
Return the minimum time to remove all the cars containing illegal goods.

Note that an empty sequence of cars is considered to have no cars containing illegal goods.

Example 1:

Input: s = "1100101"
Output: 5
Explanation:
One way to remove all the cars containing illegal goods from the sequence is to
- remove a car from the left end 2 times. Time taken is 2 * 1 = 2.
- remove a car from the right end. Time taken is 1.
- remove the car containing illegal goods found in the middle. Time taken is 2.
This obtains a total time of 2 + 1 + 2 = 5.

An alternative way is to
- remove a car from the left end 2 times. Time taken is 2 * 1 = 2.
- remove a car from the right end 3 times. Time taken is 3 * 1 = 3.
This also obtains a total time of 2 + 3 = 5.

5 is the minimum time taken to remove all the cars containing illegal goods.
There are no other ways to remove them with less time.

*/

#include <iostream>

using namespace std;

class Solution
{
public:
  int dp(int i, int prevStage, string &s, vector<vector<int>> &memo)
  {
    int n = s.length();

    if (i == n)
    {
      return 0;
    }

    if (memo[i][prevStage] != -1)
      return memo[i][prevStage];

    int ans = INT_MAX;

    for (int state = prevStage; state <= 2; state++)
    {
      int cost = 0;

      if (state == 0 || state == 2)
      {
        cost = 1;
      }
      else
      {
        cost = (s[i] == '1') ? 2 : 0;
      }

      ans = min(ans, cost + dp(i + 1, state, s, memo));
    }

    return memo[i][prevStage] = ans;
  }
  int minimumTime(string s)
  {
    int n = s.length();

    vector<vector<int>> memo(n, vector<int>(3, -1));

    return dp(0, 0, s, memo);
  }
};

int main()
{

  cout << endl;
  return 0;
}