#include <iostream>
#include <string>

#include "con/QueueList.hpp"

using std::cin;
using std::cout;
using std::string;
using std::endl;

typedef QueueList<string> Line;

int main()
{
    Line man;
    Line woman;

    while (1)
    {
        int gender;
        string name;
        cin >> gender >> name;
if (gender < 0)
{
break;
}
        if (gender)
        {
            man.enQueue(name);
        }
        else
        {
            woman.enQueue(name);
        }
    }

    cout << "These people would dance with each other:" << endl;
    while (!(man.isEmpty()||woman.isEmpty()))
    {
cout << "Mr. " << man.deQueue() << " with " << "Mz. " << woman.deQueue() << endl;
    }

    if (!man.isEmpty())
    {
        cout << "These gentlemen have to wait for the next round:" << endl;
        while (!man.isEmpty())
        {
            cout << "Mr. " << man.deQueue() << endl;
        }
    }

    if (!woman.isEmpty())
    {
        cout << "These ladies have to wait for the next round:" << endl;
        while (!man.isEmpty())
        {
            cout << "Mz. " << man.deQueue() << endl;
        }
    }
        
    return 0;
}
