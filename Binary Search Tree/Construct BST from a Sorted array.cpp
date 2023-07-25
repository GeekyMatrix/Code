TreeNode<int> *helper(int *input,int s,int e){
  //Base case
  if(s>e) return NULL;

  int mid=(s+e)/2;

  TreeNode<int>*root=new treeNode<int>(input[mid]);
  root->left=inorderToBST(input,s,mid-1);
  root->right=inorderToBST(input,mid+1,e);
  
 return root;
}

BinaryTreeNode<int>8constructTree(int *input,int n){

return helper(input,0,n-1);
}
