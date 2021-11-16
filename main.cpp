#include <iostream>
#include <string>

using namespace std;

//consumer side
bool consumerLogin();
int mobileLoadingCarrier();
float mobileLoadingAmount();
int foodOrder();
float foodOrderAmount();
float topUp();
string mobileNumber(int);

//business side
bool businessLogin();
int adminMobileLoad();
void transacHistoryMobileLoad();

//global vars
int status{1};
string consumerUsername[4] = {"Brian", "Charlize", "Gabriel", "Jeremy"};
string consumerPassword[4] = {"Paglinawan", "Amorato", "Abelardo", "Mora"};
string businessUsername[1] = {"TenderCenter"};
string businessPassword[1] = {"12345"};
string transacKind[4] = {"Mobile Load", "Food Order", "Tuition Payment", "School Misc."};
int consumerUserNumber{};
int businessUserNumber{};
int transacIndex{};
int mobileTransacIndex{};
int foodTransacIndex{};
int netOption{};
int foodOption{};
string transacHistory[20][4] = {};
string mobileHistory[20][4] = {};
string foodHistory[20][4] = {};
string networkCarrier[5] = {"Smart", "Globe", "Talk 'N Text", "Sun", "TM"};
string transacMobileNum[10] = {};
char mobileNumberInput[11] = {};
int amount;
int productOption;
string foodMenu[10] = {"Hotdog", "Burger", "Bananacue", "Tinola with Rice", "Bistek with Rice"};
float foodP[10] = {15.0, 20.0, 25.0, 35.0, 50.0};
int foodStock[10] = {50, 50, 30, 100, 75};
int foodQuan{};
string foodSpec[10] = {};

int main()
{
    cout << "==============================================================================================================================\n"
         << "==============================================================================================================================\n"
         << "   /$$                               /$$                                                           /$$                        \n"
         << "  | $$                              | $$                                                          | $$                        \n"
         << " /$$$$$$    /$$$$$$  /$$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$         /$$$$$$$  /$$$$$$  /$$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$ \n"
         << "|_  $$_/   /$$__  $$| $$__  $$ /$$__  $$ /$$__  $$ /$$__  $$       /$$_____/ /$$__  $$| $$__  $$|_  $$_/   /$$__  $$ /$$__  $$\n"
         << "  | $$    | $$$$$$$$| $$  \\ $$| $$  | $$| $$$$$$$$| $$  \\__/      | $$      | $$$$$$$$| $$  \\ $$  | $$    | $$$$$$$$| $$  \\__/\n"
         << "  | $$ /$$| $$_____/| $$  | $$| $$  | $$| $$_____/| $$            | $$      | $$_____/| $$  | $$  | $$ /$$| $$_____/| $$      \n"
         << "  |  $$$$/|  $$$$$$$| $$  | $$|  $$$$$$$|  $$$$$$$| $$            |  $$$$$$$|  $$$$$$$| $$  | $$  |  $$$$/|  $$$$$$$| $$      \n"
         << "   \\___/   \\_______/|__/  |__/ \\_______/ \\_______/|__/             \\_______/ \\_______/|__/  |__/   \\___/   \\_______/|__/      \n"
         << "==============================================================================================================================\n"
         << "==============================================================================================================================\n"
         << "Welcome to Tender Center!\n"
         << "We offer services such as mobile loading, ordering food, tuition "
         << "payment/loans and other services that you can see around the "
         << "campus!\n"
         << "Press ENTER to Continue...";
    cin.get();

    bool exit = false;
    while (exit != true)
    {
        int choice;
        do
        {
            cout << "[1] User Login\n"
                 << "[2] Business Login\n"
                 << "[0] Exit\n"
                 << "Enter your option: ";
            cin >> choice;
        } while (!(choice == 1 || choice == 2 || choice == 0));
        if (choice == 1)
        {
            bool consumerValid = consumerLogin();
            if (consumerValid)
            {
                cout << "Hello! " << consumerUsername[consumerUserNumber] << '\n';

                bool cancel = false;
                while (!(cancel))
                {
                    int option;
                    do
                    {
                        cout << "Options:\n"
                             << "[1]\tMobile Loading\n"
                             << "[2]\tFood\n"
                             << "[0]\tLog Out\n"
                             << "Enter your option here: ";
                        cin >> option;
                    } while (!(option >= 0 || option <= 3));
                    switch (option)
                    {
                    case 1:

                        transacHistory[transacIndex][0] = consumerUsername[consumerUserNumber]; //saving which user did the transaction [OVERALL]
                        mobileHistory[mobileTransacIndex][0] = transacHistory[transacIndex][0]; //saving which user did the transaction [MOBILE CATEGORY]
                        netOption = mobileLoadingCarrier();                                     //for indexing and function call [LINE 106]
                        transacHistory[transacIndex][1] = networkCarrier[netOption];            //saving the network carrier [OVERALL]
                        mobileHistory[mobileTransacIndex][1] = transacHistory[transacIndex][1]; //saving the network carrier [MOBILE CATEGORY]
                        transacHistory[transacIndex][2] = mobileNumber(netOption);              //saving the mobile number of user [OVERALL]
                        mobileHistory[mobileTransacIndex][2] = transacHistory[transacIndex][2]; //saving the mobile number of user [MOBILE CATEGORY]
                        transacHistory[transacIndex][3] = mobileLoadingAmount();                //saving the amount of load for user [OVERALL]
                        mobileHistory[mobileTransacIndex][3] = transacHistory[transacIndex][3]; //saving the amount of load for user [MOBILE CATEGORY]
                        mobileTransacIndex++;
                        transacIndex++;
                        break;
                    case 2:
                        transacHistory[transacIndex][0] = consumerUsername[consumerUserNumber]; //saving which user did the transaction [OVERALL]
                        foodHistory[foodTransacIndex][0] = transacHistory[transacIndex][0];     //saving which user did the transaction [FOOD CATEGORY]
                        foodOption = foodOrder();                                               //for indexing and computation [LINE 120 AND 124]
                        transacHistory[transacIndex][1] = foodMenu[foodOption];                 //saving what specific food order [OVERALL]
                        foodHistory[foodTransacIndex][1] = transacHistory[transacIndex][1];     //saving what specific order [FOOD CATEGORY]
                        foodQuan = foodOrderAmount();                                           //for indexing and computation [LINE 122 AND 124]
                        transacHistory[transacIndex][2] = foodQuan;                             //saving the quantity of food [OVERALL]
                        foodHistory[foodTransacIndex][2] = transacHistory[transacIndex][2];     //saving the quantity of food [FOOD CATEGORY]
                        transacHistory[transacIndex][3] = foodQuan * foodP[foodOption];         //saving total price [OVERALL]
                        foodHistory[foodTransacIndex][3] = transacHistory[transacIndex][3];     //saving total price [FOOD CATEGORY]
                        foodTransacIndex++;
                        transacIndex++;
                        break;
                    case 0:
                        main();
                    default:
                        cout << "Please enter a valid option...";
                        break;
                    }
                }
            }
        }
        else if (choice == 2)
        {
            bool businessValid = businessLogin();
            if (businessValid)
            {
                cout << "Hello Admin!\n";
                bool cancel = false;
                while (!(cancel))
                {
                    int option;
                    do
                    {
                        cout << "Businesses to Manage:\n"
                             << "[1]\tMobile Loading\n"
                             << "[2]\tFood Order\n"
                             << "[0]\tLog Out\n"
                             << "Enter your option here: ";
                        cin >> option;
                    } while (!(option >= 0 || option <= 2));
                    switch (option)
                    {
                    case 1:
                        switch (adminMobileLoad())
                        {
                        case 1:
                            //transacHistoryMobileLoad();
                            break;
                        case 2:
                            // inventoryMobileLoad();
                            break;

                        default:
                            break;
                        }
                        break;

                    default:
                        break;
                    }
                }
            }
        }
        else if (choice == 0)
        {
            cout << "Exiting the program..."
                 << "Goodbye and have a great day!";
            exit = true;
        }
        else
        {
            exit = false;
        }
    }

    return 0;
}

bool consumerLogin()
{
    system("cls");
    string username;
    string password;
    cout << "USERNAME: ";
    cin >> username;
    cout << "\nPASSWORD: ";
    cin >> password;

    for (int i = 0; i < 20; i++)
    {
        if ((username.compare(consumerUsername[i]) == 0) && (password.compare(consumerPassword[i]) == 0))
        {
            consumerUserNumber = i;
            return true;
        }
    }

    return false;
}

bool businessLogin()
{
    system("cls");
    string username;
    string password;
    cout << "USERNAME: ";
    cin >> username;
    cout << "\nPASSWORD: ";
    cin >> password;

    for (int i = 0; i < 20; i++)
    {
        if ((username.compare(businessUsername[i]) == 0) && (password.compare(businessPassword[i]) == 0))
        {
            businessUserNumber = i;
            return true;
        }
    }

    return false;
}

int mobileLoadingCarrier()
{
    do
    {
        system("cls");
        cout << "Welcome to Mobile Loading!\n"
             << "Choose your Network Carrier:\n"
             << "[1] " << networkCarrier[0] << '\n'
             << "[2] " << networkCarrier[1] << '\n'
             << "[3] " << networkCarrier[2] << '\n'
             << "[4] " << networkCarrier[3] << '\n'
             << "[5] " << networkCarrier[4] << '\n'
             << "[0] Exit Category" << '\n'
             << "Choose your option: ";
        cin >> productOption;
    } while (productOption > 5 || productOption < 0);
    switch (productOption)
    {
    case 0:
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        return productOption - 1;
    default:
        break;
    }
    return productOption - 1;
}

float mobileLoadingAmount()
{

    cout << "How much load?: ";
    cin >> amount;
    cout << amount << " Php has been added to " << mobileNumberInput << ".\n"
         << "Wait for a confirmation SMS.\n"
         << "Press ENTER to continue...\n";
    cin.get();
    cin.get();
    return amount;
}

int adminMobileLoad()
{
    cout << "Maintainance of Loading Station:\n"
         << "[1] See Transaction History\n"
         << "[2] Balance Management\n"
         << "Enter your option: ";
    cin >> productOption;
    return productOption;
}

string mobileNumber()
{
    cout << "Enter your mobile number?: ";
    cin >> mobileNumberInput[0];
    cin >> mobileNumberInput[1];
    cin >> mobileNumberInput[2];
    cin >> mobileNumberInput[3];
    cin >> mobileNumberInput[4];
    cin >> mobileNumberInput[5];
    cin >> mobileNumberInput[6];
    cin >> mobileNumberInput[7];
    cin >> mobileNumberInput[8];
    cin >> mobileNumberInput[9];
    cin >> mobileNumberInput[10];

    cout << "Your mobile number is: ";
    cout << mobileNumberInput[0];
    cout << mobileNumberInput[1];
    cout << mobileNumberInput[2];
    cout << mobileNumberInput[3];
    cout << mobileNumberInput[4];
    cout << mobileNumberInput[5];
    cout << mobileNumberInput[6];
    cout << mobileNumberInput[7];
    cout << mobileNumberInput[8];
    cout << mobileNumberInput[9];
    cout << mobileNumberInput[10];

    mobileCarrierGlobe[] = {
        '0937',
    } mobileCarrieGlobeOrTM[] = { '0817',
                                  '0904',
                                  '0915',
                                  '0916',
                                  '0917',
                                  '0926',
                                  '0927',
                                  '0935',
                                  '0936',
                                  //
    }
    //
    //baka need ng pa ganto, mobileCarrierGlobe[] = {{'0','9','3','7'}} kasi char yung values niya, dapat may single quote
    // mobileCarrierGlobeOrTM[] = {{'0','8'},}
    // egis egis
    //tama ba to??
    // i think dapat mobileNumberInput[0] == '0' && mobileNumberInput[1] == '9' ohh ok ok
    //globe or tm - 0817, 0904, 0905, 0906, 0915-0917, 0926-0927, 0935-0936, 0945, 0953-0956, 0965-0967, 0975-0979,
    // 0994-0997
    //globe - 0937
    //smart  or talk n text - 0813, 0907-0914 , 0918-0921, 0928-0930, 0938-0939, 0946-0951, 0970, 0981, 0989,0992
    //0998-0999
    // sun - 0922 -0925, 0931-0934, 0940-0944, 0973-0974
    // smart or TNT - 0961, 0963
    // smart - 0968
    // DITO - 0991-0994, 0895-0898

    return mobileNumberInput;
}

int foodOrder()
{
    do
    {
        system("cls");
        cout << "Welcome to Food Order!\n"
             << "Menu for today!\n"
             << "[1] " << foodMenu[0] << '\t' << foodP[0] << '\n'
             << "[2] " << foodMenu[1] << '\t' << foodP[1] << '\n'
             << "[3] " << foodMenu[2] << '\t' << foodP[2] << '\n'
             << "[4] " << foodMenu[3] << '\t' << foodP[3] << '\n'
             << "[5] " << foodMenu[4] << '\t' << foodP[4] << '\n'
             << "Choose your option: ";
        cin >> productOption;
    } while (productOption > 5 || productOption < 1);
    return productOption - 1;
}

float foodOrderAmount()
{
    amount = 0;
    do
    {
        cout << "How many?: ";
        cin >> amount;
    } while (amount < 0);

    amount = 0;
    cout << "How many?: ";
    cin >> amount;
    if (amount < foodStock[productOption])
    {
    }
    cout << amount << " " << foodMenu[productOption] << " coming right up!\n"
         << "Here you go!\n"
         << "That would be " << amount * foodP[productOption] << " Pesos.";
    cout << "Press ENTER to continue...";
    cin.get();
    cin.get();
    system("cls");
    return amount;
}
