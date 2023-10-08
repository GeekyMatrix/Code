class Solution {
public:
  int L, H, Z, O;
  const int M = 1e9 + 7;
    
    int solve(int length){
        //BASE CASE
        if(length > H) return 0;

         bool addone = false;
        if(length >= L && length <=H) addone = true;

        int append_zero = solve(length + Z);
        int append_one = solve(length + O);

        return (addone + append_zero + append_one) % M;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        L = low;
        O = one;
        H = high;
        Z = zero;
        return solve(0);
    }

//MEMOIZATION METHOD
  int L, H, Z, O;
  const int M = 1e9 + 7;
    
    int solve(int length, vector<int>&t){
        //BASE CASE
        if(length > H) return 0;
        
        if(t[length]!=-1) return t[length];
         bool addone = false;
        if(length >= L && length <=H) addone = true;

        int append_zero = solve(length + Z, t);
        int append_one = solve(length + O,t);

        return t[length] = (addone + append_zero + append_one) % M;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        L = low;
        O = one;
        H = high;
        Z = zero;
        vector<int>t(H + 1, -1);
        return solve(0 ,t);
    }

//DP METHOD
const int M = 1e9 + 7;

int countGoodStrings(int low, int high, int zero, int one) {

 vector<int>dp(high + 1,0); //dp[i] ->No. of good strings of length i

 dp[0] = 1; //For length 0 there will be one Empty string

 for(int i = 1; i<=high; i++){

 if(i - zero>= 0) dp[i] = (dp[i]%M + dp[i - zero]%M)%M;

 if(i - one>= 0)  dp[i] = (dp[i]%M + dp[i - one]%M)%M; 
 }

 int res = 0;
 for(int l = low; l<=high; l++) res = (res%M + dp[l]%M)%M; //low to high length ka hi chaiye

 return res;
}
};
