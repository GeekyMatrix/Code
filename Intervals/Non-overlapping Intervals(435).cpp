class Solution {
public:
//Approach 1
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end()); //start time se sorted
         int n=intervals.size();
         int cnt=0;
         int i=0,j=1;
         
         while(j<n){
           vector<int>curr_interval=intervals[i];
            vector<int>new_interval=intervals[j];
           
           int cs=curr_interval[0];
           int ce=curr_interval[1];

           int ns=new_interval[0];
           int ne=new_interval[1];

           if(ce<=ns){ // No Overlapping
               i=j;
               j++;
           }
           else if(ce<=ne){ //Overlapping
               j++;
               cnt++;
           }
            else if(ce>ne){ //Overlapping
               i=j;
               j++;
               cnt++;
           }
         }
        return cnt;
    }

//Approach 2
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end()); //start time se sorted
         int n=intervals.size();
         int cnt=0;
         int i=1;
         vector<int>L=intervals[0];

         while(i<n){
           int curr_start=intervals[i][0];
           int curr_end=intervals[i][1];

           int last_end=L[1];

           if(curr_start>=last_end)    L=intervals[i];  // No Overlapping
           else if(curr_end>=last_end) cnt++;            //Overlapping
           else if(curr_end<last_end)  {                 //Overlapping
               L=intervals[i];  
               cnt++; 
           }
           
           i++;
         }
      return cnt;
    }
//Approach3
  static bool cmp(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
        
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int cnt=0;
           int i=0;

        for(int j=1;j<n;j++){
       
        if(intervals[i][1]>intervals[j][0])    cnt++;   //Overlapping
        
        else i=j; // No Overlapping
         }
         return cnt;
    }
};
