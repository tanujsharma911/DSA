/*

2265. Count Nodes Equal to Average of Subtree

Given the root of a binary tree, return the number of nodes where the value of the node is equal to the
average of the values in its subtree.

Note:

The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.

*/

#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct Pair
{
  int sum;
  int size;
  Pair(int a, int n) : sum(a), size(n) {}
  Pair() : sum(0), size(0) {}
};

class Solution
{
public:
  int ans = 0;
  Pair helper(TreeNode *root)
  {
    if (root == NULL)
      return Pair();

    auto left = helper(root->left);
    auto right = helper(root->right);

    int avg = (left.sum + right.sum + root->val) / (left.size + right.size + 1);

    if (avg == root->val)
    {
      ans++;
    }

    return Pair(left.sum + right.sum + root->val, left.size + right.size + 1);
  }
  int averageOfSubtree(TreeNode *root)
  {
    helper(root);

    return ans;
  }
};

int main()
{

  cout << endl;
  return 0;
}