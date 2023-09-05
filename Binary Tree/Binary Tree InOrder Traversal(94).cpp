class Solution {
public:
//RECURSIVE METHOD
   void inorder(TreeNode* root,vector<int>&ans){
      if(root==NULL) return; 
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
       if(!root) return ans;
       stack<TreeNode*>st;
       TreeNode* temp=root;
    while(!st.empty()||temp){
        while(temp){
            st.push(temp);
            temp=temp->left;
        }
        temp=st.top();
        ans.push_back(st.top()->val);
        st.pop();
        temp=temp->right;
    }
        return ans;
 }
};
