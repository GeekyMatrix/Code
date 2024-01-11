class Solution {
public:
void store(TreeNode* curr, int parent, unordered_map<int,vector<int>>&adj){
 if(curr == nullptr) return; //BASE CASE

 if(parent != -1) adj[curr->val].push_back(parent);

 if(curr->left != nullptr) adj[curr->val].push_back(curr->left->val);

 if(curr->right != nullptr) adj[curr->val].push_back(curr->right->val);

 store(curr->left, curr->val, adj);
 store(curr->right, curr->val, adj);
}
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>adj;
        store(root, -1, adj); //Binary tree to undirected graph

        queue<int>q;
        q.push(start);
        unordered_set<int>visited;
        visited.insert(start);
        int mins = 0;

        while(!q.empty()){
             int n = q.size();

             while(n--){
                 int top = q.front();
                 q.pop();

                 for(auto &neighbour : adj[top]){
                     if(visited.find(neighbour) == visited.end()){ //if not visited
                        q.push(neighbour);
                        visited.insert(neighbour);
                     }
                 }
             }
         mins++;
        }
        return mins - 1;
    }
};
