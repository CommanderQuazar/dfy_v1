//
// Created by Tobey Ragain on 11/12/21.
//

#include "HashMap.h"
#include <memory>

HashMap& HashMap::remove(const std::string& name)
{
    auto ret = hash_set.find(name);
    if(ret == hash_set.end())
        return *this;
    else
        hash_set.erase(name);
    return *this;
}

HashMap& HashMap::add(const std::string& name, File &to_add)
{
    hash_set.insert({name, std::make_shared<File>(to_add)});
    return *this;
}

bool HashMap::lookup(const std::string& lookup_file)
{
    auto ret = hash_set.find(lookup_file);
    if(ret == hash_set.end())
        return false;
    else
        return true;
}

HashMap& HashMap::print_all()
{
    for(auto begin = hash_set.begin(); begin != hash_set.end(); )
    {
        std::cout << "File Name: "
                  << (*begin).first
                  << "\nMessage: "
                  << (*begin++).second->get_msg()
                  << std::endl;
    }
    return *this;
}
