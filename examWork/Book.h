#pragma once
#include "Date.h"
#include "functions.h"
#include <cstdio>
struct Book
{
	char type[30]= "";
	char name[50]= "";
	char author[50]="";
	int pages= 0;
	Date existed;
	Date added;

	void showBook() 
	{
		cout << "========================================" << endl;
		cout << "Name : " << name << endl;
		cout << "\tType : "<<type <<endl;
		cout << "\tAuthor : "<< author<<endl;
		cout << "\tPages : " << pages << endl;
		cout << "\tExist Date : ";
		existed.printDate();
		cout << "\tAdded to library date : ";
		added.printDate();
		cout << "========================================" << endl;
	}
	void addNewBook()
	{
		cout << "Enter type of book - ";
		cin.ignore();
		cin.getline(type, 30);
		cout << endl;
		
		cout << "Enter book name - ";
		cin.getline(name,50);
		cout << endl;
		
		cout << "Enter book author - ";
		cin.getline(author,50);
		cout << endl;
		
		cout << "Enter count of pages - ";
		cin >> pages;
		cout << endl;
		
		cout << "Enter date of develop"<<endl;
		
		existed.fillDate();
		
		added.getNowDate();
	}
	
	void saveToBinFile(FILE* fp) {
		int typeSize = strlen(type) + 1;
		int nameSize = strlen(name) + 1;
		int authorSize = strlen(author) + 1;

		fwrite(&typeSize, sizeof(int), 1, fp);
		fwrite(type, sizeof(char), typeSize, fp);

		fwrite(&nameSize, sizeof(int), 1, fp);
		fwrite(name, sizeof(char), nameSize, fp);

		fwrite(&authorSize, sizeof(int), 1, fp);
		fwrite(author, sizeof(char), authorSize, fp);

		fwrite(&pages, sizeof(int), 1, fp);
		existed.saveToBinFile(fp);
		added.saveToBinFile(fp);
	}

	void loadFromBinFile(FILE* fp)
	{
		int typeSize = 0, nameSize = 0, authorSize = 0;

		fread(&typeSize, sizeof(int), 1, fp);
		fread(type, sizeof(char), typeSize, fp);

		fread(&nameSize, sizeof(int), 1, fp);
		fread(name, sizeof(char), nameSize, fp);

		fread(&authorSize, sizeof(int), 1, fp);
		fread(author, sizeof(char), authorSize, fp);

		fread(&pages, sizeof(int), 1, fp);

		existed.loadFromBinFile(fp);
		added.loadFromBinFile(fp);
	}


};