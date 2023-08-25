 bool topologicalSortCheck(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree) {
        queue<int> que;
//1.0 indegree wale ko push kardo
       for(int i = 0; i<n; i++) {
            if(indegree[i] == 0)  que.push(i);
        }

//2.Do bfs
     int count = 0;

    while(!que.empty()){
     int front=que.front();
      que.pop();

//3.count ko increment kardo
      count++;

      for(auto &neighbour:adj[front]){
      indegree[neighbour]--;

        if( indegree[neighbour]==0)   que.push( neighbour);
        
      }
    }

     if(count == n) //I was able to visit all nodes (course)
            return true; //i.e. I was able to finish all courses
        
        return false; //means there was a cycle and I couldn't complete all courses
    }

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
    //MAKING ADJACENT LIST
       unordered_map<int, vector<int>> adj;
       
       vector<int> indegree(n, 0); //kahn's algo

        for(auto x:prerequisites){
        vector<int>data=x;
        int a=data[0];
        int b=data[1];
        //b---->a
        adj[b].push_back(a);

          //arrow ja raha hai 'a' me
            indegree[a]++;
        }
         //if cycle is present, not possible   
        return topologicalSortCheck(adj, numCourses, indegree);
        } 

};
