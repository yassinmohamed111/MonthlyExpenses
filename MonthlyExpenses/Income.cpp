#define _CRT_SECURE_NO_WARNINGS
#include "Income.h"

#include <ctime>


void initializeIncome(vector<string>& listOfIncome)
{
	ifstream IncomeFile("..//MonthlyExpenses//Income.txt");
	if (IncomeFile.fail())
	{
		cout << "Income File failed to open\n";
	}
	else
	{
		string temp;

		while (!IncomeFile.eof())
		{
			getline(IncomeFile, temp);
			if (temp != "")
			{
				listOfIncome.push_back(temp);
			}
		}

	}
}

void printListOfIncome(vector<string> listOfIncome)
{
	if (listOfIncome.empty() == 1)
	{
		cout << "You currently have no Income!\n";

	}
	else
	{
		cout << "Income : ";
		for (int i = 0; i < listOfIncome.size(); i++)
		{
			cout << listOfIncome[i] << endl;
		}
	}
}

void addNewIncome(vector<string>& listOfIncome, vector<IncomeObj>& listOfIncomeNodes)
{
	ofstream NewIncome;
	string IncomeName;
	Date date;
	float total;
	float income;

	IncomeObj* newIncome = new IncomeObj();
	cout << "Name of Income : ";
	cin.ignore();
	getline(cin, IncomeName);

	listOfIncome.push_back(IncomeName);

	cout << "Date as(DD MM YYYY): ";
	cin >> newIncome->dateRecieved.day >> newIncome->dateRecieved.month >> newIncome->dateRecieved.year;
	cout << "Enter Monthly Income: ";
	cin >> newIncome->MontlyIncome;
	newIncome->Wallet_Name = IncomeName;
	listOfIncomeNodes.push_back(*newIncome);

	NewIncome.open("..//MonthlyExpenses//Income//" + IncomeName + ".txt");
	if (NewIncome.fail())
	{
		cout << "Failed to create new Income file\n";
		return;
	}
	NewIncome.close();

	NewIncome.open("..//MonthlyExpenses//Income.txt", ios_base::app);
	if (NewIncome.fail())
	{
		cout << "Failed to open Income File \n";
		return;
	}
	else
	{
		NewIncome << IncomeName << endl;
	}
	NewIncome.close();
	delete newIncome;
}

void printIncomeIntoFile(vector<IncomeObj> listofIncomeNodes)
{
	ofstream CurrentFile;
	int counter;

	for (counter = 0; counter < listofIncomeNodes.size(); counter++)
	{
		CurrentFile.open("..//MonthlyExpenses//Income//" + listofIncomeNodes[counter].Wallet_Name + ".txt");//Opening Income File
		if (CurrentFile.fail())
		{
			cout << "Could not open..//MonthlyExpenses//Income//" << listofIncomeNodes[counter].Wallet_Name << ".txt\n";
		}
		else
		{
			CurrentFile << "Date: " << listofIncomeNodes[counter].dateRecieved.day << ":" << listofIncomeNodes[counter].dateRecieved.month << ":" << listofIncomeNodes[counter].dateRecieved.year << endl;
			CurrentFile << "Monthly_Income: " << listofIncomeNodes[counter].MontlyIncome << endl;
			CurrentFile << "Total: " << listofIncomeNodes[counter].total << endl;
		}
		CurrentFile.close();
	}
}

void changeMontlyIncome(vector<string> listOfIncome, vector<IncomeObj>& listOfIncomeNodes)
{
	string choice;
	float income;

	if (listOfIncome.empty())
	{
		printListOfIncome(listOfIncome);
	}
	else
	{
		printListOfIncome(listOfIncome);
		cout << "\nIn which Wallet would you like to Change Monthly Income? : ";

		cin.ignore();
		getline(cin, choice);

		for (int i = 0; i < listOfIncomeNodes.size(); i++)
		{
			if (choice == listOfIncomeNodes[i].Wallet_Name)
			{
				printSingleIncomeFile(choice);

				cout << "Enter The New Monthly Income: ";
				cin >> income;
				listOfIncomeNodes[i].MontlyIncome = income;
				break;
			}
			else
			{
				cout << "Invalid Income!\n";
			}
		}
	}
}

void printSingleIncomeFile(string nameOfIncome)
{
	ifstream file("..//MonthlyExpenses//Income//" + nameOfIncome + ".txt");
	string temp;
	if (file.fail())
	{
		cout << "Failed to open an Income file!\n";
		return;
	}
	else
	{
		cout << "\n---------- " << nameOfIncome << " Income ----------" << "\n";
		while (!file.eof())
		{
			getline(file, temp);
			cout << temp << endl;
		}
	}
}

void ViewIncomeInfo(vector<string> listOfIncome)
{
	int choice;
	cout << "(1)View all Income info\n(2)View Single Income info\nChoice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		if (listOfIncome.empty())
		{
			printListOfIncome(listOfIncome);
		}
		else
		{
			for (int i = 0; i < listOfIncome.size(); i++)
			{
				printSingleIncomeFile(listOfIncome[i]);
			}
		}
		break;
	}
	case 2:
	{
		string IncomeName;

		if (!listOfIncome.empty())
		{
			printListOfIncome(listOfIncome);
		}
		else
		{
			printListOfIncome(listOfIncome);
			cout << "\nIn which Wallet would you like to view? : ";

			cin.ignore();
			getline(cin, IncomeName);

			printSingleIncomeFile(IncomeName);
		}

		break;
	}
	default:
		cout << "Not a valid choice\n";
		break;
	}
}

void calculateTotal(vector<IncomeObj>& listofIncomeNodes)
{
	time_t t = time(0);
	tm* now = localtime(&t);
	cout << now->tm_mday << '-' << (now->tm_mon + 1) << '-' << (now->tm_year + 1900) << endl;
	for (int i = 0; i < listofIncomeNodes.size(); i++)
	{
		int paidMonths;
		int new_month = now->tm_mon + 1;
		int new_year = now->tm_year + 1900;
		if (listofIncomeNodes[i].dateRecieved.month == new_month && listofIncomeNodes[i].dateRecieved.year == new_year)
		{
			continue;
		}
		else
		{
			new_month += 12 * (new_year - listofIncomeNodes[i].dateRecieved.year);
			paidMonths = new_month - listofIncomeNodes[i].dateRecieved.month;
			listofIncomeNodes[i].total += paidMonths * listofIncomeNodes[i].MontlyIncome;
			listofIncomeNodes[i].dateRecieved.month = new_month;
			listofIncomeNodes[i].dateRecieved.year = new_year;
		}
	}
}

void Remaining(vector<IncomeObj>& listofIncomeNodes)
{
	string walletName;
	bool found = false;
	cout << "In which Wallet would you like to view Remaining Money? : ";
	cin.ignore();
	getline(cin, walletName);
	for (int i = 0; i < listofIncomeNodes.size(); i++)
	{
		if (walletName == listofIncomeNodes[i].Wallet_Name)
		{
			cout << "Remaining Money from " << listofIncomeNodes[i].Wallet_Name << " is : " << listofIncomeNodes[i].total << "\n";
			found = true;
		}
		if (!found)
		{
			cout << "Invalid Income Wallet\n";
		}
	}
}

void addExistingExpense(vector<string>listOfExpenses, vector<IncomeObj>& listOfIncomeNodes)
{
	string choice;
	string wallet;
	if (listOfExpenses.empty())
	{
		printListOfExpenses(listOfExpenses);
	}
	else
	{
		printListOfExpenses(listOfExpenses);
		cout << "\nIn which category would you like to add a value? : ";

		cin.ignore();
		getline(cin, choice);

		printSingleExpenseFile(choice);

		Date date;
		float cost;
		bool found = false;

		ofstream Expense("..//MonthlyExpenses//Expenses//" + choice + ".txt", std::ios_base::app);
		bool fileExists = 0;
		string temp;
		for (int i = 0; i < listOfExpenses.size(); i++)
		{
			temp = listOfExpenses[i];
			if (temp == choice)
			{
				fileExists = 1;
			}
		}
		if (fileExists == 0)
		{
			cout << "Invalid Expense!\n";
		}
		else
		{
			cout << "Wallet: ";
			
			//cin.ignore();
			//getline(cin, wallet);
			cin >> wallet;
			for (int i = 0; i < listOfIncomeNodes.size(); i++)
			{
				string tempname;
				tempname = listOfIncomeNodes[i].Wallet_Name;
				if (tempname == wallet)
				{
					cout << "Date as(DD MM YYYY): ";
					cin >> date.day >> date.month >> date.year;

					cout << "Cost: ";
					cin >> cost;

					listOfIncomeNodes[i].total = listOfIncomeNodes[i].total - cost;

					found = true;

					Expense << "Date: " << date.day << ":" << date.month << ":" << date.year << endl;
					Expense << "Wallet: " << wallet << endl;
					Expense << "Cost: " << cost << endl << endl;
				}
			}
			if (!found)
			{
				cout << "Invalid Income!\n";
			}
		}
		Expense.close();
	}
}