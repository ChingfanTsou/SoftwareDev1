#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    string filename[] = {"data0.in", "data1.in", "data2.in", "data3.in", "data4.in", "data5.in", "data6.in"};

    int pow = 100;
    for (int i = 0; i <= 5; ++i)
    {
        ofstream outfile(filename[i].data(),ios::out);
        
        outfile << pow << endl;
        for (int j = 0; j < pow; j++)
        {
            outfile << rand()%100000000 << endl;
        }
        pow *= 10;
    }
    
    return 0;
}
