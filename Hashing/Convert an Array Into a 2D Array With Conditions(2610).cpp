class Solution {
public:
//Approach 1
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>res;
        unordered_map<int,int>mp;
         int Maxi = 0;

        for(auto &it : nums) mp[it]++;    //  Count the frequency of each element

        for(auto &i : mp)     Maxi = max(Maxi , i.second);  // Find the maximum frequency


        //Create the 2D array

        for(int i = 1; i <= Maxi; i++){
            vector<int>temp;

            for(auto x : mp){
                if(x.second >= i) temp.push_back(x.first);
            }
            res.push_back(temp);
        }
        return res;
    }

//Approach 2(Using frequency of elements)
//T.C : O(n)
//S.C : O(n)

    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>res;

        vector<int>mp(n+1,0); //Since 1 <= nums[i] <= nums.length (you can also use vector of size n)

       for(auto it: nums){
       
        int freq = mp[it];

       if(freq == res.size()) res.push_back({}); 

        res[freq].push_back(it); 
        mp[it]++;
       }
        return res;
    }
};
