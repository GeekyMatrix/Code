// visited[node]== true && dfsvisited[node]==true; ------> mtlb cycle present hai

class Solution {
  public:
    
    bool isCycleDFS(vector<int> adj[], int node, vector<bool>& visited, vector<bool>& dfsVisited) {
        visited[node] = true;
       dfsVisited[node] = true;
        
        
        for(int &neighbour : adj[node]) {
            //if not visited, then we check for cycle in DFS
            if(visited[neighbour] == false && isCycleDFS(adj, neighbour, visited, dfsVisited))
                return true;
            else if(dfsVisited[neighbour] == true)
                return true;
        }
        
       dfsVisited[node] = false;
        return false;
        
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> dfsVisited(V, false);
        
        for(int i = 0; i<V; i++) {
            if(!visited[i] && isCycleDFS(adj, i, visited, dfsVisited))
                return true;
        }
        
        return false;
    }
};
