#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*prev;
    Node*next;
    Node(int data){
        this->data=data;
        this->prev=NULL;
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
//LENGTH OF LL
int getlength(Node*&head){
    int len=0;
    Node*temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
//INSERTION AT HEAD
void insertathead(Node*&head,Node*&tail,int d){
    if(head==NULL){
        Node*temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
    Node*temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}

//INSERTION AT TAIL
void insertattail(Node*&head,Node*&tail,int d){
    if(tail==NULL){
        Node*temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else{
    Node*temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
    
}

//INSERT AT MIDDLE
void insertatposition(Node*&head,Node*&tail,int position,int d){
    //insert at start
    if(position==1){
        insertathead(head,tail,d);
        return;
    }
    Node*temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    //insertion at end
    if(temp->next==NULL){
        insertattail(head,tail,d);
        return;
    }
    Node*nodetoinsert=new Node(d);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;
}

//NODE DELETION
void deletenode(int position,Node*&head){
    if(position==1){
        Node*temp=head;
        temp->next->prev=NULL;
        head=temp->next;
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
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main(){
    Node*node1=new Node(10);
    
    //Node*head=node1;
    //Node*tail=node1;
    
    Node*head=NULL;
    Node*tail=NULL;
    print(head);
    cout<<getlength(head)<<endl;
    /*insertathead(head,11);
    print(head);
    insertathead(head,13);
    print(head);
    insertathead(head,8);
    print(head);*/
    
    insertattail(head,tail,11);
    print(head);
    insertattail(head,tail,13);
    print(head);
    insertattail(head,tail,8);
    print(head);
    insertatposition(head,tail,3,25);
    print(head);
    insertatposition(head,tail,1,250);
    print(head);
    deletenode(2,head);
    print(head);
   // cout<<head->data<<" "<<tail->data<<endl;
    return 0;
}