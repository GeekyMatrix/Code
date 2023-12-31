class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans=-1;
        int n=nums.size();
        int s=0,e=n-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target) {
                ans= mid;
                return ans;
            }
            else if(nums[mid]<target) s=mid+1;
            else e= mid-1;
        }
        return ans;
    }
};
