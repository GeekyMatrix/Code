class Solution {
public:
 typedef pair<int,int>P;
 
 int find(vector<int>&row){ //find the Solider in each row
     int s = 0, e = row.size()-1;

     while(s<=e){
       int mid = (s + e)/2;
       if(row[mid] == 1) s = mid+1;
       else e = mid - 1;
     }
     return s;
 }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<P, vector<P> , greater<P>> pq;

        for(int i = 0; i < mat.size(); i++){ 
         int solider_cnt = find(mat[i]);
         pq.push({solider_cnt,i});
        }
      
      vector<int> res;
      while(k--){
          res.push_back(pq.top().second);
          pq.pop();
      }
        return res;
    }
};
