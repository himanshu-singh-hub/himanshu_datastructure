//in this we will get insertion ,deletion and traversing

#include<iostream>
using namespace std;

class Node{

public:
    int data;
    Node* next;
    //constructor
    Node(int data){
        this -> data =data;
        this -> next = NULL;
    }
    //destructor
    ~Node()
    {
        int value=this->data;
        //memory free
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};






void insertAtTail(Node* &Tail,int d)
{
    Node* temp=new Node(d);
    Tail->next=temp;
    Tail=temp;
}
void insertAtHead(Node* &head,int d)
{
    Node* temp= new Node(d);
    temp -> next=head;
    head=temp;
}


void InsertAtPosition(Node* &head,int position,int d)
{
    Node* temp=head;
    //insert at first
    if(position==1)
    {

        insertAtHead(head,d);
        return;
    }
    int cnt=1;
    while(cnt<position-1)
    {

        temp=temp->next;
        cnt++;
    }
    //creating a node for d
    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}


void deleteNode(int position,Node* &head)
{
    if(position==1){
        //deleting first node and last node
        Node* temp =head;
        head=head->next;
        temp->next=NULL;
        delete temp;

    }else{
        //deleting any middle node and last node
        Node* curr =head;
        Node* prev =NULL;
        int cnt=1;
        while(cnt < position)
        {

            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void print(Node* &head )
{

    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{

    Node* node1 = new Node(10);
    //cout<<node1 -> data <<endl;
    //cout<<node1 -> next <<endl;
    Node* head = node1;
    Node* Tail = node1;
    print(head);

    insertAtTail(Tail,12);
    print(head);

    insertAtTail(Tail,15);
    print(head);

    InsertAtPosition(head,1,22);
    print(head);

    InsertAtPosition(head,3,22);
    print(head);

    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<Tail->next<<endl;

    deleteNode(4,head);
    print(head);
    return 0;
}
