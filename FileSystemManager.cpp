//
// Created by Tobey Ragain on 11/15/21.
//

#include "FileSystemManager.h"

FileSystemManager& FileSystemManager::display_all_folders()
{
    out << "ALL FOLDERS:" << std::endl;
    for(const auto& x : system_layout.second)
    {
        out << x.get_folder_name() << std::endl;
    }
    return *this;
}

FileSystemManager& FileSystemManager::display_all_files()
{
    out << "ALL FILES IN SYSTEM:" << std::endl;
    system_layout.first->print_all();
    return *this;
}

FileSystemManager& FileSystemManager::display_all()
{
    out << "ALL FOLDERS AND FILES:" << std::endl;
    for(const auto& x : system_layout.second)
    {
        out << x.get_folder_name()
            << std::endl;
        x.print_files(out);
    }
    return *this;
}
