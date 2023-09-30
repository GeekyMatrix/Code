class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
         if(root == NULL) return NULL;
         //case 1:-
         if(key < root->val){//left side dekho
           root->left = deleteNode(root->left, key);
           return root;
         }

        // case 2:-
         else if(key > root->val){ //Right side dekho
             root->right = deleteNode(root->right, key);
             return root;
         }

         //case 3:-
         else{ //if key is same as the root key
        
        // condition 1:- koi child na ho
          if(root->left == NULL && root->right == NULL){ 
           delete root;
           return NULL;
          }

          // condition 2:- only right child ho
          else if(root->left == NULL){ 
            TreeNode*temp = root->right;
            root->right = NULL;
            delete root;
            return temp; 
          }

           // condition 3:- only left child ho
          else if(root->right == NULL){
              TreeNode*temp = root->left;
              root->left = NULL;
              delete root;
              return temp;
          }
          // condition 4:- Dono child ho then right side mai se sabse minm value ko root pr lga do
          else{
              TreeNode* minRoot = root->right;
              while(minRoot->left!=NULL) minRoot = minRoot->left;

               root->val = minRoot->val; //minRoot ko root pr lgya diya
              
 root->right = deleteNode(root->right, minRoot->val); //use minRoot ko delete bhi krna hoga right se
            
            return root;
          }
         }
    }
};
