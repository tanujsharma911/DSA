/*

Merge Without Extra Space

Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in
sorted order without using any extra space. Modify a[] so that it contains the first n elements
and modify b[] so that it contains the last m elements.

Examples:

Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
Output: a[] = [2, 2, 3, 4], b[] = [7, 10]
Explanation: After merging the two non-decreasing arrays, we get, [2, 2, 3, 4, 7, 10]

Input: a[] = [1, 5, 9, 10, 15, 20], b[] = [2, 3, 8, 13]
Output: a[] = [1, 2, 3, 5, 8, 9], b[] = [10, 13, 15, 20]
Explanation: After merging two sorted arrays we get [1, 2, 3, 5, 8, 9, 10, 13, 15, 20].

Input: a[] = [0, 1], b[] = [2, 3]
Output: a[] = [0, 1], b[] = [2, 3]
Explanation: After merging two sorted arrays we get [0, 1, 2, 3].

*/

#include <iostream>

using namespace std;

class Solution
{
public:
   void mergeArrays(vector<int> &a, vector<int> &b)
   {
      int n = a.size();
      int m = b.size();

      int p1 = n - 1, p2 = 0;

      while (p1 >= 0 && p2 < m)
      {
         if (a[p1] > b[p2])
         {
            swap(a[p1], b[p2]);
            p1--, p2++;
         }
         else
         {
            break;
         }
      }

      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
   }
};

int main()
{

   cout << endl;
   return 0;
}