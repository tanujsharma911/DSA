#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int t;

   cin >> t;

   while (t--)
   {
      int n;

      cin >> n;

      vector<int> arr(n, 0);

      for (int i = 0; i < n; i++)
      {
         cin >> arr[i];
      }

      int ans = 0, prev = arr[0];

      for(int i = 1; i < n; i++){
         ans += abs(arr[i] - arr[i - 1]);
      }

      cout << ans << endl;
   }

   return 0;
}