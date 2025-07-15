#include <iostream>
#include <fstream>
using namespace std;

void writef()
{
    int roll;
    string name, div, address;
    fstream write;

    cout << "Enter the roll no : ";
    cin >> roll;
    cout << "Enter the Name : ";
    cin.ignore(); 
    getline(cin, name); 
    cout << "Enter the div : ";
    cin >> div;
    cout << "Enter the address : ";
    cin.ignore(); 
    getline(cin, address); 

    // writing to file
    write.open("student.txt", ios::app);
    if (!write) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    write << roll << "\n";
    write << name << "\n";
    write << div << "\n";
    write << address << "\n";
    write << "\n";
    write.close();
}

void readf()
{
    int roll;
    string name, div, address;
    fstream read;
    read.open("student.txt", ios::in);

    // Check if the file is open
    if (!read) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    // Print headers before showing records
    cout << "Roll No\t\tName\t\tDivision\t\tAddress" << endl;
    cout << "----------------------------------------------------------" << endl;

    while (read >> roll) {
        read.ignore();  
        getline(read, name);
        read >> div;
        read.ignore();  
        getline(read, address);

        cout << roll << "\t\t" << name << "\t\t" << div << "\t\t" << address << endl;
    }

    read.close();
}

void searchf()
{
    int roll, froll;
    bool flag = false;
    string name, div, address;
    fstream read;
    cout << "Enter Roll no to search: ";
    cin >> froll;

    read.open("student.txt", ios::in);

    // Check if the file is open
    if (!read) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    // Print headers before showing records
    cout << "Roll No\t\tName\t\tDivision\t\tAddress" << endl;
    cout << "----------------------------------------------------------" << endl;

    while (read >> roll) {
        read.ignore();  
        getline(read, name);
        read >> div;
        read.ignore();  
        getline(read, address);

        if (roll == froll) {
            flag = true;
            cout << roll << "\t\t" << name << "\t\t" << div << "\t\t" << address << endl;
        }
    }

    if (!flag)
        cout << "Record Not Found" << endl;

    read.close();
}

void deletef()
{
    int roll, froll;
    bool flag = false;
    string name, div, address;
    fstream read, write;
    cout << "Enter Roll no to Delete: ";
    cin >> froll;

    read.open("student.txt", ios::in);
    // Check if the file is open
    if (!read) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    write.open("stud_updated.txt", ios::app);
    if (!write) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    while (read >> roll) {
        read.ignore();  
        getline(read, name);
        read >> div;
        read.ignore();  
        getline(read, address);

        if (roll == froll) {
            flag = true; // Skip this record
        } else {
            write << roll << "\n";
            write << name << "\n";
            write << div << "\n";
            write << address << "\n";
            write << "\n";
        }
    }

    read.close();
    write.close();

    remove("student.txt");
    rename("stud_updated.txt", "student.txt");

    if (flag)
        cout << "Record Deleted" << endl;
    else
        cout << "Record Not Found" << endl;
}

int main()
{
    int ch;
    while (1)
    {
        cout << "****************PRACTICAL NO:11(F-23)*********************" << endl;
        cout << "Prepared by: Anushka Patil" << endl;
        cout << "Menu" << endl;
        cout << "\n1.Write  \n2.Read  \n3.Delete  \n4.Search" << endl;
        cout<<"Enter your choice: "<<endl;
        cin >> ch;

        if (ch == 1)
            writef();
        else if (ch == 2)
            readf();
        else if (ch == 3)
            deletef();
        else if (ch == 4)
            searchf();
        else {
            cout << "Exiting..." << endl;
            return 0; // exit
        }
    }

    return 0;
}

