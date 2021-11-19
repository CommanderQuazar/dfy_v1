//
// Created by Tobey Ragain on 11/15/21.
//

#include "FileSystemManager.h"


/*
 * Util function to get a valid folder name from user
 * 0 - check if folder name is new
 * 1 - check if folder name is current
 */
inline std::string FileSystemManager::get_folder_name(int MODE)
{
	std::string f_name;
	do
	{
		switch (MODE)
		{
			case 0:
				out << "\nEnter a new folder name: ";
				break;
			case 1:
				out << "\nEnter a current folder name: ";
				break;
			default:
				out << "\nFolder name capture failed ERROR 11";
				break;
		}
	}
	while(std::cin >> f_name && !(chk_folder_name(f_name) || MODE));    //TODO Change when in debug phase
	return f_name;
}
/*
 * Util function to get a valid file name from user
 * 0 - check if file name is new
 * 1 - check if file name is current
 */
inline std::string FileSystemManager::get_file_name(int MODE, std::map<std::string, Folder>::iterator target_folder)
{
	std::string fi_name;
	do
	{
		switch (MODE)
		{
			case 0:
				out << "\nEnter a new file name: ";
				break;
			case 1:
				out << "\nEnter a current current name: ";
				break;
			default:
				out << "\nFile name capture failed ERROR 22";
				break;
		}
	}
	while(std::cin >> fi_name && !(target_folder->second.chk_exist(fi_name) || MODE));      //TODO Change when in debug phase
	return fi_name;
}

/*
 * Function checks if a folder name is taken
 */
bool FileSystemManager::chk_folder_name(const std::string &posi_name)
{
	auto ret = system_layout.second.find(posi_name);
	return !(ret == system_layout.second.end());
}

/*
 * Displays all folders in the file system
 */
FileSystemManager& FileSystemManager::display_all_folders()
{
    out << "ALL FOLDERS:" << std::endl;
    for(const auto& x : system_layout.second)
    {
        out << x.second.get_folder_name() << std::endl;
    }
    return *this;
}

/*
 * Displays all files that exist in the file system
 */
FileSystemManager& FileSystemManager::display_all_files()
{
    out << "ALL FILES IN SYSTEM:" << std::endl;
    system_layout.first->print_all();
    return *this;
}

/*
 * Displays all Folders and accosted files
 */
FileSystemManager& FileSystemManager::display_all()
{
    out << "ALL FOLDERS AND FILES:" << std::endl;
    for(const auto& x : system_layout.second)
    {
        out << x.second.get_folder_name()
            << std::endl;
        x.second.print_files(out);
    }
    return *this;
}

/*
 * Creates a new folder in system_layout
 */
FileSystemManager &FileSystemManager::create_folder()
{
    std::string f_name = get_folder_name(IS_NEW);

	system_layout.second.insert(std::pair(f_name, Folder(f_name)));
	return *this;
}

/*
 * Creates a new file
 */
FileSystemManager &FileSystemManager::create_file()
{
	std::string fi_name, f_name, content;
	out << "Folders:" << std::endl;
	display_all_folders();
	f_name = get_folder_name(IS_CURR);

	//Gets the Folder to operate on
	auto folder_iter = system_layout.second.find(f_name);

	fi_name = get_file_name(IS_NEW, folder_iter);

	out << "Enter the file contents: ";
	std::cin >> content;
	File to_add(fi_name, content, &folder_iter->second);

	//Add to hashmap
	system_layout.first->add(fi_name, to_add);

	//Add to folder
	folder_iter->second.add(to_add, *system_layout.first);

	return *this;
}

/*
 * Moves a file from one folder to another
 */
FileSystemManager &FileSystemManager::move_file()
{
	//Holds a iterator folder and a file ptr
	auto target_data = get_target();
	auto root_folder = system_layout.second.find(target_data.second->get_name())->second;

	//Check weather the file is already in the selected target folder
	if(target_data.first->second.search(target_data.second->get_name(), *system_layout.first) != target_data.first->second.end())
		return *this;

	//Add and remove occurrence data for the file to be moved
	target_data.second->remove_occ(&root_folder);
	target_data.second->add_occ(&target_data.first->second);

	//Reassigns pointers in folders
	target_data.first->second.move(target_data.second);
	root_folder.remove(target_data.second, *system_layout.first);
	return *this;
}

/*
 * Creates a copy of a selected file in a folder
 */
FileSystemManager &FileSystemManager::copy()
{
	//Holds a iterator folder and a file ptr
	auto target_data = get_target();

	//Check weather the file is already in the selected target folder
	if(target_data.first->second.search(target_data.second->get_name(), *system_layout.first) != target_data.first->second.end())
		return *this;

	//Assign new occurrence
	target_data.second->add_occ(&target_data.first->second);

	//Add to folder
	target_data.first->second.add(*target_data.second, *system_layout.first);

	return *this;
}

/*
 * Private member function facilitates the capture of a file and a folder for
 * Use among other public member functions
 */
std::pair<std::map<std::string, Folder>::iterator, std::shared_ptr<File>> FileSystemManager::get_target()
{
	std::string fi_name, f_name, cf_name;

	//Gets a file to move from and to a folder from user
	f_name = get_folder_name(IS_CURR);
	fi_name = get_file_name(IS_CURR, system_layout.second.find(f_name));
	cf_name = get_folder_name(IS_CURR);

	//Get the file to copy
	auto root_folder = system_layout.second.find(f_name);

	//Get the folder to copy the file to
	auto target_folder = system_layout.second.find(cf_name);

	//First a folder to move the file to
	//Second a shared_ptr iterator to a file to move
	return {target_folder, *root_folder->second.search(fi_name, *system_layout.first)};
}


