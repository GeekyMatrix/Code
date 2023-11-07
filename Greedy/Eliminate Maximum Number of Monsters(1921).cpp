class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int>time(n);
        
       for(int i = 0; i < n; i++)  time[i] = ceil((float)dist[i] / speed[i]);
       sort(time.begin() , time.end()); //choose sort bcz that monster reach the city ist

int cnt = 1 , time_passed = 1; // bcz at the starting time gun is fully charged it will kill ist monster

    for(int i = 1; i < n; i++){
    if(time[i] - time_passed <=0 ) return cnt; // monster reaches the city

       cnt++;           // how much monster killed
       time_passed++;   // how much time_passed

       }
     return cnt;
    }
};
