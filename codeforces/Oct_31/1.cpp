/*



*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int t = 0;
  cin >> t;

  while (t--)
  {
    int n, m;
    cin >> n >> m;

    string p, q;
    cin >> p >> q;

    vector<int> freq(26, 0);

    for (auto c : p)
    {
      freq[c - 'a']++;
    }

    for (auto c : q)
    {
      freq[c - 'a']--;
    }

    bool flag = true;

    for (int i = 0; i < 26; i++)
    {
      if (i == ('s' - 'a') || i == ('i' - 'a') || i == ('x' - 'a'))
      {
        if (freq[i] != 1)
        {
          flag = false;
          break;
        }
        continue;
      }

      if (freq[i] != 0)
      {
        flag = false;
        break;
      }
    }

    cout << (flag ? "YES" : "NO") << endl;
  }

  return 0;
}