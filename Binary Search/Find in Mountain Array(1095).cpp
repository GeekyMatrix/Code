class Solution {
public:
//Find peak index
int peakIndexInMountainArray( MountainArray &mountainArr){
    int l = 0, r = mountainArr.length() - 1;
  while(l < r){
  int mid = l + (r - l) / 2;

  if(mountainArr.get(mid) > mountainArr.get(mid + 1)) r = mid;
  else l = mid + 1;
  }
  return l;
}

//Binary search
int binarySearch(MountainArray &mountainArr, int l, int r,int target){
        while(l <= r) {
           int mid = l + (r-l)/2;
            
            if(mountainArr.get(mid) == target) {
                return mid;
            } else if(mountainArr.get(mid) > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return -1;
}

//Reverse Binary Search
int reversebinarySearch(MountainArray &mountainArr, int l,int r, int target){
        while(l <= r) {
           int mid = l + (r-l)/2;
            
            if(mountainArr.get(mid) == target)   return mid;

 else if(mountainArr.get(mid) > target)  l = mid+1;//Because the array in right side of peak is in descending order

            else     r = mid-1;
            
        }
        return -1;
}

//Main code
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        int peakIndex = peakIndexInMountainArray(mountainArr);
        
        int idx = binarySearch(mountainArr, 0, peakIndex, target);
        
        if(idx == -1)     return reversebinarySearch(mountainArr, peakIndex, n-1, target);
        
        
        return idx;
    }
};
