class Solution {
public:
    string decodeString(string s) {
        stack<int>stN;
        stack<string>stC;
        int currN=0;
        string currS="";
        int prevN;
        string prevS;

        for(auto i:s){
            if(isdigit(i)) currN=currN*10+(i-'0');

            if(isalpha(i)) currS.push_back(i);

            if(i=='[') {
                stN.push(currN);
                stC.push(currS);
                currN=0;
                currS="";
            }
            if(i==']'){
                 prevN=stN.top();
                 stN.pop();
                prevS=stC.top();
                stC.pop();

                //Update kardo currS ko
                int n=prevN;
                string temp=currS;
                //Repetition ko string banao
                for(int i=0;i<n-1;i++) currS+=temp;
                //prevS ke sath add kardo
                currS=prevS+currS;

            }
        }
         return currS;
    }
};
