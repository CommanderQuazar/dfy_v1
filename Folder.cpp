//
// Created by Tobey Ragain on 11/12/21.
//

#include "Folder.h"

//Function adds a new file to the folder object
Folder& Folder::add(File &file, HashMap& map)
{
    //Add file to the hashmap
    auto location = map.add(file.get_name(), file);

    //Adds occurrence to the File obj
    file.add_occ(this);

    //Add a ptr to content that points to the file in the hash map
    content.insert(location);
    return *this;
}

//Member function moves a EXISTING file into its contents
Folder &Folder::move(const std::shared_ptr<File>& m_file)
{
	//Adds occurrence to the File obj
	m_file->add_occ(this);

	//Add a ptr to content that points to the file in the hash map
	content.insert(m_file);
	return *this;
}


Folder &Folder::remove(const std::shared_ptr<File>& key, HashMap& map)
{
    //Remove the file from the folder's content
    content.erase(key);

    if(key.use_count() == 1)
        map.remove(key->get_name());
    return *this;
}

//Searches the folder for the sought term
//Accesses the HashMap lookup function to check weather the file exists
//Returns an iter to the element if found
std::set<std::shared_ptr<File>>::iterator Folder::search(std::string &term, HashMap& map)
{
    auto ret = map.lookup(term);
    auto iter_hit = content.find(ret.second);
    if(ret.first && iter_hit != content.end())
        return iter_hit;
    else
        return content.end();
}

inline void Folder::print_files(std::ostream& out_s) const
{
    for(const auto& x : content)
        out_s << "\t" << x->get_name() << std::endl;
}

//Checks if a file exists under the folder
inline bool Folder::chk_exist(const std::string &to_chk)
{
	return content.find(std::make_shared<File>(to_chk)) != content.end();
}

//Return the end iter for the content member
inline std::set<std::shared_ptr<File>>::iterator Folder::end()
{
	return content.end();
}

