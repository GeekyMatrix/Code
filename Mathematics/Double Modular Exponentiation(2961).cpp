class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int>res;
        int n = variables.size();
        
        for(int i = 0; i < n; i++){
             int ai = variables[i][0];
             int bi = variables[i][1];
             int ci = variables[i][2];
             int mi= variables[i][3];
            
            int base = 1;
            for(int j = 1; j <= bi; j++)    base = (base * ai) % 10;
            
            int formula_res = 1;
            for(int j = 1; j <= ci; j++) formula_res = (formula_res * base) % mi;

            if(formula_res == target) res.push_back(i);
            
        }
        return res;
    }
};
