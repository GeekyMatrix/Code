class Solution {
public:
//TC=O(N^3)
//SC=O(1)
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
    for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
        for(int k=j+1; k<n; k++){
          if(nums[k] > nums[j] && nums[j] > nums[i]) return true;
        }
      }
    }
       return false;
    }

//TC=O(N)
//SC=O(1)
       bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int num1 = INT_MAX;
        int num2 = INT_MAX; 

        for(int i=0; i<n; i++){
        int num3 = nums[i];

        if(num3 <= num1) num1 = num3;
        else if(num3 <= num2) num2 = num3;

        else return true; // num1<num2 ye set hai toh already num3 bda hoga
    }
       return false;
    }
};
