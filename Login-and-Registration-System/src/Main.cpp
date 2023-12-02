#include <iostream>
#include <stdlib.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include "database.h"

int main()
{
	try 
	{
		// retrieve config file
		boost::property_tree::ptree pt;
		boost::property_tree::ini_parser::read_ini("./config/config.ini", pt);

		// get config values
		std::string server = pt.get<std::string>("Database.Hostname");
		std::string username = pt.get<std::string>("Database.Username");
		std::string password = pt.get<std::string>("Database.Password");
		std::string databaseName = pt.get<std::string>("Database.DatabaseName");

		// initialise instance of database
		Database myDB(server, username, password, databaseName);

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