#include <iostream>
#include <stdlib.h>

#include "databasehandler.h"

int main()
{
	try 
	{
		// initialise instance of database
		DatabaseHandler myDB("./config/config.ini");

		// connect to DB
		if (myDB.connect())
		{
			std::cout << "Connected to the database!" << std::endl;

			myDB.disconnect();
			std::cout << "Disconnected";
		}
	}
	catch (const std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
};