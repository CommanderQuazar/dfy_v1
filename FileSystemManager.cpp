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
    std::string f_name;
	do
	{
		out << "\nEnter a folder's name: ";
	}
	while(std::cin >> f_name && chk_folder_name(f_name));

	system_layout.second.insert(std::pair(f_name, Folder(f_name)));
}

//Creates a new file
FileSystemManager &FileSystemManager::create_file()
{
	std::string fi_name, f_name, content;
	out << "Folders:" << std::endl;
	display_all_folders();
	do
	{
		out << "\nEnter a folder name: ";
	}
	while(std::cin >> f_name && chk_folder_name(f_name));

	//Gets the Folder to operate on
	auto folder_iter = system_layout.second.find(f_name);

	do
	{
		out << "\nEnter a file name: ";
	}
	while(std::cin >> fi_name && folder_iter->second.chk_exist(fi_name));

	out << "Enter the file contents: ";
	std::cin >> content;
	File to_add(fi_name, content, &folder_iter->second);

	//Add to hashmap
	system_layout.first->add(fi_name, to_add);

	//Add to folder
	folder_iter->second.add(to_add, *system_layout.first);

	return *this;
}


