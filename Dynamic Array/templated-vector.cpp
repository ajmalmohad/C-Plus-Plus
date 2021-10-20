#include <iostream>

template <typename T>
class MyVector{
    public:
        MyVector(int);
        
        void print();
        int size();
        int capacity();
        bool is_empty();
        void memory_status();
        void append(T);
        void prepend(T);
        void insert(int,T);
        void delete_index(int);
        int get(int);
        int find(T);
        int pop();
        void remove(T);

    private:
        T *arr;
        int room;
        int length=0;

        void resize(int);
        void check_resize();
};

//Constructor
template <typename T>
MyVector<T>::MyVector(int init){
    room = init;
    arr = new T[room];
}

//Private
template <typename T>
void MyVector<T>::resize(int r){
    T *temp = new T[room];
    for (int i = 0; i < length; i++) *(temp+i) = *(arr+i);
    delete[] arr;
    arr = temp;
}

template <typename T>
void MyVector<T>::check_resize(){
    if(length==room){
        room*=2;
        resize(room);
    }else if(length<(room/4)){
        room /= 2;
        resize(room);
    }
}

//Public
template <typename T>
void MyVector<T>::print(){
    std::cout<<"[";
    for (int i = 0; i < length; i++)
    {
        std::cout<<*(arr+i);
        (i<length-1)? std::cout<<", " : std::cout<<"";
    }
    std::cout<<"]\n";
}

template <typename T>
void MyVector<T>::memory_status(){
    for (int i = 0; i < room; i++) 
        std::cout<<arr+i<<" = "<<*(arr+i)<<'\n';
    std::cout<<'\n';
}

template <typename T>
int MyVector<T>::size(){
    return length;
}

template <typename T>
int MyVector<T>::capacity(){
    return room;
}

template <typename T>
bool MyVector<T>::is_empty(){
    return !length ? true: false;
}

template <typename T>
void MyVector<T>::append(T n){
    length++;
    check_resize();
    *(arr+(length-1))=n;
};

template <typename T>
void MyVector<T>::prepend(T n){
    insert(0,n);
};

template <typename T>
void MyVector<T>::insert(int i,T n){
    if(i>length || i<0) return;
    length++;
    check_resize();
    for (int j = length; j >i ; j--) *(arr+(j-1)) = *(arr+(j-2));
    *(arr+i) = n;
}

template <typename T>
int MyVector<T>::pop(){
    T temp = *(arr+(length-1));
    *(arr+(length-1))=0;
    length--;
    check_resize();
    return temp;
}

template <typename T>
void MyVector<T>::delete_index(int idx){
    if(idx>=length || idx<0) return;
    length--;
    for (int i = idx; i <length; i++) *(arr+i) = *(arr+(i+1));
    *(arr+length)=0;
    check_resize();
}

template <typename T>
int MyVector<T>::get(int i){
    return (i<length && i>=0) ? *(arr+i) : -1;
}

template <typename T>
int MyVector<T>::find(T v){
    for (int i = 0; i < length; i++) if(*(arr+i)==v)return i;
    return -1;
}

template <typename T>
void MyVector<T>::remove(T v){
    for (int i = 0; i < length; i++){
        if(*(arr+i)==v){
            delete_index(i);
            i--;
        }
    }
}

//Entry
int main(){
    MyVector<std::string> myarr(2);
    myarr.append("Hello");
    myarr.append("My");
    myarr.append("Dear");
    myarr.append("Students");
    myarr.print();
};


// print(); Prints all Elements of Array
// size(); Prints Size of Array
// capacity(); Prints Capacity of Array
// is_empty(); Know whether empty or not
// memory_status(); Display values stored in allocated memories
// append(int); Append Element to End
// prepend(int); Prepend Element to Start
// insert(int,int); Inserts Element at desired Index (index, Value)
// delete_index(int); Deletes Value at Specified Index
// get(int); Gets element at specified index
// find(int); Find index by value
// pop(); Pops Last Item


// http://hastebin.com/qoramudugo.cpp