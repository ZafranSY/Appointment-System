#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional> 
#include <limits>


const int SIZE = 100;
int cindex;
using namespace std;





class person
{
    private:
    int choice; //true means he is doctor while 0 means he is patient  
    public:
    void displaydeco()
    {
        for(int i = 0 ; i <10 ;i++)
        cout <<"*";
    }
    void display()
    {
        cout<<"\t\t\t---------HOSPITAL KAZANAH TUN-----------"<<endl;
        cout<<"\nAre you a Doctor or a Patient?"<<endl;
        cout <<"\n0 --- Patient"<<endl;
        cout <<"1 --- Doctor"<<endl;
        
        cout <<"else to exit"<<endl;
        cin>>choice;

    }
    int getChoice(){ return choice;}
        
};
class patient
{
    protected:
    bool found;
    
    public:
    int totalData;
    string name[SIZE];
    string name_entered,phoneNum_entered,IcNum_entered;
    string PhoneNum[SIZE];
    string IcNum[SIZE];
     string DrName[SIZE],Date[SIZE],Time[SIZE],Reason[SIZE];
    int *patientNum;


    patient(string n ={}, string p ={}, string ic={}) {}
    void setName()
    {
        cout<<"Enter your name : ";
        cin >> name_entered ;
    
    }
    void setIcNum()
    {
        cout <<"Enter your ic Number : ";
        cin>>IcNum_entered;

    }
    void setPhoneNum()
    {
        cout <<"Enter your phone Nubmber : ";
        cin >>phoneNum_entered;
    }
    void SearchingPatient()
    {
        
        ifstream finn("patientData.txt");
       int i = 0;
       found = false;
       cindex=0;
        while(!finn.eof())
        {
            
            
            getline(finn, name[i], '|');
            getline(finn,IcNum[i],'|');
            getline(finn,PhoneNum[i],'|');
            getline(finn,DrName[i],'|');
            getline(finn,Date[i],'|');
            getline(finn,Time[i],'|');  
            getline(finn,Reason[i]);
            

            if(name[i] == name_entered)
            {
                if(IcNum[i] == IcNum_entered)
                {
                    if(PhoneNum[i] == phoneNum_entered){
                    found = true; 
                    cindex = i;   
                    //cout display patient details
                    
                    
                    }
                }
            }
            i++;

           totalData++;
        }
    }
    bool getFound()
    {
        return found;
    }
    string getNum()
    {
        return name_entered;
    }
    string getPhoneNum()
    {
        return phoneNum_entered;
    }
    string getIcNnum()
    {
        return IcNum_entered;
    }

};
class patient_Details : public patient
{
    private:

    public:
    void Display_patientDetails()
   {
    setName();
    setIcNum();
    setPhoneNum();
    SearchingPatient();
      if(found)
      { 
       cout <<"-----------------------------------------------------"<<endl;
       cout <<"Name"<<"\t"<<"Ic Number"<<"\t"<<"Phone no"<<"\t"<<"Reason"<<endl;
       cout <<"-----------------------------------------------------"<<endl;
       
   
       cout<<name[cindex]<<"\t"<<IcNum[cindex]<<"\t\t"<<PhoneNum[cindex]<<"\t"<<Reason[cindex]<<endl;;
       cout <<"-----------------------------------------------------"<<endl;
       cout <<"Date : "<<Date[cindex]<<endl;
       cout <<"Time : "<<Time[cindex]<<endl;
       cout <<"Doctor : "<<DrName[cindex]<<endl;
       }else
       cout <<"not found"<<endl;
    
   }
    void BubbleSort_Name(string n[])
    {
        bool swapped;
        string tempVal;
        for(int i =0; i<totalData ; i++)
        {
            swapped= false;
            for(int j = 0;j<totalData -i ;j++)
            {
                if(n[j] > n[j+1])
                {
                    tempVal = n[j];
                    n[j] = n[j+1];
                    n[j+1] = tempVal;
                    tempVal = IcNum[j];
                    
                IcNum[j] = IcNum[j + 1];
                IcNum[j + 1] = tempVal;

                tempVal = PhoneNum[j];
                PhoneNum[j] = PhoneNum[j + 1];
                PhoneNum[j + 1] = tempVal;

                tempVal = DrName[j];
                DrName[j] = DrName[j + 1];
                DrName[j + 1] = tempVal;

                tempVal = Date[j];
                Date[j] = Date[j + 1];
                Date[j + 1] = tempVal;

                tempVal = Time[j];
                Time[j] = Time[j + 1];
                Time[j + 1] = tempVal;

                tempVal = Reason[j];
                Reason[j] = Reason[j + 1];
                Reason[j + 1] = tempVal;

                }
            }
        }
    }
    void view_appointments()
    {
        
        BubbleSort_Name(name);
      cout <<"-----------------------------------------------------"<<endl;
      cout <<"Name"<<"\t"<<"Ic Number"<<"\t"<<"Phone no"<<"\t"<<"\t"<<"Dr Name"
      <<"\t"<<"Date" <<"\t\t"<<"time" <<"\t"<<"Reason"<<endl;
      cout <<"-----------------------------------------------------"<<endl;
      
      
      for(int i = 0; i<totalData ;i++)
      {
        cout <<name[i]<<"\t"<<IcNum[i]<<"\t"<<PhoneNum[i]
        <<"\t"<<DrName[i]<<"\t"<<Date[i]<<"\t"<<Time[i]<<"\t"<<Reason[i]<<endl;
      }
    }
    
// 


};
class Doctor
{
    private:
    string pass_Entered;
    string name;
    string DocID;
    bool Verify_doc;
    patient_Details patient_detail;
    int index = patient_detail.totalData -1;

    

    public:
    void setID()
    {
        cout <<"Enter your ID "<<endl;
        cin >> DocID;
    }
    void setpassword()
    {
        cout<<"Enter your password "<<endl;
        cin>>pass_Entered;
    }
    // void bubleSort(vector <patient> & patients, function<bool(const patient&,const patient&)>comparator)
    // {
// 
    // }
    void add_appointment()
    {
        cout <<"Enter Patient name : ";
        cin >>patient_detail.name[index+1];

        cout <<"\nEnter patient Ic Number : ";
        cin >>patient_detail.IcNum[index+1];

        cout <<"\nEnter Patient Phone Number : ";
        cin >>patient_detail.PhoneNum[index+1];

        cout<<"\nEnter Doctor Name : ";
        cin >>patient_detail.DrName[index+1];

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"\nEnter Appointment Date : ";
        cin >>patient_detail.Date[index+1];

        cout <<"\nEnter Appointment Time : ";
        cin >>patient_detail.Time[index+1];

        cout <<"\nEnter Reason for Appointment : ";
        cin >>patient_detail.Reason[index+1];

        ofstream fout("patientData.txt", ios::app);

        fout <<'\n';
        fout<<patient_detail.name[index+1]<<'|'<<patient_detail.IcNum[index+1]<<'|'<<patient_detail.PhoneNum[index+1];
        fout <<patient_detail.DrName[index+1]<<'|'<<patient_detail.Date[index+1]<<'|'<<patient_detail.Time[index+1]
        <<'|'<<patient_detail.Reason[index+1];
        fout.close();



    }
    void change_details()
    {
        int line;
        int choice;

        string change_to;
        cout <<"Enter the line you want to change : ";
        cin >> line;
        if( line >= 0 && line <=patient_detail.totalData)
        {

        cout <<"What are want to change? "<<endl;
        cout<<"1 - Name "<<endl;
        cout<<"2 - Ic Number"<<endl;
        cout<<"3 - Phone Number"<<endl;
        cout<<"4 - Dr Name"<<endl;
        cout <<"5- Appointment Date"<<endl;
        cout << "6-Appointment Time"<<endl;
        cout <<"7 - Reason for Appointment"<<endl;

        cin >>choice;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout <<"\nwhat you want to change it to? : ";
        cin >>change_to;


        switch (choice)
        {
        case 1:
            patient_detail.name[line-1] = change_to;
            break;
        case 2:
            patient_detail.IcNum[line-1] = change_to;
        break;

        case 3:
        patient_detail.PhoneNum[line-1] = change_to;
        break;
    
        case 4:
        patient_detail.DrName[line-1] = change_to;
        break;
    
        case 5:
        patient_detail.Date[line-1] = change_to;
        break;
    
        case 6:
        patient_detail.Time[line-1] = change_to;
        break;
    
        case 7:
        patient_detail.Reason[line-1] = change_to;
        break;

        default:
            break;
        }
        
        ofstream foutt("patientData.txt");

        for(int i = 0 ; i<= patient_detail.totalData ;i++)
        {
            foutt <<patient_detail.name[i]<<'|'<<patient_detail.IcNum[i]<<'|'<<patient_detail.PhoneNum[i]<<'|'<<patient_detail.DrName[i]<<'|'
            <<patient_detail.Date[i] <<'|'<<patient_detail.Time[i]<<'|'<<patient_detail.Reason[i]<<endl;

        }
        
        foutt.close();
        }
        else 
        cout <<"There is no such line!!!!!"<<endl;

    }
    void ShowMenu()
{
    int choice;
    cout <<"\n\n\t1 - View Appointments"<<endl;
    cout <<"\t2 - Add Appointment"<<endl;
    cout <<"\t3 - Reschedule Appointment"<<endl;
    cout <<"\t0 - Exit\n"<<endl;

    cin >> choice;
    patient_detail.SearchingPatient();
    switch (choice)
    {
    case 1:
        patient_detail.view_appointments();
        break;
    case 2:
    add_appointment();
        break;

    case 3:
    change_details();
        break;

    case 0:
        break;
    
    default:
        break;
    }
}

    void SearchingID()
    {
        ifstream readfile("DoctorData.txt");
        string tempID, temp_pass;

         Verify_doc = false;
        while(getline(readfile,tempID,'|'))
        {
            getline(readfile,temp_pass);
            if(DocID == tempID)
            {
                if(pass_Entered ==  temp_pass)
                {
                    Verify_doc =true;
                    
                    break;
                    
                }
                break;
                
                
            }
             
        }
        if(Verify_doc == false) cout<<"\n\tThe Password entered was wrong!!!"<<endl;
        
    }
    bool getVerify()
    { return Verify_doc;}


};
int main()
{
    person p;
    Doctor doc;
    patient_Details pdetails;
    system("cls");
    cout <<"\n\t\t\tWELCOME TO HOSPITAL KAZANAH TUN"<<endl;
    char Run_again = 'y';
    while(Run_again == 'y'){
    p.display();
    patient a;
    switch (p.getChoice())
    {
    case 0:
    { 
        
        pdetails.Display_patientDetails();
        break;
    
    }
    case 1:
        {
        doc.setID();
        doc.setpassword();
        doc.SearchingID();
        switch (doc.getVerify())
        {
        case  1 :
          doc.ShowMenu();
            break;
        
        default:
            break;
        }
        break;

    }
    default: 
    break;
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout <<"You want to check again? Enter y : ";
    cin >>Run_again;
    }
}
