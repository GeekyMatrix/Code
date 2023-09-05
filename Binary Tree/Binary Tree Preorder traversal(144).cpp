class Solution {
public:
//RECURSIVE METHOD
    void helper(TreeNode* root,vector<int>&ans){
      if(!root) return;
       ans.push_back(root->val);
      helper(root->left,ans);
      helper(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int>ans;
       helper(root,ans);
        return ans;
    }

// ITEREATIVE METHOD
   vector<int> preorderTraversal(TreeNode* root) {
       vector<int>ans;
       if(!root) return ans;
       stack<TreeNode*>st;
       st.push(root);

       while(!st.empty()){
           root=st.top();
            st.pop();
           ans.push_back(root->val);

           if(root->right) st.push(root->right);
            if(root->left) st.push(root->left);
       }
        return ans;
    }
};
