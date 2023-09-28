class Solution {
public:
//Approach 1 (Two pointer)
    // int pairSum(ListNode* head) {
    //     vector<int>v;

    //     while(head!=NULL){
    //         v.push_back(head->val);
    //         head = head->next; 
    //     }
    //     int res = 0;
    //     int i = 0,j = v.size() - 1;
    //     while(i < j){
    //      res = max(res,v[i] + v[j]);
    //      i++;
    //      j--;
    //     }
    //     return res;
    // }

//Approach 2 (Stack)
    // int pairSum(ListNode* head) {
    //   stack<int>st;
    //   int res = 0;

    //  ListNode*temp = head;

    //  while(temp!=NULL){
    //   st.push(temp->val);
    //   temp = temp->next;
    //  }
     
    //  int N = st.size();
    //  temp = head;
    //  int cnt = 1;
     
    //  while(cnt <= N/2){
    //      res = max(res,temp->val + st.top());
    //      temp = temp->next;
    //      st.pop();
    //      cnt++;
    //  }
    //  return res;
    // }

//Approach 3
//Reverse ll method
 int pairSum(ListNode* head) {
    //step 1: mid find karo
 ListNode*slow = head; 
 ListNode*fast = head;

 while(fast!=NULL && fast->next!=NULL){
     slow = slow->next;
     fast = fast->next->next;
 }
 ListNode*mid = slow;
 
    //step 2: Reverse krdo 2nd half of LL
    ListNode*new_head = NULL;

    while(mid!=NULL){
     ListNode*temp = mid;
     mid = mid->next;
     temp->next = new_head;
     new_head = temp;
    }
  
  //Find maximum twin
  int res = 0;

  ListNode*curr = head; 
        
 while(new_head!=NULL){
     res = max(res, curr->val + new_head->val);
     new_head = new_head->next;
     curr = curr->next; 
 }
  return res;
 }
};
