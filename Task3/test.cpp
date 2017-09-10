#include <iostream>
#include "ConcreteSocialSiteMediator.h"
#include "SocialSiteUser.h"
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	ConcreteSocialSiteMediator* med = new ConcreteSocialSiteMediator();
	bool loggedIn = false;
	SocialSiteUser* loggedUser;
	string username;
	int input;

	do
	{
		cout << "\nWelcome to SocialSite!\n\n";
		if(loggedIn == false)
		{
			cout << "What would you like to do?\n";

			cout << "1. Sign Up\n"
				<< "2. Login\n"
				<< "8. Exit\n";

			cin >> input;

			if(input == 1)
			{
				cout << "Enter your desired username:\n";
				cin >> username;

				med->addUser(username);
			}
			else if(input == 2)
			{
				cout << "Enter your username:\n";
				cin >> username;

				loggedUser = dynamic_cast<SocialSiteUser*>(med->getUser(username));
				if(loggedUser != NULL)
				{
					loggedIn = true;
				}
			}
		}
		else
		{
			cout << "You are logged on as: " << loggedUser->getName() << endl;
			cout << "Your status is: " << loggedUser->viewStatus() << endl;
			cout << "What would you like to do?\n";

			cout << "1. Post a message\n"
				<< "2. Change your status\n"
				<< "3. View your inbox \n"
				<< "4. Log out\n";

			cin >> input;

			if(input == 1)
			{
				string message;
				cout << "Enter a post:\n";
				cin >> message;

				loggedUser->postMessage(message);
			}
			else if(input == 2)
			{
				string response;
				cout << "Would you like to load a previously saved status?(y/n)\n";
				cin >> response;

				if(response == "y")
				{
					loggedUser->loadStatus();
				}
				else if(response == "n")
				{
					string newStatus;
					cout << "Enter a status:\n";
					cin >> newStatus;

					loggedUser->changeStatus(newStatus);

					cout << "Would you like to save this status?(y/n)\n";
					cin >> response;

					if(response == "y")
					{
						loggedUser->saveStatus();
					}
				}
			}
			else if(input == 3)
			{
				loggedUser->viewInbox();
			}
			else if(input == 4)
			{
				loggedUser = NULL;
				loggedIn = false;
			}
		}
	}
	while(input != 8);

		delete med;
	return 0;
}