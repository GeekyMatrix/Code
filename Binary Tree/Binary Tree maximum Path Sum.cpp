class Solution {
public:
int maxSum;

 int solve(TreeNode* root){
  if(root==NULL) return NULL;

  int l=solve(root->left);
  int r=solve(root->right);

  int niche_hi_milgaya_answer=l+r+root->val;

  int koi_ek_acha_hai=max(l,r)+root->val;

  int only_root_acha=root->val;

  maxSum=max({maxSum,niche_hi_milgaya_answer,koi_ek_acha_hai,only_root_acha});

  return max(koi_ek_acha_hai, only_root_acha); //Most imp.
 }
 
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;
        
    }
};
