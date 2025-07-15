#include <iostream>
#include <fstream>
using namespace std;

void writef()
{
    int id;
    char name[50], desg[50], sal[20];
    fstream write;

    cout << "Enter the Employee ID : ";
    cin >> id;
    cin.ignore();
    cout << "Enter the Name : ";
    cin.getline(name, 50);
    cout << "Enter the Designation : ";
    cin.getline(desg, 50);
    cout << "Enter the Salary : ";
    cin.getline(sal, 20);

    if (id > 0 && id <= 10)
    {
        write.open("1to10.txt", ios::app);
        write << id << "\n" << name << "\n" << desg << "\n" << sal << "\n\n";
        write.close();
    }
    else if (id > 10 && id <= 20)
    {
        write.open("11to20.txt", ios::app);
        write << id << "\n" << name << "\n" << desg << "\n" << sal << "\n\n";
        write.close();
    }
    else if (id > 20 && id <= 30)
    {
        write.open("21to30.txt", ios::app);
        write << id << "\n" << name << "\n" << desg << "\n" << sal << "\n\n";
        write.close();
    }
}

void readf()
{
    int id;
    char name[50], desg[50], sal[20];
    fstream read;

   
    cout << "ID\t\tName\t\t\t\tDesignation\t\tSalary" << endl;
    cout << "---------------------------------------------------------------" << endl;

    
    read.open("1to10.txt", ios::in);
    while (read >> id)
    {
        read.ignore();
        read.getline(name, 50);
        read.getline(desg, 50);
        read.getline(sal, 20);

       
        cout << id << "\t\t" << name << "\t\t" << desg << "\t\t" << sal << endl;
    }
    read.close();

    
    read.open("11to20.txt", ios::in);
    while (read >> id)
    {
        read.ignore();
        read.getline(name, 50);
        read.getline(desg, 50);
        read.getline(sal, 20);

        
        cout << id << "\t\t" << name << "\t\t" << desg << "\t\t" << sal << endl;
    }
    read.close();

  
    read.open("21to30.txt", ios::in);
    while (read >> id)
    {
        read.ignore();
        read.getline(name, 50);
        read.getline(desg, 50);
        read.getline(sal, 20);

        
        cout << id << "\t\t" << name << "\t\t" << desg << "\t\t" << sal << endl;
    }
    read.close();
}

void deletef()
{
    fstream read, write;
    int id, did;
    char name[50], desg[50], sal[20];
    cout << "Enter ID of employee to delete: ";
    cin >> did;

    if (did > 0 && did <= 10)
    {
        read.open("1to10.txt", ios::in);
        write.open("1to10up.txt", ios::out | ios::app);
        while (read >> id)
        {
            read.ignore();
            read.getline(name, 50);
            read.getline(desg, 50);
            read.getline(sal, 20);

            if (id != did)
            {
                write << id << "\n" << name << "\n" << desg << "\n" << sal << "\n\n";
            }
            else
            {
                cout << "Deleting Record with ID " << did << "...\n";
            }
        }
        read.close();
        write.close();
        remove("1to10.txt");
        rename("1to10up.txt", "1to10.txt");
    }
    else if (did > 10 && did <= 20)
    {
        read.open("11to20.txt", ios::in);
        write.open("11to20up.txt", ios::out | ios::app);
        while (read >> id)
        {
            read.ignore();
            read.getline(name, 50);
            read.getline(desg, 50);
            read.getline(sal, 20);

            if (id != did)
            {
                write << id << "\n" << name << "\n" << desg << "\n" << sal << "\n\n";
            }
            else
            {
                cout << "Deleting Record with ID " << did << "...\n";
            }
        }
        read.close();
        write.close();
        remove("11to20.txt");
        rename("11to20up.txt", "11to20.txt");
    }
    else if (did > 20 && did <= 30)
    {
        read.open("21to30.txt", ios::in);
        write.open("21to30up.txt", ios::out | ios::app);
        while (read >> id)
        {
            read.ignore();
            read.getline(name, 50);
            read.getline(desg, 50);
            read.getline(sal, 20);

            if (id != did)
            {
                write << id << "\n" << name << "\n" << desg << "\n" << sal << "\n\n";
            }
            else
            {
                cout << "Deleting Record with ID " << did << "...\n";
            }
        }
        read.close();
        write.close();
        remove("21to30.txt");
        rename("21to30up.txt", "21to30.txt");
    }
}

int main()
{
    int ch;
    while (1)
    {
    	cout<<"*****************PRACTICAL NO: 12(F-24)****************"<<endl;
    	cout<<"Prepared by: Anushka Patil"<<endl;
    	cout<<"---------------------MENU-----------------"<<endl;
        cout << endl;
        cout << "\n1. Write  \n2. Read  \n3. Delete  \n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        if (ch == 1)
            writef();
        else if (ch == 2)
            readf();
        else if (ch == 3)
            deletef();
        else if (ch == 4)
            break;
        else
            cout << "Invalid choice! Please try again.\n";
    }

    return 0;
}

