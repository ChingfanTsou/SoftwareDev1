#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ofstream outfile("data.in",ios::out);
    for (int i =0;i< 100000;i++)
        outfile<<rand()<<endl;
    return 0;
}
