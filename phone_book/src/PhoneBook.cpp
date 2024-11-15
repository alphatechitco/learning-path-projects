#include<iostream>
#include<fstream>
#include<cstring>
#include<stdio.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

using namespace std;

class PhoneBook
{
    int srno;
    char n[28];
    char m[17];
    char e[40];
    char g[30];

public:
    int getSrNo() { return srno; }

    void storeData()
    {
        cout << "\n....CREATE NEW PHONE RECORD.....\n";
        cout << "Enter Serial Number :";
        cin >> srno; cin.ignore();
        cout << "Enter Record Name :";
        cin >> n;
        cout << "Enter Mobile Number:";
        cin >> m;
        cout << "Enter E-Mail I.D. :";
        cin >> e;
        cout << "Enter Record Group:";
        cin >> g;
        cout << endl;
    }

    void showData()
    {
        cout << "\n.......PHONE BOOK RECORD.......\n";
        cout << "Sr. No.    :" << srno << endl;
        cout << "Name       :" << n << endl;
        cout << "Mobile No  :" << m << endl;
        cout << "Email ID   :" << e << endl;
        cout << "Group      :" << g << endl;
    }

    void saveDataToFile()
    {
        ofstream fout;
        fout.open("PhoneBook.dat", ios::app);  // Open in append mode
        fout.write((char *)this, sizeof(*this));  // Writing the object to file
        fout.close();
        cout << "\nRecord Saved To File......\n";
    }

    static void showAllRecords()
    {
        ifstream fin;
        fin.open("PhoneBook.dat");
        PhoneBook temp;
        while (fin.read((char *)&temp, sizeof(temp)))
        {
            temp.showData();
        }
        fin.close();
        cout << "\nReading Of Data File Completed.....\n";
    }

    static void searchWithSerialNumber()
    {
        ifstream fin;
        int n, flag = 0;
        fin.open("PhoneBook.dat");
        cout << "Enter Serial Number of Record To Display:";
        cin >> n;
        PhoneBook temp;
        while (fin.read((char *)&temp, sizeof(temp)))
        {
            if (n == temp.getSrNo())
            {
                temp.showData();
                flag++;
                cout << "\n\n.....Record Found And Displayed.....\n";
                break;
            }
        }
        fin.close();
        if (flag == 0)
            cout << "\nThe Record of Serial Number " << n << " is not in list....\n";
        cout << "\nReading of Data File Completed......\n";
    }

    static void deleteRecord()
    {
        ifstream fin;
        ofstream fout;
        int n, flag = 0;
        fin.open("PhoneBook.dat");
        fout.open("temp.dat");
        cout << "Enter Serial Number of Record To Delete:";
        cin >> n;
        PhoneBook temp;
        while (fin.read((char *)&temp, sizeof(temp)))
        {
            if (n == temp.getSrNo())
            {
                cout << "\nThe Following Record Is Deleted....\n";
                temp.showData();
                flag++;
            }
            else
            {
                fout.write((char *)&temp, sizeof(temp));
            }
        }
        fin.close();
        fout.close();
        if (flag == 0)
        {
            cout << "\nThe Record of Serial Number " << n << " is not in file....\n";
        }
        else
        {
            remove("PhoneBook.dat");
            rename("temp.dat", "PhoneBook.dat");
        }
    }

    static void updateRecord()
    {
        fstream fio;
        int n, flag = 0, pos;
        fio.open("PhoneBook.dat", ios::in | ios::out);
        cout << "Enter Serial Number of Record To Modify:";
        cin >> n;
        PhoneBook temp;
        while (fio.read((char *)&temp, sizeof(temp)))
        {
            pos = fio.tellg();
            if (n == temp.getSrNo())
            {
                cout << "\nThe Following Record will be modified....\n";
                temp.showData();
                flag++;
                cout << "\nRe-Enter the New Details.....\n";
                temp.storeData();
                fio.seekg(pos - sizeof(temp));  // Move file pointer back
                fio.write((char *)&temp, sizeof(temp));
                cout << "\n....Data Modified Successfully....\n";
                break;
            }
        }
        fio.close();
        if (flag == 0)
            cout << "\nThe Record of Serial Number " << n << " is not in file....\n";
        cout << "\nReading of Data File Completed.....\n";
    }
};

void menu()
{
    int ch;
    do
    {
        cout << "............................................\n";
        cout << "           PHONE BOOK MANAGEMENT\n";
        cout << "............................................\n\n";
        cout << "=============================" << endl;
        cout << "Developed by Dev @ AlphaTech" << endl;
        cout << "=============================" << endl;
        cout << "::::::::::::::: PROGRAM MENU :::::::::::::::\n";
        cout << "0. Exit\n";
        cout << "1. Save New Phone Record\n";
        cout << "2. Display All Saved Records\n";
        cout << "3. Search Specific Record\n";
        cout << "4. Delete Specific Record\n";
        cout << "5. Modify Existing Record\n";
        cout << "Enter Your Choice  ";
        cin >> ch;

        PhoneBook pb;  // Create an instance of PhoneBook class
        switch (ch)
        {
        case 1:
            pb.storeData();
            pb.saveDataToFile();
            break;
        case 2:
            PhoneBook::showAllRecords();
            break;
        case 3:
            PhoneBook::searchWithSerialNumber();
            break;
        case 4:
            PhoneBook::deleteRecord();
            break;
        case 5:
            PhoneBook::updateRecord();
            break;
        }
    } while (ch != 0);
}

int main()
{
    menu();
    return 0;
}
