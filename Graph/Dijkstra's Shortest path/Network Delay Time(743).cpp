class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       // 1.CREATE ADJACENCY LIST
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto &vec:times){
          int u=vec[0];
          int v=vec[1];
          int w=vec[2];

          adj[u].push_back({v,w});
        }

      //2.Initialise Pq
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

      //3.Initialsie shortest path vector
        vector<int>result(n+1,INT_MAX);
        result[k]=0;
        pq.push({0,k});

      //4.Do the rest work
        while(!pq.empty()){
      //5.fetch top data
          int d=pq.top().first;
          int node=pq.top().second;
          pq.pop();

      //6Visit the neighbours
          for(auto &vec:adj[node]){

              int adjNode=vec.first;
              int dist=vec.second;
              
     //7.Update the distance
              if(d+dist<result[adjNode]){
                    result[adjNode]=d+dist;
                     pq.push({d+dist, adjNode});
              }
          }
        }
        //Answer update
        int ans=INT_MIN;
        for(int i = 1; i <= n; i++)
            ans = max(ans, result[i]);
        
	return ans == INT_MAX ? -1 : ans;
    }
};
