#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <conio.h>
using namespace std;
int dayPatients,monthlyPatients,d,n,k,dcounter=0,pcounter=0,Days,minimum,dtemp;
long double sum,monthlyTotalFee,temp;
string option;
struct days
{
int day,totaldayPatients;
long double totaldayFee;
};
struct days index[6];
struct collectinfo
{
long double fee;
string name;
};
struct collectinfo prop[10000];
void collectData ()
{
    do
    {
        cout<<"                      ***Add patients entries***"<<endl;
        cout<<endl;
        cout<<endl;
        int i=0;
        for(int j=0;j<6;j++)
        {
            dayPatients=0;
            dcounter++;
            index[j].day = dcounter;
            cout<<" // Day :"<<index[j].day<<endl;
            cout<<endl;
            cout<<endl;
            sum=0;
            do
            {
                n=1;
                k=n;
                i=i+k;
                if(prop[i].name=="")
                {
                    pcounter++;
                    do
                    {
                        cout<<"----------------------------------------------------------------"<<endl;
                        cout<<"|                                                              |"<<endl;
                        cout<<"    Enter Patient Details Here // "<<endl;
                        cout<<endl;
                        cout<<"    Enter patient's name: "<<endl;
                        cin>>prop[i].name;
                        cout<<"    Enter amount paid by patient: : "<<endl;
                        cin>>prop[i].fee;
                        cout<<"|                                                              |"<<endl;
                        cout<<"----------------------------------------------------------------"<<endl;
                        if(prop[i].fee<300 || prop[i].name=="")
                        {
                            system("PAUSE");
                            system("CLS");
                        }
                    }while(prop[i].fee<300 || prop[i].name=="");
                    cout<<endl;
                    cout<<endl;
                    cout<<"----------------------------------------------------------------"<<endl;
                    cout<<"|                                                              |"<<endl;
                    cout<<"    Patient :" <<prop[i].name<<endl;
                    cout<<"    Patient No.:"<<pcounter<<" Details entered successfully"<<endl;
                    cout<<endl;
                    cout<<"    On Day :"<<index[j].day<<endl;
                    cout<<"|                                                              |"<<endl;
                    cout<<"----------------------------------------------------------------"<<endl;
                    cout<<"    Press (Any key) to Continue / Press (99) to Exit for the Day"<<endl;
                    cin>>option;
                    cout<<endl;
                    cout<<endl;
                    cout<<endl;
                    cout<<endl;
                    sum = sum + prop[i].fee;
                    index[j].totaldayFee = sum;
                    dayPatients++;
                    index[j].totaldayPatients = dayPatients;
                }
            }while(option!="99");
            system("PAUSE");
            system("CLS");
        }
    }while(option!="99");
    system("PAUSE");
    system("CLS");
}
void seePatients()
{
    cout<<"                      ***Patients***"<<endl;
    cout<<endl;
    cout<<" Currently Booked Patients                   <99> Go back"<<endl;
    cout<<endl;
    cout<<endl;
    dcounter=1;
    k=0;
    d=0;
    for(int j=0;j<6;j++)
    {
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"|                                                              |"<<endl;
        cout<<"|   Day :"<<dcounter++;
        cout<<endl;
        cout<<endl;
        n=k;
        d=d+index[j].totaldayPatients;
        for(int i=n+1; i<d+1; i++)
        {
            cout<<"   NAME :"<<prop[i].name<<endl;
            cout<<"   AMOUNT PAID BY PATIENT :R"<<prop[i].fee;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            k++;
        }
         cout<<"|                                                              |"<<endl;
         cout<<"----------------------------------------------------------------"<<endl;
    }
        while(option!="99")
        {
            cin>>option;
        }
    system("PAUSE");
    system("CLS");
}
void totalMonthlyPatients ()
{
    do
    {
        monthlyPatients=0;
        for(int j=0; j<6; j++)
        {
            monthlyPatients = monthlyPatients+index[j].totaldayPatients;
        }
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"|                                                              |"<<endl;
        cout<<"    Total amount of patients seen this month is :"<<monthlyPatients<<endl;
        cout<<"|                                                              |"<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"Press 99 to go back"<<endl;
        while(option!="99")
        {
            cin>>option;
        }
    }while(option!="99");
    system("PAUSE");
    system("CLS");
}
void dayWithLeastPatients ()
{
    int j=0;
    Days=1;
    minimum=index[j].totaldayPatients;
    do
    {
        for(j=0; j<6; j++)
        {
            if(index[j].totaldayPatients < minimum)
            {
                minimum = index[j].totaldayPatients;
                Days = index[j].day;
            }
        }
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"|                                                              |"<<endl;
        cout<<"    The least patients seen this month is :"<<minimum<< " on day :"<<Days<<endl;
        cout<<"|                                                              |"<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"Press 99 to go back"<<endl;
        while(option!="99")
        {
            cin>>option;
        }
    }while(option!="99");
    system("PAUSE");
    system("CLS");
}
void monthlyTotalIncome ()
{
    do
    {
        sum = 0;
        cout<<"                ***monthly total income****"<<endl;
        for(int j=0; j<6; j++)
        {
            sum = sum + index[j].totaldayFee;
            monthlyTotalFee = sum;
        }
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"|                                                              |"<<endl;
        cout<<"    The total monthly income is :" <<monthlyTotalFee<< ""<<endl;
        cout<<"|                                                              |"<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"Press 99 to go back"<<endl;
        while(option!="99")
        {
            cin>>option;
        }
    }while(option!="99");
    system("PAUSE");
    system("CLS");
}
void sort_totaldayFee(long double feeArr[6], int dayArr[6], int assignments)
{
    pcounter=0;
    do
    {
        pcounter++;
        for(int j=0; j<6; j++)
        {
            temp=feeArr[j];
            dtemp=dayArr[j];
            if(temp>feeArr[j+1])
            {
                feeArr[j]=feeArr[j+1];
                feeArr[j+1]=temp;
                dayArr[j]=dayArr[j+1];
                dayArr[j+1]=dtemp;
            }
        }
    }while(pcounter!=assignments);
}
void topFiveDailyEarning ()
{
    long double feeArr[6];
    int dayArr[6], assignments;
    do
    {
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"|                                                              |"<<endl;
        cout<<"   Top Five Daily Earnings"<<endl;
        cout<<endl;
        for(int j=0; j<6; j++)
        {
            feeArr[j]=index[j].totaldayFee;
            dayArr[j]=index[j].day;
        }
        assignments=6*5/4;
        sort_totaldayFee(feeArr, dayArr, assignments);
        for(int j=5; j>=1; j--)
        {
            cout<<"   Amount Earned Is :"<<feeArr[j]<<" On day :"<<dayArr[j]<<endl;
            cout<<endl;
        }
        cout<<"|                                                              |"<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"Press (Any Key) to go back"<<endl;
        while(option!="99")
        {
            cin>>option;
        }
    }while(option!="99");
    system("PAUSE");
    system("CLS");
}
int main ()
{
    int option;
    do
    {
        cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"|                                 *** Dr Plaatje***                                                 |"<<endl;
        cout<<"|                                                                                                   |"<<endl;
        cout<<"      SELECT"<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<"        ( 1 ) New Customer(s) /                   ( 2 ) Total Monthly Patients"<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<"        ( 3 ) Total Monthly Income                ( 4 ) Day with Least No. of Patients"<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<"        ( 5 ) Top Five Daily Earnings              ( 6 ) See All Monthly Patients"<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<"        ( 999 ) Exit Program"<<endl;
        cout<<"|                                                                                                    |"<<endl;
        cout<<"|                                                                                                    |"<<endl;
        cout<<"------------------------------------------------------------------------------------------------------"<<endl;
        cin>>option;
        system("PAUSE");
        system("CLS");
        switch(option)
        {
            case 1:
                collectData();
                break;
            case 2:
                totalMonthlyPatients();
                break;
            case 3:
                monthlyTotalIncome();
                break;
            case 4:
                dayWithLeastPatients();
                break;
            case 5:
                topFiveDailyEarning();
                break;
            case 6:
                seePatients();
                break;
            default:
            break;
        }
    }while(option!=999);
    getch();
return 0;
}
