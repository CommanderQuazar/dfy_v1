//
// Created by Tobey Ragain on 11/15/21.
//

#ifndef DFY_V1_FILESYSTEMMANAGER_H
#define DFY_V1_FILESYSTEMMANAGER_H

#include <iostream>
#include "Folder.h"
#include "HashMap.h"

class FileSystemManager
{
    public:
        //Constructors
        FileSystemManager() = default;
        FileSystemManager(HashMap * table, std::set<Folder>& dir) : system_layout({table, dir}) { };

        //Display
        FileSystemManager& display_all_folders() const { };
        FileSystemManager& display_all_files() const { };
        FileSystemManager& display_all() const { };

        //Creators
        FileSystemManager& create_folder() { };
        FileSystemManager& create_file() { };

        //Movers
        FileSystemManager& move_file() { };

        //Deletes
        FileSystemManager& delete_file() { };
        FileSystemManager& delete_folder() { };

    private:
        std::pair<HashMap *, std::set<Folder>> system_layout;
};


#endif //DFY_V1_FILESYSTEMMANAGER_H
