  #include <iostream>
using namespace std;
class Deque
{
    int *arr;
    int K;
    int front;
    int rear;
    int count;

public:
    Deque(int k)
    {
        k = K;
        arr = new int[K];
        front = 0;
        rear = K - 1;
        count = 0;
    }
    bool insertFront(int value)
    {
        if(isFull()) return false;
        front=(front-1+K)%K;
        arr[front]=value;
        count++;
        return true;
    }
    bool insertLast(int value)
    {
        if(isFull()) return false;
        rear=(rear+1)%K;
        arr[rear]=value;
        count++;
        return true;
    }
    bool deleteFront()
    {
        if(isEmpty()) return false;
        front=(front+1)%K;
        count--;
        return true;
    }
    bool deleteLast()
    {
        if(isEmpty()) return false;
        rear=(rear-1+K)%K;
        return true;
    }
    int getFront()
    {
        if(isEmpty()) return -1;
        return arr[front];
    }
    int getRear()
    {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    bool isEmpty()
    {
        return count==0;
    }
    bool isFull()
    {
        return count==K;
    }
    void display(){
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int size(){
        return count;
    }
};
int main()
{
    Deque d(10);
    d.insertFront(12);
    d.insertFront(13);
    d.insertFront(14);
    d.insertFront(15);
    d.insertFront(16);
    d.display();
    d.deleteFront();
    d.display();
    d.deleteLast();
    d.display();
    cout<<d.getFront();
    cout<<d.getRear();
    // cout<<d.size();
}
