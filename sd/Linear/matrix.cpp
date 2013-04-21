#include <iostream>

using std::cin;
using std::cout;
using std::flush;
using std::endl;

struct Cell
{
    int col;
    int row;
    int data;
}mat[1000];

int main()
{
    int n,m,x;
    cout << "Input the number of rows: " << flush;
    cin >> n;
    cout << "\nInput the number of columns: " << flush;
    cin >> m;
    cout << "\nInput the " << n << "*" << m << " matrix:" << endl;

    int tot = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> x;
            if (x)
            {
                mat[++tot].col = j;
                mat[tot].row = i;
                mat[tot].data = x;
            }
        }

    //transposition;
    for (int i = 0; i < m; ++i)
    {
        int k = 0;
        for (int j = 0; j <= tot; ++j)
        {
            if (mat[j].col == i)
            {
                for (int c = 0; c < mat[j].row - k; c++)
                {
                    cout << "0 ";
                }
                cout << mat[j].data << " ";
                k = mat[j].row + 1;
            }
            if (mat[j].row == n - 1)
            {
                break;
            }
        }
        for (int c = 0; c < n - k; c++)
        {
            cout << "0 ";
        }
        cout << endl;
    }
    
    return 0;
}
