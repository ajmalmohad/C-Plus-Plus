#include <iostream>

class Queue{
    public:
    void enqueue(int);
    int dequeue();
    int empty();
    int full();
    void print();

    private:
    int front = -1;
    int rear = -1;
    int size=5;
    int arr[5];
};
int Queue::full(){
    if(empty()) return 0;
    return (front == (rear+1)%size)?1:0;
}
int Queue::empty(){
    return (front==-1 && rear==-1)?1:0;
}
void Queue::enqueue(int value){
    if(empty()){
        front=0;
        rear=0;
        arr[rear]=value;
    }else if(full()){
        std::cout<<"Full";
    }else{
        rear = (rear+1)%size;
        arr[rear]=value;
    }
}
int Queue::dequeue(){
    if(empty()){
        std::cout<<"Empty";
        return 0;
    }else if(front == rear){
        front = -1;
        rear = -1;
        return arr[front+1];
    }else{
        front = (front+1)%size;
        return arr[front-1];
    }
}
void Queue::print(){
    for (int i = 0; i < size; i++)
    {
        std::cout<<arr[i]<<' ';
    }
    std::cout<<'\n';
}

int main(){
    Queue q;
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(1);
    q.dequeue();
    q.enqueue(10);
    std::cout<<q.dequeue();
}