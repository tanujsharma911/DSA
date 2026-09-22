/*

524. Longest Word in Dictionary through Deleting

Given a string s and a string array dictionary, return the longest string in the dictionary that can be
formed by deleting some of the given string characters. If there is more than one possible result,
return the longest word with the smallest lexicographical order. If there is no possible result,
return the empty string.

Example 1:

Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"

Example 2:

Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"

*/

#include <iostream>

using namespace std;

class Solution
{
public:
   string findLongestWord(string &s, vector<string> &d)
   {
      int n = d.size();

      unordered_map<char, vector<int>> freq;

      for (int i = 0; i < s.length(); i++)
      {
         freq[s[i]].push_back(i);
      }

      string ans = "";

      for (auto word : d)
      {
         int prev = -1;
         bool isSubsequence = true;

         for (int i = 0; i < word.length(); i++)
         {

            auto current = upper_bound(freq[word[i]].begin(), freq[word[i]].end(), prev);

            if (current == freq[word[i]].end() || *current <= prev)
            {
               isSubsequence = false;
               break;
            }

            prev = *current;
         }

         if (!isSubsequence)
            continue;

         if (word.length() > ans.length())
            ans = word;

         else if (word.length() == ans.length() && word < ans)
            ans = word;
      }

      return ans;
   }
};

int main()
{

   cout << endl;
   return 0;
}