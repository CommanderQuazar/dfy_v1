#include <iostream>

#include "HashMap.h"

int main()
{
    HashMap h_set;

    for (int i = 0; i < 5; ++i)
    {
        std::string in;
        std::cin >> in;
        File tmp(in);
        h_set.add(tmp);
    }

    if(h_set.lookup() == h_set.end())

    h_set.print_all();
}
