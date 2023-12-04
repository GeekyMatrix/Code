class Solution {
public:
    string largestGoodInteger(string nums) {
        int n = nums.size();
        int prev = 0;
        string res;
     for(int i = 1; i <= n - 2; i++){
         if(nums[i] == nums[i - 1] && nums[i] == nums[i + 1]){
             if(nums[i] >= prev){
                 res = "";
             res += nums[i-1];
             res+= nums[i];
             res += nums[i+1];
             
             prev = nums[i];
             }
         }
     }   
     return res.size() == 0 ? "" : res;
    }
};
