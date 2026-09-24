/*

1298. Maximum Candies You Can Get from Boxes

You have n boxes labeled from 0 to n - 1. You are given four arrays: status, candies, keys, and containedBoxes 
where:

status[i] is 1 if the ith box is open and 0 if the ith box is closed,
candies[i] is the number of candies in the ith box,
keys[i] is a list of the labels of the boxes you can open after opening the ith box.
containedBoxes[i] is a list of the boxes you found inside the ith box.
You are given an integer array initialBoxes that contains the labels of the boxes you initially have. 
You can take all the candies in any open box and you can use the keys in it to open new boxes and you 
also can use the boxes you find in it.

Return the maximum number of candies you can get following the rules above.

*/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        unordered_set<int> keys_collected;
        unordered_set<int> locked;
        queue<int> q;

        int candies_collected = 0;

        for(auto b : initialBoxes){
            if(status[b]) {
                q.push(b);
            }
            else{
                locked.insert(b);
            }
        }

        while(!q.empty()){
            int label = q.front();
            q.pop();

            candies_collected += candies[label];

            for(int k : keys[label]){
                if(locked.count(k)){
                    q.push(k);
                    locked.erase(k);
                }
                else {
                    keys_collected.insert(k);
                }
            }

            for(auto child : containedBoxes[label]){
                if(status[child]){
                    q.push(child);
                }
                else if(keys_collected.count(child)) {
                    q.push(child);
                    keys_collected.erase(child);
                }
                else {
                    locked.insert(child);
                }
            }
        }

        return candies_collected;
    }
};

int main() {
   
   cout << endl;
   return 0;
}