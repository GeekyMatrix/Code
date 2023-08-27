class Solution {
public:
//TC=O(N) ,SC=O(N)
    int findDuplicate(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>m;
         int n=nums.size();
          for(int i=0;i<n;i++){
              m[nums[i]]++;
          }
          for(auto i:m){
              if(i.second>=2) ans=i.first;
          }
          return ans;
    }

//TC=O(N) ,SC=O(1)
int findDuplicate(vector<int>& nums) {

 int slow=nums[0];
 int fast=nums[0];

 do{
   slow=nums[slow];
   fast=nums[nums[fast]];
 }
 while(slow!=fast);

 fast = nums[0];


 while(slow!=fast) {
   slow=nums[slow];
   fast=nums[fast];
 }
  return slow;
}
};
