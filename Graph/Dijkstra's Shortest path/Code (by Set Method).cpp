vector<int>dijkstras(vector<vector<int>>&vec,int vertices,int edges,int source){

//1.CREATE ADJACENCY MATRIX
 unordered_map<int,list<pair<int,int>>>adj;

  for(int i=0;i<edges;i++){
   int u=vec[i][0];
    int v=vec[i][1];
    int w=vec[i][2];

    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
  }
  
 //2.Create dist vector with INT_MAX value
   vector<int>dist(vertices,INT_MAX);

//3.Creation of set on the basis (distance,node)
  set<pair<int,int>st;
//4.Initialise distance & set with source node
  dist[node]=0;
  st.insert(make_pair(0,source));

  while(st!.empty()){
    //fetch record
    auto top=*(st.begin());

    int nodeDistance=top.first;
    int topNode=top.second;

    //remove top record now
    st.erase(st.begin());

    //traverse on neighbours
    for(auto neighbour:adj[topNode]){
       if(nodeDistance+neighbour.second()<dist[neighbour.first]){
        auto record=st.find(make_pair(dist[neighbour],neighbour.first));
         
         //if record found then erase it
          if(record!=st.end()) st.erase(record);

         //distance update
         dist[neighbour.first]=nodeDistance+neighbour.second();

         //record push in set
         st.insert(make_pair(dist[neighbour.first],neighbour.first));
       }
    }
  }
        return dist;
  }












}
