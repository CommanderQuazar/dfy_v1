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
        explicit File(std::string init_msg = "") : msg(std::move(init_msg)) { };
        File(std::string init_msg, Folder * add_folder) : msg(std::move(init_msg)) { occurrences.insert(add_folder); };
        File(std::string init_msg, std::initializer_list<Folder*> to_add_f) : msg(std::move(init_msg))
                { occurrences.insert(to_add_f.begin(), to_add_f.end()); };
        File(File& to_copy) = default;
        File(File&& to_move) noexcept : msg(std::move(to_move.msg)), occurrences(std::move(to_move.occurrences)) { };

        ~File() = default;
        File& operator=(const File& rhs);

        File& update_msg(const std::string& new_msg) { msg = new_msg; return *this; };
        std::string get_msg() { return msg; };

    private:
        std::string msg;
        std::set<Folder*> occurrences;
};



#endif //DFY_V1_FILE_H
