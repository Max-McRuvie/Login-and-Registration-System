#include "databasehandler.h"

// constructor
DatabaseHandler::DatabaseHandler(const std::string& host, const std::string& user, const std::string& password, const std::string& database)
{
	driver = get_driver_instance();
	con = driver->connect(host, user, password);
	con->setSchema(database);
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