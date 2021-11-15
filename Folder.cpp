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

Folder &Folder::remove(const std::shared_ptr<File>& key, HashMap& map)
{
    //Remove the file from the folder's content
    content.erase(key);

    if(key.use_count() == 1)
        map.remove(key->get_name());
    return *this;
}

Folder &Folder::search(std::string &term, HashMap& map)
{

}

