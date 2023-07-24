void Postorder(BinaryTreeNode<int>*root){
if(root==NULL) retutn;

  Postorder(root->left);
  Postorder(root->right);
  cout<<root->data<<"";
  return;
}
