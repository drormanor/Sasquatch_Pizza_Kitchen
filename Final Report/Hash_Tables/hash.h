#include<cstdlib>
#include<iostream>
#include<string>

using namespace std;

#ifndef HASH_H
#define HASH_H

class Hash
{
private:
    size_t tableSize = 10;
public:
    Hash();
    int makeHash(string key);


};



#endif