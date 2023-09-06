class Solution {
public:
int preIndex=0;
 TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int is,int ie){
 if(is>ie) return NULL;
 TreeNode* root=new TreeNode(postorder[preIndex]);
preIndex++;

int inIndex;
for(int i=is;i<=ie;i++){
   if(inorder[i]==root->val){
       inIndex=i;
       break;
   }
} 
root->left=solve(inorder,postorder,is,inIndex-1);
root->right=solve(inorder,postorder ,inIndex+1,ie);

return root;
 }
   
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         reverse(postorder.begin(),postorder.end());
        TreeNode* ans=solve(inorder,postorder,0,inorder.size()-1);
        return ans;
    }
};
