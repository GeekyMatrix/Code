class Solution {
public:
int m , n;
int res;
int Non_obstacles_cnt;

vector<vector<int>>directions{{1,0}, {-1,0}, {0,1}, {0,-1}};

void BackTrack(vector<vector<int>>& grid, int cnt, int i, int j){
    if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) return; //Boundary condition

    if(grid[i][j] == 2){
       if(cnt == Non_obstacles_cnt) res++;  //Reach the Ending square
        return;
    }

    grid[i][j] = -1; //Mark visited

    for(vector<int> &dir : directions){
        int new_i = i + dir[0];
        int new_j = j + dir[1];

        BackTrack(grid, cnt + 1, new_i, new_j);
    }
    grid[i][j] = 0; //Backtrack krdo
}

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        Non_obstacles_cnt = 1;
         int start_x = 0, start_y = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == 1){
                    start_x = i;
                    start_y = j;
                }
                if(grid[i][j] == 0) Non_obstacles_cnt++;
            }
        }
         BackTrack(grid, 0, start_x, start_y);

         return res;
    }
};
