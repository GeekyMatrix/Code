class Solution {
public:
//BRUTE FORCE 
//TC=O(N^2)
//SC=O(1)

 int majorityElement(vector<int>& arr) {
 int n=arr.size();

 for(int i=0;i<n;i++){
     //Take one Element from Array (say,Element)
     int ele=arr[i];
     int cnt=0;

     for(int j=0;j<n;j++){
         if(arr[j]==ele) cnt++;
     }
     if(cnt>n/2)  return arr[i]; 
 }
  return -1;
 }

//Optimise method (moore's Voting algorithm)
 //TC=O(N)
 //SC=O(1)
    int majorityElement(vector<int>& nums) {
         int ele=arr[0];
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(count==0)ele=arr[i];
            count+=(ele==arr[i])?1:-1;
        }
        return ele;
    }
};
