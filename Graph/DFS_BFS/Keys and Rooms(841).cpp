class Solution {
public:
//Approach 1 (DFS)
bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();
    vector<bool> visited(n, 0);

    stack<int>st;
    st.push(0);
    visited[0] = true;

    while (!st.empty())
    {
        int curr = st.top();
        st.pop();

        for (auto element : rooms[curr])
        {
            if (!visited[element])
            {
                visited[element] = true;
                st.push(element);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

//Approach 2(BFS)
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        queue<int>q;
        vector<bool>visited(n,0);
        q.push(0);
       visited[0]=true;
       //MARKS THE ROOM WHICH WE HAVE KEYS
        while(!q.empty()){
            int front=q.front();
            q.pop();

            for(auto keys:rooms[front]){
                if(!visited[keys]){
                    visited[keys]=true;
                    q.push(keys);
                }
            }
        }
        //CHECK FOR WHICH ROOM IS NOT VISITED
        for(int i=0;i<n;i++){
            if(visited[i]==0) return false;
        }
        return true;
    }
};
