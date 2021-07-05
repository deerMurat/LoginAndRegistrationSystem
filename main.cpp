#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct userInfo
{
	string name, pass;
};

bool getUserInfo(string username, string password)
{
	userInfo user1;
	string user;
	ifstream users;
	
	users.open("UserInfo.txt");
	if (users.is_open())
	{
		while (getline(users,user))
		{	
			size_t namepos=0, passpos=0;
			std::string token;
			namepos = user.find("=");
			passpos = user.find(":");			
			user1.name = user.substr(namepos+1,user.find(" ")-(namepos+1));
			user1.pass = user.substr(passpos+1, user.length()-1);
			if (user1.name == username && user1.pass == password)
			{
				return true;				
			}
		}
		users.close();
	}
	return false;

}

bool registerNewUser(string username, string password)
{
	if ((getUserInfo(username, password)))
	{
		cout << endl << "User already exist!.. ";
		return false;
	}
	else
	{
		fstream users;
		users.open("UserInfo.txt", fstream::app);
		if (users.is_open())
		{
			users << "username=" << username << " password:" << password << endl;
		}
		users.close();
	}
	
	return true;

}




int main() 
{
	char choise;
	string username, password;
	
	cout << "***** Welcome :) ******" << endl;
	cout << "Please select a procces, and type a number!" << endl;
	cout << "1. Login \n2. Register" << endl;
	cout << "Your choice is : ";
	
	cin >> choise;

	switch (choise)
	{
	case '1':
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		(getUserInfo(username, password)) ? cout << endl << "SUCCESS!.. " : cout << endl << "INVALID!.. ";
		break;
	
	case '2':
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		(registerNewUser(username, password)) ? cout << endl << "SUCCESS!.. " : cout << endl << "INVALID!.. ";
		break;

	default:
		break;
	}


	return 0;
}