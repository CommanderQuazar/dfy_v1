//
// Created by Tobey Ragain on 11/12/21.
//

#ifndef DFY_V1_FILE_H
#define DFY_V1_FILE_H

#include <iostream>
#include <set>
#include <utility>

class Folder;
class File
{
    public:
		explicit File(std::string name, std::string init_msg = "") : msg(std::move(init_msg)), file_name(std::move(name)) { };
        File(std::string name, std::string init_msg, Folder * add_folder) : msg(std::move(init_msg)), file_name(std::move(name)) { occurrences.insert(add_folder); };
        File(std::string name, std::string init_msg, std::initializer_list<Folder*> to_add_f) : msg(std::move(init_msg)), file_name(std::move(name))
                { occurrences.insert(to_add_f.begin(), to_add_f.end()); };
        File(File& to_copy) = default;
        File(File&& to_move) noexcept : msg(std::move(to_move.msg)), occurrences(std::move(to_move.occurrences)) { };

        ~File() = default;
        File& operator=(const File& rhs);

        File& update_msg(const std::string& new_msg) { msg = new_msg; return *this; };
        std::string get_msg() { return msg; };
        std::string get_name() { return file_name; }
        File& add_occ(Folder* folder_ptr) { occurrences.insert(folder_ptr); return *this; };
        File& remove_occ(Folder* folder_ptr) { occurrences.erase(folder_ptr); return *this; }

    private:
        std::string file_name;
        std::string msg;
        std::set<Folder*> occurrences;
};



#endif //DFY_V1_FILE_H
