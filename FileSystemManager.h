//
// Created by Tobey Ragain on 11/15/21.
//

#ifndef DFY_V1_FILESYSTEMMANAGER_H
#define DFY_V1_FILESYSTEMMANAGER_H

#include <map>
#include "HashMap.h"
#include "Folder.h"
#include "unistd.h"

struct triple_type
{
	std::map<std::string, Folder>::iterator target;
	std::shared_ptr<File> action_file;
	std::map<std::string, Folder>::iterator root;
};

struct double_type
{
	std::map<std::string, Folder>::iterator target;
	std::shared_ptr<File> action_file;
};

class FileSystemManager
{
	#define IS_NEW 0
	#define IS_CURR 1
	#define LIMIT 4

	public:
		//Constructors
		explicit FileSystemManager(std::ostream& out_stream) : out(out_stream) { };
		FileSystemManager(const HashMap& table, std::map<std::string, Folder>& dir, std::ostream& out_stream) :
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
		bool is_empty() const;
		std::string get_file_name(int MODE, std::map<std::string, Folder>::iterator);

		struct triple_type get_target_triple();
		struct double_type get_target_double();

};


#endif //DFY_V1_FILESYSTEMMANAGER_H
