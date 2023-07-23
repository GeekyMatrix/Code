//Iterative method

Eg:- i/p=1->2->3->4->5->-1
  i=0,data=99
  o/p=99->1->2->3->4->5->-1
  
Node insertNode(Node *head,int i,int data){
  Node *newNode=newNode(data);
 int count=0;
  Node *temp=head;

  if(i==0){
  newNode->next=head;
    head=newNode;
    return head;
  }

  while(temp!=NULL && count<i-1){
  temp=temp->next;
    count++;
  }
  if(temp!=NULL){
    Node *a=temp->next;
    temp->next=newNode;
    newNode->next=a;
}
void print(Node *head){
 while(head!=NULL){
cout<<head->data<<" ";
   head=head->next;
}
}
int main(){
  print(head);
int i,data;
cin>>i>>data;
head=insertNode(head,i,data);
print(head);
}

//Recursive Method

Node insertNode(Node *head,int i,int data){
  
  if(i==0 || head==NULL){
   Node *newNode=newNode(data);
  newNode->next=head;
    head=newNode;
    return head;
  }
else{
 head->next= insertNode(head->next,i-1,data);
}
 return head;
}

void print(Node *head){
 while(head!=NULL){
cout<<head->data<<" ";
   head=head->next;
}
}
int main(){
  print(head);
int i,data;
cin>>i>>data;
head=insertNode(head,i,data);
print(head);
