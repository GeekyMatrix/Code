class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;
        sort(nums.begin() , nums.end());

        for(int i = n - 1; i > 0; i--){
            if(nums[i - 1] != nums[i]){
              operations+= n - i;
            }
        }
        return operations;
    }
};
