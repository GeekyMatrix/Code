class Solution {
public:
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
    int maxScore(string s) {
        int n = s.length();

        int res = INT_MIN;

        for(int i = 0; i < n - 1; i++){

            int Zeros_left = 0;
            for(int j = 0; j <= i; j++){
                if(s[j] == '0')  Zeros_left++;
            }

            int Ones_right = 0;
            for(int j = i + 1; j < n; j++){
                if(s[j] == '1')  Ones_right++;
            }

            res = max(res , Zeros_left + Ones_right);
        }
        return res;
    }

//Approach-2 (Making use of ones count - 2 Pass)
//T.C : O(n)
//S.C : O(1)

    int maxScore(string s) {
        int n = s.length();

        int res = INT_MIN;
        int total_ones = count(s.begin(),s.end(),'1');
        int zeros_cnt = 0;

        for(int i = 0; i < n - 1; i++){

                if(s[i] == '1')  total_ones--;
                else zeros_cnt++;
        
            res = max(res , zeros_cnt + total_ones);
        }
        return res;
    }

//Approach-3 (1 Pass - Use equation)
//T.C : O(n)
//S.C : O(1)
  
  //formula 
 //Scores=(ZEROS_left) + (ONES_RIGHT) ==>>>(ZEROS_left) + (ONES_TOTAL - ONES_LEFT) ==>>(ZEROS_left - ONES_LEFT + ONES_TOTAL)
    int maxScore(string s) {
        int n = s.length();

        int res = INT_MIN;
        int ones_cnt = 0;
        int zeros_cnt = 0;

        for(int i = 0; i < n - 1; i++){

                if(s[i] == '1')  ones_cnt++;
                else zeros_cnt++;
        
            res = max(res , zeros_cnt - ones_cnt);
        }
            if(s[n-1] == '1')  ones_cnt++;
        
        return res + ones_cnt;
    }
};
