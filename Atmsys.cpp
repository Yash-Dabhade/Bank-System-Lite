#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class user
{
private:
    long int id;
    char username[20];
    long double balance;
    long double withdraw;

public:
    void setname(void);
    void setid(void);
    void setbalance(void);
    void checkbalance();
    void WithdrawAmount();
    void generateReceipt();
    long int getid();
};
long int user::getid()
{
    return (id);
}
struct LinkedList
{
    user obj;
    struct LinkedList *next;
};
void CreateAccount(struct LinkedList **head)
{
    struct LinkedList *temp, *t;
    temp = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    temp->next = NULL;
    cout << "\nEnter ID :";
    temp->obj.setid();
    cout << "\nEnter Username :";
    temp->obj.setname();
    cout << "\nEnter balance :";
    temp->obj.setbalance();
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        t = *head;
        while (t->next)
            t = t->next;
        t->next = temp;
    }
}
struct LinkedList *SearchAccount(struct LinkedList **head, long int sid)
{
    if (*head == NULL)
    {
        cout << "\nNo account Found or Registered";
        return (NULL);
    }
    long int i;
    struct LinkedList *t;
    t = *head;

    while (t != NULL)
    {
        if (t->obj.getid() == sid)
        {
            return (t);
        }
        t = t->next;
    }
    return (NULL);
}
struct LinkedList *head = NULL;
void user::setname(void)
{
    cin >> username;
}
void user::setid(void)
{
    cin >> id;
}
void user::setbalance(void)
{
    cin >> balance;
}
void user::checkbalance()
{
    cout << "\nUser Name :: " << username;
    cout << "\nBalance :: " << balance;
}
void user::WithdrawAmount()
{

    // struct LinkedList *acc;
    // float wd;
    // acc = SearchAccount(head, id);
    // if (acc == NULL)
    // {
    //     printf("\nInvalid ID or Create New Account!!");
    //     return;
    // }
    cout << "\nEnter withdraw amount :";
    cin >> withdraw;
    balance = balance - withdraw;
    cout << "\nTake Money !!!";
}
void user::generateReceipt(void)
{

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
    cout << "\n\n\t\t\t ATM machince software ";
    cout << "\n\n\t------------------------------------------";
    cout << "\n\t 1-) Create Account \n\t 2-) Check Balance  \n\t 3-) Withdraw Amount\n\t 4-) Generate Receipt \n\t 5-) Exit ";
    cout << "\n\n\tEnter choice :: ";
    cin >> choice;
    return (choice);
}
int main()
{
    while (1)
    {
        system("cls");
        int choice;
        long int id;
        struct LinkedList *account;
        choice = menu();
        switch (choice)
        {
        case 1:
            CreateAccount(&head);
            break;
        case 2:
            cout << "\nEnter id of account :: ";
            cin >> id;
            account = SearchAccount(&head, id);
            if (account == NULL)
            {
                cout << "\nInvalid id";
                break;
            }
            account->obj.checkbalance();
            break;
        case 3:
            cout << "\nEnter id of account :: ";
            cin >> id;
            account = SearchAccount(&head, id);
            if (account == NULL)
            {
                cout << "\nInvalid id";
                break;
            }
            account->obj.WithdrawAmount();
            break;
        case 4:
            cout << "\nEnter id of account :: ";
            cin >> id;
            account = SearchAccount(&head, id);
            if (account == NULL)
            {
                cout << "\nInvalid id";
                break;
            }
            account->obj.generateReceipt();
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