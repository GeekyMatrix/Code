class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,1) , hash(n+1);
        int last_index = 0,  maxL = 0;

        sort(nums.begin() , nums.end());

        for(int i = 1; i < n; i++){
          hash[i] = i; // The ith index is definetly be ist LIS
          for(int j = 0; j < i; j++){
              if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                  dp[i] = dp[j] + 1; //Increase the LIS length
                  hash[i] = j; //add that index in the LIS
              }
          }
           if(dp[i] > maxL){
               maxL = dp[i];
               last_index = i;
           }
        }

        vector<int>PLCS;

        while(hash[last_index] != last_index){
            PLCS.push_back(nums[last_index]);
            last_index = hash[last_index];
        }
        PLCS.push_back(nums[last_index]);
        reverse(PLCS.begin(), PLCS.end());
        return PLCS;
    }
};
