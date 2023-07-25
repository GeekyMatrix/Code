// Ques:- Given a BST &two integers k1&k2 ,find and print the elements which are in Range k1&k2(both inclusive)

void elemenstInRange(BinaryTreeNode<int>*root,int k1,int k2){
 if(root==NULL)return;

  if(k1<root->data) elemenstInRange(root->left,k1,k2);
   
   if(root->data >=k1 && root->data<=k2) cout<<root->data<<" ";

  if(root->data<k2)  elemenstInRange(root->right,k1,k2);

}
