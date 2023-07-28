class Solution {
public:
//Aproach 1
   int t[23][23];
   int solve(int i,int j,vector<int>& nums){
     //BASE CASE
     if(i>j) return 0;
     if(i==j) return nums[i];
      
      if (t[i][j]!=-1) return t[i][j];

     int take_i=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));

     int take_j=nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums));

     return t[i][j]=max(take_i,take_j);
   }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        int total_score=accumulate(nums.begin(),nums.end(),0);
        
        int player1_score=solve(0,n-1,nums);

        int player2_score=total_score-player1_score;

        return player1_score>=player2_score;
    }
  
  //Approach2

   int t[23][23];
   int solve(vector<int>& nums,int i,int j){
     //BASE CASE
     if(i>j) return 0;
     if(i==j) return nums[i];
      
      if (t[i][j]!=-1) return t[i][j];

      int take_i=nums[i]-solve(nums,i+1,j);

      int take_j=nums[j]-solve(nums,i,j-1);

      return t[i][j]=max(take_i,take_j);

   }

   bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
    
        return solve(nums,0,n-1)>=0;
    }
};
