class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0,j = 0;
        int res = INT_MIN, Curr_sum = 0;

        while(j < nums.size()) {
         Curr_sum+=nums[j];

         if(j-i+1 == k){
             res = max(res,Curr_sum);
             Curr_sum-=nums[i];
             i++;
         }
         j++;
        }
        return  ((double)res/k);
    }
};
