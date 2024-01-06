class Solution {
public:
//Approach 1
//TC=O(n) SC=O(1)
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;

        for(auto &i : nums) res ^= i;

        return res;
    }
//Approach 2
//TC=O(log n) SC=O(1)
int singleNonDuplicate(vector<int>& nums) {
int s = 0, e = nums.size() - 1;

while(s < e){
    int mid = s + (e - s) / 2;

   bool isEven;
 
 //Right side mai even hai ya odd hai
   if((e - mid) % 2 == 0) isEven = true;
   else isEven = false;

//Check your bagal wala element (mid+1)
   if(nums[mid] == nums[mid + 1]){
       if(isEven) s = mid + 2;
       else e = mid - 1;  
   }

     else{                        //nums[mid] != nums[mid + 1]
       if(isEven) e = mid;
       else s = mid + 1;  
   }

}
  return nums[s]; //or, nums[e]
}
};
