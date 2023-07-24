void PrintLevelwise(Binary TreeNode<int>*root){
//Edge case 
  if(root==NULL) return;

  queue<Binary TreeNode<int>*>q;
  q.push(root);

  while(q.size()){
   Binary TreeNode<int>*front=q.front();
    q.pop();
   cout<<front->data<<":";

    if(front->left){
   cout<<"L:" front->left->data<<",";
      q.push(front->left);
    }
   else{
      cout<<"L:"<<"-1";
   }
  if(front->right){
  cout<<"R:"<<front->right->data;
    q.push(front->data);
  }
 else{
     cout<<"R:"<<-1;
 }
 cout<<endl;
  }
}
