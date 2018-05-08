#include<cstdlib>
#include<iostream>
#include<string>

#include "hash.h"

using namespace std;

int main()
{
    Hash h;
    string s;

    while (s != "off") 
    {
    cin >> s;
    cout <<  h.makeHash(s) << endl;
    }


    return EXIT_SUCCESS;
}