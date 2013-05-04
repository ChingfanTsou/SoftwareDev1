#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    ofstream outfile("data.in", ios::out);
    
    int n = 100;
    outfile << n << endl;
    for (int i = 0; i < n; ++i)
    {
        outfile << rand()%10000 << endl;
    }
    return 0;
}
