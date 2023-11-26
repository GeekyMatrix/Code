class Solution {
public:
// //T.C : O(m*nlogn)
// //S.C : O(n) creating arrays
bool Check(vector<int>& nums){
    sort(nums.begin() , nums.end());

    int d = nums[1] - nums[0];

    for(int i = 2; i < nums.size(); i++)  if(nums[i] - nums[i-1] != d) return false;

    return true;
}
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
         vector<bool>res;

        for(int i = 0; i < m; i++){
            vector<int>subarray(nums.begin() + l[i] , nums.begin() + r[i] + 1); //subarray bna liya

           res.push_back(Check(subarray));
        }
        return res;
    }

//Approach-2 (Without sorting)
//T.C : O(m*n)
//T.C : O(n) using hash set
bool Check(vector<int>& nums){
  int n = nums.size();

  int minE = INT_MAX; // AP ist element
  int maxE = INT_MIN; // AP last element

  unordered_set<int>st; 

  for(auto &num:nums){
      minE = min(minE,num);
      maxE = max(maxE,num);

      st.insert(num); 
  }
      if((maxE - minE) % (n-1) != 0) return false; // if not divisible

      int d =  (maxE - minE) / (n-1);  // common difference
      
      int currE = minE + d;           // next element

      while(currE < maxE){
          if(st.find(currE) == st.end()) return false;

          currE += d; // currE, currE+d , currE+2d, currE+3d
      }

    return true;
}
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
         vector<bool>res;

        for(int i = 0; i < m; i++){
            vector<int>subarray(nums.begin() + l[i] , nums.begin() + r[i] + 1); //subarray bna liya

           res.push_back(Check(subarray));
        }
        return res;
    }
};
