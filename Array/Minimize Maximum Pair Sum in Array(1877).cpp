class Solution {
public:
//T.C : O(nlogn) due to sorting
//S.C : O(1)
    int minPairSum(vector<int>& nums) {
        int res = 0;
     sort(nums.begin() , nums.end());

        int s = 0, e = nums.size() - 1;

        while(s < e){
         int pair_sum = nums[s] + nums[e];
        res = max(res , pair_sum);

         s++;
         e--;
        }
        return res;
    }
};
