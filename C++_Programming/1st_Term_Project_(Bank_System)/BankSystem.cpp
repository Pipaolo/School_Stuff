#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <iomanip>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main();
class User 
{
    private:
        string nameInput, passInput, passInputCheck,  userPass, finalUserPass;
    private:

        void hideInput()
        {
            /*
                This Function is handling the inputs for the windows
                console, i just found this in the internet loool
            */
            HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);             
            DWORD mode = 0;
            GetConsoleMode(hStdin, &mode);
            SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
        } 

        void duplicateCheck(string username)
        {
            string userCheck;
            std::ifstream data;
            data.open("data.dat");
            while(!data.eof())
            {
                data >> userCheck;
                if (username == userCheck)
                {
                    cout << "Username Already Exists!" << endl;
                    system("pause");
                    main();
                }
            }
        }

    public:

        int count = 0;
        string fullName, name;
        bool login = false; //this is to check whether a user is currently logged in or not

    public:
        void registerUser()
        {
            int setupBankAcc = 0;
            start:
            system("cls");
            cout << "--------------------------------------" << endl;
            cout << "            Create Account" << endl;
            cout << "--------------------------------------" << endl;
            if ( cin.peek() == '\n' ) // This Function ignores whitespaces or enters
            cin.ignore();  
            cout << "Enter Full Name: ";
            getline(cin, fullName);
            cout << "Enter Username: ";
            cin >> nameInput;
            cout << "Enter Password: ";
            hideInput();
            cin >> passInput;
            cout << endl;
            cout << "Re Enter Password: ";
            cin >> passInputCheck;
            cout << endl;
            std::fstream data; //initialize file stream
            std::fstream accHolder;
            data.open("data.dat", std::ios::out | std::ios::app);
            duplicateCheck(nameInput);
            // Initialize Password Check
            if (passInput != passInputCheck)
            {
                cout << "Password is not same!\n";
                system("pause");
                goto start;
            } 
            else 
            {   
                accHolder.open(fullName, std::ios::out); // Create bank account for the user

                if (data.is_open())
                {
                    data << fullName << endl << nameInput << " " << passInput << endl;
                    accHolder << setupBankAcc;
                    data.close();
                    accHolder.close();
                    count += 1;
                    cout << "You have been registered!";
                    Sleep(1000);
                }  
            }
        }

        void loginUser()
        {
            system("cls");
            cout << "--------------------------------------" << endl;
            cout << "               Login" << endl;
            cout << "--------------------------------------" << endl;
            cout << "Enter Username: ";
            cin >> nameInput;
            hideInput();
            cout << "Enter Password: ";
            cin >> passInput;
            cout << endl;
            finalUserPass = nameInput + " " + passInput;
            //initialize read stream
            std::fstream data;
            data.open("data.dat");
            if (data.is_open())
            {
                while (!data.eof())
                {
                    getline(data, fullName);
                    getline(data, userPass);
                    if (finalUserPass == userPass)
                    {
                        cout << "Login Success!!\n";
                        data.close();
                        name = fullName;
                        login = true;
                        Sleep(1000);
                        break;
                    }  
                }
                if (data.is_open())
                {
                    cout << "Incorrect Password or Username";
                    data.close();
                    Sleep(1000);
                }
            }
            else
            {
                cout << "No existing data." << endl;
                cout << "Please Register First" << endl;
                system("pause");
                main();
            }
        }

        int counter()
        {
            int tempCount = 0;
            std::fstream userCount;
            userCount.open("counter");
            if (!userCount.is_open()) // Create counter file if not found
            {
                userCount.open ("counter", std::ios::out);
                userCount << count;
                userCount.close();

            } else {

                userCount >> tempCount; //assign current value of counter to tempcount
                userCount.clear();

                if (count != 0) // if the count is not 0 or if someone registers add it to tempcount
                {
                    tempCount += count; // Add the current value of the counter to the temp count
                    userCount.seekp(0, std::ios::beg);
                    userCount << tempCount; //overwrite the counter file with the new val
                    userCount.close();
                    userCount.open("counter");
                    userCount >> tempCount; //assign current value of counter to tempcount
                    userCount.close();
                    count = 0;           
                }
                return tempCount;               
            }
     }
};

class userAccount : public User
{
    private:
        char input;
        long double money = 0.0;
    private:

        void balance()
        {
            system("cls");
            std::fstream bank;
            bank.open(accHolder, std::ios::in);
            bank >> money;
            cout << "Currently you have: P" << money << "\n";
            bank.close();
            system("pause");
            bankMenu();
        }

        void deposit()
        {
            system("cls");
            long double tempMoney = 0;
            cout << "---------------------------------\n";
            cout << "              Deposit\n";
            cout << "---------------------------------\n";
            cout << "Amount of pesos to be deposited: ";
            cin >> money;
            std::fstream bank;
            bank.open(accHolder, std::ios::in);
            bank >> tempMoney;
            long double temp = tempMoney + money;
            bank.close();
            bank.open(accHolder);
            bank << temp;
            bank.close();
            recordTransactions('D', tempMoney, money, temp);
            money = 0;
            Sleep(1000);
            bankMenu();
        }

        void withdraw()
        {
            system("cls");
            long double tempMoney = 0;
            cout << "---------------------------------\n";
            cout << "              Withdraw\n";
            cout << "---------------------------------\n";
            cout << "Amount of pesos to be withdrawn: ";
            cin >> money;
            std::fstream bank;
            bank.open(accHolder, std::ios::in);
            bank >> tempMoney;
            cout << tempMoney << endl;
            long double temp = tempMoney - money;
            cout << temp;
            bank.close();
            bank.open(accHolder, std::ios::out);
            bank << temp;
            bank.close();
            recordTransactions('W', tempMoney, money, temp);
            money = 0;
            Sleep(1000);
            bankMenu();
        }

        void checkTransactions()
        {
            string line;
            system("cls");
            cout << "----------------------------\n";
            cout << "         Transactions\n";
            cout << "----------------------------\n";
            cout << "Here are your past transactions: \n";
            cout << "Type P.Bal Amount T.Bal\n";
            std::ifstream transactionLogRead;
            transactionLogRead.open(accHolder + ".log");
            if (!transactionLogRead.is_open())
            {
                std::cerr << "You have no previous transactions.\n";
                system("pause");
                bankMenu();
            } 
            else
            {
                while(!transactionLogRead.eof())
                {
                    getline(transactionLogRead, line);
                    cout << line << endl;
                }

                system("pause");
                bankMenu();
            }
        }

        void recordTransactions(char transactionType, long double &prevBalance, long double &money, long double &endBalance)
        {

            std::ofstream transactionLog;
            transactionLog.open(accHolder + ".log", std::ios::app);
            transactionLog << transactionType << " " << prevBalance << " " << money << " " << endBalance << endl;
            transactionLog.close();
        }

    public:

        string accHolder; 

    public:
        void bankMenu()
        {
            start:
            system("cls");
            cout << "------------------------------------------\n";
            cout << "                 Bank Menu\n";
            cout << "------------------------------------------\n";
            cout << "<--Welcome " << accHolder << "-->" << endl;
            cout << "1. Deposit\n";
            cout << "2. Withdraw\n";
            cout << "3. Check Balance\n";
            cout << "4. Transactions\n";
            cout << "5. Logout\n";
            cout << "6. Exit\n";
            cout << "What do you want to do? ";
            cin >> input;
            switch (input)
            {
                case '1':
                    deposit();
                    break;
                case '2':
                    withdraw();
                    break;
                case '3':
                    balance();
                    break;
                case '4':
                    checkTransactions();
                    break;
                case '5':
                    cout << "Logging out...\n";
                    Sleep(1000);
                    cout << "Thank you!";
                    Sleep(1000);
                    main();
                    break;
                case '6':
                    exit(NULL);
                    break;
                default:
                    std::cerr << "Invalid Choice! Please try again." << endl;
                    goto start;
                    break;
            }
        }
};

int main()
{
    char input;

    User user;
    userAccount bank;
    start:
    int count = user.counter();
    system("cls");

    cout << "---------------------------------------\n";
    cout << "                 Main Menu\n";
    cout << "---------------------------------------\n";
    cout << "Account holder counter: " << count << endl;
    if (user.login == true)
    {
        bank.accHolder = user.name;
        bank.bankMenu();
        goto start;
    } 
    else
    {
        cout << "1. Login\n2. Register\n3. Exit\n";
        cout << "Please Enter Desired Input: ";
        cin >> input;
        switch (input)
        {
            case '1':
                user.loginUser();
                goto start;
                break;
            case '2':
                user.registerUser();
                goto start;
                break;     
            case '3':
                system("cls");
                cout << "Goodbye!!";
                Sleep(1000);
                exit(NULL);
            default:
                std::cerr << "Invalid Input. Please Try Again.";
                Sleep(1000);
                goto start;
        }
    }
}

void hideInput(){
    /*
        This Function is used in hiding the password
        found in the internet lol.
    */
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);             
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));        
}
