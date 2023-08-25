class MinStack {
public:
//Approach1
stack<int>st,min_stack;
    MinStack() {
        
    }
    
    void push(int val) {
           if(min_stack.empty() || val<=min_stack.top()) min_stack.push(val);

           st.push(val);
    }
    
    void pop() {
          if(st.top()==min_stack.top()) min_stack.pop();

          st.pop();
    }
    
    int top() {
       return st.top();
    }
    
    int getMin() {
         return min_stack.top();
    }
//Approach 2
vector<int>arr;
int size=0;
    MinStack() {
        
    }
    
    void push(int val) {
           arr.push_back(val);
            size++;
    }
    
    void pop() {
        arr.erase(arr.begin()+(size-1));
        arr.resize(size-1);
        size--;
    }
    
    int top() {
       return  arr[size-1];
    }
    
    int getMin() {
        return(*min_element(arr.begin(),arr.end()));
    }
};
