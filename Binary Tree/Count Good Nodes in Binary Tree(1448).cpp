class Solution {
public:
 int cnt = 0;
 void valid(TreeNode* root,int curr){
     if(root ==NULL) return;

     if(root->val >= curr) {
         cnt++;
         curr = root->val;
     }
    valid(root->left, curr);
    valid(root->right, curr);
 }
    int goodNodes(TreeNode* root) {
        valid(root, root->val);
        return cnt;
    }
};
