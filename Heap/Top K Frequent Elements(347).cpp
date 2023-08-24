class Solution {
public:
//Time complexity: O(N+N∗log(N)) for min priority queue  Time complexity: O(N+N∗log(K))
//Space complexity: O(N+K)

    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int>m;
    priority_queue<pair<int,int>>pq;
    vector<int>ans;
 
    for(auto i:nums) m[i]++;    //MAP mai insert karo
  
     for(auto i:m) pq.push({i.second,i.first});    //MAX priority queue mai insert karo as a pair form

     while(k--){
     ans.push_back(pq.top().second);
     pq.pop();
     }
      return ans;
    }

//T.C=O(n),S.C=O(n)
vector<int> topKFrequent(vector<int>& nums, int k) {
    int n=nums.size();
unordered_map<int,int>m;

    for(auto &i:nums) m[i]++; //MAP mai insert karo

vector<vector<int>>bucket(n+1);
//Index=freq
//value=Elements
//Bucket[i]=Elements having i frequency
 for(auto &i:m) bucket[i.second].push_back(i.first);

  vector<int>ans;
 for(int i=n;i>=0;i--){
     if(bucket[i].size()==0) continue;

     while(bucket[i].size()>0 && k>0) {
         ans.push_back(bucket[i].back());
         bucket[i].pop_back();
         k--;
     }
 }
 return ans;
}
};
