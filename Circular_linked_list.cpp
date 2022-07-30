 #include<iostream>
 using namespace std;

 class Node{
public:
    int data ;
    Node* next;

    //constructor
    tiis ->data=d;
    this->next=NULL;

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


 int main()

{

    return 0;
}
