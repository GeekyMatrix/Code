class Solution {
public:
//RECURSIVE METHOD
  void helper(TreeNode* root, vector<int>&ans){
      if(!root) return;
      helper(root->left,ans);
      helper(root->right,ans);
      ans.push_back(root->val);
  }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        helper(root,ans);
        return ans;
    }

//ITERATIVE METHOD
 vector<int> postorderTraversal(TreeNode* root) {
      vector<int>ans;
       if(!root) return ans;
       stack<TreeNode*>s;
        s.push(root);
        
        while(!s.empty()){
            TreeNode* curr = s.top();
            if(curr->left){
                s.push(curr->left);
                curr->left = NULL;
            }
            else{
                if(curr->right){
                    s.push(curr->right);
                    curr->right = NULL;
                }
                else{
                    ans.push_back(curr->val);
                    s.pop();
                }
            }
        }
        return ans;
 }
};
