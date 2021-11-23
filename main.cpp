#include <iostream>

#include "FileSystemManager.h"

/*
 * Gets a number from user that represents a choice
 */
unsigned int get_ans(size_t range)
{
	int user_ans;
	while(true)
	{
		std::cout << "Enter a choice: ";
		std::cin >> user_ans;

		if(isnumber(user_ans) && user_ans > range)
		{
			std::cout << "Invalid entry, try again" << std::endl;
			continue;
		}
		else
			break;
	}
	return user_ans;
}


int main()
{
    //Builds a hashmap
    FileSystemManager sys_mgr(std::cout);

	while(true)
	{
		unsigned int ans;
		std::cout << "YOUR FILE SYSTEM" << std::endl;
		sys_mgr.display_all();
		std::cout << "\n\n1. Create Folder\n2. Create File\n3. Move File\n4. Copy File\n5. Delete File\n6. Delete Folder\n" << std::endl;
		ans = get_ans(6);

		switch(ans)
		{
			case 1:
				sys_mgr.create_folder();
				break;
			case 2:
				sys_mgr.create_file();
				break;
			case 3:
				sys_mgr.move_file();
				break;
			case 4:
				sys_mgr.copy();
				break;
			case 5:
				sys_mgr.delete_file();
				break;
			case 6:
				sys_mgr.delete_folder();
				break;
			default:
				break;
		}
	}

    //User adds files to a folder

    //CRUD stuff?
}
