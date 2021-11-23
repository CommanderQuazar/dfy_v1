//
// Created by Tobey Ragain on 11/12/21.
//

#ifndef DFY_V1_HASHMAP_H
#define DFY_V1_HASHMAP_H

#include "File.h"
#include <unordered_map>

using hash_set_type = std::unordered_map<std::string, std::shared_ptr<File>>;

class HashMap
{
    public:
        HashMap() = default;
        explicit HashMap(const std::string& name, File& file_obj) { hash_set.insert(
                    {name, std::make_shared<File>(file_obj)}); };
        std::shared_ptr<File> add(const std::string& name, File& to_add);
        HashMap& remove(const std::string& name);
        std::pair<size_t, std::shared_ptr<File>> lookup(const std::string& lookup_msg);
        HashMap& print_all();

    private:
        hash_set_type hash_set;
};


#endif //DFY_V1_HASHMAP_H
