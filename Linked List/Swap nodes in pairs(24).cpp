class Solution {
public:
//Intituion 
 //A->B->C->D->NULL
 //A->solve(C);
//B->next=A;

// head=A
//head->next=B;
//head->next->next=C;

    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

         ListNode *temp=head->next;  //B ko store krwa liya
         head->next=swapPairs(head->next->next); //A->solve(C);
         temp->next=head;     //B->next=A;

         return temp;      //return B
    }
};
