//
// Created by Tobey Ragain on 11/15/21.
//

#include "FileSystemManager.h"


//Displays all folders in the file system
FileSystemManager& FileSystemManager::display_all_folders()
{
    out << "ALL FOLDERS:" << std::endl;
    for(const auto& x : system_layout.second)
    {
        out << x.second.get_folder_name() << std::endl;
    }
    return *this;
}

//Displays all files that exist in the file system
FileSystemManager& FileSystemManager::display_all_files()
{
    out << "ALL FILES IN SYSTEM:" << std::endl;
    system_layout.first->print_all();
    return *this;
}

//Displays all Folders and accosted files
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

//Function checks if a folder name is taken
bool FileSystemManager::chk_folder_name(const std::string &posi_name)
{
	auto ret = system_layout.second.find(posi_name);
	return !(ret == system_layout.second.end());
}

//Creates a new folder in system_layout
FileSystemManager &FileSystemManager::create_folder()
{
    std::string f_name = get_folder_name(IS_NEW);

	system_layout.second.insert(std::pair(f_name, Folder(f_name)));
	return *this;
}

//Creates a new file
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

//Moves a file from one folder to another
FileSystemManager &FileSystemManager::move_file()
{
	std::string fi_name, f_name, move_folder;

	//Gets a file to move from and to a folder from user
	f_name = get_folder_name(IS_CURR);
	fi_name = get_file_name(IS_CURR, system_layout.second.find(f_name));
	move_folder = get_folder_name(IS_CURR);

	if()

}

//Util function to get a valid folder name from user
//0 - check if folder name is new
//1 - check if folder name is current
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

//Util function to get a valid file name from user
//0 - check if file name is new
//1 - check if file name is current
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


