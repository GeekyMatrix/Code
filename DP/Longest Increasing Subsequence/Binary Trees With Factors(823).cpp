class Solution {
public:
int MOD = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end()); //kyuki child uss point se left mai hi honge

    unordered_map<int,long long>mp; // child store krne ke liye
    mp[arr[0]] = 1;

    for(int i = 1; i < n; i++){
        int root = arr[i];
        mp[root] = 1;
        for(int j = 0; j < i; j++){
          
            int LC = arr[j];

            if(root % LC == 0 && mp.find(arr[i] / LC) != mp.end() ){ // RC = arr[i] / LC;
                 mp[root]+=mp[LC] * mp[arr[i] / LC];
            }
        }
    }
long res = 0;
//it.first = value
//it.second = ways
for(auto &it :mp) res = (res + it.second) % MOD;
return res;
    }
};
