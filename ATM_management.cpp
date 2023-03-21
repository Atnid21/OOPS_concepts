//! Mini Project ATM

#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

class atm
{
private:
  long int account_No;
  string name;
  int PIN;
  double balance;
  string mobile_No;

public:
  // Setter
  void setData(long int account_No_A, string name_A, int PIN_A, double balance_A, string mobile_No_A)
  {
    account_No = account_No_A;
    name = name_A;
    PIN = PIN_A;
    balance = balance_A;
    mobile_No = mobile_No_A;
  }
  // Getters
  long int getAccountNo()
  {
    return account_No;
  }
  string getName()
  {
    return name;
  }
  int getPIN()
  {
    return PIN;
  }
  string getMobileNo()
  {
    return mobile_No;
  }
  int getBalance()
  {
    return balance;
  }

  // Setter to set/update mobile no.

  void setMobileNo(string mob_prev, string mob_new)
  {
    if (mob_prev != mob_new)
    {
      mobile_No = mob_new;
      cout << "\nMobile no. is Updated Successfully";
      getch();
    }
    else
    {
      cout << "\n Same mobile number entered";
    }
  }

  void cashWithDraw(int amount_A)
  {
    if (amount_A > 0 && amount_A < balance)
    {
      balance = balance - amount_A;
      cout << "\nCollect cash";
      cout << "\nCurrent amount available: " << balance;
      getch();
    }
    else
    {
      cout << "\n Input Error or Insufficient Balance";
      getch();
    }
  }
};

int main()
{

  int choice = 0, enterPIN;
  long int enterAccountNo;

  system("cls");

  atm user1; // class and object

  user1.setData(12345, "Boy", 1111, 30000.00, "123456");

  do
  {
    system("cls");
    cout << "Account no : 12345  PIN : 1111"
         << "\n";

    cout << "-----ATM Management-----"
         << "\n";
    cout << "\n Enter Account no. : ";
    cin >> enterAccountNo;

    cout << "\n Enter PIN : ";
    cin >> enterPIN;

    if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
    {
      do
      {
        int amount = 0;
        string oldMobileNo, newMobileNo;

        system("cls");
        cout << "Account no : 12345  PIN : 1111  Mobile no. : 123456  Prev. Balance: 30000 "
             << "\n";
        cout << "-----ATM Management-----"
             << "\n";
        cout << "Options :"
             << "\n";
        cout << "\n 1. Check Balance"
             << "\n";
        cout << "\n 2. Cash WithDraw"
             << "\n";
        cout << "\n 3. Show User Details"
             << "\n";
        cout << "\n 4. Update Mobile no."
             << "\n";
        cout << "\n 5. Exit"
             << "\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
          cout << endl
               << "Your Balance is : " << user1.getBalance();
          getch();
          break;
        case 2:
          cout << endl
               << "Enter amount to be Withdraw : ";
          cin >> amount;
          user1.cashWithDraw(amount);
          getch();
          break;

        case 3:
          cout << endl
               << "---User Details---";
          cout << endl
               << "1. Account no. : " << user1.getAccountNo();
          cout << endl
               << "2. Name : " << user1.getName();
          cout << endl
               << "3. Balance : " << user1.getBalance();
          cout << endl
               << "4. Mobile No. : " << user1.getMobileNo();
          getch();

          break;

        case 4:
          cout << endl
               << "Enter previous Mobile No. : ";
          cin >> oldMobileNo;

          cout << endl
               << "Enter new Mobile No. : ";
          cin >> newMobileNo;

          user1.setMobileNo(oldMobileNo, newMobileNo);
          getch();
          break;

        case 5:
          exit(0);

        default:
          cout << "\nEnter valid input !";
          break;
        }

      } while (1);
    }
    else
    {
      cout << endl
           << "User detail invalid!";
      getch();
      exit(0);
    }
  } while (1);
}
