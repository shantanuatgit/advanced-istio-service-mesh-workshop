#include<bits/stdc++.h>
using namespace std;
class heap
{
    int *arr;
    int capacity,heap_size;
public:
     heap(int capacity)
     {
         this->capacity=capacity;
         heap_size=0;
         arr=new int[capacity];
     }
     void heapify(int i);
     int parent(int i)
     {
         return (i-1)/2;
     }
     int left(int i)
     {
         return (2*i+1);
     }
     int right(int i)
     {
         return (2*i+2);
     }
     int extractMin();
     int getMin()
     {
         return arr[0];
     }
     void insertKey(int k);
};

void change(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void heap :: insertKey(int k)
{
    if(heap_size==capacity)
    {
        cout<<"heap overflow";
        return;
    }
    heap_size++;
    int i=heap_size-1;
    arr[i]=k;
    while(i!=0&&arr[parent(i)]>arr[i])
    {
        change(&arr[i],&arr[parent(i)]);
        i=parent(i);
    }

}
void heap :: heapify(int i)
{
    int l=left(i),r=right(i);
    int smallest=i;
    if(l<heap_size&&arr[l]<arr[i])
        smallest=l;
    if(r<heap_size&&arr[r]<arr[smallest])
        smallest=r;
    if(smallest!=i)
    {
        change(&arr[i],&arr[smallest]);
        heapify(smallest);
    }
}

int heap :: extractMin()
{
    int root=arr[0];
    arr[0]=arr[heap_size-1];
    heap_size--;
    heapify(0);
    return root;
}
int main()
{
    heap h(11);
    h.insertKey(3);
    h.insertKey(2);
    //h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout<<h.extractMin()<<" ";
    cout<<h.getMin();
}
