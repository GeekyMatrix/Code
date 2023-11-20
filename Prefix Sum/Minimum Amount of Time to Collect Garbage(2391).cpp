class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time = 0;

     int n = garbage.size();
        int G_idx = 0;
        int M_idx = 0;
        int p_idx = 0;
    
      for(int i = 0; i < n; i++){ // specific garbage index kha tk hai
          for(int j = 0; j < garbage[i].length(); j++){
              if(garbage[i][j] == 'M') M_idx = i;
              else if(garbage[i][j] == 'P')  p_idx = i;
              else G_idx = i;

              time++; // for Picking up one unit of any type of garbage takes 1 minute
          }
      }

        for(int i = 1; i < travel.size(); i++) travel[i]+=travel[i- 1]; // prefix Sum

        time+= G_idx > 0 ? travel[G_idx - 1] : 0; // time taken to travel house for G truck
        time+= M_idx > 0 ? travel[M_idx - 1] : 0; // time taken to travel house for M truck
        time+= p_idx > 0 ? travel[p_idx - 1] : 0; // time taken to travel house for P truck

        return time;
    }
};
