#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#include "Bubble.h"
#include "Heap.h"
#include "Insert.h"
#include "Quick.h"
#include "Shell.h"
#include "Select.h"
#include "Radix.h"
#include "Merge.h"

int main()
{
    int n;
    ifstream infile("data.in", ios::in);
    infile >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++)
    {
        infile >> data[i];
    }
    
    Merge bs;
    bs(data);

    for (int i = 0; i < n; i++)
    {
        cout << data[i] << endl;
    }

    return 0;
}
