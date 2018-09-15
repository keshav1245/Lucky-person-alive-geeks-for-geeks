#include<iostream>
#include<stdlib.h>
using namespace std;
int i,n;
class Node{
public:
Node* next;
int data;
};

class cll{
public:
Node * head;
cll(){
head = NULL;
}
Node* createnode(int val);
void addele(int val);
void display();
void deleteatpos(int pos);
void deleteatbeg();
void actual_procedure();
};
//create Node
Node* cll::createnode(int val){
Node* temp = new Node;
temp->data = val;
return temp;
}
//add element
void cll::addele(int val){
if(head==NULL){
Node* temp = createnode(val);
head = temp; 
temp->next = head;
}else{
Node* temp = createnode(val);
Node* ptr;
ptr=head;
while(ptr->next!=head){
ptr=ptr->next;
}
ptr->next = temp;
temp->next = head;
}
}
//printing for demonstration and checking
void cll::display(){
if(head==NULL){
cout<<"\n\nNO SOLDIERS\n\n";
return;
}else{
Node* ptr;
ptr=head;
while(ptr->next!=head){
cout<<ptr->data<<" ";
ptr=ptr->next;
}
cout<<ptr->data<<" ";
}
}
//delete element at beg
void cll::deleteatbeg(){
if(head==NULL){
cout<<"\n\nUNDERFLOW !\n\n";
return;
}else if(head->next==head){
head = NULL;
return;
}
Node * ptr = new Node;
Node * preptr = new Node;
preptr=head;
do{
preptr=preptr->next;
}while(preptr->next!=head);
ptr=head;
head = ptr->next;
preptr->next = head;
delete ptr;
}

//deleting at position 
void cll::deleteatpos(int pos){
if(head==NULL){
return;
}else if(pos==1){
/*Node* ptr = head;
head=ptr->next;
delete ptr;
Node* lp = head;

if(n==2){
head->next = NULL;
}

if(lp==head){
i=0;
}else if(lp->next==head){
i=-1;
}
return;
*/
deleteatbeg();
}else{
Node* ptr;
ptr = head;
Node* prev;
for(int i=1;i<pos;i++){
prev =ptr;
ptr=ptr->next;
}
prev->next=ptr->next;
delete ptr;
Node* lp = prev->next;
if(lp==head){
i=0;
}else if(lp->next==head){
i=-1;
}

}
}
//main solution of the problem
void cll::actual_procedure(){
cout<<"\nEnter Number of Soldiers : ";
cin>>n;
for(int i=1;i<=n;i++){
addele(i);
}
display();
i=1;
if(n==0)
exit(0);
while(n!=1){
deleteatpos(i+1);

n--;
i++;
}
Node * ans = head;
cout<<"\n\nLUCKY SOLDIER IS : "<<ans->data<<endl;
}
int main(){
cll obj;
obj.actual_procedure();
}
