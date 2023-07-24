Node *Reverse(Node *head){
Node *new_head=NULL;
  while(head!=NULL){
 Node *curr=head;
    head=head->next;
    curr->next=new_head;
    new_head=curr;
  }
 return new_head;
}

Node *middle(Node *head){
 Node *slow=head;
 Node *fast=head->next;

  while(fast!=NULL && fast->next!=NULL){
     slow=slow->next;
     fast=fast->next->next;
  }
  return slow;
}

//Main code
bool is palindrome(Node *head){

  if(head==NULL || head->next==NULL) return true;
  Node *mid=middle(head);
  Node *temp=mid->next; 
 mid->next=Reverse(temp);
  
//Compare both halves
  Node *a=head;
  Node *b=mid->next;

  while(b!=NULL){
  if(a->data!=b->data) return false;

  a=a->next;
  b=b->next;
  }
 return true;
}
