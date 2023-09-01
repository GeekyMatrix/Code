class Solution {
public:
//O(N) SPACE SOLUTION
 ListNode *detectCycle(ListNode *head) {
   unordered_set< ListNode *>s;
    ListNode *curr=head;
    while(curr !=NULL){
     if(s.find(curr) !=s.end()) return curr;
     else{
         s.insert(curr);
         curr =curr->next;
     }
    }
  return NULL;
 }

//O(1) SPACE SOLUTION
    ListNode *detectCycle(ListNode *head) {
         ListNode *slow=head,*fast=head;

         while(fast && fast->next){
             slow =slow->next;
             fast =fast->next->next;
             
            if(slow == fast){
                while(slow != head){
                    slow = slow->next;
                    head = head->next;
            }
                return slow;
            }
         }
         return NULL;
    }
};
