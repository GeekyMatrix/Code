bool SearchInBst(Binary TreeNode<int>*root,int k){
if(root==NUL_ return false;

  if(root->data==k) return true;

  else if(k<root->data) return SearchInBst(root->left,k);

  else return SearchInBst(root->right,k);
}
