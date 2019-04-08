#ifndef STUDENTDATA_H_INCLUDED
#define STUDENTDATA_H_INCLUDED

#include<iostream>
using namespace std;

class StudentData
{
private:
    string address;
    string phoneNumber;
    string fullName;

public:
    StudentData()
    {
        address = "";
        phoneNumber = "";
        fullName = "";
    }
    StudentData(string fn, string ph, string ad)
    {
        address = ad;
        phoneNumber = ph;
        fullName = fn;
    }
    string getAddress()
    {   return address; }
    string getPhoneNumber()
    {   return phoneNumber; }
    string getFullName()
    {   return fullName; }

    void setAddress(string ad)
    {   address = ad; }
    void setPhoneNumber(string ph)
    {   phoneNumber = ph;}
    void setFullName(string fn)
    {   fullName = fn;}

    friend ostream &operator << (ostream &, const StudentData &);
};


ostream &operator<<(ostream &strm, const StudentData &obj)
{
    strm<<"Student Full Name: "<<obj.fullName<<endl;
    strm<<"Student Phone Number: "<<obj.phoneNumber<<endl;
    strm<<"Student Address: "<<obj.address<<endl;

    return strm;
}


#endif // STUDENTDATA_H_INCLUDED
