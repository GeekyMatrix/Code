void Preorder(BinaryTreeNode<int>*root){
if(root==NULL) return;
  
cout<<root->data<" ";
  Preorder(root->left);
  Preorder(root->right);
}
