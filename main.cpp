#include <iostream>

#include "FileSystemManager.h"

/*
 * Gets a number from user that represents a choice
 * If any alpha key or 0 is pressed the program quits
 */
unsigned int get_ans(size_t range)
{
	size_t pass = 0;
	std::cout << "Enter a choice OR PRESS any OTHER key to exit: ";
	while(true)
	{
		int user_ans;
		std::cin >> user_ans;
		if(user_ans <= range && user_ans >= 0)
			return user_ans;
		else
		{
			//If user has entered four invalid entries program returns to main menu
			if(++pass == LIMIT)
			{
				std::cerr << "Sorry, all of your entries are invalid" << std::endl;
				return -1;
			}
			std::cerr << "Invalid entry, try again: ";
			continue;
		}
	}
}


int main()
{
    //Builds a hashmap
    FileSystemManager sys_mgr(std::cout);

	while(true)
	{
		unsigned int ans;
		std::cout << "YOUR FILE SYSTEM - " << sys_mgr.get_counter() << std::endl;
		sys_mgr.display_all();
		std::cout << "\n\n1. Create Folder\n2. Create File\n3. Move File\n4. Copy File\n5. Delete File\n6. Delete Folder\n"
					 "+-----------------+" << std::endl;
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
			case 0:
				std::cout << "Quitting..." << std::endl;
				sleep(1);
				return 1;
			default:
				break;
		}
	}

    //User adds files to a folder

    //CRUD stuff?
}
