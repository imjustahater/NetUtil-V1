#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool isValidTarget(string Target) {
	stringstream ss(Target);

	int a, b, c, d;
	char x, y, z;

	if (ss >> a >> x >> b >> y >> c >> z >> d)
	{
		int octets[] = { a,b,c,d };
		for (int n : octets)
		{
			if (n < 0 || n > 255) return false;
		}

		if (x != '.' || y != '.' || z != '.') return false;

		string extra;
		if (ss >> extra) return false;

		return true; 
	}
	
	return false;
}

int main() {
	char choice;
	string Target;

	do {
		cout << "------------------------\n";
		cout << "|     Net Utility V1   |\n";
		cout << "------------------------\n";

		cout << "1.) IP-Lookup\n2.) Ping IP Address\n3.) Exit\n";
		cout << "Your Choice: ";
		cin >> choice;

		if (choice == '1')
		{
			system("cls");
			cout << "Enter an IP Address: ";
			getline(cin >> ws, Target);

			while (!isValidTarget(Target))
			{
				cout << "Invalid IP, Try again!\nEnter an IP Address: ";
				getline(cin >> ws, Target);
			}

			cout << "Success! Validating " << Target << "..." << endl;

			system("cls");

			string command = "nslookup " + Target;
			system(command.c_str());

			cin.get(); cin.ignore(); system("cls");
		}

		if (choice == '2')
		{
			char subChoice;
			system("cls");

			if (Target.empty())
			{
				cout << "Enter an IP Address: ";
				getline(cin >> ws, Target);

				while (!isValidTarget(Target))
				{
					cout << "Invalid IP, Try again!\nEnter an IP Address: ";
					getline(cin >> ws, Target);
				}
			}
			else
			{
				cout << "Would you like to use: " << Target << "?\n";
				cin >> subChoice; cin.ignore();
				
				if (subChoice == 'n' || subChoice == 'N')
				{
					do {
						cout << "Enter an IP Address: ";
						cin >> Target;

						while (!isValidTarget(Target))
						{
							cout << "Not a valid Target\n Enter an IP Address: ";
							cin >> Target;
						}
					} while (Target.empty());
				}
				if (subChoice == 'y' || subChoice == 'Y')
				{
					
				}

			}

			string pingCount;
			cout << "How many pings would you like to send?\nPings: ";
			getline(cin >> ws, pingCount);

			system("cls");

			string command = "ping " + Target + " -n " + pingCount;
			system(command.c_str());

			cin.get(); cin.ignore();
			// Clear screen to keep console clean
			system("cls");

		}

	} while (choice != '3');
	{
		system("cls");
	}

}