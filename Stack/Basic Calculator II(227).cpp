class Solution {
public:
//Brute force
//TC = O(N)
//SC = O(N)
    int calculate(string s) {
        int n = s.length();
        if(n == 0) return 0;

        stack<int>st;

        int currN = 0;
        char op = '+';

        for (int i = 0; i < n; i++) {

            char currCh = s[i];

            if(isdigit(currCh)) currN = (currN * 10) + (currCh - '0'); // for did=gits

            if(!isdigit(currCh) && !iswspace(currCh) || i == n - 1){   // for operands or (n - 1 )

                 if(op == '-') st.push(-currN);

                 else if(op == '+') st.push(currN);

                 else if(op == '*'){
                     int stackTop = st.top();
                     st.pop();
                     st.push(stackTop * currN);
                 }
                 else if(op == '/'){
                     int stackTop = st.top();
                     st.pop();
                     st.push(stackTop / currN); 
                 }

                 op = currCh;
                 currN = 0;
            }

        }

        //Now Sum all the Numbers in the stack
           int res = 0;
           while(!st.empty()){
               res += st.top();
               st.pop();
           }

           return res;
    }

//Optimal 
//TC = O(N)
//SC = O(1)
    int calculate(string s) {
        int n = s.length();
        if(n == 0) return 0;

        int currN = 0 , lastN = 0, res = 0;
        char op = '+';

        for (int i = 0; i < n; i++) {

            char currCh = s[i];

            if(isdigit(currCh)) currN = (currN * 10) + (currCh - '0'); // for did=gits

            if(!isdigit(currCh) && !iswspace(currCh) || i == n - 1){   // for operands or (n - 1 )

                if(op == '+' || op == '-'){
                    res += lastN;
                    lastN = (op == '+') ? currN : -currN;
                }

                 else if(op == '*')  lastN *= currN;
                 
                 else if(op == '/')  lastN /= currN;

                 op = currCh;
                 currN = 0;
            }
        }

      res += lastN;

      return res;
    }
};
