#ifndef AIRPORT_H
#define AIRPORT_H
#include <string>
#include <vector>
#include "Ticket.h"
using namespace std;


class Airport
{
    public:
        Airport();
        Airport(string);
        virtual ~Airport();
        string Getname() { return m_name; }
        void Setname(string val) { m_name = val; }
        int GetArrLenght() { return m_currentLenght; }
        void SetArrLenght(int val) { m_currentLenght = val; }
        void Add();
        int IsThereSuckPassenger();
        void Add(Ticket);
        void DeleteFlight();
        void Print();
        void PrintByFlight();
        void PrintPassengerWithTheHeaviestLug();
        void Menu();
        void CreateAirport();


        std::vector<Ticket> m_flights;
    protected:

    private:
        std::vector<Airport> m_airports;
        string m_name;
        int m_currentLenght;
};

#endif // AIRPORT_H

