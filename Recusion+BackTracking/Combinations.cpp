class Solution {
public:
//Approach 1
void solve(int index,int n,int k, vector<int>&output, vector<vector<int>>&ans){
    //BASE CASE
    if(k==0) {
        ans.push_back(output);
        return;
    }
   if(index>n) return;

   //INSERT THE ELEMENTS
   output.push_back(index);
   solve(index+1, n, k-1,output,ans);
   //UNDO THE CHANGES
   output.pop_back();
    solve(index+1,n, k,output,ans);
}

    vector<vector<int>> combine(int n, int k) {
         vector<vector<int>>ans;
         vector<int>output;
         solve(1,n,k,output,ans);
         return ans;
    }

//Approach 2
void solve(int index,int n,int k, vector<int>&output, vector<vector<int>>&ans){
    //BASE CASE
    if(k==0) {
        ans.push_back(output);
        return;
    }

   //INSERT THE ELEMENTS
   for(int i=index;i<=n;i++){
   output.push_back(i);
   solve(i+1, n, k-1,output,ans);
   //UNDO THE CHANGES
   output.pop_back();
   }

}
 vector<vector<int>> combine(int n, int k) {
         vector<vector<int>>ans;
         vector<int>output;
         solve(1,n,k,output,ans);
         return ans;
    }
}; 
