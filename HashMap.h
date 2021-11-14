//
// Created by Tobey Ragain on 11/12/21.
//

#ifndef DFY_V1_HASHMAP_H
#define DFY_V1_HASHMAP_H

#include "File.h"
#include <iostream>
#include <unordered_set>

using hash_set_type = std::unordered_set<std::shared_ptr<File>>;

class HashMap
{
    public:
        HashMap() = default;
        explicit HashMap(File& file_obj) { hash_set.insert(std::make_shared<File>(file_obj)); };

        HashMap& add(File& to_add);
        HashMap& remove(const std::shared_ptr<File>& to_remove);
        bool lookup(const std::shared_ptr<File>& term);
        HashMap& print_all();

    private:
        hash_set_type hash_set;

};


#endif //DFY_V1_HASHMAP_H
