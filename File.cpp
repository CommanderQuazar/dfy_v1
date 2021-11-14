//
// Created by Tobey Ragain on 11/12/21.
//

#include "File.h"

File &File::operator=(const File &rhs)
{
    auto cp_msg = rhs.msg;
    auto occ = rhs.occurrences;

    this->~File();
    msg = cp_msg;
    occurrences = occ;

    return *this;
}

