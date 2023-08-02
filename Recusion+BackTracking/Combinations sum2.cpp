class Solution {
public:
  void solve(int index,vector<int>& candidates,int target,vector<vector<int>>&ans, vector<int>&output){
        //BASE CASE
        if(target==0){
            ans.push_back(output);
            return;
        }

        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;

          //TAKE THE ELEMENT
        output.push_back(candidates[i]);
        solve(i+1,candidates,target-candidates[i],ans,output);
        //BACKTRACK
         output.pop_back();
        }
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
         vector<vector<int>>ans;
        vector<int>output;
        solve(0,candidates,target,ans,output);
        return ans;
    }
};
