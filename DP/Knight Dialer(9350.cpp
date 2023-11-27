class Solution {
public:
//Recursion
int M = 1e9+7;
vector<vector<int>>adj{{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2,4}}; //adjacency list

int Solve(int n , int cell){
 if(n == 0) return 1; // BASE CASE

 int ans = 0;
  for(auto &nextCell : adj[cell]) ans = (ans + Solve(n - 1, nextCell)) % M;

  return ans;
}
    int knightDialer(int n) {
        int res = 0;

        for(int cell = 0; cell <= 9; cell++) res = (res + Solve(n - 1, cell)) % M;

        return res;
    }

//Memoization
int t[5001][10];
int M = 1e9+7;
vector<vector<int>>adj{{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2,4}}; //adjacency list

int Solve(int n , int cell){
 if(n == 0) return t[n][cell] = 1; // BASE CASE
 
 if(t[n][cell] != -1) return t[n][cell];

 int ans = 0;
  for(auto &nextCell : adj[cell]) ans = (ans + Solve(n - 1, nextCell)) % M;

  return t[n][cell] = ans;
}
    int knightDialer(int n) {
        int res = 0;
         memset(t ,-1, sizeof(t));
        for(int cell = 0; cell <= 9; cell++) res = (res + Solve(n - 1, cell)) % M;

        return res;
    }

//DP
int M = 1e9+7;
vector<vector<int>>adj{{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2,4}}; //adjacency list

    int knightDialer(int n) {
         int res = 0;
        vector<vector<int>>dp(n, vector<int>(10));
         
       for(int cell = 0; cell <= 9; cell++) dp[0][cell] = 1; //BASE CASE

       for(int i = 1; i <= n - 1; i++){ 
            for(int cell = 0; cell <= 9; cell++){

       int ans = 0;
        for(auto &nextCell : adj[cell]) ans = (ans + dp[i - 1][nextCell]) % M;

           dp[i][cell] = ans;
           }
       }

       for(int cell = 0; cell <= 9; cell++) res = (res + dp[n - 1][cell]) % M;

        return res;

    }
};
