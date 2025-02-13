#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
class CDL
{
public:
    Node *head;
    Node *tail;
    CDL()
    {
        head = NULL;
        tail = NULL;
    }
    void insertatEnd(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = newNode;
            tail = newNode;
            head->next = head;
            head->prev = head; // Points to itself
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail = newNode; // Update tail to the new node
    }
    void display()
    {
        cout << tail->prev->data;
        cout << tail->next->data;
    }
};
int main()
{
    CDL head;
    head.insertatEnd(3);
    head.insertatEnd(4);
    head.insertatEnd(5);
    head.insertatEnd(6);
    head.display();
    // cout<<head->next->data;
    // cout<<head->next->prev->data;
    // cout<<head->next->next->next->data;
    // cout<<head->next->next->next->prev->data;
}