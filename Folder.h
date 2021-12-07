//
// Created by Tobey Ragain on 11/12/21.
//

#ifndef DFY_V1_FOLDER_H
#define DFY_V1_FOLDER_H

#include <set>
#include <unistd.h>

#include "File.h"
#include "HashMap.h"

typedef std::shared_ptr<File> file_ptr_t;

//Compare class used to find values in Folder content member (Callable class)
struct Compare
{
	bool operator() (const file_ptr_t& a, const file_ptr_t& b) const { return (a->get_name() != b->get_name()); }
};

class Folder
{
	public:
		Folder() = default;
		explicit Folder(std::string f_name) :
			folder_name(std::move(f_name)) { };
	//Folder(const Folder& copy) : folder_name(copy.get_folder_name()), content(copy.get_content()){ };

	Folder& add(File& file, HashMap& map);
	Folder& move(const file_ptr_t& m_file, Folder * root_f);
	Folder& remove(const file_ptr_t& key, HashMap& map);
	Folder& clear_files(HashMap& map);

	std::set<file_ptr_t>::iterator search(std::string& term, HashMap& map);

	std::string get_folder_name() const { return folder_name; };

	std::set<file_ptr_t>::iterator end();
	void print_files(std::ostream& out_s) const;
	bool chk_exist(const std::string& to_chk);
	bool empty() { return content.empty(); };


	private:
		std::string folder_name;
		std::set<file_ptr_t, Compare> content;
};


#endif //DFY_V1_FOLDER_H
