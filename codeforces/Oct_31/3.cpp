/*



*/

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

    int arr[n], sum = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
      sum += arr[i];
    }

    bool internal = false;
    
    for (int i = 1; i < n - 1; i++)
    {
      if(arr[i] > 1) {
        internal = true;
        break;
      }
    }

    if(internal) cout << sum - 1;

    else if(arr[0] != 1 || arr[n - 1] != 1) cout << sum - (n - 1);

    else cout << -1;
    
    cout << endl;
  }

  return 0;
}