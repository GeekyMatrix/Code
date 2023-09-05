class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
          vector<vector<int>>ans;
          int n;
          if(!root) return {};
          queue<TreeNode*>pendingnodes;
          pendingnodes.push(root);

          while(!pendingnodes.empty()){
           n=pendingnodes.size(); 
           vector<int>temp;
           while(n--){
              TreeNode*front=pendingnodes.front();
              pendingnodes.pop();
              temp.push_back(front->val);

              if(front->left)  pendingnodes.push(front->left);
              if(front->right)  pendingnodes.push(front->right);
           }
           ans.push_back(temp);
          }

       return ans;
    }
};
