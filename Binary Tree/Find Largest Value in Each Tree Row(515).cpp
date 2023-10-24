class Solution {
public:
//BFS
    vector<int> largestValues(TreeNode* root) {
         vector<int>res;
        if(root == NULL) return res;

         queue<TreeNode*>q;
         q.push(root);

         while(!q.empty()){
             int n = q.size();
            int maxi = INT_MIN;

             while(n--){
             TreeNode* front = q.front();
             q.pop();
            
            maxi = max(maxi , front->val);

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
             }
             res.push_back(maxi);
         }
         return res;
    }

//DFS
void Solve(int row, TreeNode* node, vector<int>&res){
 if(!node) return; //BASE CASE
 
 if(row >= res.size()) res.push_back(node->val);

 else res[row] = max(res[row] , node->val);

  Solve(row + 1 , node->left , res);
  Solve(row + 1 , node->right , res);

}

vector<int> largestValues(TreeNode* root) {
 vector<int>res;
 Solve( 0 , root , res);
 return res;
}
};
