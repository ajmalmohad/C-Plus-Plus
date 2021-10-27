#include <iostream>

/* 
Node
*/
class Node{
    public:
    Node();
    Node(int);

    int data;
    Node* next;
};
Node::Node(){
    data = 0;
    next = NULL;
}
Node::Node(int value){
    data = value;
    next = NULL;
}

/* 
Linked List
*/
class LinkedList{
    public:
    LinkedList();
    LinkedList(Node*);
    void append(Node*);
    void prepend(Node *);
    void insert(int, Node*);
    void print();

    int size;
    Node* head;
    Node* tail;
};
LinkedList::LinkedList(){
    size = 0;
    head = NULL;
    tail = NULL;
};
LinkedList::LinkedList(Node *node){
    head = node;
    tail = head;
    size++;
};
void LinkedList::append(Node* node){
    if(size==0){
        head = node;
        tail = head;
        size++;
    }else{
        Node* temp = head;
        while(temp->next!=NULL) temp = temp->next;
        temp->next = node;
        size++;
    }
};
void LinkedList::prepend(Node* node){
    if(size==0) append(node);
    else{
        node->next=head;
        head=node;
        size++;
    }
}
void LinkedList::insert(int i,Node* node){
    if(i > size || i<0){
        std::cout<<"insert::Enter a Valid Index\n";
    }else if(i==0){
        prepend(node);
    }else if(i==size){
        append(node);
    }else{
        Node* temp = head;
        for (int j = 0; j < i-1; j++) temp = temp->next;
        node->next = temp->next;
        temp->next = node;
        size++;
    }
}
void LinkedList::print(){
    Node* temp = head;
    while(temp!=NULL){
        std::cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    std::cout<<" Null\n";
}

/* 
Entry
*/
int main(){
    LinkedList ll;
    Node one(10);
    Node two(20);
    Node three(30);
    Node four(40);
    ll.append(&one);
    ll.append(&two);
    ll.append(&four);
    ll.insert(1,&three);
    ll.print();
}