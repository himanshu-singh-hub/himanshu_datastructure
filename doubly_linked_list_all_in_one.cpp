//here insertion,deletion,iteration all in one will get in doubly linked list

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
    
    ~Node()
    {
        int val=this->data;
        if(next!=NULL)
        {
            delete next;
            next NULL;
        }
        cout<<"memory is free from Data"<<val<<endl;
    }
};
//traversing a linked list
void Print(Node* head){
    Node* temp=head;
    while(temp!=NULL)
    {

        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
//give length
int getLength(Node* head)
{
    int len=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;
}

void insertAtHead(Node* &head ,int d)
{
    Node* temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void insertAtTail(Node* &tail ,int d)
{
    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insertAtPosition(Node* &tail,Node* &head,int position,int d)
{
    //insert at start
    if(position==1)
    {
        insertAtHead(head,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }
    //inserting at last position
    if(temp->next==NULL)
    {
        insertAtTail(tail,d);
        return;
    }
    //creating a node for d
    Node* nodeToInsert =new Node(d);
    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;
}

void deleteNode(int position,Node* &head)
{
    if(position ==1)
    {
        Node* temp=head;
        temp->next->prev=NULL;
        head=temo->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
         curr->prev=NULL;
         prev->next=curr->next;
        curr->next=NULL;
        delete curr;
}

int main()
{

    Node * node1=new Node(10);
    Node* head =node1;
    Node* tail =node1;
    Print(head);

    //cout<<getLength(head)<<endl;
     insertAtHead(head,11);
     Print(head);

     insertAtHead(head,8);
     Print(head);
    
     insertAtHead(head,12);
     Print(head);
    
    insertAtTail(tail,25);
    Print(head);

    insertAtPosition(tail,head,1,101);
    Print(head);
    
    insertAtPosition(tail,head,2,102);
    Print(head);
    
    insertAtPosition(tail,head,8,103);
    Print(head);
    
    deleteNode(1,head);
     Print(head);
    
    return 0;
}
