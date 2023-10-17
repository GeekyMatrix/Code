class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int , int>child_to_parent;

        for(int i = 0; i < n; i++){
            int node  = i;
            int leftC = leftChild[i];
            int rightC = rightChild[i];

            if(leftC !=-1){
                adj[i].push_back(leftC);

                if(child_to_parent.find(leftC) != child_to_parent.end()) return false; //Already present hai

                child_to_parent[leftC] = node;
            }
           
                if(rightC !=-1){
                adj[i].push_back(rightC);

                if(child_to_parent.find(rightC) != child_to_parent.end()) return false; //Already present hai

                child_to_parent[rightC] = node;
            }
        }

       int root = -1;

       for(int i = 0; i < n; i++){
           if(child_to_parent.find(i) == child_to_parent.end()){
               if(root != -1) return false;

               root = i;
           }
       }
       if(root == -1) return false;

       //Write Normal BFS/DFS
       int count = 0;
       queue<int>que;
       vector<bool>visited(n , false);

       que.push(root);
       count = 1;
       visited[root] = true;

       while(!que.empty()){
           int node = que.front();
           que.pop();

           for(int &v : adj[node]){
               if(!visited[v]){
                   visited[v] = true;
                   count++;
                   que.push(v);
               }
           }
       }
        return count == n;
    }
};
