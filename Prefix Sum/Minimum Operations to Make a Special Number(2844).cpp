class Solution {
public:
typedef long long ll;
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
       ll n=nums.size();
       vector<ll>prefix(n+1,0);

       unordered_map<ll,ll>m;

       m[0]=1;

       ll res=0;
       for(int i=0; i<n; i++){
           if(nums[i] % mod ==k) prefix[i+1] =prefix[i]+1;
           else prefix[i+1] =prefix[i];
      
      ll target = (prefix[i+1] - k + mod)%mod;

      res += m[target];

      m[prefix[i+1] % mod]++;
    }
 return res;
 }
};
