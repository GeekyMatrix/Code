class Solution {
public:
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

//APPROACH 1
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*a=reverseLL(l1);
        ListNode*b=reverseLL(l2);
        //Old 
         int carry=0;
        ListNode*temp=new ListNode(0);
        ListNode*curr=temp;
        while(a||b||carry){
            int sum=0;
            if(a!=NULL){
                sum+=a->val;
                a=a->next;
            }
             if(b!=NULL){
                sum+=b->val;
                b=b->next;
            }
            sum+=carry;
            carry=sum/10;
           ListNode* n = new ListNode(sum%10);
           curr->next=n;
           curr=curr->next;
        }
        ListNode*ans=reverseLL(temp->next);
     return ans;
    }

//APPROACH 2
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
l1=reverseLL(l1);
l2=reverseLL(l2);

int sum=0,carry=0;
ListNode *ans=new ListNode();

while (l1!=NULL|| l2!=NULL){
if(l1!=NULL){
sum+=l1->val;
l1=l1->next;
}
if(l2!=NULL){
sum+=l2->val;
l2=l2->next;
}
ans->val=sum%10;
carry=sum/10;

ListNode *newNode=new ListNode(carry);
newNode->next=ans;
ans=newNode;
sum=carry;

}
  return carry==0?ans->next:ans;
}

//FOLLOW UP
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        while (l1 != NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int sum = 0, carry = 0;
        ListNode* ans = new ListNode();
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            ans->val = sum % 10;
            carry    = sum / 10;
            
            ListNode* newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            sum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }

};
