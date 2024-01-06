#include "Budget.h"

void initializeListsOfNodes(vector<IncomeObj>& listOfIncomeNodes, vector<ExpenseObj>& listOfExpenseNodes, vector <string>& listOfExpenses, vector <string>& listOfIncome)
{
	ifstream CurrentFile;
	int counter;
	string temp;
	bool readDate = 0;
	bool readAmount = 0;
	bool readWallet = 0;
	bool readTotal = 0;
	IncomeObj* newIncome = new IncomeObj();

	for (counter = 0; counter < listOfIncome.size(); counter++)
	{
		CurrentFile.open("..//MonthlyExpenses//Income//" + listOfIncome[counter] + ".txt");//Opening Income File
		if (CurrentFile.fail())
		{
			cout << "Could not open..//MonthlyExpenses//Income//" << listOfIncome[counter] << ".txt\n";
		}
		else
		{
			while (CurrentFile>> temp)
			{
				if (readDate)
				{
					readDate = 0;
					vector<int> vect;
					stringstream tempstream(temp);
					for (int i; tempstream >> i;i++) 
					{
						vect.push_back(i);
						if (tempstream.peek() == ':')
							tempstream.ignore();
					}
					newIncome->dateRecieved.day = vect[0];
					newIncome->dateRecieved.month = vect[1];
					newIncome->dateRecieved.year = vect[2];
				}
				else if (readAmount)
				{
					readAmount = 0;
					newIncome->MontlyIncome = atof(temp.c_str());
					newIncome->Wallet_Name = listOfIncome[counter];
					
				}
				else if (readTotal)
				{
					readTotal = 0;
					newIncome->total = atof(temp.c_str());
					listOfIncomeNodes.push_back(*newIncome);
				}
				if (temp == "Date:") readDate = 1;
				else if (temp == "Monthly_Income:") readAmount = 1;
				else if (temp == "Total:") readTotal = 1;
				
			}
		}
		CurrentFile.close();
	}
	delete newIncome;

	ExpenseObj* newExpense = new ExpenseObj();
	for (counter = 0; counter < listOfExpenses.size(); counter++)
	{
		CurrentFile.open("..//MonthlyExpenses//Expenses//" + listOfExpenses[counter] + ".txt");//Opening Income File
		if (CurrentFile.fail())
		{
			cout << "Could not open..//MonthlyExpenses//Expenses//" << listOfExpenses[counter] << ".txt\n";
		}
		else
		{
			while (CurrentFile >> temp)
			{
				if (readDate)
				{
					readDate = 0;
					vector<int> vect;
					stringstream tempstream(temp);
					for (int i; tempstream >> i; i++)
					{
						vect.push_back(i);
						if (tempstream.peek() == ':')
							tempstream.ignore();
					}
					newExpense->dateOfPurchase.day = vect[0];
					newExpense->dateOfPurchase.month = vect[1];
					newExpense->dateOfPurchase.year = vect[2];
				}
				else if (readWallet)
				{
					readWallet = 0;
					newExpense->Wallet = temp;
					listOfExpenseNodes.push_back(*newExpense);
				}
				else if (readAmount)
				{
					readAmount = 0;
					newExpense->amountOfPurchase = atof(temp.c_str());
					newExpense->category = listOfExpenses[counter];
				}
				if (temp == "Date:") readDate = 1;
				else if (temp == "Cost:")readAmount = 1;
				else if (temp == "Wallet:")readWallet = 1;

			}
		}
		CurrentFile.close();
	}

}

void cleanVector(vector<IncomeObj>& listOfIncomeNodes, vector<ExpenseObj>& listOfExpenseNodes)
{
	listOfIncomeNodes.clear();
	listOfExpenseNodes.clear();
}
