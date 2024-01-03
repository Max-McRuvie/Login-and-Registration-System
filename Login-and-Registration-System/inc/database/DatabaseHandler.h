#pragma once

#ifndef DATABASEHANDLER_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

class DatabaseHandler
{
	private:
		// member vars
		sql::Driver* driver; 
		sql::Connection* con; 
		sql::Statement *stmt; 
		sql::PreparedStatement* pstmt; 
	public:
		DatabaseHandler(const std::string& configFile);
	
		bool connect();
		void disconnect();
		void addUser(const std::string& username, const std::string& password);
		bool findUser(const std::string& username);
};

#endif // DATABASE_H