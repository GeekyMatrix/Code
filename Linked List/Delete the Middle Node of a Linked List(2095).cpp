class Solution {
public:
 int count_nodes(ListNode* head){
     int cnt = 0;
     while(head) {
         cnt++;
         head = head->next;
     }
     return cnt;
 }
    ListNode* deleteMiddle(ListNode* head) {
        int n = count_nodes(head);
        if(n == 1) return NULL;
      
        int mid = n/2-1;
        
        ListNode* temp = head;
        while(mid--)     temp = temp->next;
        
        temp->next = (temp->next)->next;

        return head;
    }
};
