class Solution {
public:
//Appraoch 1
     ListNode* ReverseLL(ListNode* head,ListNode* tail){
         //BASE CASE
         if(head==tail) return head;
         //FUNCTION CALL
          ListNode* smallAns=ReverseLL(head->next,tail);
          head->next->next=head;
          head->next=NULL;
          return smallAns;
     }

    ListNode* reverseKGroup(ListNode* head, int k) {
             ListNode* new_head=head;
             ListNode* curr=head;
              int size=1;
          
                while(size !=k && curr){
                    curr=curr->next;
                    size++;
                }
    
               if(size==k && curr){
                  ListNode*next=curr->next;
                   new_head =ReverseLL(head,curr);
                   head->next=reverseKGroup(next,k);
            }
       return new_head;
    }

//Approach 2
ListNode* reverseKGroup(ListNode* head, int k) {
//BASE CASE
if(head == NULL) return NULL;

//step1 Reverse first k nodes
ListNode* prev =NULL;
ListNode* cur r=head;
ListNode* next =NULL;
 ListNode* temp = curr;
int count =0;

//Agar k size se chota hai toh
int cnt =0;
    while(temp !=NULL){
        cnt++;
        temp =temp->next;
    }
    if(cnt<k){
        return head;
    }
//aaga ka
  while(curr !=NULL && count<k){
  next =curr->next;
  curr->next =prev;
  prev =curr;
  curr =next;
 count++;
  }
 
 //step2 Recursion dekh lega aage ka
 if(next !=NULL) head->next =reverseKGroup(next,k);

 //Return head of the Reverse list
 return prev;
}
};
