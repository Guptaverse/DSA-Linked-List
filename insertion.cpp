#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        
        node(int d){
            data = d;
            next = NULL;
        }
};

void build(node*head,int d){

}
void insertAthead(node*&head,int d){   //passing head by reference
    if(head==NULL){
        head = new node(d);
        return;
    }
    node*n = new node(d);
    n->next = head;
    head = n;
}
void insertAtMiddle(node*&head,int d,int pos){
    if(head==NULL){
        head = new node(d);
        return;
    }
    node*temp =head;
    int idx =1;
    while(temp!=NULL){
        node*n = new node(d);
        if(idx == pos-1){
            n->next = temp->next;
            temp->next = n;
        }
        idx++;
        temp = temp->next;
    }
    temp = head;

}
void insertAtEnd(node*&head,int d){
    if(head==NULL){
        head = new node(d);
        return;
    }
    node*temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    node*n = new node(d);
    temp->next=n;
    temp=head;
}
void printList(node*head){    //passing head by value
    while(head->next!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data<<endl;
}

int main(){
    node*head =NULL;
    insertAthead(head,4);
    insertAthead(head,3);
    insertAthead(head,2);
    insertAthead(head,1);
    printList(head);
    insertAtMiddle(head,5,3);
    printList(head);
    insertAtEnd(head,8);
    printList(head);
    return 0;
}
//OUTPUT : 1->2->3->4
