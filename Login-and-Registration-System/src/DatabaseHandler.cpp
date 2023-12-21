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

// insert user
void DatabaseHandler::addUser(const std::string& username, const std::string& password)
{
	try
	{
		pstmt = con->prepareStatement("INSERT INTO users(username, password) VALUES(?,?)");
		pstmt->setString(1, username);
		pstmt->setString(2, password);
		pstmt->execute();
		std::cout << "User Successfully Added" << "n/";
	}
	catch (sql::SQLException& e)
	{
		// Handle the exception (e.g., log or throw)
		std::cerr << "Error adding user: " << e.what() << std::endl;
	}
}

// check user
bool DatabaseHandler::findUser(const std::string& username)
{
	try
    {
        pstmt = con->prepareStatement("SELECT username FROM users WHERE username = ?");
        pstmt->setString(1, username);

        // Execute the query and get the result set
        std::unique_ptr<sql::ResultSet> resultSet(pstmt->executeQuery());

        // Check if the result set has any rows
        return resultSet->next();
    }
    catch (sql::SQLException& e)
    {
        // Handle the exception (e.g., log or throw)
        std::cerr << "Error checking if user exists: " << e.what() << std::endl;
        return false; // Assuming false means an error occurred
    }
	
}

