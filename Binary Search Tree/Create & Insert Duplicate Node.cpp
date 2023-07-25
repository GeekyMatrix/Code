void insertDuplicateNode(BinaryTreeNode<int>*root){

  if(root==NULL) return ;

  BinaryTreeNode<int>*newNode=new BinaryTreeNode<int>(root->data);

   BinaryTreeNode<int>*saveleft=root->left;

  root->left=newNode;
  newNode->left=saveleft;

  insertDuplicateNode(root->left);
  insertDuplicateNode(root->right);
}
