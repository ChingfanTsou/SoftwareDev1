#ifndef HASHEXP_H
#define HASHEXP_H

#include <stdexcept>
using std::runtime_error;

calss DuplicateExp : public runtime_error
{
public:
    DuplicateExp()
        :runtime_error("Duplicate Keyword!")
    {}
};

class TableFull : public runtime_error
{
public:
    TableFull()
        :runtime_error("Hash Table Overflow!")
    {}
};

#endif /* HASHEXP_H */
