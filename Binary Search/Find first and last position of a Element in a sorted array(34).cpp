class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
    //FIRST OCCURENCE
      int s=0,e=nums.size()-1;
     while(s<=e){
       int mid=(s+e)/2;
       if(nums[mid]==target){
           ans[0]=mid;
           e=mid-1;
       }
       else if(nums[mid]<target) s=mid+1;
       else e=mid-1;
    }
    //LAST OCCURENCE
       s=0,e=nums.size()-1;
     while(s<=e){
       int mid=(s+e)/2;
       if(nums[mid]==target){
           ans[1]=mid;
           s=mid+1;
       }
       else if(nums[mid]<target) s=mid+1;
       else e=mid-1;
    }
        return ans;
    }
};
