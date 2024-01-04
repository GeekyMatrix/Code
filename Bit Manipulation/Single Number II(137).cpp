class Solution {
public:
    //Approach 1
    //TC=O(n) SC=O(n)
    int singleNumber(vector<int>& nums) {
        int ans;
        unordered_map<int,int>m;
        for(auto i:nums) m[i]++;

        for(auto x:m){
            if(x.second==1) ans=x.first;
        }
        return ans;
    }

    //Approach 2
      //TC=O(nlogn) SC=O(1)
     int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
          int n = nums.size();

        if(nums.size()==1 )return nums[0];
        if(nums[0]!=nums[1])    return nums[0];
        if(nums[n-1]!=nums[n-2])     return nums[n-1];
        
        for(int i=1; i<n-1; i++){
            if(nums[i]!=nums[i-1] and nums[i]!=nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }

//Approach 3
  int singleNumber(vector<int>& nums) {
     int result=0;
 
   for(int k=0;k<=31;k++){
  int temp=(1<<k);
  int countzeros=0,countones=0;

  // harr ek nums ke index pr kth bit ke liye zeros & ones find krenge
  for(auto & num : nums){
  if((num & temp)==0) countzeros++;
  else countones++;
  }

  if(countones%3==1) result = result | temp;
   }

return result;
  }
};
