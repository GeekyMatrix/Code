class Solution {
public:
# //Approach 1

//    ListNode* reverseLL(ListNode* head){
//   if(!head||!head->next) return head;
//   //FUNCTION CALL
//    ListNode* smallAns=reverseLL(head->next);
//    head->next->next=head;
//    head->next=NULL;
//    return smallAns;
//    }

//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         if(left==right) return head;
//          ListNode* start=NULL;
//          int count=1;
//           ListNode* temp=head;

//           while(count!=left){
//               start=temp;
//               temp=temp->next;
//               count++;
//           }
//            ListNode* a=temp;

//           while(count!=right){
//             temp=temp->next;
//             count++;
//           }

//       ListNode* end=temp->next;
//       temp->next=NULL;

//         ListNode* rev= reverseLL(a);

//         if(start == NULL && end == NULL) return rev;
//         if(start == NULL){
//             a->next =end;
//             return rev;
//         }
//         else{
//         start->next=rev;
//         a->next=end;
//         }

//       return head;
//     }

# //Approach 2
  
 ListNode* reverseBetween(ListNode* head, int left, int right) {
 if(head == NULL || head->next == NULL) return head;
 ListNode* dummy = new ListNode(0);
 dummy->next = head;

 ListNode* prev = dummy;

 for(int i=1; i<left; i++) prev=prev->next;

 ListNode* curr = prev->next;

 for(int i=1; i<=right-left; i++){

  ListNode* temp = prev->next; //0
  prev->next = curr->next; //1
  curr->next = curr->next->next; //2
  prev->next->next = temp; //3
 }
 return dummy->next;
 }
};
