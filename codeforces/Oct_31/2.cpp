/*


2
R S P
0 0 3
1 1 2

RPS, SSS
SPSS, PRSS


*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  while(t--){
    int R, S, P; // R, S, P
    cin >> R >> S >> P;

    char move;

    if(R >= S && R >= P){
      move = 'P';
    }

    if(S >= R && S >= P){
      move = 'R';
    }

    if(P >= S && P >= R){
      move = 'S';
    }

    cout << string(R + P + S, move);

    cout << endl;
  }
  
  return 0;
}