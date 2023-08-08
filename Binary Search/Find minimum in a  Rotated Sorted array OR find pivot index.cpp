  int findPivot(vector<int>& nums,n){
  int l=0,r=n-1;

  while(l<r){
      int mid=l+(r-l)/2;

      if(nums[mid]>nums[r]) l=mid+1;   //Minimum right side hi milega
      else r=mid;                      //us mid pr bhi mil skta hai
  }
    return r;
  }
