//
// Created by Tobey Ragain on 11/12/21.
//

#ifndef DFY_V1_FOLDER_H
#define DFY_V1_FOLDER_H

#include <iostream>
#include <set>
#include <utility>
#include "File.h"

class Folder
{
    public:

    private:
        std::set<std::shared_ptr<File>> content;
};


#endif //DFY_V1_FOLDER_H
