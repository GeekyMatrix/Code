class Solution {
public:
    //Brute force(TLE)
     long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        
        for(int i = 0; i < n; i++){
         for(int j = i + 1; j < n; j++){
           for(int k = j + 1; k < n; k++){
             res = max(res, 1ll*(nums[i] - nums[j]) * nums[k]);
            }
             }
              }
        return res;
    }
    
    //optimise 
    typedef long long LL;
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        LL res = 0;
        int a = 0; //a->num[i]
        int b = 0;  //b-> nums[i] - nums[j]
        
        for(int i = 2; i < n; i++){
            
          a = max(a , nums[i - 2]);
          b = max(b, a - nums[i - 1]);
          
        res = max(res, 1LL * b * nums[i]); //nums[i]->nums[k]
        }
        return res;
    }
};
