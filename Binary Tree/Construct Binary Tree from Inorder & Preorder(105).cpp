//Approach 1
class Solution {
public:
int preIndex=0;
 TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int is,int ie){
 if(is>ie) return NULL;
 TreeNode* root=new TreeNode(preorder[preIndex]);
preIndex++;

int inIndex;
for(int i=is;i<=ie;i++){
   if(inorder[i]==root->val){
       inIndex=i;
       break;
   }
}
root->left=solve(preorder,inorder,is,inIndex-1);
root->right=solve(preorder,inorder,inIndex+1,ie);

return root;
 }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* ans=solve(preorder,inorder,0,inorder.size()-1);
        return ans;
    }
};
//Approach 2
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
