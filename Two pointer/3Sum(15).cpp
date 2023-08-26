class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>s;
         int n=nums.size();
         sort(nums.begin(),nums.end());
      
         for(int i=0;i<n-2;i++){
             int j=i+1;
             int k=n-1;
           
             while(j<k){
                 int sum=nums[j]+nums[k];
                 if(sum==-nums[i]){   //nums[i]+nums[j]+nums[k]==0;
                  s.insert({nums[i],nums[j],nums[k]});
                  j++;
                  k--;
                 }
                 else if(sum>-nums[i]) k--;
                 else if(sum<-nums[i]) j++;
             }
         }
              vector<vector<int>>res;
              for(auto x:s){
                  ans.push_back(x);
         }
         return ans;
    }
};
