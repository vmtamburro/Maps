#include <iostream>
#include <limits>
#include "StudentData.h"
#include <map>


using namespace std;


int main()
{



    map<int, StudentData> studentInfo =
    {{1000, StudentData("Victoria Tamburro", "908-235-9019", "14 Elizabeth Ave, Cherry Hill NJ 08002")},
     {1001, StudentData("Alexandra Scoval", "809-678-2367", "17 Park Ave, Philadelphia PA 19145")},
     {1003, StudentData("Kala Giannone", "903-873-2457", "2996 Bark Road, Toms River NJ 08004")}};

    int lastKey = 1003;
    bool ret;

    while(ret == true)
    {
        system("cls");
        int choice;
         const int ADDSTUDENT = 1,
                   UPDATESTUDENT = 2,
                   REMOVESTUDENT = 3,
                   FINDSTUDENT = 4,
                   DISPLAYINFO = 5,
                   DISPLAYALL = 6,
                   QUIT = 7;
          cout << "Select an option from the menu below:\n\n";
          cout<< "1. Add Student"<<endl;
          cout<< "2. Update Student"<<endl;
          cout<< "3. Remove Student"<<endl;
          cout<< "4. Find Student"<<endl;
          cout<< "5. Display Student Info"<<endl;
          cout<< "6. Display All Students"<<endl;
          cout<< "7. Quit"<<endl;

          cin>>choice;
          while(cin.fail())
          {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              cout<< "Invalid entry. Enter a number from 1-6: ";
              cin >> choice;
          }

     int studentID;

     switch(choice)
     {
        case ADDSTUDENT:
            {
                string fullName, phoneNumber, address;
                cout<< "Enter the Full Name of the student you would like to add: ";
                cin.ignore();
                getline(cin, fullName);
                cout<< "Enter the Phone Number of the student you would like to add: ";
                getline(cin, phoneNumber);
                cout<< "Enter the Address of the student you would like to add: ";
                getline(cin, address);
                lastKey++;
                studentInfo.emplace(lastKey, StudentData(fullName, phoneNumber, address));

                cout<< "Student Successfully Added."<<endl;

                ret = true;
                break;
            }

        case UPDATESTUDENT:
            {
            cout<< "Enter the Student ID of the student you would like to update"<<endl;
            cin>> studentID;
            cout<< "Displaying Existing Data: "<<endl;
            if(studentInfo.count(studentID))
                cout<< studentInfo.at(studentID);
            else
            {
                cout<< "No student found with that ID. "<<endl;
                ret = true;
                break;
            }
            string fullName, phoneNumber, address;
            cout<< "Enter the Full Name of the student you would like to add: ";
            cin.ignore();
            getline(cin, fullName);
            cout<< "Enter the Phone Number of the student you would like to add: ";
            getline(cin, phoneNumber);
            cout<< "Enter the Address of the student you would like to add: ";
            getline(cin, address);
            studentInfo[studentID] = StudentData(fullName, phoneNumber, address);

            cout<< "Displaying New Data: "<<endl;
            cout<< studentInfo.at(studentID);
            ret = true;
            break;
            }
        case REMOVESTUDENT:
            cout<<"Enter the Student ID of the student you would like to erase: ";
            cin>>studentID;

            if(studentInfo.count(studentID))
            {
                studentInfo.erase(studentID);
                cout << "Student successfully erased"<<endl;
            }
            else
                cout<< "Student was not found"<<endl;
            ret = true;
            break;
        case FINDSTUDENT:
            cout<< "Enter the Student ID of the student you are searching for: ";
            cin>>studentID;
            if(studentInfo.count(studentID))
                cout<< "Student found!";
            else
                cout<< "Student was not found.";
            ret = true;
            break;
        case DISPLAYINFO:
            cout<< "Enter the Student ID of the student you would like to display: ";
            cin>> studentID;
            if(studentInfo.count(studentID))
                cout<< studentInfo.at(studentID)<<endl;
            else
                cout<< "Student not found"<<endl;
            ret = true;
            break;
        case DISPLAYALL:
            for(auto element: studentInfo)
            {
                cout<< "Student ID: "<<element.first<<endl;
                cout << element.second<<endl;
            }
            break;
        case QUIT:
            ret = false;
            break;
     }
     system("pause");
    }
    return 0;
}
