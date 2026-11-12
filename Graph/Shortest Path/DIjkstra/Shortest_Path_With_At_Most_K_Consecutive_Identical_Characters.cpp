/*

3970. Shortest Path With At Most K Consecutive Identical Characters

You are given an integer n representing the number of nodes in a directed weighted graph, numbered from 0
to n - 1. This is represented by a 2D integer array edges, where edges[i] = [ui, vi, wi] represents a directed
edge from node ui to node vi with weight wi.

You are also given a string labels of length n, where labels[i] is the character assigned to node i, and an integer k.

Return the minimum total edge weight of a path from node 0 to node n - 1 such that the concatenation of the labels
of the nodes along the path contains at most k consecutive identical characters. If no valid path exists, return -1.

*/

#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
  int shortestPath(int n, vector<vector<int>> &edges,
                   string labels, int k)
  {

    vector<vector<pair<int, int>>> adj(n);

    for (auto &e : edges)
    {
      int u = e[0], v = e[1], w = e[2];

      adj[u].push_back({v, w});
    }

    // {distance, node, lastChar, consecutiveCount}
    using State = tuple<int, int, int, int>;

    priority_queue<
        State,
        vector<State>,
        greater<State>>
        pq;

    // {node, lastChar, consecutiveCount} -> distance
    map<tuple<int, int, int>, int> dist;

    int srcChar = labels[0] - 'a';

    pq.push({0, 0, srcChar, 1});
    dist[{0, srcChar, 1}] = 0;

    while (!pq.empty())
    {

      auto [d, node, lastChar, cnt] = pq.top();
      pq.pop();

      auto state = make_tuple(node, lastChar, cnt);

      if (dist[state] != d)
        continue;

      if (node == n - 1)
        return d;

      for (auto [neighbour, wt] : adj[node])
      {

        int ch = labels[neighbour] - 'a';

        int newCnt = (ch == lastChar) ? cnt + 1 : 1;

        if (newCnt > k)
          continue;

        int newDist = d + wt;

        auto newState = make_tuple(neighbour, ch, newCnt);

        if (!dist.count(newState) ||
            newDist < dist[newState])
        {

          dist[newState] = newDist;

          pq.push({newDist,
                   neighbour,
                   ch,
                   newCnt});
        }
      }
    }

    return -1;
  }
};

int main()
{

  cout << endl;
  return 0;
}