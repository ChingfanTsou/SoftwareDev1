#include <iostream>
#include <fstream>

#include "HuffTree.hpp"

using std::cout;
using std::ifstream;
using std::ios;
using std::ifstream;

int main()
{
    string t;
    ifstream inFile("text.in", ios::in);
    inFile >> t;
    
    HuffTree* ft = new HuffTree(t);
    ft -> outHuff(); //output the characters' huffman code;
    
    ft -> conCode(); //output the huffman code of the text;
    
    ft -> deCode(); //decode the huffman code;
    
    return 0;
}
