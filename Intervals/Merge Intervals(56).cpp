class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();

        vector<vector<int>>ans;
        for(int i=0;i<n;i++){

            //Ist time visit kiye ho ya next ki value bdi ho
            if(ans.empty() || ans.back()[1]<intervals[i][0]) ans.push_back(intervals[i]);

            //pehle se kuch hoga toh update krdo
            else{
             //overlapping
               ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};
