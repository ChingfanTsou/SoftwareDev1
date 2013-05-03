#include <iostream>
#include <fstream>
#include <cstring>

#include "HashExp.h"
#include "CloseHash.h"
#include "OpenHash.h"
#include "OverFlowHash.h"
#include "HashFun.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ios;

int main()
{
    int m = 100000;
    const int mod = 99991;
    OpenHash<KMod, mod>* kmod_table = new OpenHash<KMod, mod>(m);

    cout << "OpenHash: " << endl;
    for (int i = 1; i <= 10; ++i)
    {
        cout << "Insert " << i << endl;
        kmod_table -> insert(i);
    }

    for (int i = 1; i <= 10; ++i)
    {
        cout << "find " << i << " true:1 false:0  --->" << kmod_table -> find(i) << endl;
    }

    cout << "find " << 90 << " true:1 false:0  --->" << kmod_table -> find(90) << endl;
    cout << "find " << 23 << " true:1 false:0  --->" << kmod_table -> find(23) << endl;
    delete kmod_table;

    /*-----------------------------------------*/

    cout << "CloseHash: " << endl;
    CloseHash<KMod, mod>* close_table1 = new CloseHash<KMod, mod>(m);

    ifstream infile("data.in",ios::in);
    int ran[m+1];
    for (int i = 1; i <= 10; ++i)
    {
        infile >> ran[i];
        cout << "Insert " << ran[i] << endl;
        close_table1 -> insert(ran[i]);
    }

    for (int i = 1; i <= 10; ++i)
    {
        cout << "find " << ran[i] << " true:1 false:0  --->" << close_table1 -> find(ran[i]) << endl;
    }

    cout << "find " << 5 << " true:1 false:0  --->" << close_table1 -> find(5) << endl;
    cout << "find " << 9 << " true:1 false:0  --->" << close_table1 -> find(9) << endl;
    cout << "find " << 22 <<" true:1 false:0  --->" << close_table1 -> find(22) << endl;

    delete close_table1;

    /*--------------------------------------*/

    cout << "OverFlowHash: " << endl;
        int base = 10;

        OverFlowHash<KMod, mod>* of_table = new OverFlowHash<KMod, mod>(m);
        for (int i = 1; i <= base; ++i)
        {
            cout << "Insert " << ran[i] << endl;
            of_table -> insert(ran[i]);
        }

        for (int i = 1; i <= base; ++i)
        {
            cout << "find " << ran[i] << " true:1 false:0  --->" << of_table -> find(ran[i]) << endl;
        }
        cout << "find " << 301 << " true:1 false:0  --->" << of_table -> find(301) << endl;
        cout << "find " << 302 << " true:1 false:0  --->" << of_table -> find(302) << endl;
        cout << "find " << 333 << " true:1 false:0  --->" << of_table -> find(333) << endl;

        delete of_table;

    return 0;
}
