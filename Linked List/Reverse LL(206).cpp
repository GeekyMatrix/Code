//ITERATIVE APPROACH
class Solution {
public:
//Iterative method
 ListNode* reverseList(ListNode* head) {
 ListNode *new_head=NULL;
 while(head!=NULL){
     ListNode *temp=head;
     head=head->next;
     temp->next=new_head;
     new_head=temp;
 }
  return new_head;
 }

//Recursive Method
    ListNode* reverseList(ListNode* head) {
        //Step :1 Base case
        if(!head || !head->next) return head;

      //Step 2:Function call
       ListNode* Chotahead = reverseList(head->next);  //1->2->3->NULL return krdega 3 ko
       //lekin head mera 2 par hoga 
       //step:3
       head->next->next=head;  // 3->2
       head->next=NULL;        //3->2->NULL
       return Chotahead;       // 3 ko return krdia
    }
};
