class Solution {
public:
//RECURSIVE METHOD
   void inorder(TreeNode* root,vector<int>&ans){
      if(root == NULL) return; 
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
      inorder(root,ans);
     return ans;
    }

//ITERATIVE METHOD
 vector<int> inorderTraversal(TreeNode* root) {
       vector<int>ans;
       stack<TreeNode*>st;
       TreeNode* node=root;

  while(true){
        if(node !=NULL){
            st.push(node);
            node =node->left;
        }
        else{
            if(st.empty()) break;
            node=st.top();
            st.pop();
            ans.push_back(node->val);
            node =node->right;
        }
  }
        return ans;
 }
};
