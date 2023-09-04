link:-https://leetcode.com/problems/permutations/description/
class Solution {
public:
   void solve( int index,vector<int>& nums,vector<vector<int>>&ans){
  //BASE CASE
  if(index>=nums.size()){
      ans.push_back(nums);
      return;
  }
for(int i=index;i<nums.size();i++){
    swap(nums[index],nums[i]);
    solve(index+1,nums,ans);
    //BACKTRACK
    swap(nums[index],nums[i]);
}
   }

    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>>ans;
         int index=0;
         solve(index,nums,ans);
         return ans;
    }
};
