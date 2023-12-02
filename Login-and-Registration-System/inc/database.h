#pragma once

#ifndef DATABASE_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class Database
{
	private:
		sql::Driver* driver; 
		sql::Connection* con; 
		//sql::Statement *stmt; 
		//sql::PreparedStatement* pstmt; 
	public:
		Database(const std::string& host, const std::string& user, const std::string& password, const std::string& database);
		~Database();
	
		bool connect();
		void disconnect();
};

#endif // DATABASE_H