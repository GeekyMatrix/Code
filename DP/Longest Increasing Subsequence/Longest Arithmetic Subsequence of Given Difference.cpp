class Solution {
public:
//Recursive method

int n;
int D;

int solve(int idx,vector<int>& arr){
int result=0;

for(int j=idx+1;j<n;j++){
    int preVal=arr[idx];
    int currVal=arr[j];

    if(currVal-preVal==D) {
        result=max(result,1+solve(j,arr));
    }
}
  return result;
}
int longestSubsequence(vector<int>& arr, int difference) {
    n=arr.size();
int result=0;
 D=difference;
for(int i=0;i<n;i++){

    result=max(result,1+solve(i,arr));

}
 return result;
}

//Memoization
 
int n;
int D;
int t[100001];
int solve(int idx,vector<int>& arr){
int result=0;

if(t[idx]!=-1) return t[idx];
for(int j=idx+1;j<n;j++){
    int preVal=arr[idx];
    int currVal=arr[j];

    if(currVal-preVal==D) {
        result=max(result,1+solve(j,arr));
    }
}
  return t[idx]=result;
}
int longestSubsequence(vector<int>& arr, int difference) {
    n=arr.size();
int result=0;
 D=difference;
 memset(t,-1,sizeof(t));
for(int i=0;i<n;i++){

    result=max(result,1+solve(i,arr));

}
 return result;
}

//DP WITH HASHMAP

int longestSubsequence(vector<int>& arr, int difference) {
  unordered_map<int,int>mp;
  int result=0;
  
  for(int i=0;i<arr.size();i++){
  int prev=arr[i]-difference;

 //check answer exist for prev already or not
 int length_till_prev=mp[prev];

 //current answer update
 mp[arr[i]]=1+length_till_prev;
 
 //result ko update kardo
 result=max(result,mp[arr[i]]);
  }
 return result;
}
};
