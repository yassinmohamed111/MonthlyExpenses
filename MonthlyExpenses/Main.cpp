#include <iostream>
#include "Budget.h"

using namespace std;

int main()
{
	//Initialize systems
	vector <IncomeObj> listOfIncomeNodes;
	vector <ExpenseObj> listOfExpenseNodes;

	vector <string> listOfExpenses;
	vector <string> listOfIncome;
	
	initializeExpenses(listOfExpenses);
	initializeIncome(listOfIncome);
	//printListOfIncome(listOfIncome);
	initializeListsOfNodes(listOfIncomeNodes, listOfExpenseNodes, listOfExpenses, listOfIncome);

	calculateTotal(listOfIncomeNodes);

	int choice;
	while (1)
	{
		cout << "[1]Add New Income\n[2]Change Monthly Income\n[3]View Income Info\n[4]Add New Expense\n[5]Add to existing Expense\n[6]View Expense Info\n[7]View Remaing Money\n[8]Exit\nChoice : ";
		
		cin >> choice;
		cout << "\n";

		switch (choice)
		{
		case 1:
		{
			addNewIncome(listOfIncome,listOfIncomeNodes);
			calculateTotal(listOfIncomeNodes);
			break;
		}
		case 2:
		{
			changeMontlyIncome(listOfIncome,listOfIncomeNodes);
			calculateTotal(listOfIncomeNodes);
			
			break;
		}
		case 3:
		{
			printIncomeIntoFile(listOfIncomeNodes);
			calculateTotal(listOfIncomeNodes);
			ViewIncomeInfo(listOfIncome);
			break;
		}
		case 4:
		{
			addNewExpenseCategory(listOfExpenses);
			break;
		}
		case 5:
		{
			addExistingExpense(listOfExpenses, listOfIncomeNodes);
			printIncomeIntoFile(listOfIncomeNodes);
			cleanVector(listOfIncomeNodes, listOfExpenseNodes);
			initializeListsOfNodes(listOfIncomeNodes, listOfExpenseNodes, listOfExpenses, listOfIncome);
			break;
		}
		case 6:
		{
			ViewExpenseInfo(listOfExpenses,listOfExpenseNodes);
			break;
		}
		case 7:
		{
			Remaining(listOfIncomeNodes);
			break;
		}
		case 8:
		{
			printIncomeIntoFile(listOfIncomeNodes);
			cleanVector(listOfIncomeNodes, listOfExpenseNodes);
			exit(0);
		}
		default:
		{
			cout << "Not a valid choice::Try Again\n";
			break;
		}
		}

		cout << "\n\n";
		system("pause");
		system("cls");
	}

	system("pause");
	return 0;
}