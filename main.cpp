#include <iostream>
#include <string>
#include "Airport.h"
#include "Ticket.h"
using namespace std;

int main()
{
   /*Ticket t("Miella Krusteva", "sofia",22.30), t1("Aleksandur Datsov", "rome",31.30),t2("Aleksandur Datsov", "sofia",21.30);
    t.Print();
    cout<<endl;
    t1.Print();
    cout<<endl;
    t2.Print();

    Airport a("Sofia Airport");
    a.Add(t);
    a.Add(t1);    a.Add(t2);

    cout<<"\n  PRINT METHOD: "<<endl;
    a.Print();
    //a.PrintByFlight();
    a.PrintPassengerWithTheHeaviestLug();*/

    Airport a("Sofia_Airport");
    a.Menu();
    return 0;
}
