#pragma once

#ifndef DATABASEHANDLER_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class DatabaseHandler
{
	private:
		sql::Driver* driver; 
		sql::Connection* con; 
		//sql::Statement *stmt; 
		//sql::PreparedStatement* pstmt; 
	public:
		DatabaseHandler(const std::string& configFile);
		~DatabaseHandler();
	
		bool connect();
		void disconnect();
};

#endif // DATABASE_H