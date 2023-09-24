class StockSpanner {
public:
stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1; //for current stock

        while(!st.empty() && st.top().first <= price){
         span+=st.top().second; // adding previous span
          st.pop();   //No need of smaller value one 
        }

        st.push({price,span});
        return span;
    }
};
