#include<cstdlib>
#include<iostream>
#include<string>

#include "hash.h"

using namespace std;
    Hash::Hash()
    {
    }
    int Hash::makeHash(string key)
    {
        int hash = 0;
        int index;

        for(int i =0; i < key.length(); i++)
        {
            int p = (int)key[i];
            cout << key[i] << " = " << p << endl;
            hash += (int)key[i];
        }
        index =  hash % tableSize;

        return index;
    }
