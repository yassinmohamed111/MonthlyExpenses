#include "Expense.h"

vector<ExpenseObj> newExpenseNodes;

void initializeExpenses(vector<string>& listOfExpenses)
{
	ifstream ExpensesFile("..//MonthlyExpenses//Expenses.txt");
	if (ExpensesFile.fail())
	{
		cout << "Expense File failed to open\n";
	}
	else
	{
		string temp;

		while (!ExpensesFile.eof())
		{
			getline(ExpensesFile, temp);
			if (temp != "")
			{
				listOfExpenses.push_back(temp);
			}
		}

	}
}

void addNewExpenseCategory(vector<string>& listOfExpenses)
{
	ofstream NewExpense;
	string ExpenseName;
	cout << "Name of Expense (Category) : ";
	
	cin.ignore();
	getline(cin, ExpenseName);

	listOfExpenses.push_back(ExpenseName);
	
	NewExpense.open("..//MonthlyExpenses//Expenses//" + ExpenseName + ".txt");
	if (NewExpense.fail())
	{
		cout << "Failed to create new Expense file\n";
		return;
	}
	else NewExpense.close();

	NewExpense.open("..//MonthlyExpenses//Expenses.txt", ios_base::app);
	if (NewExpense.fail())
	{
		cout << "Failed to open Expenses File #1001\n";
		return;
	}
	else
	{
		NewExpense << ExpenseName << endl;
	}
	NewExpense.close();
}

void printListOfExpenses(vector<string>listOfExpenses)
{
	if (listOfExpenses.empty() == 1)
	{
		cout << "You currently have no Expenses!\n";
	}
	else
	{
		cout << "Expenses : ";
		for (int i = 0; i < listOfExpenses.size(); i++)
		{
			cout << listOfExpenses[i] << endl;
		}
	}
}

void printSingleExpenseFile(string nameOfExpense)
{
	ifstream file("..//MonthlyExpenses//Expenses//" + nameOfExpense + ".txt");
	string temp;
	if (file.fail())
	{
		cout << "Failed to open an Expense file!\n";
		return;
	}
	else
	{
		cout << "\n---------- " << nameOfExpense << " Expenses ----------" << "\n";
		while (!file.eof())
		{
			getline(file, temp);
			cout << temp << endl;
		}
	}
}

void ViewExpenseInfo(vector<string> listOfExpenses,vector<ExpenseObj>listOfExpenseNodes)
{
	int choice;
	cout << "(1)View all Expense info\n(2)Apply Filtres \nChoice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		if (listOfExpenses.empty())
		{
			printListOfExpenses(listOfExpenses);
		}
		else
		{
			for (int i = 0; i < listOfExpenses.size(); i++)
			{
				printSingleExpenseFile(listOfExpenses[i]);
			}
		}
		break;
	}
	case 2:
	{
		FilterExpense(listOfExpenseNodes);
		break;
	}
	default:
		cout << "Not a valid choice\n";
		break;
	}
}

void FilterExpense(vector<ExpenseObj>&listofExpensesNode)
{
	int choice;
	string category;
	string walletName;
	Date date;
	float cost;
	cout << "(1)Filter By Wallet\n(2)Filter By Date\n(3)Filter By Category\n(4)Filter By Cost\nChoice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		if (listofExpensesNode.empty())
		{
			cout << "You currently have no Expenses!\n";
		}
		else
		{
			cout << "\nIn which Wallet would you like to view? : ";
			cin.ignore();
			getline(cin, walletName);
			cout << "\n";
			newExpenseNodes = filterByWallet(listofExpensesNode, walletName);
			filterByWalletSecond(newExpenseNodes);
		}
		break;
	}
	case 2:
	{
		if (listofExpensesNode.empty())
		{
			cout << "You currently have no Expenses!\n";
		}
		else
		{
			cout << "\nIn which Date would you like to view? Date as(DD MM YYYY) : ";
			cin >> date.day >> date.month >> date.year;
			
			cout << "\n";
			newExpenseNodes = filterByDate(listofExpensesNode, date);
			filterByDateSecond(newExpenseNodes);
		}
		break;
	}
	case 3:
	{
		if (listofExpensesNode.empty())
		{
			cout << "You currently have no Expenses!\n";
		}
		else
		{
			cout << "\nIn which Wallet would you like to view? : ";
			cin.ignore();
			getline(cin, category);
			cout << "\n";
			newExpenseNodes = filterByCategory(listofExpensesNode, category);
			filterByCategorySecond(newExpenseNodes);
		}
		break;
	}
	case 4:
	{
		if (listofExpensesNode.empty())
		{
			cout << "You currently have no Expenses!\n";
		}
		else
		{
			cout << "\nIn which Cost would you like to view? : ";
			cin >> cost;
			cout << "\n";
			newExpenseNodes = filterByAmount(listofExpensesNode, cost);
			filterByAmountSecond(newExpenseNodes);
		}
		break;
	}
	default:
		cout << "Not a valid choice\n";
		break;
	}
}

void filterByWalletSecond(vector<ExpenseObj>& newExpenseNodes)
{
	int choice;
	string category;
	Date date;
	float cost;
	cout << "(1)Filter By Date\n(2)Filter By Category\n(3)Filter By Cost\nChoice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		if (newExpenseNodes.empty())
		{
			cout << "You currently have no Expenses!\n";
		}
		else
		{
			cout << "\nIn which Date would you like to view? Date as(DD MM YYYY) : ";
			cin >> date.day >> date.month >> date.year;

			cout << "\n";
			newExpenseNodes = filterByDate(newExpenseNodes, date);
		}
		break;
	}
	case 2:
	{
		if (newExpenseNodes.empty())
		{
			cout << "You currently have no Expenses!\n";
		}
		else
		{
			cout << "\nIn which Wallet would you like to view? : ";
			cin.ignore();
			getline(cin, category);
			cout << "\n";
			newExpenseNodes = filterByCategory(newExpenseNodes, category);
		}
		break;
	}
	case 3:
	{
		if (newExpenseNodes.empty())
		{
			cout << "You currently have no Expenses!\n";
		}
		else
		{
			cout << "\nIn which Cost would you like to view? : ";
			cin >> cost;
			cout << "\n";
			newExpenseNodes = filterByAmount(newExpenseNodes, cost);
		}
		break;
	}
	default:
		cout << "Not a valid choice\n";
		break;
	}
}

void filterByDateSecond(vector<ExpenseObj>& newExpenseNodes)
{
	int choice;
	string category;
	string walletName;
	float cost;
	cout << "(1)Filter By Wallet\n(2)Filter By Category\n(3)Filter By Cost\nChoice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		if (newExpenseNodes.empty())
		{
			cout << "You currently have no Expenses!\n";
		}
		else
		{
			cout << "\nIn which Wallet would you like to view? : ";
			cin.ignore();
			getline(cin, walletName);
			cout << "\n";
			newExpenseNodes = filterByWallet(newExpenseNodes, walletName);
		}
		break;
	}
	case 2:
	{
		if (newExpenseNodes.empty())
		{
			cout << "You currently have no Expenses!\n";
		}
		else
		{
			cout << "\nIn which Wallet would you like to view? : ";
			cin.ignore();
			getline(cin, category);
			cout << "\n";
			newExpenseNodes = filterByCategory(newExpenseNodes, category);
		}
		break;
	}
	case 3:
	{
		if (newExpenseNodes.empty())
		{
			cout << "You currently have no Expenses!\n";
		}
		else
		{
			cout << "\nIn which Cost would you like to view? : ";
			cin >> cost;
			cout << "\n";
			newExpenseNodes = filterByAmount(newExpenseNodes, cost);
		}
		break;
	}
	default:
		cout << "Not a valid choice\n";
		break;
	}
}

void filterByCategorySecond(vector<ExpenseObj>& newExpenseNodes)
{
	int choice;
	string walletName;
	Date date;
	float cost;
	cout << "(1)Filter By Wallet\n(2)Filter By Date\n(3)Filter By Cost\nChoice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		if (newExpenseNodes.empty())
		{
			cout << "You currently have no Expenses!\n";
		}
		else
		{
			cout << "\nIn which Wallet would you like to view? : ";
			cin.ignore();
			getline(cin, walletName);
			cout << "\n";
			newExpenseNodes = filterByWallet(newExpenseNodes, walletName);
		}
		break;
	}
	case 2:
	{
		if (newExpenseNodes.empty())
		{
			cout << "You currently have no Expenses!\n";
		}
		else
		{
			cout << "\nIn which Date would you like to view? Date as(DD MM YYYY) : ";
			cin >> date.day >> date.month >> date.year;

			cout << "\n";
			newExpenseNodes = filterByDate(newExpenseNodes, date);
		}
		break;
	}
	case 3:
	{
		if (newExpenseNodes.empty())
		{
			cout << "You currently have no Expenses!\n";
		}
		else
		{
			cout << "\nIn which Cost would you like to view? : ";
			cin >> cost;
			cout << "\n";
			newExpenseNodes = filterByAmount(newExpenseNodes, cost);
		}
		break;
	}
	default:
		cout << "Not a valid choice\n";
		break;
	}
}

void filterByAmountSecond(vector<ExpenseObj>& newExpenseNodes)
{
	int choice;
	string category;
	string walletName;
	Date date;
	cout << "(1)Filter By Wallet\n(2)Filter By Date\n(3)Filter By Category\nChoice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		if (newExpenseNodes.empty())
		{
			cout << "You currently have no Expenses!\n";
		}
		else
		{
			cout << "\nIn which Wallet would you like to view? : ";
			cin.ignore();
			getline(cin, walletName);
			cout << "\n";
			newExpenseNodes = filterByWallet(newExpenseNodes, walletName);
		}
		break;
	}
	case 2:
	{
		if (newExpenseNodes.empty())
		{
			cout << "You currently have no Expenses!\n";
		}
		else
		{
			cout << "\nIn which Date would you like to view? Date as(DD MM YYYY) : ";
			cin >> date.day >> date.month >> date.year;

			cout << "\n";
			newExpenseNodes = filterByDate(newExpenseNodes, date);
		}
		break;
	}
	case 3:
	{
		if (newExpenseNodes.empty())
		{
			cout << "You currently have no Expenses!\n";
		}
		else
		{
			cout << "\nIn which Wallet would you like to view? : ";
			cin.ignore();
			getline(cin, category);
			cout << "\n";
			newExpenseNodes = filterByCategory(newExpenseNodes, category);
		}
		break;
	}
	default:
		cout << "Not a valid choice\n";
		break;
	}
}

vector<ExpenseObj> filterByWallet(vector<ExpenseObj>& listOfExpenseNodes, string wallet)
{
	vector<ExpenseObj> newList;
	for (int i = 0; i < listOfExpenseNodes.size(); i++) {
		if (listOfExpenseNodes[i].Wallet == wallet)
			newList.push_back(listOfExpenseNodes[i]);
	}
	for (int i = 0; i < newList.size(); i++)
	{
		cout << "Category: " << newList[i].category << endl;
		cout << "Date: " << newList[i].dateOfPurchase.day << "/" << newList[i].dateOfPurchase.month << "/" << newList[i].dateOfPurchase.year << endl;
		cout << "Wallet: " << newList[i].Wallet << endl;
		cout << "Cost: " << newList[i].amountOfPurchase << endl;
	}
	return newList;
}

vector<ExpenseObj> filterByDate(vector<ExpenseObj>& listOfExpenseNodes, Date date)
{
	vector<ExpenseObj> newList;
	for (int i = 0; i < listOfExpenseNodes.size(); i++) {
		if (listOfExpenseNodes[i].dateOfPurchase == date)
			newList.push_back(listOfExpenseNodes[i]);
	}
	for (int i = 0; i < newList.size(); i++)
	{
		cout << "Category: " << newList[i].category << endl;
		cout << "Date: " << newList[i].dateOfPurchase.day << "/" << newList[i].dateOfPurchase.month << "/" << newList[i].dateOfPurchase.year << endl;
		cout << "Wallet: " << newList[i].Wallet << endl;
		cout << "Cost: " << newList[i].amountOfPurchase << endl;
	}
	return newList;
}

vector<ExpenseObj> filterByCategory(vector<ExpenseObj>& listOfExpenseNodes, string category)
{
	vector<ExpenseObj> newList;
	for (int i = 0; i < listOfExpenseNodes.size(); i++) {
		if (listOfExpenseNodes[i].category == category)
			newList.push_back(listOfExpenseNodes[i]);
	}
	for (int i = 0; i < newList.size(); i++)
	{
		cout << "Category: " << newList[i].category << endl;
		cout << "Date: " << newList[i].dateOfPurchase.day << "/" << newList[i].dateOfPurchase.month << "/" << newList[i].dateOfPurchase.year << endl;
		cout << "Wallet: " << newList[i].Wallet << endl;
		cout << "Cost: " << newList[i].amountOfPurchase << endl;
	}
	return newList;
}

vector<ExpenseObj> filterByAmount(vector<ExpenseObj>& listOfExpenseNodes, float amount)
{
	vector<ExpenseObj> newList;
	for (int i = 0; i < listOfExpenseNodes.size(); i++) {
		if (listOfExpenseNodes[i].amountOfPurchase == amount)
			newList.push_back(listOfExpenseNodes[i]);
	}
	
	//validation
	for (int i = 0; i < newList.size(); i++)
	{
		cout << "Category: " << newList[i].category << endl;
		cout << "Date: " << newList[i].dateOfPurchase.day << "/" << newList[i].dateOfPurchase.month << "/" << newList[i].dateOfPurchase.year << endl;
		cout << "Wallet: " << newList[i].Wallet << endl;
		cout << "Cost: " << newList[i].amountOfPurchase << endl;
	}
	return newList;
}
