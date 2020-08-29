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
    user()
    {
        id = NULL;
        balance = NULL;
        withdraw = NULL;
    }
    void Transfer(struct LinkedList *account, struct LinkedList *desaccount, double amount);
    void setname(void);
    void setid(void);
    void setbalance(void);
    void checkbalance();
    void WithdrawAmount();
    void generateReceipt();
    void Deposit(double amount);
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
void deleteAccount(struct LinkedList **head, long int id)
{
    struct LinkedList *r, *temp, *prev;
    struct LinkedList *account = SearchAccount(head, id);
    if (*head == NULL)
    {
        cout << "\n\nNo Matching Account Found";
        return;
    }
    if (*head == account)
    {
        r = account;
        *head = (*head)->next;
        free(r);
    }
    else if (account->next = NULL)
    {
        temp = *head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    else
    {
        temp = *head;
        while (temp->next != account)
        {
            temp = temp->next;
        }
        if (temp->next == account)
        {
            temp->next = NULL;
            free(account);
        }
    }
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
    cout << "\nEnter withdraw amount :";
    cin >> withdraw;
    balance = balance - withdraw;
    cout << "\nTake Money !!!";
}
void user::Deposit(double amount)
{
    balance = balance + amount;
}
void user::Transfer(struct LinkedList *account, struct LinkedList *desaccount, double amount)
{
    if (balance < amount)
    {
        cout << "\nInsufficient Balance in account !!!";
        return;
    }
    else
    {
        balance = balance - amount;
        desaccount->obj.balance = desaccount->obj.balance + amount;
        cout << "\n><><><><><><><> Transfer Successfull <><><><><><>><><><> ";
    }
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
    cout << "\n\n\t\t Bank System software ";
    cout << "\n\n\t------------------------------------------";
    cout << "\n\t 1-) Create Account \n\t 2-) Check Balance  \n\t 3-) Withdraw Amount\n\t 4-) Generate Receipt \n\t 5-) Delete account \n\t 6-) Deposit Money \n\t 7-) Transfer Money \n\t 8-) Exit ";
    cout << "\n\n\tEnter choice :: ";
    cin >> choice;
    return (choice);
}
int main()
{
    system("color 02");
    while (1)
    {
        system("cls");
        int choice;
        double amount;
        long int id, tid;
        struct LinkedList *account, *desaccount;
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
            cout << "\nEnter id of account :: ";
            cin >> id;
            deleteAccount(&head, id);
            break;
        case 6:
            cout << "\nEnter id of account :: ";
            cin >> id;
            cout << "\nEnter amount To Be Deposited :: ";
            cin >> amount;
            cout << "\nProcessing.>.>.>.>.> ";
            account = SearchAccount(&head, id);
            account->obj.Deposit(amount);
            break;
        case 7:
            cout << "\nEnter id of your account :: ";
            cin >> id;
            cout << "\nEnter id of destination account  :: ";
            cin >> tid;
            cout << "\nEnter amount to be tranfered :: ";
            cin >> amount;
            account = SearchAccount(&head, id);
            desaccount = SearchAccount(&head, tid);
            account->obj.Transfer(account, desaccount, amount);
            break;

        case 8:
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