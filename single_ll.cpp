#include<iostream>
using namespace std;
//CLASS FORMATION
class Node{
    //Node Creator
    public:
    int data;
    Node*next;
    //Node constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    //Node Destructor
    ~Node(){
        int value=this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};
//PRINTING LINKED LIST
void print(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//INSERTION AT HEAD
void insertathead(Node*&head,int d){
    Node*temp=new Node(d);
    temp->next=head;
    head=temp;
}

//INSERTION AT TAIL
void insertattail(Node*&tail,int d){
    Node*temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

//INSERTION AT MIDDLE
void insertatposition(Node*&head,Node*&tail,int position,int d){
    Node*temp=head;
    int count=1;
    //insert at start
    if(position==1){
        insertathead(head,d);
        return;
    }
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    //insertion at end
    if(temp->next==NULL){
        insertattail(tail,d);
        return;
    }
    Node*nodetoinsert=new Node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}

//NODE DELETION
void deletenode(int position,Node*&head){
    if(position==1){
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        //deleting any middle or last node
        Node*curr=head;
        Node*prev=NULL;
        int count=1;
        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main(){
    Node*node1=new Node(10);
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;
    Node*head=node1;
    Node*tail=node1;
    print(head);
   /* insertathead(head,12);
    print(head);
    insertathead(head,15);
    print(head);*/

    insertattail(tail,12);
    print(head);
    insertattail(tail,15);
    print(head);
    insertatposition(head,tail,3,20);
    print(head);
    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;
    deletenode(4,head);
    print(head);
    return 0;
}