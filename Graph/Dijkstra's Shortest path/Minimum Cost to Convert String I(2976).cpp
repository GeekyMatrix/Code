class Solution {
public:
typedef pair<int,int>p;
void Dijkstras(unordered_map<char, vector<pair<char, int>>>& adj, char source, vector<vector<int>>& distance) {

  priority_queue<p, vector<p>, greater<p>>pq;
  pq.push({source,0}); 

 while(!pq.empty()){
     char node = pq.top().first;
     int d = pq.top().second;
     pq.pop();

 // Iterate through the neighbors of the current node
     for(auto &it : adj[node]){
         char adjNode = it.first;
         int dist = it.second;

         if(d + dist < distance[source - 'a'][adjNode - 'a']){
             distance[source - 'a'][adjNode - 'a'] = d + dist;
             pq.push({adjNode, d+ dist});
         }
     }
 }
}
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        //Make Adjacency list

        unordered_map<char,vector<pair<char, int>>>adj;

        for(int i = 0; i < original.size(); i++) adj[original[i]].push_back({changed[i], cost[i]}); //a--(b,dist)

        long long ans = 0; 
        vector<vector<int>>distance(26,vector<int>(26,INT_MAX)); // u-->{v,w}
        //Use Dijkstras
        
        for(auto it : original){
           Dijkstras(adj, it, distance);
        }
    
      // Calculate the total cost of transforming 'source' to 'target'
        for (int i = 0; i < source.size(); i++) {

        if(source[i] == target[i]) continue;  // If characters are the same, no cost is incurred

        if(distance[source[i] - 'a'][target[i] - 'a'] == INT_MAX) return -1; //Impossible

        else ans+= distance[source[i] - 'a'][target[i] - 'a'];
    }
     return ans;
    }
};
