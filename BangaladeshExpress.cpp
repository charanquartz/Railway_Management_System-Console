#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>

using namespace std;

struct AddData
{
    char si[10];
    char train_number[10];
    char train_name[20];
    char start[10];
    char destination[10];
    char price[10];
    int seat;
    char time[10];
};

struct BookTicket
{
    char train_number[20];
    char name[20];
    char phone[20];
    char date[20];
    int seat;
};

AddData add[1000];
BookTicket book[1000];

int k = 0, u = 0;

void viewInfo() {}
void bookTicket();
void cancelTicket();
void admin();
void password();
void viewPassenger();
void addTrain();
void deleteTrain();
void writeToFile() {}
void readFromFile() {}

int main()
{
    readFromFile();

    system("COLOR 0f");

    int choice;

    time_t currentTime;
    time(&currentTime);

    char* timeStr;
    timeStr = ctime_s(&currentTime);
    cout << "\n\t\t\t     " << timeStr;
    cout << "\n\t\t\t*********************************\n";
    cout << "\t\t\t*******BANGLADESH RAILWAYS*******\n";
    cout << "\t\t\t*********************************\n";
    cout << "\n\t\t\t<<<<<<<<<<WELCOME USERS>>>>>>>>>>\n";
    cout << "\n\n\t\t\t\t      MENU\n";
    cout << "\t\t\t             ******\n";
    cout << "\n\t\t\t[1] VIEW INFORMATION\n";
    cout << "\n\t\t\t[2] BOOK TICKET\n";
    cout << "\n\t\t\t[3] CANCEL TICKET\n";
    cout << "\n\t\t\t[4] ADMIN\n";
    cout << "\n\n\t\t\t[5] EXIT\n";
    cout << "\n\t\t\t********************************\n";
    cout << "\n\t\t\t********************************\n";
    cout << "\n\t\t\tENTER YOUR CHOICE: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        viewInfo();
        break;
    case 2:
        bookTicket();
        break;
    case 3:
        cancelTicket();
        break;
    case 4:
        password();
        break;
    case 5:
        system("cls");
        cout << "\n\t\t\t *********************************\n";
        cout << "\t\t\t *******BANGLADESH RAILWAYS*******\n";
        cout << "\t\t\t *********************************\n";
        cout << "\n\n\t\t\tTHANK YOU FOR USING THIS SOFTWARE BY\n\n";
        cout << "\t\t\t\t***ZIHADUL ISLAM***\n";
        system("pause");
        return 0;
    default:
        system("cls");
        cout << "\n\t\t\t   *********************************\n";
        cout << "\t\t\t   *******BANGLADESH RAILWAYS*******\n";
        cout << "\t\t\t   *********************************\n";
        cout << "\n\n\t\t\t<<<<<<<<YOU ENTERED WRONG CHOICE>>>>>>>>\n";
        cout << "\t\t\t<<<<<<<<PLEASE ENTER RIGHT THING>>>>>>>>\n";
        system("pause");
        system("cls");
        main();
    }

    return 0;
}

void bookTicket()
{
    int count, j, n, i, found = -1;
    char choice;

    system("cls");
    readFromFile();

    cout << "\n\n\t\t\t***************************************";
    cout << "\n\t\t\t**********BANGLADESH RAILWAYS**********\n";
    cout << "\t\t\t***************************************";
    cout << "\n\n\t\t\thow many ticket do you want to buy: ";
    cin >> n;

    for (j = u; j < u + n; j++)
    {
        cout << "\n\n\t\t\tEnter train number: ";
        cin >> book[j].train_number;

        for (i = 0; i < k; i++)
        {
            if (strcmp(book[j].train_number, add[i].train_number) == 0)
            {
                if (add[i].seat == 0)
                {
                    cout << "\n\n\t\t\tnot available seat";
                    system("pause");
                    system("cls");
                    main();
                }
                else
                {
                    found = 1;
                    cout << "\n\t\t\tenter book " << j + 1 << " no ticket: ";
                    cout << "\n\t\t\tenter date: ";
                    cin >> book[j].date;
                    cout << "\n\t\t\tenter your name: ";
                    cin >> book[j].name;
                    cout << "\n\t\t\tenter your phone number: ";
                    cin >> book[j].phone;
                    cout << "\n\t\t\tseat number : " << add[i].seat;

                    book[j].seat = add[i].seat;

                    writeToFile();

                    add[i].seat--;
                    writeToFile();
                }
            }
        }

        if (found == -1)
        {
            cout << "\n\n\t\t\ttrain not found!!!";
            system("pause");
            system("cls");
            main();
        }
    }

    u = j;
    writeToFile();

    cout << "\n\n\t\t\tenter '1' for main menu & press any key to exit: ";
    cin >> choice;

    if (choice == '1')
    {
        system("cls");
        main();
    }

    if (choice != '1')
    {
        exit(0);
    }
}

void cancelTicket()
{
    readFromFile();

    char phoneNumber[100];
    int location = -1, e;

    cout << "\n\n\t\t\tenter phone number: ";
    cin >> phoneNumber;

    for (e = 0; e < u; e++)
    {
        if (strcmp(phoneNumber, book[e].phone) == 0)
        {
            location = e;
            break;
        }
    }

    if (location == -1)
    {
        cout << "\n\n\t\t\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n";
        system("pause");
        system("cls");
        main();
    }
    else
    {
        for (e = location; e < u; e++)
        {
            strcpy(book[e].date, book[e + 1].date);
            strcpy(book[e].train_number, book[e + 1].train_number);
            strcpy(book[e].name, book[e + 1].name);
            strcpy(book[e].phone, book[e + 1].phone);

            writeToFile();
        }

        u--;
        writeToFile();

        cout << "\n\n\t\t\t<<<<<<<<<<<<<<<ticket cancelled successfully>>>>>>>>>>>>";
        system("pause");
        system("cls");
        main();
    }
}

void admin()
{
    int choice;
    system("cls");

    cout << "\n     **********************************************************";
    cout << "\n     ********************BANGLADESH RAIWAYS********************";
    cout << "\n     **********************************************************";
    cout << "\n\n";
    cout << "           <<<<<<<<<<<<<<<WELCOME_ADMIN>>>>>>>>>>>>>>>\n";
    cout << "\n\n";
    cout << "              ************************************\n";
    cout << "              ||      CHOOSE YOUR OPERATION     ||\n";
    cout << "              ||--------------------------------||\n";
    cout << "              ||      [1] VIEW PASSENGERS       ||\n";
    cout << "              ||      [2] ADD TRAIN             ||\n";
    cout << "              ||      [3] DELETE TRAIN          ||\n";
    cout << "              ||      [4] BACK                  ||\n";
    cout << "              ||                                ||\n";
    cout << "              ************************************\n\n";
    cout << "     **********************************************************\n";
    cout << "\n\t\tENTER YOUR CHOICE: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        viewPassenger();
        break;
    case 2:
        addTrain();
        break;
    case 3:
        deleteTrain();
        break;
    case 4:
        system("cls");
        system("pause");
        main();
        break;
    default:
        system("pause");
        cout << "\n\t\t\tyou entered wrong KEY!!!!";
        system("pause");
        system("cls");
        main();
    }

    system("pause");
}

void password()
{
    int password = 171351906;
    int pass;

    cout << "\n\t\t\tenter password: ";
    cin >> pass;

    if (pass == password)
    {
        cout << "\n\n\t\t\t<<<<<login successfully>>>>>";
        system("pause");
        system("cls");
        admin();
    }
    else
    {
        cout << "\n\n\t\t\t\t   ERROR!!!!!";
        cout << "\n\n\t\t\t<<<<<<<<wrong password>>>>>>>>";
        system("pause");
        system("cls");
        main();
    }
}

void deleteTrain()
{
    readFromFile();

    char trainNumber[100];
    int location = -1, f;

    cout << "\n\n\tenter train number: ";
    cin >> trainNumber;

    for (f = 0; f < k; f++)
    {
        if (strcmp(trainNumber, add[f].train_number) == 0)
        {
            location = f;
            break;
        }
    }

    if (location == -1)
    {
        cout << "\n\n\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n";
        system("pause");
        system("cls");
        admin();
    }
    else
    {
        for (f = location; f < k; f++)
        {
            strcpy(add[f].si, add[f + 1].si);
            strcpy(add[f].train_number, add[f + 1].train_number);
            strcpy(add[f].train_name, add[f + 1].train_name);
            strcpy(add[f].start, add[f + 1].start);
            strcpy(add[f].destination, add[f + 1].destination);
            strcpy(add[f].price, add[f + 1].price);
            strcpy(add[f].time, add[f + 1].time);

            writeToFile();
        }

        k--;
        writeToFile();

        cout << "\n\n\t<<<<<<<<<<<<<train deleted successfully>>>>>>>>>>>>>";
        system("pause");
        system("cls");
        admin();
    }
}

void viewPassenger()
{
    int choice, j;
    system("cls");
    readFromFile();

    cout << "\n\t\t\t       **********************************************************";
    cout << "\n\t\t\t       ********************BANGLADESH RAIWAYS********************";
    cout << "\n\t\t\t       **********************************************************";
    cout << "\n\n\t\t\ttrain number\t\tname\t\tphone number\t\tdate\t\tseat\n";
    cout << "\n\t\t\t**********************************************************************************\n";

    for (j = 0; j < u; j++)
    {
        cout << "\n\t\t\t" << book[j].train_number << "\t\t\t" << book[j].name << "\t\t" << book[j].phone << "\t\t" << book[j].date << "\t" << book[j].seat;
        book[j].seat++;
    }

    cout << "\n\t\t\t**********************************************************************************\n";

    cout << "\n\n\t\t\tenter '1' for main menu & enter '0' for back: ";
    cin >> choice;

    if (choice == 1)
    {
        system("cls");
        main();
    }

    if (choice == 0)
    {
        system("cls");
        admin();
    }
}

void addTrain()
{
    int choice;

    system("cls");
    readFromFile();

    int i, a;

    cout << "\n\t\t     **********************************************************";
    cout << "\n\t\t     ********************BANGLADESH RAIWAYS********************";
    cout << "\n\t\t     **********************************************************";
    cout << "\n\n\t\t\thow many trains do you want to add: ";
    cin >> a;

    for (i = k; i < k + a; i++)
    {
        cout << "\n\t\t\tenter " << i + 1 << " train details: ";
        cout << "\n\t\t\tenter serial number: ";
        cin >> add[i].si;
        cout << "\n\t\t\tenter train number: ";
        cin >> add[i].train_number;
        cout << "\n\t\t\tenter train name: ";
        cin >> add[i].train_name;
        cout << "\n\t\t\tenter start place: ";
        cin >> add[i].start;
        cout << "\n\t\t\tenter destination place: ";
        cin >> add[i].destination;
        cout << "\n\t\t\t enter price: ";
        cin >> add[i].price;
        cout << "\n\t\t\t enter seat: ";
        cin >> add[i].seat;
        cout << "\n\t\t\t enter time: ";
        cin >> add[i].time;
    }

    cout << "\n\n\t\t\tconfirm train: (y=1/n=0):- ";
    cin >> choice;

    if (choice == 1)
    {
        writeToFile();
        k = i;
        writeToFile();
        system("cls");
        cout << "\n\n\t\t\t**********************************************************";
        cout << "\n\t\t\t********************BANGLADESH RAIWAYS********************";
        cout << "\n\t\t\t**********************************************************";
        cout << "\n\n";
        cout << "\n\t\t\t\t   **********************************";
        cout << "\n\t\t\t\t   *<<<<<train add successfully>>>>>*";
        cout << "\n\t\t\t\t   **********************************";
        system("pause");
        system("cls");
        main();
    }

    if (choice == 0)
    {
        system("cls");
        admin();
    }

    if ((choice != 1) && (choice != 0))
    {
        system("cls");
        main();
    }
}

void viewinfo() {
    int ch, i;
    system("cls");
    //aread();
    std::cout << "\n\t\t     **********************************************************";
    std::cout << "\n\t\t     ********************BANGLADESH RAIWAYS********************";
    std::cout << "\n\t\t     **********************************************************";
    std::cout << "\n\n\n    SI\ttrain number\ttrain name\tstart place\tdestination place\tprice\tseat\ttime\n\n";

    for (i = 0; i < k; i++) {
        std::cout << "    " << add[i].si << "\t" << add[i].train_number << "\t\t" << add[i].train_name << "\t\t" << add[i].start
                  << "\t\t" << add[i].destination << "\t\t" << add[i].price << "\t\t" << add[i].seat << "\t" << add[i].time << "\n";
    }

    std::cout << "    ***********************************************************************************************\n";
    std::cout << "\n\t\t\tpress '1' for main menu & press any key for exit:  ";
    std::cin >> ch;

    switch (ch) {
        case 1:
            system("cls");
            main();
            break;
        default:
            exit(0);
    }
}

void bookticket_write() {
    std::ofstream booklist("booklist.txt", std::ios::binary);
    booklist.write(reinterpret_cast<char*>(&book), sizeof(book));
    booklist.close();

    std::ofstream booklistreport("booklistreport.txt", std::ios::binary);
    booklistreport.write(reinterpret_cast<char*>(&u), sizeof(u));
    booklistreport.close();
}

void viewpassengers_read() {
    std::ifstream booklist("booklist.txt", std::ios::binary);
    booklist.read(reinterpret_cast<char*>(&book), sizeof(book));
    booklist.close();

    std::ifstream booklistreport("booklistreport.txt", std::ios::binary);
    booklistreport.read(reinterpret_cast<char*>(&u), sizeof(u));
    booklistreport.close();
}

void awrite() {
    std::ofstream train_details("train_details.txt", std::ios::binary);
    train_details.write(reinterpret_cast<char*>(&add), sizeof(add));
    train_details.close();

    std::ofstream train_report("train_report.txt", std::ios::binary);
    train_report.write(reinterpret_cast<char*>(&k), sizeof(k));
    train_report.close();
}

void aread() {
    std::ifstream train_details("train_details.txt", std::ios::binary);
    train_details.read(reinterpret_cast<char*>(&add), sizeof(add));
    train_details.close();

    std::ifstream train_report("train_report.txt", std::ios::binary);
    train_report.read(reinterpret_cast<char*>(&k), sizeof(k));
    train_report.close();
}
