class Solution {
public:
//Recusive

int n;
static bool comp(string &words1, string &words2){
    return words1.length() < words2.length();
}

bool ispred(string &prev,string &curr){
  int M = prev.length();
  int N = curr.length();
  
  if(M >= N || N-M!=1) return false;
  int i = 0;
  for(auto x : curr){
      if(prev[i] == x) i++;
  }
  return (i == prev.length() ? true : false);
}
int lis(vector<string>& words, int prev_idx, int curr_idx){
    if(curr_idx == n) return 0; //Base Case
    
    int taken , not_taken;
 //INCLUDE
if(prev_idx == -1 || ispred(words[prev_idx],words[curr_idx])) taken = 1 + lis(words, curr_idx, curr_idx+1);

//EXCLUDE
not_taken = lis(words, prev_idx, curr_idx+1);

return max(taken, not_taken);
}

    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(words.begin(), words.end() ,comp);  //step:1 sort karoge length ke basis pr

        return lis(words, -1, 0);     //step:2 lis find karlo
    }

//Memoization

int t[1001][1001];
int n;

//Comparator function
static bool comp(string &words1, string &words2){
    return words1.length() < words2.length();
}

//Is subsequence function
bool ispred(string &prev,string &curr){
  int M = prev.length();
  int N = curr.length();
  
  if(M >= N || N-M!=1) return false;
  int i = 0;
  for(auto x : curr){
      if(prev[i] == x) i++;
  }
  return (i == prev.length() ? true : false);
}

// LIS function
int lis(vector<string>& words, int prev_idx, int curr_idx){
    if(curr_idx == n) return 0; //Base Case
    
    if(prev_idx!=-1 && t[prev_idx][curr_idx]!=-1) return t[prev_idx][curr_idx];

    int taken = 0, not_taken = 0;
 //INCLUDE
if(prev_idx == -1 || ispred(words[prev_idx],words[curr_idx])) taken = 1 + lis(words, curr_idx, curr_idx+1);

//EXCLUDE
not_taken = lis(words, prev_idx, curr_idx+1);

if(prev_idx!=-1) t[prev_idx][curr_idx] = max(taken, not_taken);

return  max(taken, not_taken);
}

//Main code
    int longestStrChain(vector<string>& words) {
        n = words.size();
        memset(t,-1,sizeof(t));
        sort(words.begin(), words.end() ,comp);  //step:1 sort karoge length ke basis pr

        return lis(words, -1, 0);     //step:2 lis find karlo
    }

//DP

int n;
//Comparator function
static bool comp(string &words1, string &words2){
    return words1.length() < words2.length();
}

//Is subsequence function
bool ispred(string &prev,string &curr){
  int M = prev.length();
  int N = curr.length();
  
  if(M >= N || N-M!=1) return false;
  int i = 0;
  for(auto x : curr){
      if(prev[i] == x) i++;
  }
  return (i == prev.length() ? true : false);
}

//Main code
    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(words.begin(), words.end() ,comp);  //step:1 sort karoge length ke basis pr
       int maxL = 1;
         //step:2 lis find karlo
         vector<int>dp(n,1);
         for(int i = 1; i<n; i++){
             for(int j = 0; j<i; j++){
                 
                 if(ispred(words[j],words[i])) {
                     dp[i] = max(dp[i], dp[j] + 1);
                      maxL = max(maxL,dp[i]);
                 }
             }
         }
         return maxL;
    }
};
