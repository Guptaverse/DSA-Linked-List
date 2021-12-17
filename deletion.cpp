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
int lengthOfList(node*head){
    int len = 0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}
// bool helper(node*head,pos){
//     int idx =0;
//     while(head)
// }
//.....................INSERTION OPERATION..........................

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
// ...............................DELETION OPERATION............................
void deleteAtEnd(node*&head);
void deleteAthead(node*&head){
    if(head == NULL){
        return;
    }
    node*temp = head->next; //stored the value of next pointer 
    delete head;            //Now simply delete the head
    head = temp;            //point the head to the next pointer (temp or head->next)
}
void deleteAtMiddle(node*&head,int pos){
    if(head ==NULL){
        return;
    }
    else if(pos == 1){
        deleteAthead(head);
    }
    else if(pos>=lengthOfList(head)){
        deleteAtEnd(head);
    }
    int idx=1;
    node*prev=head;
    node*curr = head->next;
    while(prev!=NULL){
        if(idx==pos-1){
            prev->next = curr->next;
            delete curr;
            prev = head;
            break;
        }
        idx++;
        prev = prev->next;
        curr = curr->next;
    }

}
void deleteAtEnd(node*&head){
    if(head == NULL){
        return ;
    }
    node*prev=head;
    node*curr=head->next;
    while(curr->next!=NULL){
        prev = prev->next;
        curr = curr->next;
    }
    prev->next = NULL;
    delete curr;
    prev=head;
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
    // INSERTION
    cout<<"inserting at the head of linked list"<<endl;
    insertAthead(head,4);
    insertAthead(head,3);
    insertAthead(head,2);
    insertAthead(head,1);
    printList(head);
    cout<<"inserting in the middle of linked list"<<endl;
    insertAtMiddle(head,5,3);
    printList(head);
    cout<<"inserting at the tail of linked list"<<endl;
    insertAtEnd(head,8);
    printList(head);

    // DELETION
    cout<<"Deletion at the head of linked list"<<endl;
    deleteAthead(head);
    printList(head);
    cout<<"Deletion at the middle of linked list"<<endl;
    deleteAtMiddle(head,3);
    printList(head);
    cout<<"Deletion at the tail of linked list"<<endl;
    deleteAtEnd(head);
    printList(head);


    return 0;
}


