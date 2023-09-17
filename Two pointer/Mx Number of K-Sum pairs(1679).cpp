class Solution {
public:
//Approach 1
//Time Complexity: O(n),Space Complexity: O(n)
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
       unordered_map<int,int>m;

    for(int i=0; i<nums.size(); i++){
        int diff = k-nums[i];

      if(m.find(diff)!=m.end()){ //pair mil jata hai 
        m[diff]--;
        count++;
        if(m[diff] == 0)m.erase(diff);
      }
      else m[nums[i]]++;
    }
        return count;
    }

//Approach 2
//Time Complexity: O(n*log(n)),Space Complexity: O(1)
int maxOperations(vector<int>& nums, int k) {
sort(nums.begin(),nums.end());
int count = 0;
int s = 0,e = nums.size()-1;

while(s < e){
  if(nums[s] + nums[e] == k){
    s++;
    e--;
    count++;
  }
  else if(nums[s] + nums[e] < k) s++;
  else  e--;
}
return count;
}
};
