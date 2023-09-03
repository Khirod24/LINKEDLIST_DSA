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

void insertnode(Node*&tail,int element,int d){
    //empty list
    if(tail==NULL){
        Node*temp=new Node(d);
        tail=temp;
        temp->next=temp;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list
        Node*curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }

        //element found ->curr is representing element wla part
        Node*temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}

void print(Node*tail){
    if(tail==NULL){
        cout<<"list is empty"<<endl;
    }
    Node*temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
}

//DELETION
void deletenode(Node*&tail,int value){
    //empty list
    if(tail==NULL){
        cout<<"LIST IS EMPTY"<<endl;
        return;
    }
    else{
        Node*prev=tail;
        Node*curr=prev->next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        //1 node delete
        if(curr==prev){
            tail=NULL;
        }
        //>=2 nodes delete
        else if(curr==tail){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;

    }
}

int main(){
    Node*tail=NULL;
    insertnode(tail,1,3);
    print(tail);
    //  //cout<<tail->data<<endl;
    // insertnode(tail,3,5);
    // print(tail);
    // //cout<<tail->data<<endl;
    // insertnode(tail,5,8);
    // print(tail);
    // //cout<<tail->data<<endl;
    // insertnode(tail,5,30);
    // print(tail);
    // insertnode(tail,3,40);
    // print(tail);

    // deletenode(tail,5);
    // print(tail);
    // deletenode(tail,40);
    // print(tail);
    deletenode(tail,3);
    print(tail);

    
}