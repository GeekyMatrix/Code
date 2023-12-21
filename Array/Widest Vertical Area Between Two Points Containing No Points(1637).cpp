class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n = points.size();
        
        int res = INT_MIN;
        for(int i = 1; i < n; i++)     res = max(res,points[i][0] - points[i-1][0]);
        
        return res;
    }
};
