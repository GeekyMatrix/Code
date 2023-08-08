class Solution {
public:
//LIS Approach
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int>LIS(n,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(obstacles[j]<=obstacles[i]){
                    LIS[i]=max(LIS[i],LIS[j]+1);
                }
            }
        }
        return LIS;
    }
//Optimise Approach
       vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int>LIS;
        vector<int>result(n);

        for(int i=0;i<n;i++){
             int index=upper_bound(LIS.begin(),LIS.end(),obstacles[i])-LIS.begin();

            if(index==LIS.size()) LIS.push_back(obstacles[i]);

            else{
            LIS[index]=obstacles[i];
            //index+1=length of subsequence
            //Ending element obstacle[i]
            }
              result[i]=index+1;
            }
        return result;
    }
};
