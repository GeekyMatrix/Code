//comment kiya hua wala cycle wala part hai

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int N, vector<int> adj[]) {
        queue<int> que;
	    vector<int> indegree(N, 0);
	    
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
	        }
	    }
	    
	    //3. Simple BFS
      vector<int>ans;   //  int count = 0;
	    while(!que.empty()) {
	        int front = que.front();
	        que.pop();

        //ANSWER STORE KARLO
        ans.push_back(front);   //count++;
        
	        for(int &neighbour : adj[front]) {
	            indegree[neighbour]--;
	            
	            if(indegree[neighbour] == 0) {
	                que.push(neighbour);
	            }
	            
	        }
	    }
	    return ans;   //if(count==n) return false ,else return true 
    }
};
