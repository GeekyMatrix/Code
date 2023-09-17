class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0,j = 0;
        int countzeros = 0 ,res = INT_MIN;
        
        while(j < nums.size()){
            if(nums[j] == 0) countzeros++;

          while(countzeros > k){
              if(nums[i] == 0) countzeros--;
              i++;
          }
            res = max(res,j-i+1);
            j++;
        }
        return res;
    }
};
