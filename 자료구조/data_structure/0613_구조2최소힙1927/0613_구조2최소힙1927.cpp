#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int temp = b;
    b = a;
    a = temp;
}

int heap[100001];
int heapsize = 0;

int pop()
{
    int ans = heap[1];
    heap[1] = heap[heapsize];
    heap[heapsize] = 2147483647;
    heapsize--;
    for (int i = 1; i * 2 <= heapsize;)
    {
        if (heap[i] < heap[i * 2] && heap[i] < heap[i * 2 + 1]) {
            break;
        }
        else if (heap[i * 2] < heap[i * 2 + 1]) {
            swap(heap[i], heap[i * 2]);
            i = i * 2;
        }
        else {
            swap(heap[i], heap[i * 2 + 1]);
            i = i * 2 + 1;
        }
    }
    return ans;

}

void push(int x)
{
    heapsize++;
    heap[heapsize] = x;

    for (int i = heapsize; i > 1; i /= 2)
    {
        if (heap[i] < heap[i / 2])
        {
            swap(heap[i], heap[i / 2]);
        }
        else
            break;
    }
}



int N;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin >> N;
    int input;
    for (int i = 0; i < N; ++i)
    {

        cin >> input;
        if (0 == input)
        {
            if (heapsize == 0) {
                cout << "0" << "\n";
            }
            else
                cout << pop() <<"\n";
        }
        else
        {
            push(input);
        }
    }
}
