class Solution {
public:
//TC = O(N)
//SC = O(1)
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i+1]) return i;
        }
        return n - 1;
    }

//TC = O(log N)
//SC = O(1)
int findPeakElement(vector<int>& nums) {
int l = 0, r = nums.size() - 1;

  while(l < r){
    int mid = l + (r - l)/2;
    if(nums[mid] > nums[mid+1]) r = mid;
    else l = mid + 1;
}
 return  l;
}
};
