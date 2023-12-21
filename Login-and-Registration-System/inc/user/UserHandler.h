#pragma once

class UserHandler 
{
public:
	// login and registration functionality
	void registerUser(const std::string& username, const std::string& password);

	void login(const std::string& username, const std::string& password);

	void logout(const User& user);

};
