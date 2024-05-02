#include "Book.h"
int main()
{
	int NBooks=NULL;
    FILE* fp = nullptr;
    Book* books=new Book[1];
    
    fopen_s(&fp, "books.txt", "r");
    if (fp != NULL) 
    {    
        fread(&NBooks, sizeof(int), 1, fp);
        delete[] books;
        books = new Book[NBooks];
        for(int i =0 ;i<NBooks;i++)
        {
            books[i].loadFromBinFile(fp);
        }
        fclose(fp);
    }


	int menu,deleteId,menuSort,menuEdit,editId,menuFind;
    Book tmp;
	do 
	{
        cout << "--------------------------------\n";
        cout << "|             MENU             |\n";
        cout << "|------------------------------|\n";
        cout << "|1.Show all books in library   |\n";
        cout << "|2.Add new book                |\n";
        cout << "|3.Remove book                 |\n";
        cout << "|4.Show sorted books           |\n";
        cout << "|5.Edit info in book           |\n";
        cout << "|6.Search book                 |\n";
        cout << "|------------------------------|\n";
        cout << "|0.Exit                        |\n";
        cout << "--------------------------------\n";
        cout << " >>> "; cin >> menu;
	
        switch (menu)
        {
        
        case 1:
            cout << "\n\n\n";
            for(int i = 0;i<NBooks;i++)
            {
                books[i].showBook();
            }
            cout << "\n\n\n";
            break;
        
        case 2:
            tmp.addNewBook();
            if (NBooks==NULL) 
            {
                cout << "asd";
                books[0] = tmp;
                NBooks=1;
            }
            else
            {
                addItemBack(books, NBooks, tmp);
            }
            break;
        
        case 3:
            char deleteName[50];
            cout << "\n\nEnter book name to delete - ";
            cin.ignore();
            cin.getline(deleteName,50);
            cout << endl;
            deleteId = -1;
            for (int i = 0; i < NBooks; i++)
            {
                if (strcmp(books[i].name, deleteName) == 0) 
                {
                    deleteId = i;
                    break;
                }
            }
            if(deleteId!=-1)
            {
            removeItem(books, NBooks, deleteId);
            cout << "Deleted!\n" << endl;
            }
            else 
            {
                cout << "Not found book with that name!\n"<<endl;
            }
            break;

        case 4:
            do {
                cout << "\n\n";
                cout << "------------------------------------------------------\n";
                cout << "|                           SORT                     |\n";
                cout << "------------------------------------------------------\n";
                cout << "|1.Sort by pages (from max to min)                   |\n";
                cout << "|2.Sort by develope year (from older to newest)      |\n";
                cout << "|3.Sort by add to library year (from older to newest)|\n";
                cout << "|----------------------------------------------------|\n";
                cout << "|0.Back to main menu                                 |\n";
                cout << "------------------------------------------------------\n";
                cout << " >>> "; cin >> menuSort;
                cout << "\n\n";
                
                switch (menuSort) 
                {
                case 1:
                    showSortedPages(books, NBooks);
                    break;
                case 2:
                    showSortedDateWriten(books, NBooks);
                    break;
                case 3:
                    showSortedDateAdded(books, NBooks);
                    break;
                case 0:
                    break;
                default:
                    cout << "Error command!"<<endl;
                    break;
                }
            } while (menuSort != 0);
                break;
        case 5:
            char editingBook[50];
            cout << "\nEnter name of book for edit - ";
            cin.ignore();
            cin.getline(editingBook, 50);
            cout << endl;
            editId = -1;
            for (int i = 0; i < NBooks; i++)
            {
                if (strcmp(books[i].name, editingBook) == 0)
                {
                    editId = i;
                    break;
                }
            }
            if(editId!=-1)
            {
                do {

                    cout << "\n\n";
                    cout << "-------------------------------------------------\n";
                    cout << "|                          EDIT                 |\n";
                    cout << "-------------------------------------------------\n";
                    cout << "|1. Edit type of book                           |\n";
                    cout << "|2. Edit name of book                           |\n";
                    cout << "|3. Edit author of book                         |\n";
                    cout << "|4. Edit count pages in book                    |\n";
                    cout << "|5. Edit write date                             |\n";
                    cout << "|6. Edit add to library date                    |\n";
                    cout << "|-----------------------------------------------|\n";
                    cout << "|0.Back to main menu                            |\n";
                    cout << "-------------------------------------------------\n";
                    cout << " >>> "; cin >> menuEdit;
                    cout << "\n\n";

                    switch (menuEdit)
                    {
                    case 1:
                        cout << "Enter new type of book - ";
                        cin.ignore();
                        cin.getline(books[editId].type, 30);
                        cout << "\nDone!"<<endl<<endl;
                        break;
                    case 2:
                        cout << "Enter new name of book - ";
                        cin.ignore();
                        cin.getline(books[editId].name, 50);
                        cout << "\nDone!"<<endl<<endl;
                        break;
                    case 3:
                        cout << "Enter new author of book - ";
                        cin.ignore();
                        cin.getline(books[editId].author, 50);
                        cout << "\nDone!"<<endl<<endl;
                        break; 
                    case 4:
                        cout << "Enter count of pages in book - ";
                        cin >> books[editId].pages;
                        cout << "\nDone!"<<endl<<endl;
                        break;
                    case 5:
                        cout << "Enter new date of creating book: "<<endl;
                        books[editId].existed.fillDate();
                        cout << "\nDone!"<<endl<<endl;
                        break;
                    case 6:
                        cout << "Enter new date of adding book: "<<endl;
                        books[editId].added.fillDate();
                        cout << "\nDone!"<<endl<<endl;
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Error!";
                        break;
                    }

                } while (menuEdit != 0);
            }
            else 
            {
                cout << "\nError!"<<endl;
            }
            break;
        case 6:
            do
            {
                cout << "\n\n";
                cout << "----------------------------\n";
                cout << "|          FIND            |\n";
                cout << "---------------------------|\n";
                cout << "|1.Find by name            |\n";
                cout << "|2.Find by literature type |\n";
                cout << "|3.Find by Author          |\n";
                cout << "|4.Find by adding month    |\n";
                cout << "|--------------------------|\n";
                cout << "|0.Back to main menu       |\n";
                cout << "----------------------------\n";
                cout << " >>> "; cin >> menuFind;
                cout << "\n\n";

                switch (menuFind)
                {
                case 1:
                    char findName[50];
                    cout << "Enter find name - ";
                    cin.ignore();
                    cin.getline(findName, 50);
                    for (int i = 0; i < NBooks; i++)
                    {
                        if (strcmp(findName, books[i].name) == 0) 
                        {
                            books[i].showBook();
                        }
                    }
                    cout << endl << endl;
                    break;
                case 2 :
                    char findType[30];
                    cout << "Enter find type - ";
                    cin.ignore();
                    cin.getline(findType, 30);
                    for (int i = 0; i < NBooks; i++)
                    {
                        if (strcmp(findType, books[i].type) == 0)
                        {
                            books[i].showBook();
                        }
                    }
                    cout << endl << endl;
                    break;
                case 3 :
                    char findAuthor[50];
                    cout << "Enter find type - ";
                    cin.ignore();
                    cin.getline(findAuthor, 50);
                    for (int i = 0; i < NBooks; i++)
                    {
                        if (strcmp(findAuthor, books[i].type) == 0)
                        {
                            books[i].showBook();
                        }
                    }
                    cout << endl << endl;
                    break;
                case 4:
                    int findYear;
                    cout << "Enter find month - ";
                    cin >> findYear;
                    for (int i = 0; i < NBooks; i++)
                    {
                        if (findYear == books[i].added.month)
                        {
                            books[i].showBook();
                        }
                    }
                    cout << endl << endl;
                    break;
                case 0:
                    break;
                default:
                    cout << "error!"<<endl;
                    break;
                }

            } while (menuFind);
            break;
        default:
            break;
        }
    
    } while (menu != 0);

    
    fopen_s(&fp, "books.txt", "wb"); //Сохраняем данные
    if (fp != NULL) {
        fwrite(&NBooks, sizeof(int), 1, fp);
        for (int i = 0; i < NBooks; ++i) {
            books[i].saveToBinFile(fp);
        }
        fclose(fp);
    }
    delete[] books;
}
