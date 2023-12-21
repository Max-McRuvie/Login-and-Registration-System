#pragma once
#ifndef USER_H

#include <string>

class User 
{
	private:
		// member vars
		std::string username;
		std::string password;
	public:
		// construct
		User(const std::string& username, const std::string& password);

		// member funcs
		void setUsername(const std::string& username);
		void setPassword(const std::string& password);
		std::string getUsername() const;
		std::string getPassword() const;
};

#endif