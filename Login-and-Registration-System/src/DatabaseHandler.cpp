#include "databasehandler.h"
#include <iostream>
#include <stdlib.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

// constructor
DatabaseHandler::DatabaseHandler(const std::string& configFile)
{
	// retrieve config file
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini(configFile, pt);

	// get config values
	std::string server = pt.get<std::string>("Database.Hostname");
	std::string username = pt.get<std::string>("Database.Username");
	std::string password = pt.get<std::string>("Database.Password");
	std::string databaseName = pt.get<std::string>("Database.DatabaseName");

	// declare driver, connection details, and schema
	driver = get_driver_instance();
	con = driver->connect(server, username, password);
	con->setSchema(databaseName);
}

// destructor
DatabaseHandler::~DatabaseHandler()
{
	delete con;
}

// connect to DB
bool DatabaseHandler::connect()
{
	try 
	{
		// check connection is valid
		if (!con->isValid())
		{
			con->reconnect();
		}
		return true;
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "Database connection error" << e.what() << std::endl;
		return false;
	}
}

// disconnect from DB
void DatabaseHandler::disconnect()
{
	delete con;
}