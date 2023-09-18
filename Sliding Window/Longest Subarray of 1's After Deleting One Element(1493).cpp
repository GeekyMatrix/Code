class Solution {
public:
int n;
int findMax(vector<int>& nums, int skip_idx){
    int currlength = 0;
    int maxlength = 0;

    for(int i = 0; i<n; i++){

        if(i == skip_idx) continue;

        if(nums[i] == 1){
            currlength++;
            maxlength = max(maxlength, currlength);
        }
        else  currlength = 0;
    }
    return maxlength;
}
int longestSubarray(vector<int>& nums) {
 n = nums.size();
int res = 0,Countzeros = 0;

for(int i = 0;i<n;i++){
    if(nums[i] == 0){
     Countzeros++;
     res = max(res, findMax(nums, i));
    }
}
  if(Countzeros == 0) return n-1;

  return res;
}

//Approach 2
//Sliding Window
    int longestSubarray(vector<int>& nums) {
        int i = 0,j = 0;
        int res = INT_MIN , Countzeros = 0;

        while(j < nums.size()){
            if(nums[j] == 0) Countzeros++;

            while(Countzeros == 2){
                if(nums[i] == 0)  Countzeros--;
                i++;
            }
        res = max(res,j-i);
        j++;
        }
        return res;
    }

//Approach 3
int longestSubarray(vector<int>& nums) {
int i = 0,j = 0;
int last_zero_idx = -1;
int res = 0;

while(j < nums.size()){
  if(nums[j] == 0){
      i = last_zero_idx + 1;
      last_zero_idx = j;
  }
  res = max(res,j-i);
  j++;
}
  return res;
}
};
