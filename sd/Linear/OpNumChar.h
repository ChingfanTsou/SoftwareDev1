#ifndef OPNUMCHAR_H
#define OPNUMCHAR_H

#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::pair;
using std::ostream;

class OpNumChar
{
    friend ostream& operator<<(ostream&, const OpNumChar&);
    
public:
    OpNumChar(const string&, string::const_iterator&); //construct from a string
    OpNumChar();
    ~OpNumChar();
    bool higherThan(const OpNumChar&); //return true if this operator is priorer than that one
    bool isOpt() const;
    double calc(const OpNumChar&, const OpNumChar&);
    double getData() const; //return the number
    char getOpt() const;//return the operator
   
    
private:
    const static bool prepared;
    bool isDec(string::const_iterator);
    double data;
    bool isOp;
    string rawStr;
    static bool prePro();
    static map<char, int> opWeight;
};

#endif /* OPNUMCHAR_H */
