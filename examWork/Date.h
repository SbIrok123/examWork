#pragma once
#include <ctime>
#include <iostream>
using namespace std;
struct Date {
	int day = 0;
	int month = 0;
	int year = 0;
	char str[50] = "";

	void fillDate() {
		cout << "Day -> ";
		cin >> day;
		cout << endl;
		cout << "Month -> ";
		cin >> month;
		cout << endl;
		cout << "Year -> ";
		cin >> year;
		cout << endl;
	}

	void printDate() {
		cout << day / 10 << day % 10 << "." << month / 10 << month % 10 << "." << year << endl;
	}

	const char* toString(const char* format = "%d %B %Y") {
		tm dateInfo = { 0, 0, 0, day, month - 1, year - 1900 };
		strftime(str, 50, format, &dateInfo);
		return str;
	}

	void getNowDate() {
		time_t seconds = time(NULL);
		tm dateInfo = { 0 };
		localtime_s(&dateInfo, &seconds);

		year = dateInfo.tm_year + 1900;
		month = dateInfo.tm_mon + 1;
		day = dateInfo.tm_mday;
	}
	void saveToBinFile(FILE* fp) {
		fwrite(&day, sizeof(int), 1, fp);
		fwrite(&month, sizeof(int), 1, fp);
		fwrite(&year, sizeof(int), 1, fp);
	}

	void loadFromBinFile(FILE* fp) {
		fread(&day, sizeof(int), 1, fp);
		fread(&month, sizeof(int), 1, fp);
		fread(&year, sizeof(int), 1, fp);
	}
};