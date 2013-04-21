#include "OpNumChar.h"

OpNumChar::OpNumChar(const string& str, string::const_iterator& ptr)
    :isOp(false), data(0)
{
    if ('0' <= *ptr && *ptr <= '9')
    {
        double weight = 1;
        for (;ptr != str.end() && isDec(ptr); ptr++)
        {
            rawStr += *ptr;
            if ('0' <= *ptr && *ptr <= '9')
            {
                data *= weight; 
                data += *ptr - '0';
                weight *= 10;
            }
            else if (*ptr == '.')
            {
                weight = 0.1;
                double fra = 0;
                for(++ptr; ptr != str.end() && isDec(ptr); ptr++)
                {
                    fra += (*ptr - '0') * weight;
                    weight *= 0.1;
                }
                data += fra;
                break;
            }
        }
    }
    else
    {
        isOp = true;
        rawStr.push_back(*ptr);
        ++ptr;
    }
}

OpNumChar::~OpNumChar()
{
}

bool OpNumChar::isDec(string::const_iterator p)
{
    if ('0' <= *p && *p <= '9' || *p == '.')
    {
        return true;    
    }
    else
    {
        return false;
    }
}

bool OpNumChar::isOpt() const
{
    return (isOp);
}

map<char, int> OpNumChar::opWeight;
bool OpNumChar::prePro()
{
    opWeight.insert(pair<char, int> ('(', 10000));
    opWeight.insert(pair<char, int> ('+', 0));
    opWeight.insert(pair<char, int> ('-', 0));
    opWeight.insert(pair<char, int> ('*', 10));
    opWeight.insert(pair<char, int> ('/', 10));
    return true;
}

const bool OpNumChar::prepared = OpNumChar::prePro();

bool OpNumChar::higherThan(const OpNumChar& op)
{
    return (opWeight.find(rawStr.at(0)) -> second > opWeight.find(op.getOpt()) -> second);
}

double OpNumChar::calc(const OpNumChar& opt, const OpNumChar& opd)
{
    switch (opt.getOpt())
    {
    case '*':
        data *= opd.getData();
        break;
    case '+':
        data += opd.getData();
        break;
    case '-':
        data = opd.getData() - data;
        break;
    case '/':
        data = opd.getData() / data;
    }
}

double OpNumChar::getData() const
{
    return data;
}

char OpNumChar::getOpt() const
{
    return rawStr.at(0);
}

bool isDec(const string::const_iterator& p)
{
    if (*p == '.')
    {
        return true;    
    }
    else if (*p >= '0' && *p <= '9')
    {
        return true;
    }
    return false;
}

OpNumChar::OpNumChar()
{
}

ostream& operator<<(ostream &output, const OpNumChar& it)
{
    if (it.isOpt())
    {
        output << it.rawStr;
    }
    else
    {
        output << it.data;
    }
    return output;
}
