void inorder(BinaryTreeNode<int> *root,vector<int>&in){
if(root==NULL) return ;

  inorder(root->left,in);
  in.push_back(root->data);
  inorder(root->right,in);
}
TreeNode<int> *inorderToBST(int s,int e,vector,int>in){
  //Base case
  if(s>e) return NULL;

  int mid=(s+e)/2;

  TreeNode<int>*root=new treeNode<int>(in[mid]);
  root->left=inorderToBST(s,mid-1,in);
  root->right=inorderToBST(mid+1,e,in);
  
 return root;
}

TreeNode<int>*balancedBst(TreeNode<int>*root){
vector<int>inorderval;
  //store inorder ->sorted values
  inorder(root,inorderval);
  
return inorderToBST(0,inorder.size()-1,inorderval);
}
