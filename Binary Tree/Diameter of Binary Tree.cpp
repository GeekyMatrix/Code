class Solution {
public:
//Approach 1
   int height(TreeNode* root){
            if(root==NULL) return 0;
            return 1+max(height(root->left),height(root->right));
        }
    int diameterOfBinaryTree(TreeNode* root) {
      
            if(root==NULL) return 0;
         
         int option1=height(root->left)+height(root->right);
         int option2=diameterOfBinaryTree(root->left);
         int option3=diameterOfBinaryTree(root->right);

        return max(option1,max(option2,option3));
    }

//Approach 2
 int res=0;
        int height(TreeNode* root){
            if(root==NULL) return 0;
            int lh=height(root->left);
            int rh=height(root->right);
            res=max(res, 1+lh+rh);

            return 1+max(lh,rh);
        }

  int diameterOfBinaryTree(TreeNode* root) {
   int data=height(root);
   return res-1;
  }

//Approach 3
 pair<int,int>diameterfast(TreeNode* root){ //ist->diameter , 2nd->height

//Base Case
if(root==NULL){
    pair<int,int>p=make_pair(0,0);
    return p;
}
pair<int,int>left=diameterfast(root->left);
pair<int,int>right=diameterfast(root->right);

 int option1=left.first;
 int option2=right.first;
 int option3= left.second+right.second;

  pair<int,int>ans;
  ans.first=max(option1,max(option2,option3));
  ans.second=max(left.second,right.second)+1;
  return ans;
 }
 
 int diameterOfBinaryTree(TreeNode* root) {
  return diameterfast(root).first;
 }
};
