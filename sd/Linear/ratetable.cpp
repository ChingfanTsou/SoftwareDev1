#include <fstream>
#include <iostream>
#include <cstdlib>
#include "con/SeqVec.hpp"

using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::endl;
using std::flush;

struct rateitem
{
    rateitem(int a, double b) :year(a),rate(b) {}
    rateitem() {}
    bool operator==(const rateitem& a)
        {
            return (this->year == a.year);
        }
    int year;
    double rate;
};

int main()
{
    ifstream infile("ratetable.txt");
    ofstream outfile("ratetable.txt");
    SeqVec<rateitem> r_table;
    int y;
    double r;

    while (infile.eof())
    {
        infile >> y >> r;
        r_table.insert(rateitem(y,r));
    }

    int ch;
    cout << "1.insert\n2.delete\n3.check\n4.print\n5.exit\n" << endl;
    while (!cin.eof())
    {
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "please input the time and the rate: " << flush;
            cin >> y >> r;
            r_table.insert(rateitem(y,r));
            break;
        case 2:
            cout << "please input the time: " << flush;
            cin >> y;
            r_table.delByPos(r_table.findByVal(rateitem(y,0)));
            break;
        case 3:
            cout << "please input the time: " << flush;
            cin >> y;
            cout << r_table.findByPos(r_table.findByVal(rateitem(y,0))).rate;
            break;
        case 4:
            for (int p = r_table.first(); p <= r_table.last(); p++)
            {
                if (!r_table.findByPos(p).year)
                {
                    continue;
                }
                cout << r_table.findByPos(p).year << " " << r_table.findByPos(p).rate << endl;
            }
            break;
        case 5:
            for (int p = r_table.first(); p <= r_table.last(); p++)
            {
                outfile << r_table.findByPos(p).year << " " << r_table.findByPos(p).rate << endl;
            }
            exit(0);
        }
        cout << "1.insert\n2.delete\n3.check\n4.print\n5.exit\n" << endl;
    }
    
    infile.close();
    outfile.close();

    return 0;
}
