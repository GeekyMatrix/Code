class Solution {
public:

//ITERATIVE METHOD
 bool isSymmetric(TreeNode* root) {
    if(!root) return true;

    queue<pair<TreeNode*, TreeNode*>>q;
    q.push(make_pair(root->left,root->right));

    while(!q.empty()){
        pair<TreeNode*, TreeNode*>top=q.front();
        q.pop();

        if(!top.first && !top.second) continue;
        if(!top.first || !top.second) return false;
        if(top.first->val !=top.second->val) return false;

        q.push(make_pair(top.first->left,top.second->right));
         q.push(make_pair(top.first->right,top.second->left));
    }
    return true;
    }

//RECUSIVE METHOD
   bool isequal(TreeNode* subroot1,TreeNode* subroot2){

  if((subroot1 && !subroot2) || (!subroot1 && subroot2)) return false;
   if(!subroot1 && !subroot2) return true;
   if(subroot1->val==subroot2->val) {
       return isequal(subroot1->left,subroot2->right) && isequal(subroot1->right,subroot2->left);
   }
   else return false;
   }

    bool isSymmetric(TreeNode* root) {
        return isequal(root->left,root->right);
    }
};
