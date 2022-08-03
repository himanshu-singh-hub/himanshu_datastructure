 #include<iostream>
 using namespace std;

 class Node{
public:
    int data ;
    Node* next;

    //constructor
    Node(int d){
    this->data=d;
    this->next=NULL;
    }
    //destructor
    ~Node(){
        int value=this->data;
        if(this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<< "memory is free for node write data"<<value<<endl;
    }
};

void insertnode(Node* &tail,int element, int d)
{
    //assuming that the element is present in the list
    //empty list
    if(tail==NULL){
    Node* newNode = new Node(d);
    tail=newNode;
    newNode->next=newNode;
    }else{
        //non empty list
        //assuming that the element is present in the list
        Node* curr=tail;
        while(curr->data!=element)
        {
            curr=curr->next;
        }
        //element found ->curr is representing element wala node
        Node* temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void print(Node* tail)
{
    if(tail==NULL)
    {

        cout<<"its empty";
    }
    Node* temp=tail;
    do
    {
        cout<<tail->data<<" ";
        tail=tail->next;
    }
    while(tail!=temp);
    cout<<" "<<endl;
}

void deleteNode(Node* &tail,int value)
{

    //empty list
    if(tail==NULL){
        cout<<"List is empty,"<<endl;
        return;
    }else{
        //non empty
        //assuming that 'value ' is present in ll
        Node * prev =tail;
        Node* curr =prev->next;
        while(curr->data!=value)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        //1 node ll
        if(curr==prev)
        {
            tail=NULL;
        }
        //>=2 node ll
        if(tail==curr)
        {
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}

int main()

{
    Node * tail=NULL;
    //empty list me insert kar rahee hai
     insertnode(tail,5,3);
     print(tail);
    insertnode(tail,3,5);
     print(tail);
     insertnode(tail,5,7);
     print(tail);
     insertnode(tail,7,9);
     print(tail);
     insertnode(tail,5,6);
     print(tail);
     insertnode(tail,9,10);
     print(tail);
     insertnode(tail,3,4);
     print(tail);
     deleteNode(tail,6);
     print(tail);
    return 0;
}
