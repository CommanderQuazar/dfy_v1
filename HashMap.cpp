//
// Created by Tobey Ragain on 11/12/21.
//

#include "HashMap.h"
#include <memory>


HashMap& HashMap::remove(const std::shared_ptr<File>& to_remove)
{
    auto ret = hash_set.find(to_remove);
    if(ret == hash_set.end())
        return *this;
    else
        hash_set.erase(to_remove);
    return *this;
}

HashMap& HashMap::add(File &to_add)
{
    hash_set.insert(std::make_shared<File>(to_add));
    return *this;
}

hash_set_type::iterator& HashMap::lookup(const std::shared_ptr<File>& term)
{
    auto ret = hash_set.find(term);
    return ret;
    //????
}

HashMap& HashMap::print_all()
{
    for(auto begin = hash_set.begin(); begin != hash_set.end(); )
    {
        std::cout << "Massage: "
                  << (*begin++)->get_msg()
                  << std::endl;
    }
    return *this;
}
