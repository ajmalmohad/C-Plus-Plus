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
Node::Node(int data){
    data = data;
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
        std::cout<<"append::Node Appended\n";
    }else{
        Node* temp = head;
        while(temp->next!=NULL) temp = temp->next;
        temp->next = node;
        size++;
        std::cout<<"append::Node Appended\n";
    }
};
void LinkedList::prepend(Node* node){
    if(size==0) append(node);
    else{
        node->next=head;
        head=node;
        size++;
        std::cout<<"prepend::Node Prepended\n";
    }
}
void LinkedList::insert(int i,Node* node){
    if(i > size || i<0){
        std::cout<<"insert::Enter a Valid Index\n";
    }
}

/* 
Entry
*/
int main(){
    LinkedList ll;
    Node one(10);
    Node two(10);
    ll.prepend(&one);
    ll.insert(0,&two);
}