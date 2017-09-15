#ifndef TICKET_H
#define TICKET_H
#include <string>

using namespace std;

        static long long m_ticketUniqueNumber = 1000000;
class Ticket
{

    public:

        Ticket();
        Ticket(string, string, double);
        virtual ~Ticket();

        string GetFlight() { return m_flight; }
        bool SetFlight();
        long long GetTicketNumber() { return m_ticketNumber; }
        void SetTicketNumber(){m_ticketNumber = m_ticketUniqueNumber++;}
        string GetPassengerName() { return m_passengerName; }
        bool SetPassengerName(string val);
        int GetSeatNumber() { return m_seatNumber; }
        bool SetSeatNumber();
        string GetDirection() { return m_country+" "+m_city; }
        bool SetDirection(string);
        double GetPrice() { return m_price; }
        bool SetPrice();
        double GetLuggageWeight() { return m_luggageWeight; }
        bool SetLuggageWeight(double val);
        string GetCity(){return m_city;}
        void Read();
        void Print();
    protected:

    private:

        string m_flight;
        long long m_ticketNumber;
        string m_passengerName;
        int m_seatNumber;
        string m_country;
        string m_city;
        double m_price;
        double m_luggageWeight;
};

#endif // TICKET_H

