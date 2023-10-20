class NestedIterator {
public:
// //Approach 1
stack<NestedInteger>st;

    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();

        for(int i = n - 1; i>=0; i--) st.push(nestedList[i]);
    }
    
    int next() {
        int num = st.top().getInteger();
        st.pop();

        return num;
    }
    
    bool hasNext() {
        if(st.empty()) return false;

        while(!st.empty()){
         NestedInteger curr = st.top();
         if(curr.isInteger())return true;

         st.pop();

         vector<NestedInteger>vec = curr.getList();

         for(int i = vec.size() - 1; i>=0; i--) st.push(vec[i]);
        }
        return false;
    }

//Approach 2
stack<NestedInteger*>st;

    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();

        for(int i = n - 1; i>=0; i--) st.push(&nestedList[i]);
    }
    
    int next() {
        int num = st.top()->getInteger();
        st.pop();

        return num;
    }
    
    bool hasNext() {
        if(st.empty()) return false;

        while(!st.empty()){
         NestedInteger* curr = st.top();
         if(curr->isInteger())return true;

         st.pop();

         vector<NestedInteger>&vec = curr->getList();

         for(int i = vec.size() - 1; i>=0; i--) st.push(&vec[i]);
        }
        return false;
    }

//Approach 3
 queue<int>que;

 void Flatten(vector<NestedInteger> &nestedList){
     int n = nestedList.size();

     for(int i = 0; i < n; i++){

         NestedInteger&obj = nestedList[i];

         if(obj.isInteger()) que.push(obj.getInteger());

         else  Flatten(obj.getList());
     }
 }

    NestedIterator(vector<NestedInteger> &nestedList) {
     Flatten(nestedList);
    }
    
    int next() {
    int num = que.front();
    que.pop();
    return num;
    }
    
    bool hasNext() {
     if(que.empty()) return false;

     return true;
    }
};
