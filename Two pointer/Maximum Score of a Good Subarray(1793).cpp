class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        
        int i = k;
        int j = k;

        int currMin = nums[k] , res = nums[k];

        while(i > 0 || j < n - 1){
           
           int left_Value = (i > 0) ? nums[i - 1] : 0;
           int right_Value = (j < n -1)? nums[j + 1] : 0;

           if(left_Value > right_Value){
              i--;
              currMin = min(currMin , nums[i]);
           }

           else{ //left_Value < right_Value
             j++;
             currMin = min(currMin , nums[j]);
           }

           res = max(res ,currMin * (j - i +1)); //Update krte jao max Good subarray ko
        }
      return res;
    }
};
