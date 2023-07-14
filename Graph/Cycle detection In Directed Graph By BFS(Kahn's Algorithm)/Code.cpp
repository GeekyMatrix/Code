class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int N, vector<int> adj[]) {
        queue<int> que;
	    vector<int> indegree(N, 0);
	    int count = 0;
	    //1 Sbka indegree find karo
	    for(int u = 0; u<N; u++) {
	        for(int &v : adj[u]) {
	            indegree[v]++;
	        }
	    }
	    
	    //2. Fill que, indegree with 0
	    for(int i = 0; i<N; i++) {
	        if(indegree[i] == 0) {
	            que.push(i);
	            count++;
	        }
	    }
	    
	    //3. Simple BFS
	    while(!que.empty()) {
	        int front = que.front();
	        que.pop();
	        
	        for(int &neighbour : adj[front]) {
	            indegree[neighbour]--;
	            
	            if(indegree[neighbour] == 0) {
	                que.push(neighbour);
	                count++;
	            }
	            
	        }
	    }
	    
	    return count != N;
    }
};
