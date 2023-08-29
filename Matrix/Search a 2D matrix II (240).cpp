class Solution {
public:
// //TC-O(n*m)
// //SC:O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

            for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==target)return true;
            }
        }
        return false;
    }

//TC-O(n*logm)
//SC:O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

            for(int i=0; i<n; i++){
                int s=0,e=m-1;

                while(s<=e){
              int mid = s+(e-s)/2;

                if(matrix[i][mid]==target)return true;
                else if(matrix[i][mid]>target) e=mid-1 ;
                else s=mid+1;
            }
        }
        return false;
    }


//TC-O(n+m)
//SC:O(1)
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

};
