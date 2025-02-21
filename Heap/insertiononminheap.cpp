#include <iostream>
using namespace std;
class MinHeap
{
int *arr;
int size;
int totalSize;

public:
MinHeap(int n)
{
    arr = new int[n];
    size = 0;
    totalSize = n;
}
void insert(int val)
{
    if (size == totalSize)
    {
        cout << "Full";
        return;
    }
    arr[size] = val;
    int index = size;
    size++;
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (arr[parent] > arr[index])
        {
            swap(arr[parent], arr[index]);
            index = parent;
        }
        else
            return;
    }
}
void display()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
};

int main()
{
MinHeap h(5);
h.insert(10);
h.insert(9);
h.insert(12);
h.insert(15);
h.insert(3);
//       10
//       / \
//     9    12
//    / \  
//   15  3 
h.display();
//        3
//       / \
//     9   12
//    / \
//   15  10
return 0;
}

