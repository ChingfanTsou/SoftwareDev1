#include <iostream>
#include "Heap.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n,a[100];
    cout << "How many numbers?" << endl;
    cin >> n;
    cout << "Input the numbers: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    Heap<int> maxHeap(n);
    for (int i = 0; i < n; ++i)
    {
        maxHeap.insert(a[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        cout << maxHeap.getTop() << " ";
    }
    cout << endl;

    return 0;
}
