class Solution {
public:
//Recursive 
int n;
bool solve(vector<int>& nums,int i){

if(i>=n) return true;

bool result=false;

//Rule 1
if(i+1<n && nums[i]==nums[i+1]) {
    result|=solve(nums,i+2);
}

//Rule 2
if(i+2 <n && nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
    result|=solve(nums,i+3);
}


//Rule 3
if(i+2<n && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1 ){
    result|=solve(nums,i+3);
}
   return result;
}
    bool validPartition(vector<int>& nums) {
       n=nums.size();

        return solve(nums,0);
    }

//Memoization
int t[100001];
int n;
bool solve(vector<int>& nums,int i){

if(i>=n) return true;

if(t[i]!=-1) return t[i];

bool result=false;

//Rule 1
if(i+1<n && nums[i]==nums[i+1]) {
    result|=solve(nums,i+2);
}

//Rule 2
if(i+2 <n && nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
    result|=solve(nums,i+3);
}


//Rule 3
if(i+2<n && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1 ){
    result|=solve(nums,i+3);
}
   return t[i]=result;
}
    bool validPartition(vector<int>& nums) {
       n=nums.size();
      memset(t,-1,sizeof(t));
        return solve(nums,0);
    }
};
