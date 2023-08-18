class Solution {
public:
//Approach 1
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        //step 1:-Adjaceny list
        unordered_map<int,unordered_set<int>>adj;
        
         for(auto &road:roads){
            int u=road[0];
            int v=road[1];

            adj[u].insert(v);
            adj[v].insert(u);
         }
        // step2:- Each road ke liye connected find karo
        int max_Rank=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                int i_rank=adj[i].size();
                int j_rank=adj[j].size();

                int total_rank=i_rank+j_rank;
                
                if(adj[i].find(j)!=adj[i].end()) total_rank--;

                max_Rank=max(max_Rank,total_rank);
            }
        }
        return  max_Rank;
    }

//Approach 2
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>degree(n,0);
        
        vector<vector<bool>>connected(n,vector<bool>(n,false));
  
        
         for(auto &road:roads){
            int u=road[0];
            int v=road[1];

            degree[u]++;
            degree[v]++;

            connected[u][v]=true;
            connected[v][u]=true;
         }
        // step2:- Each road ke liye connected degree find karo
        int max_Rank=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                int i_rank=degree[i];
                int j_rank=degree[j];

                int total_rank=i_rank+j_rank;
                
                if(connected[i][j]) total_rank--;

                max_Rank=max(max_Rank,total_rank);
            }
        }
        return  max_Rank;
    }
};
