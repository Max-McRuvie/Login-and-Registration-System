#include "database.h"

// constructor
Database::Database(const std::string& host, const std::string& user, const std::string& password, const std::string& database)
{
	driver = get_driver_instance();
	con = driver->connect(host, user, password);
	con->setSchema(database);
}

// destructor
Database::~Database()
{
	delete con;
}

// connect to DB
bool Database::connect()
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
void Database::disconnect()
{
	delete con;
}