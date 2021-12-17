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
void insertAthead(node*&head,int d){
    if(head==NULL){
        head = new node(d);
        return;
    }
    node*n = new node(d);
    n->next = head;
    head = n;
}
void printList(node*head){
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
    return 0;
}

