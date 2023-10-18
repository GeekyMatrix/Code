class Solution {
public:
//Recursive method
    int numTrees(int n) {
        if(n<=1) return 1;     // if(n==0) that means null is also a answer
       
       int ans=0;

       for(int i=1;i<=n;i++){
          ans+=numTrees(i-1)*numTrees(n-i);
       }
       return ans;
    }
//Memoization
   int solve(int n,vector<int>&t) {
        if(n<=1) return 1;     // if(n==0) that means null is also a answer
       
       int ans=0;
       
       if(t[n]!=-1) return t[n];

       for(int i=1;i<=n;i++){
          ans+=solve(i-1,t)*solve(n-i,t);
       }
       return t[n]=ans;
    }
    int numTrees(int n) {
        vector<int>t(n+1,-1);
     return solve(n,t);
    }

//DP 
    int solve(int n) {
        vector<int>dp(n+1,0);
       dp[0]=dp[1]=1;    // if(n==0) that means null is also a answer

       for(int i=2;i<=n;i++){         //i->no. of nodes
          for(int j=1;j<=i;j++){     //j->root node
           dp[i]+=dp[j-1]*dp[i-j];
          }
       }
       return dp[n];
    }
       int numTrees(int n) {
         return solve(n);
    }
};
