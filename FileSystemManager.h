//
// Created by Tobey Ragain on 11/15/21.
//

#ifndef DFY_V1_FILESYSTEMMANAGER_H
#define DFY_V1_FILESYSTEMMANAGER_H

#include <map>
#include "HashMap.h"
#include "Folder.h"
#include "unistd.h"

#define LIMIT 4
typedef std::pair<std::map<std::string, Folder>::iterator, std::shared_ptr<File>> target_t;

class FileSystemManager
{
	#define IS_NEW 0
	#define IS_CURR 1

    public:
        //Constructors
        explicit FileSystemManager(std::ostream& out_stream) : out(out_stream) { };
        FileSystemManager(HashMap table, std::map<std::string, Folder>& dir, std::ostream& out_stream) :
                            system_layout({table, dir}), out(out_stream) { };
        //Display
        FileSystemManager& display_all_folders();
        FileSystemManager& display_all_files();
        FileSystemManager& display_all();

        //Creators
        FileSystemManager& create_folder();
        FileSystemManager& create_file();

        //Movers
        FileSystemManager& move_file();
		FileSystemManager& copy();

        //Deletes
        FileSystemManager& delete_file();
        FileSystemManager& delete_folder();
    private:
        std::ostream& out;
		std::pair<HashMap, std::map<std::string, Folder>> system_layout;
		static inline void clearScreen();
		std::string get_folder_name(int MODE);
		bool chk_folder_name(const std::string& posi_name);
		std::string get_file_name(int MODE, std::map<std::string, Folder>::iterator);
		target_t get_target_triple();
		target_t get_target_double();
};


#endif //DFY_V1_FILESYSTEMMANAGER_H
