#include <iostream>
#include <cstdlib>
#include "con/SeqList.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::flush;

struct PolyItem
{
    PolyItem(int a, double b) :exp(a),coef(b) {}
    bool operator==(const PolyItem& ot)
        {
            return (this->exp == ot.exp);
        }
    int exp;
    double coef;
};

typedef SeqList<PolyItem> Poly;

void read_poly(Poly& p)
{
    int e;
    double c;
    while (1)
    {
        cin >> e >> c;
        if (e == -1)
        {
            break;
        }
        p.insert(PolyItem(e, c), p.last());
    }
}

void add(Poly& p1, Poly& p2)
{
    for (Poly::Node* p = p2.first(); p != p2.llast(); p = p -> next)
    {
        Poly::Node* m_it = p1.findByVal(p -> data);
        if (m_it)
        {
            m_it->data.coef += p -> data.coef;
        }
        else
        {
            p1.insert(p->data, p1.last());
        }
    }
}

void nummul(Poly& p1, int fac)
{
    for (Poly::Node* p = p1.first(); p != p1.llast(); p = p -> next)
    {
        p -> data.coef *= fac;
    }
}

void mul(Poly& p1, Poly& p2)
{
    Poly& p3 = *(new Poly());
    PolyItem* m_it;
    Poly::Node* n_it;
    for (Poly::Node* ptr1 = p1.first(); ptr1 != p1.llast(); ptr1 = ptr1 -> next)
        for (Poly::Node* ptr2 = p2.first(); ptr2 != p2.llast(); ptr2 = ptr2 -> next)
        {
            m_it = new PolyItem(ptr1->data.exp+ptr2->data.exp, ptr1->data.coef*ptr2->data.coef);
            n_it = p3.findByVal(*m_it);
            if (n_it)
            {
                n_it->data.coef += m_it -> coef;
            }
            else
            {
                p3.insert(*m_it, p3.last());
            }
            delete m_it;
        }
    p1=p3;//与指针不同，此处相当与poly1=p3,poly1原有值被丢弃
}

void write(const Poly& p1)
{
    for (Poly::Node* p = p1.first(); p != p1.llast(); p = p -> next)
    {
        cout << p -> data.exp << " " << p -> data.coef << endl;
    }
}
int main()
{
    Poly poly1;
    Poly poly2;
    
    cout << "Please input the first polynomial" << endl;
    read_poly(poly1);
    cout << "Please input the second polynomial" << endl;
    read_poly(poly2);

    cout << "Operatin?\n1.+\n2.-\n3.*\n4.\\\n" << endl;

    int inst;
    cin >> inst;

    switch (inst)
    {
    case 1:
        add(poly1, poly2);
        write(poly1);
        break;
    case 2:
        nummul(poly2, -1);
        add(poly1, poly2);
        write(poly1);
        break;
    case 3:
        mul(poly1, poly2);
        write(poly1);
    }
    return 0;
}
