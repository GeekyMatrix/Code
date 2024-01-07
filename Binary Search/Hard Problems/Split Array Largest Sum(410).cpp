class Solution {
public:
bool isPossible(vector<int>& arr, int n, int m, int mid){
  
  int StudentCnt = 1;
  long long pageSum = 0;

  for(int i = 0; i < n ; i++){

      if(pageSum + arr[i] <= mid)  pageSum += arr[i]; // Usse page ko add krr skte hai
      
      else{
          StudentCnt++; //Dusre student ko allot krwaoge
          if(StudentCnt > m || arr[i] > mid) return false; // allot nhi kr skte

          pageSum = arr[i]; //New student ko allot krwae ho
      }
  }
  return true;
}
//Allocate Books
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m > n) return -1;

    int s = *max_element(arr.begin() , arr.end());
    int e = accumulate(arr.begin() , arr.end() , 0); //Total sum
    
    int res = -1;
    while(s <= e){
        int mid = s + (e - s) / 2;
         
        if(isPossible(arr, n, m, mid)){
            res = mid;
            e = mid - 1;
        }

        else s = mid + 1;
    }
    return res;
}
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums, nums.size() , k);
    }
};
