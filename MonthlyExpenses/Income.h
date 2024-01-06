#pragma once

#include "Expense.h"

struct IncomeObj
{
	string Wallet_Name;
	Date dateRecieved;
	float MontlyIncome;
	float total;
};


void initializeIncome(vector<string>& listOfIncome);

void printListOfIncome(vector<string>listOfIncome);

void addNewIncome(vector<string>& listOfIncome,vector<IncomeObj>& listOfIncomeNodes);

//void addExistingIncome(vector<string>listOfIncome);

void changeMontlyIncome(vector<string>listOfIncome,vector<IncomeObj>& listOfIncomeNodes);

void printIncomeIntoFile(vector<IncomeObj> listofIncomeNodes);

void printSingleIncomeFile(string nameOfIncome);

void ViewIncomeInfo(vector<string>listOfIncome);

void calculateTotal(vector<IncomeObj>& listofIncomeNodes);

void Remaining(vector<IncomeObj>& listofIncomeNodes);

void addExistingExpense(vector<string>listOfExpenses, vector<IncomeObj>& listOfIncomeNodes);