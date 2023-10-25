class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();

        int gola_idx = - 1;
        for(int i = n - 1; i > 0; i--){  
          if(nums[i - 1] < nums[i]){ // step 1:- dip kha pr hai (gola_idx)
              gola_idx = i - 1;
              break;
          }
        }

 if(gola_idx == -1)  reverse(nums.begin(),nums.end()); // mtlb already descending order mai hai 

  else {
    for(int j = n - 1; j >= gola_idx + 1; j--){
        if(nums[j] > nums[gola_idx]){      // step 2:- find just greater element of nums[gola_idx]
            swap(nums[j] , nums[gola_idx]); 
            break;
        }
    }
    
    //step 3:-Try to place remaining in a sorted order
       reverse(nums.begin() + gola_idx + 1 ,nums.end()); 
    }
    }
};
