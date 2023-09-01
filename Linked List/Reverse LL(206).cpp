//ITERATIVE APPROACH
 ListNode*reverseLL(ListNode*head){
          ListNode *new_head=NULL;
          while(head!=NULL){
            ListNode *curr=head;
            head=head->next;
            curr->next=new_head;
            new_head=curr;
          } 
         return new_head;
     }

//RECURSIVE METHOD
 ListNode*reverseLL(ListNode*head){
         //BASE CASE
         if(head==NULL||head->next==NULL) return head;

         //Recursive call
         ListNode*SmallAns=reverseLL(head->next);
         //Calculation
        head->next->next=head;
         head->next=NULL;
         return SmallAns;

     }
