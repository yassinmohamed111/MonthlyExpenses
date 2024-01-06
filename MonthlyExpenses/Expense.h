#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Date.h"
//#include "Income.h"
using namespace std;

struct ExpenseObj
{
	string category;
	string Wallet;
	Date dateOfPurchase;
	float amountOfPurchase;
};

void initializeExpenses(vector<string>& listOfExpenses);

void addNewExpenseCategory(vector<string>& listOfExpenses);

void printListOfExpenses(vector<string>listOfExpenses);



void printSingleExpenseFile(string nameOfExpense);

void ViewExpenseInfo(vector<string>listOfExpenses, vector<ExpenseObj>listOfExpenseNodes);

void FilterExpense(vector<ExpenseObj>&listofExpensesNode);

vector<ExpenseObj> filterByWallet(vector<ExpenseObj>& listOfExpenseNodes, string wallet);

vector<ExpenseObj> filterByDate(vector<ExpenseObj>& listOfExpenseNodes, Date date);

vector<ExpenseObj> filterByCategory(vector<ExpenseObj>& listOfExpenseNodes, string category);

vector<ExpenseObj> filterByAmount(vector<ExpenseObj>& listOfExpenseNodes, float amount);

void filterByWalletSecond(vector<ExpenseObj>& newExpenseNodes);

void filterByDateSecond(vector<ExpenseObj>& newExpenseNodes);

void filterByCategorySecond(vector<ExpenseObj>& newExpenseNodes);

void filterByAmountSecond(vector<ExpenseObj>& newExpenseNodes);