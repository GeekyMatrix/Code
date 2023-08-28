class MyStack {
public:
   queue<int>q1,q2;
    MyStack() {
        
    }

    void push(int x) {
        q1.push(x); 

        while(!q2.empty()){
          q1.push(q2.front());
          q2.pop();
        }

    swap(q1,q2); 
}
    int pop() {
    int val=q2.front();
    q2.pop();
    return val;

    }
    
    int top() {
    return q2.front();
    }
    
    bool empty() {
    return q2.empty();
    }
};


//Approach 2

class MyStack {
public:
    MyStack() {
        
    }
    queue<int>q;
    void push(int x) {
        q.push(x);
        for(auto i=0;i<q.size()-1;i++){
        q.push(q.front());
        q.pop();
    }
}
    int pop() {
        int temp=q.front();
        q.pop();
        return temp;
    }
    
    int top() {
      return  q.front();
    }
    
    bool empty() {
      return  q.empty();
    }
// };
