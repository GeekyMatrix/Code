class Solution {
public:
//TC-o(n+m)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int i=0,j=m-1;
        while(i>=0 && i<n && j>=0 && j<m){
        if(matrix[i][j]==target) return true;
        else if(matrix[i][j]> target) j--;
         else if(matrix[i][j]< target) i++;
        }
        return false;
    }

//TC-O(log(m * n)) ,//Binary search
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int n = matrix.size();
        int m = matrix[0].size();
        
        int start = 0;
        int end   = m*n-1;
        
        while(start <= end) {
            int mid = start + (end-start)/2;
            
            int row = mid/m;
            int col = mid%m;
            
            if(matrix[row][col] > target) {
                end = mid-1;
            } else if(matrix[row][col] < target) {
                start = mid+1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};
