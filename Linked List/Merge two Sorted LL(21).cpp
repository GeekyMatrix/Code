class Solution {
public:
    ListNode* mergeTwoLists(ListNode*  head1, ListNode* head2) {
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
       
     //Step:1 intialize
         ListNode *head=NULL;
          ListNode *tail=NULL;

          if(head1->val< head2->val){
            head = head1;
            tail = head1;
            head1 = head1->next;
          }
           else{
            head = head2;
            tail = head2;
            head2 = head2->next;
           }

        //Step:2 Move the pointer to the sorted list until both the LL exist
          while(head1 !=NULL && head2 !=NULL){
              if(head1->val<head2->val){
                  tail->next =head1;
                  tail =tail->next;
                  head1 =head1->next;
              }
               else{
                    tail->next =head2;
                    tail =tail->next;
                    head2 =head2->next;
               }
          }
          //Step:3 if anyone is NULL then 
              if(head1 !=NULL) tail->next =head1;
              else tail->next =head2;
             
             return head;
    }
};
