#include "user/User.h"
#include <string>
#include <stdexcept>

User::User(const std::string& username, const std::string& password)
	: username(username), password(password)
{
	// check username and password have values
	if (username.empty() || password.empty())
	{
		throw std::invalid_argument("Username and password cannot be empty.");
	}
}

// getters for username & password
std::string User::getUsername() const
{
	return username;
}

std::string User::getPassword() const
{
	return password;
}

// setters for username & password
void User::setUsername(const std::string& newUsername)
{
	username = newUsername;
}

void User::setPassword(const std::string& newPassword)
{
	password = newPassword;
}