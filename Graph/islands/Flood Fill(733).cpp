class Solution {
public:
void dfs(vector<vector<int>>& image, int row, int col, int newcolor, int oldcolor){
  if(row >= image.size() || row < 0 || col >= image[0].size() || col < 0 || image[row][col] != oldcolor) return;
   
  image[row][col] = newcolor; //Mark
  
  //Explore
  dfs(image, row+1, col, newcolor,oldcolor);
  dfs(image, row-1, col, newcolor,oldcolor);
  dfs(image, row, col+1, newcolor,oldcolor);
  dfs(image, row, col-1, newcolor,oldcolor);

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       if(image[sr][sc] == color) return image;
        int oldcolor = image[sr][sc];
        dfs(image, sr, sc, color, oldcolor);
        return image;
    }
};
