class Solution {
public:
//Approach 1
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
         vector<int>res(n);
           res[0] = pref[0];
        
        for(int i = 1; i < n; i++)  res[i] = pref[i] ^ pref[i - 1];
         return res;
    }

//Approach 2
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        
        for(int i = n - 1; i >= 1; i--)  pref[i] = pref[i] ^ pref[i - 1];
         return pref;
    }
};
