class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>>m;
        vector<vector<int>>res;

        for(int i = 0;i<groupSizes.size();i++)  {
            int L=groupSizes[i];
          m[L].push_back(i);
          
          if(m[L].size() == L){
              res.push_back(m[L]);
              m[L].clear();
          }
        }
        return res;
    }
};
