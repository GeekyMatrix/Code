class Solution {
public:
  int findPivot(vector<int>& nums,int n){
  int l=0,r=n-1;

  while(l<r){
      int mid=l+(r-l)/2;

      if(nums[mid]>nums[r]) l=mid+1;   //Minimum right side hi milega
      else r=mid;                      //us mid pr bhi mil skta hai
  }
    return r;
  }

      int BinarySearch(int s,int e,vector<int>& nums, int target) {
        int idx=-1;

        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target) {
                idx= mid;
                return idx;
            }
            else if(nums[mid]<target) s=mid+1;
            else e= mid-1;
        }
        return idx;
    }

 //MAIN FUNCTION
    int search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        int n=nums.size();

        int pivot_index=findPivot(nums,n); 

       int idx=BinarySearch(0,pivot_index-1,nums,target); //left side of pivot index
        if(idx!=-1) return idx;

         idx=BinarySearch(pivot_index,n-1,nums,target); //right side of including pivot index

        return idx;
    }
};
