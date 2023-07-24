class Solution{
    public:
    void createMapping(int in[], map<int,int> &nodeToindex,int n){
        for(int i=0;i<n;i++){
            nodeToindex[in[i]]=i;
        }
    }

    Node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n,map<int,int>&nodeToindex){
        
        //BASE CASE
        if(index>=n || inorderStart>inorderEnd) return NULL;
        
        int element=pre[index++];
        Node* root=new Node(element);
        int position=nodeToindex[element];
        
        //Recursive calls
        root->left=solve(in,pre,index,inorderStart,position-1,n,nodeToindex);
        root->right=solve(in,pre,index,position+1,inorderEnd,n,nodeToindex);
        
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preorderIndex=0;
        map<int,int>nodeToindex;
        //create node to index mapping
        createMapping(in,nodeToindex,n);
        Node *ans=solve(in,pre,preorderIndex,0,n-1,n,nodeToindex);
        return ans;
    }
};
