class Solution {
public:
//DFS
unordered_map<int,vector<int>>adj;
    int maxTime=0;
    
    void dfs(int curr_Employee,vector<int>&informTime,int curr_Time){
        maxTime=max(maxTime,curr_Time);

        for(auto employee:adj[curr_Employee]){
         
            dfs(employee,informTime,curr_Time+informTime[curr_Employee]);
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
           // FILL umap
        for(int i=0;i<n;i++){
            int employee_i=i;
            int manager_i=manager[i];
            if(manager_i!=-1) adj[manager_i].push_back(employee_i);
        }
        dfs(headID,informTime,0);
        return maxTime;
    }

//BFS
unordered_map<int,vector<int>>adj;
    int maxTime=0;
    
    void bfs(int curr_Employee,vector<int>&informTime,int headID){
     
     queue<pair<int,int>>q;  //---->>>>>>> pair mai uss node ke liye time bhi hoga
      
      q.push({headID,0});

      while(!q.empty()){

    pair<int,int>temp=q.front();
    q.pop();

    int curr_Employee=temp.first;
    int curr_Time=temp.second;

     maxTime=max(maxTime,curr_Time);

      for(auto employee:adj[curr_Employee]){
        q.push({employee,curr_Time+informTime[curr_Employee]});
      }
      }

    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
           // FILL umap
        for(int i=0;i<n;i++){
            int employee_i=i;
            int manager_i=manager[i];
            if(manager_i!=-1) adj[manager_i].push_back(employee_i);
        }
        bfs(headID,informTime, headID);
        return maxTime;
    }
};
