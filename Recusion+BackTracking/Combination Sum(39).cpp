class Solution {
public:
void solve(int sumtillnow,int index,int target,vector<int>& candidates,vector<int> output,vector<vector<int>>&ans){

 //BASE CASE
 if(sumtillnow == target) {
     ans.push_back(output);
     return;
 }
 if(sumtillnow >target) return;
 if(index >=candidates.size()) return;

 //TAKE THE ELEMENT
 output.push_back(candidates[index]);
 sumtillnow +=candidates[index];
 solve(sumtillnow,index,target,candidates,output,ans);

 //BACKTRACK
 sumtillnow -=candidates[index];
 output.pop_back();
 solve(sumtillnow,index+1,target,candidates,output,ans);
  }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>output;
        solve(0,0,target,candidates,output,ans);
        return ans;
    }
};
