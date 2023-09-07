class Solution {
public:
//1ST APPROACH
bool findpath(TreeNode* root, vector<TreeNode*>&path,TreeNode* n){
  if(root==NULL) return false;
  path.push_back(root);
  if(root==n) return true;

  if(findpath(root->left,path,n) || findpath(root->right,path,n)) return true;

  path.pop_back();
  return false;
}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1,path2;
        if(!findpath(root,path1,p) || !findpath(root,path2,q)) return NULL;

         TreeNode* ans=NULL;
         for(int i=0;i<path1.size() && i<path2.size();i++){
             if(path1[i]==path2[i]) ans=path2[i];
         }
         return ans;
    }

//2ND APPROACH
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //BASE CASE
if(root==NULL) return NULL;
//If it is same as p and other q
if(root==p || root==q) return root;

//If one of its subtree contains p and other contains q
 TreeNode* LCA1=lowestCommonAncestor(root->left,p,q);
 TreeNode* LCA2=lowestCommonAncestor(root->right,p,q);

//If anyone of its subtree contains both p and q
if(LCA1!=NULL && LCA2!=NULL) return root;

if(LCA1!=NULL) return LCA1;

return LCA2;
}
};
