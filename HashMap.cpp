//
// Created by Tobey Ragain on 11/12/21.
//

#include "HashMap.h"
#include <memory>

/*
 * Removes a file from the HashMap
 */
HashMap& HashMap::remove(const std::string& name)
{
    auto ret = hash_set.find(name);
    if(ret == hash_set.end())
        return *this;
    else
        hash_set.erase(name);
    return *this;
}

/*
 * Adds a file into the HashMap
 */
std::shared_ptr<File> HashMap::add(const std::string& name, File &to_add)
{
    auto file_ptr = std::make_shared<File>(to_add);
    hash_set.try_emplace(name, file_ptr);
    return file_ptr;
}

/*
 * Member function takes a string and searches the keys of the map
 * Returns a pair with a status pit and a pointer to the file (if found)
 * If not found returns nullptr
 */
std::pair<size_t, std::shared_ptr<File>> HashMap::lookup(const std::string& lookup_file)
{
    auto ret = hash_set.find(lookup_file);
    if(ret == hash_set.end())
        return {0, nullptr};
    else
        return {1, ret->second};
}

/*
 * Prints all files stored within a HashMap
 */
HashMap& HashMap::print_all()
{
    for(auto begin = hash_set.begin(); begin != hash_set.end(); )
    {
        std::cout << "File Name: "
                  << (*begin++).first
                  //<< "\nMessage: "
                  //<< (*begin++).second->get_msg()
                  << std::endl;
    }
    return *this;
}
