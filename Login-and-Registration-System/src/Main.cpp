#include <iostream>
#include <stdlib.h>

#include "database/databasehandler.h"
#include "user/User.h"

int main()
{
	try 
	{
		// initialise instance of database
		DatabaseHandler myDB("./config/config.ini");

		// connect to DB
		if (myDB.connect())
		{
			std::cout << "Connected to the database!" << '\n';

			myDB.disconnect();
			std::cout << "Disconnected";
			std::cout << '\n';
			
			User newUser("Max", "123");

			std::string Name = newUser.getUsername();
			std::string Pass = newUser.getPassword();

			std::cout << Name << '\n';
			std::cout << Pass << '\n';
			

		}
	}
	catch (const std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
};