Node *merge(Node *head1,Node *head2){

  if(head1==NULL) return head2;
   if(head2==NULL) return head1;

  Node *head=NULL;
  Node *Tail=NULL;

  if(head1->data <head2->data){
  head=head1;
  Tail=head1;
  head1=head1->next;
  }

else{
 head=head2;
  Tail=head2;
  head2=head2->next;
}

while(head1!=NULL && head2!=NULL){
 if(head1->data < head2->data){
 Tail->next=head1;
  Tail=Tail->next;
   head1=head1->next;
 }
else{
 Tail->next=head2;
  Tail=Tail->next;
   head2=head2->next;
}
}
  if(head1!=NULL){
 Tail->next=head1;
  head1=head1->next;
  }

  else{
       Tail->next=head2;
        head2=head2->next;
  }
  return head;
}