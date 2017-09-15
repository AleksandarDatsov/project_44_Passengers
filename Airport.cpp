#include "Airport.h"
#include <iostream>
#include <string>

using namespace std;

Airport::Airport()
{
    m_name = "";
}
Airport::Airport(string name)
{
    Setname(name);
}

void Airport::Add()
{
    Ticket f;
    f.Read();
    //f.Print();
    m_flights.push_back(f);
}
void Airport::Add(Ticket f)
{
    m_flights.push_back(f);
}
int Airport::IsThereSuckPassenger()
{
    long long tn;
    cout<<"Enter the Ticket Number of the Searched Passenger: ";
    cin>>tn;
    int index = -1;
    Ticket * f = m_flights.data();
    for (vector<Ticket>::iterator it = m_flights.begin(); it != m_flights.end(); ++it)
    {
        if( f[++index].GetTicketNumber() == tn) return index;
    }

    return -1;
}
void Airport::DeleteFlight()
{
    int index = IsThereSuckPassenger();
    if(index > -1)
    {
        m_flights.erase(m_flights.begin() + index);
    }
}

void Airport::Print()
{
    Ticket* f = m_flights.data();
    int i = 0;
    for (vector<Ticket>::iterator it = m_flights.begin(); it != m_flights.end(); ++it)
    {
        // cout<<i<<"<--- index name    vectorLen: "<<m_flights.size()<<"       passenger--->"<<f[i].GetPassengerName()<<endl;
        f[i].Print();
        i++;
        cout<<endl;
    }
}
void Airport::PrintByFlight()
{
    cout<<"Print Passenger By Number of his Ticket "<<endl;
    string flight;
    cin>>flight;
    int i = 0;
    Ticket * f = m_flights.data();
    for (vector<Ticket>::iterator it = m_flights.begin(); it != m_flights.end(); ++it)
    {
        if(f[i].GetFlight().compare(flight) == 0)f[i].Print();

        i++;
        cout<<endl;
    }
}
void Airport::PrintPassengerWithTheHeaviestLug()
{
    cout<<m_flights.size()<<endl;
    int i = 0;
    Ticket * f = m_flights.data();
    double luggageWeight = -1;
    int indexOfPassWithHeaviestLug = i;
    for(vector<Ticket>::iterator it = m_flights.begin(); it != m_flights.end(); ++it)
    {
        if(f[i].GetLuggageWeight() > luggageWeight)
        {
            indexOfPassWithHeaviestLug = i;
            cout<<"Weight :"<<luggageWeight;
            luggageWeight = f[i].GetLuggageWeight();
        }
        i++;
    }
    cout<<"The passenger with the Heaviest Bag is: "<<endl;
    f[indexOfPassWithHeaviestLug].Print();

}
/*void Airport::CreateAirport()
{
    cout<<"Name for Airport: ";
    string name;
    cin>>name;

    Airport a(name);
    m_airports.push_back(a);
}*/
void Airport::Menu()
{
    int choice;
    do{
    cout<<"\nCHOOSE OPTION:"<<endl;
    cout<<"1. Add Ticket."<<endl;
    cout<<"2. DELETE Ticket By Ticket Number."<<endl;
    cout<<"3. Print All."<<endl;
    cout<<"4. Print By Flight Number."<<endl;
    cout<<"5. Print The Passenger With The Heaviest Luggage."<<endl;
    cout<<"0. Exit."<<endl;
    cin>>choice;

        switch(choice)
        {
        case 1:
            Add();
            break;
        case 2:
            DeleteFlight();
            break;
        case 3:
            Print();
            break;
        case 4:
            PrintByFlight();
            break;
        case 5:
            PrintPassengerWithTheHeaviestLug();
            break;
        case 0: return;
}
    }while(choice);
}
Airport::~Airport()
{
   // cout << "The Airport is being destroyed" << endl;
}
