//
// Created by Tobey Ragain on 11/15/21.
//

#ifndef DFY_V1_FILESYSTEMMANAGER_H
#define DFY_V1_FILESYSTEMMANAGER_H

#include <iostream>
#include <map>
#include "Folder.h"
#include "HashMap.h"

class FileSystemManager
{
	#define IS_NEW 0
	#define IS_CURR 1

    public:
        //Constructors
        explicit FileSystemManager(std::ostream& out_stream) : out(out_stream) { };
        FileSystemManager(HashMap * table, std::map<std::string, Folder>& dir, std::ostream& out_stream) :
                            system_layout({table, dir}), out(out_stream) { };
        //Display
        FileSystemManager& display_all_folders() ;
        FileSystemManager& display_all_files();
        FileSystemManager& display_all();

        //Creators
        FileSystemManager& create_folder();
        FileSystemManager& create_file();

        //Movers
        FileSystemManager& move_file();

        //Deletes
        FileSystemManager& delete_file() { };
        FileSystemManager& delete_folder() { };
    private:
        std::ostream& out;
        std::pair<HashMap *, std::map<std::string, Folder>> system_layout;
		bool chk_folder_name(const std::string& posi_name);
		std::string get_folder_name(int MODE);
};


#endif //DFY_V1_FILESYSTEMMANAGER_H
