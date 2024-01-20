class Solution {
public:
int Solve(TreeNode* root , int &moves){
    if(!root) return 0;
    
    int leftChild = Solve(root->left , moves);
    int rightChild = Solve(root->right , moves);
    
    moves += abs(leftChild) + abs(rightChild);
    
    return root->val - 1 + leftChild + rightChild;
}
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        Solve(root , moves);
        return moves;
    }
};
