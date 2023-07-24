void createMapping(int in[], map<int,int> &nodeToindex,int n){
        for(int i=0;i<n;i++){
            nodeToindex[in[i]]=i;
        }
    }
    
     Node* solve(int in[],int post[],int &index,int inorderStart,int inorderEnd,int n,map<int,int>&nodeToindex){
        
        //BASE CASE
        if(index<0 || inorderStart>inorderEnd) return NULL;
        
        int element=post[index--];
        Node* root=new Node(element);
        int position=nodeToindex[element];
        
        //Recursive calls
        root->right=solve(in,post,index,position+1,inorderEnd,n,nodeToindex);
        root->left=solve(in,post,index,inorderStart,position-1,n,nodeToindex);
        
        return root;
        
    }
Node *buildTree(int in[], int post[], int n) {
    // Your code here
     int postorderIndex=n-1;
        map<int,int>nodeToindex;
        //create node to index mapping
        createMapping(in,nodeToindex,n);
        Node *ans=solve(in,post,postorderIndex,0,n-1,n,nodeToindex);
        return ans;
}
