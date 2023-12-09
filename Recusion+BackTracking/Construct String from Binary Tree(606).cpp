class Solution {
public:
    string tree2str(TreeNode* root) {
        if(!root) return "";
       
       string res = to_string(root->val);
       string l = tree2str(root->left);
       string r = tree2str(root->right);

       if(!root->left && !root->right) return res;

       if(!root->left) return res + "()" + "(" + r + ")"; 
        
      if(!root->right) return res + "(" + l + ")";

      return res + "(" + l + ")" + "(" + r + ")"; 

    }
};
