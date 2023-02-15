#include <iostream>
#include <fstream>
using namespace std;
void logo();
void menupizza();
void menudrinks();
void menuside();

int main()
{

    char fullname[30];
    int PDS = 0, FOTF = 0, Enter = 0, EnterA = 0, totall = 0, howmany = 0;
    int ce, loop;
    float order[3][4] = { {35,40,30,40} , {4,6,3,2.5},{40,20,6,0} };
    int howmanytime[100];
    char HT;
    string name[3][4] =
    {
        {"Chicken Ranch","Chicken Pepperoni With Barbecue Sauce","Classic Veggie Pizza ","Margherita With Cheese Burst"},
        {"Apple Juice ","Strawberry Juice","Pepsi" ,"Water"}
        ,{"BBQ Wings and Fries","Chicken Strips","Fries"} };
    string theorder[100];
    ofstream thebill("the bill.txt");
    ofstream thedayc("cheach.txt");
    ofstream forthechef("for the chef.txt");

    cout << "\t\t\t|--------------------------------------------------------|\n";
    cout << "\t\t\t|         Legends Restaurant Food Ordering System        |\n";
    cout << "\t\t\t|--------------------------------------------------------|\n\n";
    cout << "Please Enter Your Name: ";
    cin >> fullname;
    cout << "\nHello " << fullname << "\n\n";
    cout <<

        "\nWelcome to the Legends Restaurant\n";
    logo();

    while (Enter < 1) {


        cout <<
            "\n ------------------------------------------------------------------------------------------\n"
            " Enter which category you want order from: \n"
            "    |   1- Pizza   |   2- Drinks   |   3- Sides  |   4- Check your order |   5- Exit    | \n";

        cin >> PDS;
        if (PDS == 1) {
            menupizza();
            cin >> FOTF;
            cout << "\nPlease Enter Quantity:" << endl;
            cin >> howmany;
            FOTF = FOTF - 1;
            PDS = PDS - 1;
            totall = (order[PDS][FOTF] * howmany) + totall;
            theorder[EnterA] = name[PDS][FOTF];
            howmanytime[EnterA] = howmany;

            cout << endl << fullname << "," << " your " << howmany << " " << name[PDS][FOTF] << " has been added to your order.\nThe Total :" << "RM " << totall << endl << endl;
            EnterA++;
        }
        if (PDS == 2) {
            menudrinks();
            cin >> FOTF;
            cout << "\nPlease Enter Quantity:"<< endl;
            cin >> howmany;
            FOTF = FOTF - 1;
            PDS = PDS - 1;
            totall = (order[PDS][FOTF] * howmany) + totall;
            theorder[EnterA] = name[PDS][FOTF];
            howmanytime[EnterA] = howmany;
            cout << endl << fullname << "," << " your " << howmany << " " << name[PDS][FOTF] << " has been added to your order.\nThe Total :" << "RM " << totall << endl << endl;
            EnterA++;
        }
        if (PDS == 3) {
            menuside();
            cin >> FOTF;
            cout << "\nPlease Enter Quantity:"<< endl;
            cin >> howmany;
            FOTF = FOTF - 1;
            PDS = PDS - 1;
            totall = (order[PDS][FOTF] * howmany) + totall;
            theorder[EnterA] = name[PDS][FOTF];
            howmanytime[EnterA] = howmany;
            cout << endl << fullname << "," << " your " << howmany << " " << name[PDS][FOTF] << " | has been added to your order.\nThe Total :" << " RM " << totall << endl << endl;
            EnterA++;
        }
        if (PDS == 4) {
            cout << endl;
            cout << "\nDo you want to Dine In or Take Away?\n"
                "Type H if you want to Dine In\n"
                "Type T if you want Take Away\n"<< endl ;
            cin >> HT;
            if (HT == 'H' || HT == 'h') {
                for (int i = 0; i < EnterA; i++) {
                    cout << i + 1 << " : " << theorder[i] << "  " << howmanytime[i] << endl;

                }
                cout << endl 
                    << fullname << ", please show your Vaccination Status at next section and kindly have a seat.\nYour order will be ready in few minutes.;)\n"
                    "The Total : RM " << totall << "\n\n\n\n\n\n\n";
                ;

            }
            else if (HT == 'T' || HT == 't') {

                for (int i = 0; i < EnterA; i++) {
                    cout << i + 1 << " : " << theorder[i] << "  " << howmanytime[i] << endl;

                }
                cout << endl
                    << fullname << ", please wait a few minutes and take your order from the next section.;)\n "
                    "The Total : RM " << totall << "\n\n\n\n\n\n\n";
                ;

            }
            else {
                cout << "\n error 404 \n"
                    "\nPlease type T or H\n ";
            }
        }



        if (PDS == 5) {
            cout << endl;
            for (int i = 0; i < EnterA; i++) {
                thebill << i + 1 << " : " << theorder[i] << "  " << howmanytime[i] << endl;
                cout << i + 1 << " : " << theorder[i] << "  " << howmanytime[i] << endl;
                forthechef << i + 1 << " : " << theorder[i] << "  " << howmanytime[i] << endl;

            }

            thebill <<
                "Your order will be ready in few  minutes \n"
                "The Total : RM " << totall << " \n"
                "Thank you for Visiting Us\n";
            thebill <<

                " \t\t\t\t\t_____________________\n"
                " \t\t\t\t\t|                   |\n"
                " \t\t\t\t\t| ****              |  \n"
                " \t\t\t\t\t| ****              |   \n"
                " \t\t\t\t\t| ****              |    \n"
                " \t\t\t\t\t| ****              |    \n"
                " \t\t\t\t\t| ****              |     \n"
                " \t\t\t\t\t| ****              |     \n"
                " \t\t\t\t\t| ****************  |     \n"
                "'\t\t\t\t\t| ****************  |\n"
                " \t\t\t\t\t|___________________|";

            cout <<
                " Your order will be ready in few  minutes \n"
                " The Totall :  RM " << totall << " \n"
                " Make the payment at Next Section !!! \n"
                " Thank you for Visiting Us\n";
            logo();
            cout << "\n\n\n\n\n";
            Enter++;
        }

    }

}
void logo()
{
    cout <<

        " \t\t\t\t\t_____________________\n"
        " \t\t\t\t\t|                   |\n"
        " \t\t\t\t\t| ****              |  \n"
        " \t\t\t\t\t| ****              |   \n"
        " \t\t\t\t\t| ****              |    \n"
        " \t\t\t\t\t| ****              |    \n"
        " \t\t\t\t\t| ****              |     \n"
        " \t\t\t\t\t| ****              |     \n"
        " \t\t\t\t\t| ****************  |     \n"
        "'\t\t\t\t\t| ****************  |\n"
        " \t\t\t\t\t|___________________|";

}
void menupizza()
{
    cout <<
        "\n\nWhat would like to eat?: \n\n "
        "\t\t\t\t\t_______________________\n"
        "\t\t\t\t\t|        Pizza         |\n"
        "\t\t\t\t\t|______________________|\n"
        "\t\t\t\t\t|1- Chicken Ranch      |\n"
        "\t\t\t\t\t|   (Rm 35)            |\n"
        "\t\t\t\t\t|______________________|\n"
        "\t\t\t\t\t|2- Chicken pepperoni  |\n"
        "\t\t\t\t\t|   with barbecue sauce|\n"
        "\t\t\t\t\t|   (Rm 40)            |\n"
        "\t\t\t\t\t|______________________|\n"
        "\t\t\t\t\t|3- Classic veggie     |\n"
        "\t\t\t\t\t|   Pizza (Rm 30)      |\n"
        "\t\t\t\t\t|----------------------|\n"
        "\t\t\t\t\t|4- Mrgherita with     |\n"
        "\t\t\t\t\t|   Cheese Burst (Rm45)|\n"
        "\t\t\t\t\t|______________________|\n";
}
void menudrinks()
{
    cout <<
        "\n\nWhat would like to drink?: \n\n "
        "\t\t\t\t\t______________________\n"
        "\t\t\t\t\t|       Drinks        |\n"
        "\t\t\t\t\t|_____________________|\n"
        "\t\t\t\t\t|1- Apple Juice       |\n"
        "\t\t\t\t\t|---------------------|\n"
        "\t\t\t\t\t|2- Strawberry Juice  |\n"
        "\t\t\t\t\t|---------------------|\n"
        "\t\t\t\t\t|3- Pepsi             |\n"
        "\t\t\t\t\t|---------------------|\n"
        "\t\t\t\t\t|4- Water             |\n"
        "\t\t\t\t\t|_____________________|\n";
}

void menuside()
{
    cout <<
        "\n\nWhat would like to have?: \n\n "
        "\t\t\t\t\t____________________\n"
        "\t\t\t\t\t|      Sides        |\n"
        "\t\t\t\t\t____________________\n"
        "\t\t\t\t\t|1- BBQ wings and   |\n"
        "\t\t\t\t\t|   fries (Rm 40)   |\n"
        "\t\t\t\t\t____________________\n"
        "\t\t\t\t\t|2- Chicken         |\n"
        "\t\t\t\t\t|   strips (Rm 20)  |\n"
        "\t\t\t\t\t____________________\n"
        "\t\t\t\t\t|3- Fries  (Rm 6)   |\n"
        "\t\t\t\t\t|                   |\n"
        "\t\t\t\t\t|___________________|\n";
}
