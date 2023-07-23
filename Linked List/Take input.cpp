//T.C=O(n^2)

Node *takeInput(){
int data;
cin>>data;
Node*head=NULL;

while(data!=-1){
Node *newNode=newNode(data);

if(head==NULL) {
  head=newNode;
  }
  
else {
Node *temp=head;

  while(temp->next!=NULL){
    temp=temp->next;
  }
    temp->next=newNode;
}
  cin>>data;
}
return head;
}

//TC =O(n)
Node *takeInput(){
int data;
cin>>data;
Node *head=NULL;
Node *tail=NULL;

while(data!=-1){
Node *newNode=newNode(data);

if(head==NULL) {
  head=newNode;
  tail=newNode;
  }
else{
tail->next=newNode;
  tail=tail->next;
}

cin>>data;
}
return head;
}



