class Solution {
public:
   vector<vector<int>>directions {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
       int n=maze.size();
       int m=maze[0].size();

       queue<pair<int,int>>q;
       q.push({entrance[0],entrance[1]});
         maze[entrance[0]][entrance[1]]='+'; //visited

         int steps=0;
        // bfs call
        while(!q.empty()){
            int size=q.size();
            while(size--){
         pair<int,int>p=q.front();
         q.pop();

         int i=p.first;
         int j=p.second;
        
        //Boundary reached or not
     if((p!=make_pair(entrance[0],entrance[1])) && (i==0||i==n-1||j==0||j==m-1)) return steps;
         
         //Neighbours explore
         for(auto &dir:directions){
             int new_i=i+dir[0];
             int new_j=j+dir[1];
             
            // Valid hoga toh traverse karo
             if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && maze[new_i][new_j]!='+'){
               q.push({new_i,new_j});
                maze[new_i][new_j]='+'; //visited
             }
         }
            }
            steps++;
        }
        return -1;
    }
};
