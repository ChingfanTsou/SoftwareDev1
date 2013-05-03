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
    OpenHash<Rand, mod>* rand_table = new OpenHash<Rand, mod>(m);
    OpenHash<Fold, mod>* fold_table = new OpenHash<Fold, mod>(m);

    for (int i = 1; i <= 10*m; ++i)
    {
        kmod_table -> insert(i);
        rand_table -> insert(i);
        fold_table -> insert(i);
    }

    long long tot1=0;
    long long tot2=0;
    long long tot3=0;
    for (int i = 1; i <= 10*m; ++i)
    {
        kmod_table -> search(i);
        tot1 += kmod_table->get_q_time();
        rand_table -> search(i);
        tot2 += rand_table->get_q_time();
        fold_table -> search(i);
        tot3 += fold_table->get_q_time();
    }

    cout << "Mod Hash Function ASL:" << double(tot1) / m << endl;
    cout << "Random Hash Function ASL:" << double(tot2) / m << endl;
    cout << "Fold Hash Function ASL:" << double(tot3) / m << endl;

    delete kmod_table;
    delete rand_table;
    /*-----------------------------------------*/

    CloseHash<KMod, mod>* close_table1 = new CloseHash<KMod, mod>(m);
    CloseHash<KMod, 199999>* close_table2 = new CloseHash<KMod,199999>(m*2);
    CloseHash<KMod, 299993>* close_table3 = new CloseHash<KMod,299993>(m*3);
    CloseHash<KMod, 399989>* close_table4 = new CloseHash<KMod,399989>(m*4);

    ifstream infile("data.in",ios::in);
    int ran[m+1];
    for (int i = 1; i <= mod; ++i)
    {
        infile >> ran[i];
        close_table1 -> insert(ran[i]);
        close_table2 -> insert(ran[i]);
        close_table3 -> insert(ran[i]);
        close_table4 -> insert(ran[i]);
    }

    long long tot[5];
    memset(tot,0,sizeof(tot));

    for (int i = 1; i <= mod; ++i)
    {
        close_table1 -> search(ran[i]);
        tot[1] += close_table1->get_q_time();
        close_table2 -> search(ran[i]);
        tot[2] += close_table2->get_q_time();
        close_table3 -> search(ran[i]);
        tot[3] += close_table3->get_q_time();
        close_table4 -> search(ran[i]);
        tot[4] += close_table4->get_q_time();
    }

    for (int i=1;i<=4;i++)
    {
        cout << "Alpha = "<< double(mod)/(m*i) << " ASL = " << double(tot[i])/mod << endl;
    }

        delete close_table3;
        delete close_table4;
        delete close_table1;
        delete close_table2;
    /*--------------------------------------*/

        int base = 10000;
        for (int j = 1; j <= 10; ++j)
        {
            OverFlowHash<KMod, mod>* of_table = new OverFlowHash<KMod, mod>(m);
            for (int i = 1; i <= base; ++i)
            {
                of_table -> insert(ran[i]);
            }

            tot1=0;
            for (int i = 1; i <= base; ++i)
            {
                of_table -> search(ran[i]);
                tot1 += of_table->get_q_time();
            }

            cout << "n = " << base <<" ASL = " << double(tot1)/base << endl;
            base += 10000;
            delete of_table;
        }

        base = 10000;
        for (int j = 1; j <= 10; ++j)
        {
            OverFlowHash<KMod, mod>* of_table = new OverFlowHash<KMod, mod>(m);
            for (int i = 1; i <= base; ++i)
            {
                of_table -> insert(i);
            }

            tot1=0;
            for (int i = 1; i <= base; ++i)
            {
                of_table -> search(i);
                tot1 += of_table->get_q_time();
            }

            cout << "n = " << base <<" ASL = " << double(tot1)/base << endl;
            base += 10000;
            delete of_table;
        }

    return 0;
}
