class Solution {
public:
//Approach 1
    int minimumOperations(string num) {
        int n = num.size();
        int ans = num.size();

        for(int i=n-1; i>=0;i--){
            for(int j=i-1; j>=0; j--){
                int lastNum = (num[i]-'0') + (num[j]-'0')*10;
                if(lastNum % 25==0) ans=min(ans,n-j-2);
            }
            if(num[i] == '0') ans=min(ans,n-1);
        }
        return ans;
    }

//Approach 2 (DP)
  int t[101][27];
  int solve(int idx,int num,string s){
    if(idx == s.size()) {
       if(num % 25 == 0) return 0;
       return 1e9; 
    }
    if(t[idx][num]!=-1) return t[idx][num];

    int digit=s[idx]-'0';
    int non_pick = 1+solve(idx+1,num,s);
    int pick = solve(idx+1,(num*10+digit)%25,s);

    return t[idx][num]=min(pick,non_pick);
  }

   int minimumOperations(string num) {
       memset(t,-1,sizeof(t));
       return solve(0,0,num);
   }
};
