class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();

        int idx=-1;
        for(int i=n-2;i>=0;i--){  // step 1:- dip kha pr hai
          if(nums[i]<nums[i+1]){
              idx=i;
              break;
          }
        }
        if(idx==-1)  reverse(nums.begin(),nums.end()); // mtlb already descending order mai hai 
  else {
    // step 2:- find just greater element of nums[idx]
    for(int i=n-1;i>idx;i--){
        if(nums[i]>nums[idx]){
            swap(nums[i],nums[idx]);
            break;
        }
    }
    
    //step 3:-Try to place remaining in a sorted order
       reverse(nums.begin()+idx+1,nums.end()); 
    }
    }
};
