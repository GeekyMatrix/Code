class Solution {
public:
//BRURTE FORCE
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
     vector<int>res;

     for(int i = 0; i < n; i++){
         int sum = 0;
         for(int j = 0; j < n; j++){
             int diff = abs(nums[i] - nums[j]);
             sum+=diff;
         }
          res.push_back(sum);
     }
     return res;
    }

//OPTIMAL FORCE
//TC = O(N)
//SC = O(N)
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
     vector<int>prefixSum(n);
     prefixSum[0] = nums[0];

     for(int i = 1; i < n; i++) prefixSum[i] = prefixSum[i - 1] + nums[i];
     
      vector<int>res(n);

      for(int i = 0; i < n; i++){
          int leftSum = prefixSum[i] - nums[i]; //(nums[0] + nums[1] + ... + nums[i-1])
          int rightSum = prefixSum[n - 1] - prefixSum[i];//(nums[i+1] + nums[i+2] + ... + nums[n-1])

          int leftTotal = (nums[i] * i) - leftSum;
          int rightTotal = rightSum - (nums[i] * (n-i-1));

          res[i] = leftTotal + rightTotal; 
      }
     return res;
    }

//BEST FORCE
//TC = O(N)
//SC = O(N)
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
     int prefixSum = 0;
     
      vector<int>res(n);
      
      int Sum = accumulate(nums.begin(),nums.end() ,0);

      for(int i = 0; i < n; i++){
          int leftSum = prefixSum;                    //(nums[0] + nums[1] + ... + nums[i-1])
          int rightSum = Sum - prefixSum - nums[i];  //(nums[i+1] + nums[i+2] + ... + nums[n-1])

          int leftTotal = (nums[i] * i) - leftSum;
          int rightTotal = rightSum - (nums[i] * (n-i-1));

          res[i] = leftTotal + rightTotal;
          prefixSum+= nums[i]; 
      }
     return res;
    }
};
