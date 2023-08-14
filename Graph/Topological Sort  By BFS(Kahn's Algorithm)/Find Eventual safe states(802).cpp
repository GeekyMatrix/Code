vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

int V=graph.size();
vector<vector<int>>adj(V);
 queue<int> que;
 vector<int> indegree(V, 0);

//1.Reverse the Node
for(int u=0;u<V;u++){
    for(int &v:graph[u]){
        adj[v].push_back(u);
        indegree[u]++;
    }
}
    
	    //2. Fill que, indegree with 0
	    for(int i = 0; i<V; i++) {
	        if(indegree[i] == 0) {
	            que.push(i);
	        }
	    }
	    
	    //3. Simple BFS
        vector<bool>isSafe(V,false);

	    while(!que.empty()) {
	        int u = que.front();
	        que.pop();
	        isSafe[u]=true;

	        for(int &v : adj[u]) {
	            indegree[v]--;
	            
	            if(indegree[v] == 0) {
	                que.push(v);
	            }
	        }
	    }
	    vector<int>safenodes;

        for(int i=0;i<V;i++){
            if(isSafe[i]==true) safenodes.push_back(i);
        }

 return safenodes;
}
