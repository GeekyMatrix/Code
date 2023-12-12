class Solution {
public:
// //APPROACH 1
// //TC = O(n logn)
// //SC = O(1)
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();

        int a = nums[n-2] - 1;
        int b = nums[n-1] - 1;

        return a*b;
    }

// //APPROACH 2
// //TC = O(n)
// //SC = O(1)
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int firstMax = 0;
        int SecondMax = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] > firstMax){
                SecondMax = firstMax;
                firstMax = nums[i];
            }
            else SecondMax = max(SecondMax , nums[i]);
        }

        return (firstMax-1) * (SecondMax-1);
    }

//APPROACH 2
//TC = O(n)
//SC = O(1)
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int MaxNum = nums[0];
        int res = 0;

        for(int i = 1; i < n; i++){
          res = max(res , (MaxNum - 1) * (nums[i] - 1));
          MaxNum = max(MaxNum , nums[i]);
        }

        return res;
    }
};
