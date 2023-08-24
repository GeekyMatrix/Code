class Solution {
public:
//BRUTE FORCE
//TC=O(N*N)
//SC=O(N)
int cnt;
bool linearSearch(vector<int>& arr,int num){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==num) return true;
    }
    return false;
}

 int longestConsecutive(vector<int>& nums) {
     int longest=0;
     int n=nums.size();

 for(int i=0;i<n;i++){
     int x=nums[i];
    cnt=1;

   while(linearSearch(nums,x+1)==true){
       cnt++;
       x++;
   }
   longest=max(longest,cnt);
 }
 return longest;
 }

//Better FORCE
//TC=O(n log n)
//SC=O(N)
 int longestConsecutive(vector<int>& nums) {
int n=nums.size();
if(n==0) return 0;
sort(nums.begin(),nums.end());
int longest=1;
 int cnt=0;
 int lastSmaller=INT_MIN;

 for(int i=0;i<n;i++){
     if(lastSmaller==nums[i]-1){
         cnt++;
          lastSmaller=nums[i];
     }
     else if(lastSmaller!=nums[i]){
         cnt=1;
          lastSmaller=nums[i];
     }
     longest=max(longest,cnt);
 }
  return longest;
 }
//OPTIMAL SPACE
//TC=O(N)
//SC=O(N)
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        for(int i=0;i<n;i++)     s.insert(nums[i]);
        
        int len=0;
        for(int i=0;i<n;i++){
            if(s.find(nums[i]-1)!=s.end()) continue;

            else{
                int count=0;
                int curr=nums[i];
                while(s.find(curr)!=s.end()){
                    count++;
                    curr++;
                }
                len=max(len,count);
            }
        }
        return len;
    }
};
