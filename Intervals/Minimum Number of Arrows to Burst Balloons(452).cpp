class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
     int n =points.size();
     sort(points.begin(),points.end());
     int req_Arrows = 1; // for 0th ballon
     
      vector<int>prev = points[0];

     for(int j = 1; j < n; j++){

       int currStartPoint = points[j][0];
        int currEndPoint = points[j][1];

        int prevStartPoint = prev[0];
        int prevEndPoint =   prev[1];

        if(currStartPoint > prevEndPoint){   //Non Overlapping
         req_Arrows++;  //need one more arrow
         prev = points[j];
        }
        else{ // overlapping
           prev[0] = max(currStartPoint, prevStartPoint); //overlapping region
           prev[1] = min(currEndPoint, prevEndPoint);     //overlapping region
        }
     } 
      return req_Arrows;
    }
};
