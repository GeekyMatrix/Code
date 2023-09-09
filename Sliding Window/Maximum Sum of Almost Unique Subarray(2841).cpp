class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int,int> mp;
        int i = 0, j = 0;
        long long maxi = 0, sum = 0;

        while(j < nums.size()){
          sum += nums[j];
          mp[nums[j]]++;
          
            while(j-i+1 > k) {  //Uss window size se bahar nikal rha hai
              mp[nums[i]]--;
              sum -= nums[i];
              if(mp[nums[i]] == 0)mp.erase(nums[i]);
              i++;
            }

          if(j-i+1 == k){  //Uss window size ka mil gya
              if(mp.size() >=m)  maxi=max(maxi,sum);
          }
            j++;
        }
        return maxi;
    }
};
