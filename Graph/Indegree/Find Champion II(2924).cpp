class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n);
        int res;

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

              indegree[v]++; //u---->v
        }
         int cnt = 0;
        for(int i = 0 ; i < n ; i++){
          if(indegree[i] == 0) {
              cnt++;
              if(cnt > 1) return -1;
              res = i;
          }

        }
        return res;
    }
};
