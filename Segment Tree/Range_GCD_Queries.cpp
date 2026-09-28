/*

Range GCD Queries

Given an integer array arr[] and a 2D array queries[][] containing q queries, where each query 
is one of the following two types:

Type 1: [0, l, r] -> Return the GCD of all elements in the range [l, r] (both inclusive).
Type 2: [1, index, value] -> Update arr[index] to value.
Return an array containing the answers to all Type 1 queries in the order they appear in queries[][].

Note: Use 0-based indexing.

*/

#include <iostream>

using namespace std;

class SegmentTree {
private:
    vector<int> seg;
    int n;
    
    int build(int idx, int l, int r, vector<int>& arr){
        if(l >= r){
            return seg[idx] = arr[l];
        }
        
        int mid = (l + r) / 2;
        
        int left = build(idx * 2 + 1, l, mid, arr);
        int right = build(idx * 2 + 2, mid + 1, r, arr);
        
        return seg[idx] = gcd(left, right);
    }
    
    int gcd(int a, int b){
        if(b == 0) return a;
        if(a == 0) return b;
        
        return gcd(b % a, a);
    }
    
    int range_gcd_util(int idx, int l, int r, int range_l, int range_r){
        if(r < range_l || l > range_r){
            return 0;
        }
        if(range_l <= l && r <= range_r){
            return seg[idx];
        }
        if(l == r){
            return seg[idx];
        }
        
        int mid = (l + r) / 2;
        
        int left = range_gcd_util(idx * 2 + 1, l, mid, range_l, range_r);
        int right = range_gcd_util(idx * 2 + 2, mid + 1, r, range_l, range_r);
        
        return gcd(left, right);
    }
    int update_util(int idx, int l, int r, int u_idx, int u_value){
        if (u_idx < l || u_idx > r){
            return seg[idx];
        }
        if(l == r){
            return seg[idx] = u_value;
        }
        
        int mid = (l + r) / 2;
        
        int left = update_util(idx * 2 + 1, l, mid, u_idx, u_value);
        int right = update_util(idx * 2 + 2, mid + 1, r, u_idx, u_value);
        
        return seg[idx] = gcd(left, right);
    }
public:
    
    SegmentTree(vector<int>& arr){
        n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
    }
    
    void update(int idx, int value){
        update_util(0, 0, n - 1, idx, value);
    }
    
    int range_gcd(int l, int r){
        return range_gcd_util(0, 0, n - 1, l, r);
    }
};
class Solution {
  public:
    
    vector<int> processQueries(vector<int> arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int q = queries.size();
        
        SegmentTree s(arr);
        
        vector<int> ans;
        
        for(auto q : queries){
            if(q[0] == 0){
                int l = q[1], r = q[2];
                
                ans.push_back(s.range_gcd(l, r));
            }
            else {
                int index = q[1], value = q[2];
                
                s.update(index, value);
            }
        }
        
        return ans;
    }
};

/*

[2, 3, 4]

[3 % 2, 2, 4] =  [1, 2, 4]

[2 % 1, 1, 4] =  [0, 1, 4]

*/

int main() {
   
   cout << endl;
   return 0;
}