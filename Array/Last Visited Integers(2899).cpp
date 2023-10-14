class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int>res;
        vector<int>val;
        int cnt = 0;
        
        for(string word : words){
            if(word == "prev"){
                cnt++;
                
                if(cnt > val.size()) res.push_back(-1);
                
                else res.push_back(val[val.size() - cnt ]);
            }
            else { // For number
                cnt = 0;
                 val.push_back(stoi(word));
            }
        }
        return res;
    }
};
