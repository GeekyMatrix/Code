class Solution {
public:
//HEIGHT PAR LONGEST INCREASING SUBSEQUENCE FIND KARLO 
static bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
     return a[1] > b[1];
     return a[0] < b[0];
}
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        if(n==0) return 0;

        sort(envelopes.begin(),envelopes.end(),cmp); 

        vector<int>ans;
        ans.push_back(envelopes[0][1]);

        for(int i=1;i<n;i++){
    //AGAR AAGE BDA MIL RHA HAI TOH AAD KRTE JAO
    if(envelopes[i][1]>ans.back()) ans.push_back(envelopes[i][1]);
    else{
    //AGAR CHOTA MIL RHA HAI TOH ans ko change krro
    
    //Find index of just bdda element in ans
    int index=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
    ans[index]=envelopes[i][1];
    }
}
  return ans.size();
}
};
