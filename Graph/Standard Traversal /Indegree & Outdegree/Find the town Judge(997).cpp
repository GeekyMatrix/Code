class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>v(n+1,0);
       for(auto i:trust){
      //OUTDEGREE
       v[i[0]]--;
        //INDEGREE
       v[i[1]]++;
       } 
       //CHECK( INDEGREE-OUTDEGREE=n-1)then it is a town judge
      for(int i=1;i<=n;i++){
        int value=v[i];
        if(value==n-1) return i;
      }
       return -1;
    }
};
