#include <iostream>

using namespace std;

class patient
{
    private:
    string name;
    string PhoneNum;
    string IcNum;

    public:
    patient(string n, string p , string ic) : name(n),PhoneNum(p), IcNum(ic){}
    string getNum()
    {
        return name;
    }
    string PhoneNum()
    {
        return PhoneNum;
    }
    string IcNum()
    {
        return IcNum;
    }

};
class patient_Details
{
    private:
    string bloodGroup;
    string medical_history;

    public:
    void Display_patientDetails()
    {}
};