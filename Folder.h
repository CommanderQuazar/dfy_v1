//
// Created by Tobey Ragain on 11/12/21.
//

#ifndef DFY_V1_FOLDER_H
#define DFY_V1_FOLDER_H

#include <iostream>
#include <set>
#include <utility>
#include "File.h"
#include "HashMap.h"

typedef std::shared_ptr<File> file_ptr_t;

//Compare class used to find values in Folder content member
struct Compare
{
	bool operator() (const file_ptr_t& a, const file_ptr_t& b) const { return (a->get_name() != b->get_name()); }
};

class Folder
{
    public:
        Folder() = default;
        explicit Folder(std::string  f_name) : folder_name(std::move(f_name)) { };

        Folder& add(File& file, HashMap& map);
		Folder& move(const std::shared_ptr<File>& m_file);
        Folder& remove(const std::shared_ptr<File>& key, HashMap& map);
		Folder& clear_files(HashMap& map);
        std::set<std::shared_ptr<File>>::iterator search(std::string& term, HashMap& map);

		bool operator() (const file_ptr_t& a, const file_ptr_t& b) const { return (a->get_name() != b->get_name()); }

		std::set<std::shared_ptr<File>>::iterator end();

        std::string get_folder_name() const { return folder_name; };
        void print_files(std::ostream& out_s) const;
		bool chk_exist(const std::string& to_chk);

    private:
        std::string folder_name;
        std::set<file_ptr_t, Compare> content;
};


#endif //DFY_V1_FOLDER_H
