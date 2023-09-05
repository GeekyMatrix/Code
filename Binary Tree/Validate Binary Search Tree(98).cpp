class Solution {
public:
  bool solve(TreeNode* root,long min,long max){
    //base case
      if(!root) return true;

      if(root->val >min && root->val <max){
      bool left =solve(root->left, min, root->val);
      bool right =solve(root->right, root->val, max);
      return left && right;
      }
     else return false;
  }

    bool isValidBST(TreeNode* root) {
       return solve(root,LONG_MIN, LONG_MAX);
    }
};
