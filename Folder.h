//
// Created by Tobey Ragain on 11/12/21.
//

#ifndef DFY_V1_FOLDER_H
#define DFY_V1_FOLDER_H

#include <iostream>
#include <set>
#include <utility>
#include "File.h"
#include "HashMap.h"

class Folder
{
    public:
        Folder() = default;
        explicit Folder(std::string  f_name) : folder_name(std::move(f_name)) { };

        Folder& add(File& file, HashMap& map);
        Folder& remove(const std::shared_ptr<File>& key, HashMap& map);
        std::set<std::shared_ptr<File>>::iterator search(std::string& term, HashMap& map);

        std::string get_folder_name() const { return folder_name; };
        void print_files(std::ostream& out_s) const;

    private:
        std::string folder_name;
        std::set<std::shared_ptr<File>> content;
};


#endif //DFY_V1_FOLDER_H
