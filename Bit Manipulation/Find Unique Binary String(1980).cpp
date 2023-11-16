class Solution {
public:
//TC = O(n ^ 2)
//SC = O(n) 
    string findDifferentBinaryString(vector<string>& nums) {
        
        unordered_set<int>st;
        
        for(string &num : nums) st.insert(stoi(num , 0 , 2)); // iss Binary se decimal mai convert hoga
        
        int n = nums.size();
        
        string res = "";

        for(int number = 0; number <= n; number++){  // 2^n - 1 == 65235
          if(st.find(number) == st.end()){
              res = bitset<16>(number).to_string(); // ye Binary mai convert krega 
              
              return res.substr(16 - n , n); // n length ka binary dega
          }
        }
        return "";
    }

//Approach 2
//T.C : O(n)
//S.C : O(1)
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        
        string res = "";

        for(int i = 0; i < n; i++){
           char ch = nums[i][i];

           res += (ch == '0') ? "1" : "0";
        }
        return res;
    }
};
