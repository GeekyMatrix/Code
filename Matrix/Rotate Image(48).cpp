class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //FIND THE TRANSPOSE OF THE MATRIX
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
            // REVERSE THE TRANPOSE 
            for(auto &it:matrix) reverse(it.begin(),it.end());
    }
};
