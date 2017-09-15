#include "Ticket.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;


struct country
{
    string capital;
    char name[40];
    char flightNumber[8];
    double price;
    bool freeSeats[57][200];
};

struct country cont_list[] =
{
    "Amman","Jordan","AA1000",90,{{0},{0}},
    "Amsterdam","Netherlands","AB1100",79.95,{{1},{0}},
    "Athens","Greece","AC1010",50,{{2},{0}},
    "Bangkok","Thailand","AD2100",250,{{3},{0}},
    "Beijing","China","BA1003",390,{{4},{0}},
    "Berlin","Germany","BB1404",17.99,{{5},{0}},
    "Cairo","Egypt","BC1550",120,{{6},{0}},
    "Canberra","Australia","BD6006",890,{{7},{0}},
    "Copenhagen","Denmark","CA8808",209,{{8},{0}},
    "Dhaka","Bangladesh","CB9990",890,{{9},{0}},
    "Doha","Qatar","CC1099",800,{{10},{0}},
    "Dublin","Ireland","CD1999",300,{{11},{0}},
    "Helsinki","Finland","EA9065",550,{{12},{0}},
    "Jakarta","Indonesia","EB1230",890,{{13},{0}},
    "Kabul","Afghanistan","EC7674",390,{{14},{0}},
    "Kingston","Jamaica","EF4333",888,{{15},{0}},
    "Kuala lumpur","Malaysia","AF5555",600,{{16},{0}},
    "London","United Kingdom","BF6632",150,{{17},{0}},
    "Lisbon","Portugal","CF3342",240,{{18},{0}},
    "Madrid","Spain","DF7781",220,{{19},{0}},
    "Manila","Philippines","DA3333",800,{{20},{0}},
    "Mexico city","Mexico","DB0087",1000,{{21},{0}},
    "Moscow","Russia","DC0066",300,{{22},{0}},
    "Nairobi","Kenya","DD6335",490,{{23},{0}},
    "Nassau","Bahamas","FA3021",1100,{{24},{0}},
    "New delhi","India","FB4813",770,{{25},{0}},
    "Ottawa","Canada","FC6970",1090,{{26},{0}},
    "Oslo","Norway","FD0004",440,{{27},{0}},
    "Paris","France","FE0422",39.95,{{28},{0}},
    "Prague","Czech Republic","FF9472",80,{{29},{0}},
    "Pretoria","Africa","GA9845",400,{{30},{0}},
    "Pristina","Kosovo","GB2209",100,{{31},{0}},
    "Pyonyang","North Korea","GC3233",460,{{32},{0}},
    "Riyadh","Saudi Arabia","GD5552",919.95,{{33},{0}},
    "Rome","Italy","GE3255",59.95,{{34},{0}},
    "Colombo","Sri Lanka","EG0003",770,{{35},{0}},
    "Santiago","Chile","AG0909",999,{{36},{0}},
    "Seoul","South Korea","GF1015",450,{{37},{0}},
    "Singapore","Singapore","JA8080",970,{{38},{0}},
    "Sofia","Bulgaria","JB6060",230,{{39},{0}},
    "Stockholm","Sweden","JC6565",170,{{40},{0}},
    "Suva","Fiji","JD9093",700,{{41},{0}},
    "Taipei","Taiwan","JE9096",600,{{42},{0}},
    "Tashkent","Uzbekistan","JF1219",400,{{43},{0}},
    "Tbilisi","Georgia","JG9993",200,{{44},{0}},
    "Tehran","Iran","GJ8882",309.95,{{45},{0}},
    "Tirana","Albania","IA8883",111,{{46},{0}},
    "Tokyo","Japan","IB8884",1000,{{47},{0}},
    "Tripoli","Libya","IC7774",300,{{48},{0}},
    "tunis","Tunisia","ID7773",450,{{49},{0}},
    "Ulaanbaatar","Mongolia","IE7772",400,{{50},{0}},
    "Vienna","Austria","IF7771",89.95,{{51},{0}},
    "Vientiane","Laos","FI6662",300,{{52},{0}},
    "Warsaw","Poland","KA6661",130,{{53},{0}},
    "Washington d.c","united states of america","KB6666",990,{{54},{0}},
    "Wellington","New Zealand","KC0000",390,{{55},{0}},
    "Zagreb","Croatia","KD2200",140,{{56},{0}}
};


Ticket::Ticket()
{
    m_flight="";
    m_ticketNumber= 0;
    m_passengerName= "";
    m_seatNumber=0;
    m_country="";
    m_city="";
    m_price=0;
    m_luggageWeight = 0;
}

template <typename T>
std::string NumberToString ( T Number )
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}

Ticket::Ticket(string passengerName, string city, double luggageWeight)
{
    SetDirection(city);
    SetPassengerName(passengerName);
    SetLuggageWeight(luggageWeight);
    SetSeatNumber();
    SetTicketNumber();
    SetFlight();
    SetPrice();
}

bool caseInsensitiveStringCompare(const string& str1, const string& str2)
{
    if (str1.size() != str2.size())
    {
        return false;
    }
    for (string::const_iterator c1 = str1.begin(), c2 = str2.begin(); c1 != str1.end(); ++c1, ++c2)
    {
        if (tolower(*c1) != tolower(*c2))
        {
            return false;
        }
    }
    return true;
}
int FindPriceForDestination(string city)
{
    for(int i = 0; i < 57; i++)
    {
        if(cont_list[i].capital == city) return i;
    }
    return -1;
}
bool Ticket::SetFlight()
{
    for(int i = 0; i < 57; i++)
    {
        if(caseInsensitiveStringCompare(GetCity(), cont_list[i].capital))
        {
            m_flight = cont_list[i].flightNumber;
            return true;
        }
    }
    return false;
}
bool Ticket::SetPassengerName(string passengerName)
{
    int countWords = 1;
    int nameLen = passengerName.length();
    for(int i =0 ; i < nameLen; i++)
    {
        if(passengerName[i] == ' ')
        {
            countWords++;
        }
        else if(!isalnum(passengerName[i]))return false;
    }
    if(countWords > 1)
    {
        m_passengerName = passengerName;
        return true;
    }
    return false;
}

bool Ticket::SetSeatNumber()
{
    int index = FindPriceForDestination(m_city);
    if(index > -1)
    {
        for(int i = 0; i < 200; i++)
        {
            if(!cont_list[index].freeSeats[index][i] == 1)
            {
                cont_list[index].freeSeats[index][i] = 1;
                m_seatNumber = ++i;
                return true;
            }
        }
    }
    return false;
}

bool Ticket::SetDirection(string city)
{
    int sizeOfList = sizeof cont_list/ sizeof cont_list[0];
    for(int i = 0; i < sizeOfList; i++)
    {
        if(caseInsensitiveStringCompare(city, cont_list[i].capital))
        {
            m_country = cont_list[i].name;
            m_city = city;
            return true;
        }
    }
    return false;

}

bool Ticket::SetPrice()
{
    int indexOfSearchedDestination = FindPriceForDestination(m_city);
    if(indexOfSearchedDestination > -1)
    {
        m_price = cont_list[indexOfSearchedDestination].price;
        if(m_luggageWeight > 20) m_price += (m_luggageWeight - 20) * 10.0;
        return true;
    }
    return false;
}
bool Ticket::SetLuggageWeight(double luggageWeight)
{
    if(luggageWeight >= 0 && luggageWeight <= 40)
    {
        m_luggageWeight = luggageWeight;
        return true;
    }
    return false;
}
void Ticket::Read()
{
    string str;
    double d;
    do
    {
        cout<<"Enter at least two Names For the Passenger: ";
        cin.ignore();
        getline(cin, str);
        cout<<endl;
    }
    while(!SetPassengerName(str));
    do
    {
        cout<<"Enter a destination (city). It must be capital city. : ";
        getline(cin, str);
    }
    while(!SetDirection(str));
    do
    {
        cout<<"\nEnter a weight for luggage.You must pay *10 for each kg over 20kg : ";
        cin>>d;
        cout<<endl;
    }
    while(!SetLuggageWeight(d));
    SetSeatNumber();
    SetTicketNumber();
    SetFlight();
    SetPrice();
}

void Ticket::Print()
{
    cout<<"Flight Number: "<<GetFlight()<<endl;
    cout<<"Ticket Number: "<<GetTicketNumber()<<endl;
    cout<<"Passenger Name: "<<GetPassengerName()<<endl;
    cout<<"Seat : "<<GetSeatNumber()<<endl;
    cout<<"Destination: "<<GetDirection()<<endl;
    cout<<"Price : "<<GetPrice()<<endl;
    cout<<"Luggage Weight: "<<GetLuggageWeight()<<endl;
}
Ticket::~Ticket()
{
    cout << "The Flight is being canceled" << endl;


}
