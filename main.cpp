#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<map>
#include<string>

#define INF 100000000
#define pi 3.141592654
#define graph std::vector<std::vector<int>>
#define hashset std::map<int, std::unordered_set<int>> // faster to check if the pair is visited or not

using namespace std;

void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
}

#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

class MinHeap
{
private:
    int *array;
    int size;
    int capacity;

    int LeftChild(int idx)
    {
        int p = 2 * idx + 1;
        return p >= size ? -1 : p;
    }

    int RightChild(int idx)
    {
        int p = 2 * idx + 2;
        return p >= size ? -1 : p;
    }

    int parent(int idx)
    {
        return idx == 0 ? -1 : (idx - 1) / 2;
    }

    void heapifyDown(int idx)
    {
        int leftChild = LeftChild(idx);
        int rightChild = RightChild(idx);
        int smallest = idx;

        if (leftChild != -1 && array[leftChild] < array[smallest])
            smallest = leftChild;
        if (rightChild != -1 && array[rightChild] < array[smallest])
            smallest = rightChild;

        if (smallest != idx)
        {
            swap(array[idx], array[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap(int cap = 1000) : size(0), capacity(cap)
    {
        array = new int[capacity];
    }
    MinHeap(const vector<int>&v)//O(N)
    {
        int i=0;
        for(auto it:v)
            this->array[i]=it,i++;
        heapify();



    }
    void heapify()
    {
        for(int i=(size)/2-1;i>=0;i--)
            heapifyDown(i);//
    }

    ~MinHeap()
    {
        delete[] array;
    }
      void heapSort(int *p,int len)
      {
        int*tempArray=array;
        int tempSize=size;
        this->array=p;
        this->size=len;
       heapify();
          while (size--)
          {
              swap(array[0],array[size]);
              heapify();

          }

          this->array=tempArray;
          this->size=tempSize;

      }
    int top()
    {
        if (!isEmpty())
            return array[0];

    }

    void heapifyUp(int idx)
    {
        int parentIdx = parent(idx);
        if (parentIdx == -1 || array[parentIdx] <= array[idx])
            return;
        swap(array[idx], array[parentIdx]);
        heapifyUp(parentIdx);
    }

    void pushKey(int key)
    {

        array[size++] = key;
        heapifyUp(size - 1);
    }

    void pop()
    {
        if (!isEmpty())
        {
            array[0] = array[--size];
            heapifyDown(0);
        }

    }

    bool isEmpty()
    {
        return size == 0;
    }
};
class MaxHeap
{
private:
    int *array;
    int size;
    int capacity;

    int LeftChild(int idx)
    {
        int p = 2 * idx + 1;
        return p >= size ? -1 : p;
    }

    int RightChild(int idx)
    {
        int p = 2 * idx + 2;
        return p >= size ? -1 : p;
    }

    int parent(int idx)
    {
        return idx == 0 ? -1 : (idx - 1) / 2;
    }

    void heapifyDown(int idx)
    {
        int leftChild = LeftChild(idx);
        int rightChild = RightChild(idx);
        int largest = idx;

        if (leftChild != -1 && array[leftChild] > array[largest])
            largest = leftChild;
        if (rightChild != -1 && array[rightChild] > array[largest])
            largest = rightChild;

        if (largest != idx)
        {
            swap(array[idx], array[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap(int cap = 1000) : size(0), capacity(cap)
    {
        array = new int[capacity];
    }
    MaxHeap(const vector<int>&v)//O(N)
    {
        int i=0;
        for(auto it:v)
            this->array[i]=it,i++;
        for(int i=(v.size())/2-1;i>=0;i--)
            heapifyDown(i);//


    }

    ~MaxHeap()
    {
        delete[] array;
    }

    int top()
    {
        if (!isEmpty())
            return array[0];

    }
    bool really(int node)
    {
        int left= LeftChild(node);
        int right= RightChild(node);
        if(right!=-1&&array[node]>array[right])
            return false;
        if(left!=-1&&array[node]>array[left])
            return false;
        if(left!=-1&&right!=-1)
            return really(left)&& really(right);

    }
     bool isHeap(int *p,int n)
    {
       int *temp=p;
       int tempsize=n;
        this->array=p;
        this->size=n;
        bool result=really(0);
        this->array=temp;
        this->size=tempsize;
        return result;
    }

    void heapifyUp(int idx)
    {
        int parentIdx = parent(idx);
        if (parentIdx == -1 || array[parentIdx] >= array[idx])
            return;
        swap(array[idx], array[parentIdx]);
        heapifyUp(parentIdx);
    }

    void pushKey(int key)
    {

        array[size++] = key;
        heapifyUp(size - 1);
    }

    void pop()
    {
        if (!isEmpty())
        {
            array[0] = array[--size];
            heapifyDown(0);
        }

    }

    bool isEmpty()
    {
        return size == 0;
    }
};


int main()
{
    fast();
    vector<int> arr = {3, 5, 1, 10, 2, 7, 6};
    MinHeap heap;
    heap.heapSort(arr.data(), arr.size());

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
