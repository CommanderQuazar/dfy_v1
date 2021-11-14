#include <iostream>

#include "HashMap.h"

int main()
{
    HashMap h_set;

    for (int i = 0; i < 5; ++i)
    {
        std::string in, name;
        std::cin >> name >> in;
        File tmp(in);
        h_set.add(name, tmp);
    }

    if(h_set.lookup("Lookup"))
        std::cout << "Found!" << std::endl;
    else
        std::cout << "Not Found!" << std::endl;

    h_set.print_all();
}
