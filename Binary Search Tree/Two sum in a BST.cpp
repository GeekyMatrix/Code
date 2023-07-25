void inorder(BinaryuTreeNode<int>*root,vector<int>&in){
if(root==NULL) return ;

  inorder(root->left,in);
  in.push_back(root->data);
  inorder(root->right,in);
}

bool twoSumInBST(BinaryuTreeNode<int>*root,int target){
vector<int>inoderval;
  //store inorder->sorted values
  inorder(root,inorder);
  //Use 2 pointer approach to check if pair exists
  int i=0,j=inorder.size()-1;

  while(i<j){
    int sum=inorderval[i]+inorderval[j];

    if(sum==target) return true;
    else if(sum>target) j--;
    else i++;

    return false;
}
