class Solution {
public:
//Approach 1
    int totalMoney(int n) {
        int res = 0;

        int Monday_money = 1; // 1 dollar

        while(n > 0){
           
           int money = Monday_money;

           for(int i = 1; i <= min(n,7); i++){
             res += money;
             money++;
           }

           n -= 7; // for next week
           Monday_money++; // next week // 2 dollar
        }
        return res;
    }

    int totalMoney(int n) {
        int terms = n / 7; //weeks

        int first = 28;
        int last = first + (terms - 1) * 7; // AP formula for nth term ,,,,,last = a + (n - 1)*d

        int res = terms * (first + last) / 2; //Sum of nth terms in an AP,,, sum = n * (a + l)/2

        //Final week remaining days = n % 7
        int start_money = 1 + terms;

        for(int day = 1; day <= (n % 7); day++){
            res += start_money;
            start_money++;
        }
        return res;
    }
};
