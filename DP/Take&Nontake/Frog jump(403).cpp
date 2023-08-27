class Solution {
public:
//Recursion method
int n;
unordered_map<int,int>mp;

 bool solve(vector<int>& stones,int curr_stone_idx,int prevjump){
     if(curr_stone_idx ==n-1 ) return true;
     
     bool result=false;

     for(int nextjump=prevjump-1 ; nextjump <= prevjump+1 ; nextjump++){
       
       if(nextjump > 0){
         int next_stone = stones[curr_stone_idx] + nextjump;

         if(mp.find(next_stone)!=mp.end()){

             result=result || solve(stones,mp[next_stone],nextjump);
         }
       }
     }
     return result;
 }

    bool canCross(vector<int>& stones) {
        n=stones.size();
        
        if(stones[1]!=1) return false; // bcz 1st  jump will always be of 1 unit
        
        for(int i=0;i<n;i++) mp[stones[i]]=i;
        
        return solve(stones,0,0);
    }

//Memoization method
int n;
unordered_map<int,int>mp;
int t[2001] [2001];

 bool solve(vector<int>& stones,int curr_stone_idx,int prevjump){
     if(curr_stone_idx ==n-1 ) return true;
     
     if(t[ curr_stone_idx][ prevjump]!=-1) return t[ curr_stone_idx][ prevjump];
     bool result=false;

     for(int nextjump=prevjump-1 ; nextjump <= prevjump+1 ; nextjump++){
       
       if(nextjump > 0){
         int next_stone = stones[curr_stone_idx] + nextjump;

         if(mp.find(next_stone)!=mp.end()){

             result=result || solve(stones,mp[next_stone],nextjump);
         }
       }
     }
     return t[ curr_stone_idx][ prevjump] = result;
 }

    bool canCross(vector<int>& stones) {
        n=stones.size();
        memset(t,-1,sizeof(t));

        if(stones[1]!=1) return false; // bcz 1st  jump will always be of 1 unit
        
        for(int i=0;i<n;i++) mp[stones[i]]=i;
        
        return solve(stones,0,0);
    }
};
