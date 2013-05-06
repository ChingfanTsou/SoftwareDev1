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

int main(int argc, char *argv[])
{
    string filename[] = {"data0.in", "data1.in", "data2.in", "data3.in", "data4.in", "data5.in", "data6.in"};

    ifstream* infile;
    
    int n;
    vector<int>* data;
    vector<int>* buf;

    int pow = 100;
    for (int i = 0; i < 6; ++i)
    {
        infile = new ifstream(filename[i].data(), ios::in);
        *infile >> n;
        data = new vector<int>(n);
        for (int j = 0; j < n; ++j)
        {
            *infile >> (*data)[j];
        }

        cout << pow << ": " << endl;
        Bubble bs;
        buf = new vector<int>(*data);
        bs(*buf);
        cout << "Comparing times of Bubble Sort is : " << bs.com << endl;
        cout << "Exchanging times of Bubble Sort is : " << bs.chg << endl;
        delete buf;

        cout << pow << ": " << endl;
        Heap hs;
        buf = new vector<int>(*data);
        hs(*buf);
        cout << "Comparing times of Heap Sort is : " << hs.com << endl;
        cout << "Exchanging times of Heap Sort is : " << hs.chg << endl;
        delete buf;

        cout << pow << ": " << endl;
        Insert ins;
        buf = new vector<int>(*data);
        ins(*buf);
        cout << "Comparing times of Insert Sort is : " << ins.com << endl;
        cout << "Exchanging times of Insert Sort is : " << ins.chg << endl;
        delete buf;

        cout << pow << ": " << endl;
        Shell shs;
        buf = new vector<int>(*data);
        shs(*buf);
        cout << "Comparing times of Shell Sort is : " << shs.com << endl;
        cout << "Exchanging times of Shell Sort is : " << shs.chg << endl;
        delete buf;

        cout << pow << ": " << endl;
        Quick qs;
        buf = new vector<int>(*data);
        qs(*buf);
        cout << "Comparing times of Quick Sort is : " << qs.com << endl;
        cout << "Exchanging times of Quick Sort is : " << qs.chg << endl;
        delete buf;

        cout << pow << ": " << endl;
        Select ses;
        buf = new vector<int>(*data);
        ses(*buf);
        cout << "Comparing times of Select Sort is : " << ses.com << endl;
        cout << "Exchanging times of Select Sort is : " << ses.chg << endl;
        delete buf;

        cout << pow << ": " << endl;
        Merge ms;
        buf = new vector<int>(*data);
        ms(*buf);
        cout << "Comparing times of Merge Sort is : " << ms.com << endl;
        cout << "Exchanging times of Merge Sort is : " << ms.chg << endl;
        delete buf;

        cout << pow << ": " << endl;
        Radix rs;
        buf = new vector<int>(*data);
        rs(*buf);
        cout << "Distribution times of Radix Sort is : " << rs.chg << endl;
        delete buf;
        
        infile -> close();
        delete infile;
        pow *=10;
        delete data;
    }
    return 0;
}
