#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
class user
{
private:
    long int id;
    char username[20];
    long double balance;
    long double withdraw;

public:
    void setname(char name[]);
    void setid(int i);
    void setbalance(float b);
    void checkbalance(void);
    void withdrawamount();
    void generateReceipt();
};
void user::setname(char name[])
{
    strcpy(username, name);
}
void user::setid(int i)
{
    id = i;
}
void user::setbalance(float b)
{
    balance = b;
}
void user::checkbalance()
{
    if (balance == NULL)
    {
        printf("\nNo account Found");
        return;
    }
    cout << "\n Balance :: " << balance;
}
void user::withdrawamount(void)
{

    if (balance == NULL)
    {
        printf("\nNo account Found");
        return;
    }
    float wd;
    cout << "\nEnter withdraw amount :";
    cin >> wd;
    balance = balance - wd;
    withdraw = wd;
}
void user::generateReceipt(void)
{
    if (balance == NULL || id == NULL)
    {
        printf("\nNo account Found");
        return;
    }

    system("cls");
    cout << "\n\n\t------------------------------------------";
    cout << "\n\n\t\t\tR E C E I P T ";
    cout << "\n\n\t------------------------------------------";
    cout << "\n\n\tID : " << id << " \t\t Name :: " << username;
    cout << "\n\n\t$Amount Withdrawed ::  " << withdraw;
    cout << " \n\n\t$Balance before withdraw :: " << balance + withdraw;
    cout << "\n\n\t____________________________________________";
    cout << "\n\n\t$Current Balance is :: " << balance;
}
int menu(void)
{
    int choice;
    cout << "\n\n\t------------------------------------------";
    cout << "\n\n\t\t\tATM machince software ";
    cout << "\n\n\t------------------------------------------";
    cout << "\n\t 1-) Create Account \n\t 2-) Check Balance \n\t 3-) Withdraw Amount\n\t 4-) Generate Receipt \n\t 5-) Exit ";
    cout << "\n\nEnter choice :: ";
    cin >> choice;
    return (choice);
}
int main()
{
    while (1)
    {
        system("cls");
        int choice;
        char name[20];
        int id, i;
        float balance;
        choice = menu();
        switch (choice)
        {
        case 1:
            cout << "\nEnter ID :";
            cin >> id;
            i = id;
            cout << "\nEnter Username :";
            scanf("%s", &name);
            cout << "\nEnter balance :";
            cin >> balance;
            user id;
            id.setid(i);
            id.setname(name);
            id.setbalance(balance);
            cout << "\nCongratulations !!! Account Created ";
            break;
        case 2:
            id.checkbalance();
            break;
        case 3:
            id.withdrawamount();
            break;
        case 4:
            id.generateReceipt();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "\n\nInvalid input !!";
            break;
        }
        cout << "\n\n";
        system("pause");
    }
}