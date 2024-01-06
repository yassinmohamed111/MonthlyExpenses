#pragma once

struct Date
{
	int day;
	int month;
	int year;

	bool operator==(Date date) const {
		if (date.day == day && date.month == month && date.year == year)return true;
		else return false;
	}
};