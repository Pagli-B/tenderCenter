#include <iostream>
#include <string>
#include <iomanip>

//consumer side
bool consumerLogin();
int mobileLoadingCarrier();
float mobileLoadingAmount();
int foodOrder();
float foodOrderAmount();
float topUp();
std::string mobileNumber();

//business side
bool businessLogin();
int adminMobileLoad();
void transacHistoryMobileLoad();
void transacHistoryFoodOrder();
int inventoryMobileLoad();
int inventoryFoodOrder();
void transacHistoryOverall();

//global vars
int status{1};
std::string consumerUsername[4] = {"Brian", "Charlize", "Gabriel", "Jeremy"};
std::string consumerPassword[4] = {"Paglinawan", "Amorato", "Abelardo", "Mora"};
std::string businessUsername[1] = {"TenderCenter"};
std::string businessPassword[1] = {"12345"};
std::string transacKind[4] = {"Mobile Load", "Food Order", "Tuition Payment", "School Misc."};
int consumerUserNumber{};
int businessUserNumber{};
bool cancel{};
int transacIndex{};
int mobileTransacIndex{};
int foodTransacIndex{};
int i{};
int netOption{};
int foodOption{};
std::string transacHistory[20][4] = {};
std::string mobileHistory[20][4] = {};
float cost[20] = {};
float mobileCost[20] = {};
float foodCost[20] = {};
std::string foodHistory[20][4] = {};
std::string networkCarrier[5] = {"Smart", "Globe", "Talk 'N Text", "Sun", "TM"};
std::string transacMobileNum[10] = {};
float loadStock[10] = {5000, 5000, 5000, 5000, 5000};
char mobileNumberInput[11] = {};
char confirmInput{};
bool numInput{false};
float loadTotal;
int amount;
int productOption;
std::string foodMenu[10] = {"Hotdog", "Burger", "Bananacue", "Tinola with Rice", "Bistek with Rice"};
float foodP[10] = {15.0, 20.0, 25.0, 35.0, 50.0};
int foodStock[10] = {50, 50, 30, 100, 100};
int foodQuan{};
int quanRecord[20] = {};
float foodTotal{};
float overallTotal{};
std::string foodSpec[10] = {};

int main()
{
    std::cout << "==============================================================================================================================\n"
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
              << "campus!\n";

    bool exit = false;
    while (exit != true)
    {
        int choice;
        do
        {
            std::cout << "[1] User Login\n"
                      << "[2] Business Login\n"
                      << "[0] Exit\n"
                      << "Enter your option: ";
            std::cin >> choice;
        } while (!(choice == 1 || choice == 2 || choice == 0));
        if (choice == 1)
        {
            bool consumerValid = consumerLogin();
            if (consumerValid)
            {
                system("cls");
                std::cout << "Hello! " << consumerUsername[consumerUserNumber] << '\n';

                cancel = false;
                while (!(cancel))
                {
                    int option;
                    do
                    {
                        std::cout << "Options:\n"
                                  << "[1] Mobile Loading\n"
                                  << "[2] Food Order\n"
                                  << "[0] Log Out\n"
                                  << "Enter your option here: ";
                        std::cin >> option;
                    } while (!(option >= 0 || option <= 3));
                    switch (option)
                    {
                    case 1:
                        netOption = mobileLoadingCarrier(); //for indexing and function call [LINE 106]
                        if (netOption == -1)
                        {
                            system("cls");
                            break;
                        }
                        transacHistory[transacIndex][0] = consumerUsername[consumerUserNumber]; //saving which user did the transaction [OVERALL]
                        mobileHistory[mobileTransacIndex][0] = transacHistory[transacIndex][0]; //saving which user did the transaction [MOBILE CATEGORY]
                        transacHistory[transacIndex][1] = networkCarrier[netOption];            //saving the network carrier [OVERALL]
                        mobileHistory[mobileTransacIndex][1] = transacHistory[transacIndex][1]; //saving the network carrier [MOBILE CATEGORY]
                        transacHistory[transacIndex][2] = mobileNumber();                       //saving the mobile number of user [OVERALL]
                        mobileHistory[mobileTransacIndex][2] = transacHistory[transacIndex][2]; //saving the mobile number of user [MOBILE CATEGORY]
                        cost[transacIndex] = mobileLoadingAmount();                             //saving the amount of load for user [OVERALL]
                        mobileCost[mobileTransacIndex] = cost[transacIndex];                    //saving the amount of load for user [MOBILE CATEGORY]
                        system("cls");
                        mobileTransacIndex++;
                        transacIndex++;
                        break;
                    case 2:
                        foodOption = foodOrder(); //for indexing and computation [LINE 120 AND 124]
                        if (foodOption == -1)
                        {
                            system("cls");
                            break;
                        }
                        transacHistory[transacIndex][0] = consumerUsername[consumerUserNumber]; //saving which user did the transaction [OVERALL]
                        foodHistory[foodTransacIndex][0] = transacHistory[transacIndex][0];     //saving which user did the transaction [FOOD CATEGORY]
                        transacHistory[transacIndex][1] = foodMenu[foodOption];                 //saving what specific food order [OVERALL]
                        foodHistory[foodTransacIndex][1] = transacHistory[transacIndex][1];     //saving what specific order [FOOD CATEGORY]
                        foodQuan = foodOrderAmount();                                           //for indexing and computation [LINE 122 AND 124]
                        quanRecord[foodTransacIndex] = foodQuan;                                //saving the quantity of food [OVERALL]
                        cost[transacIndex] = foodQuan * foodP[foodOption];                      //saving total price [OVERALL]
                        foodCost[foodTransacIndex] = cost[transacIndex];                        //saving total price [FOOD CATEGORY]
                        foodTransacIndex++;
                        transacIndex++;
                        break;
                    case 0:
                        system("cls");
                        cancel = true;
                        exit = true;
                        main();
                        break;
                    default:
                        std::cout << "Please enter a valid option...";
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
                system("cls");
                std::cout << "Hello Admin!\n\n\n";
                bool cancel = false;
                while (!(cancel))
                {
                    int option;
                    do
                    {
                        std::cout << "Businesses to Manage:\n"
                                  << "[1] Mobile Loading\n"
                                  << "[2] Food Order\n"
                                  << "[3] Overall Transactions\n"
                                  << "[0] Log Out\n"
                                  << "Enter your option here: ";
                        std::cin >> option;
                    } while (!(option >= 0 || option <= 2));
                    switch (option)
                    {
                    case 1:
                        do
                        {
                            std::cout << "\n\nMaintainance of Loading Station:\n"
                                      << "[1] See Transaction History\n"
                                      << "[2] Load Balance Management\n"
                                      << "[0] Exit Category\n"
                                      << "Enter your option: ";
                            std::cin >> option;
                        } while (!(option >= 0 || option <= 3));
                        switch (option)
                        {
                        case 1:
                            transacHistoryMobileLoad();
                            break;
                        case 2:
                            do
                            {
                                system("cls");
                                netOption = inventoryMobileLoad();
                                if (netOption == 0)
                                {
                                    system("cls");
                                    break;
                                }
                                if (netOption > 0 || netOption < 3)
                                {
                                    system("cls");
                                }
                            } while (!(netOption >= 0 || netOption <= 3));
                            switch (netOption)
                            {
                            case 1:
                                break;
                            }
                        }
                        break;
                    case 2:
                        do
                        {
                            std::cout << "\nInventory of Food Ordering:\n"
                                      << "[1] See Transaction History\n"
                                      << "[2] Menu Management\n"
                                      << "[0] Exit Category\n"
                                      << "Enter your option: ";
                            std::cin >> option;
                        } while (!(option >= 0 || option <= 2));
                        switch (option)
                        {
                        case 1:
                            transacHistoryFoodOrder();
                            break;
                        case 2:
                            do
                            {
                                foodOption = inventoryFoodOrder();
                                if (netOption == 0)
                                {
                                    system("cls");
                                    break;
                                }
                                if (netOption > 0 || netOption < 3)
                                {
                                    system("cls");
                                }
                            } while (!(netOption >= 0 || netOption <= 3));
                            switch (netOption)
                            {
                            case 1:
                                break;
                            }
                        }
                        break;
                    case 3:
                        transacHistoryOverall();
                        break;
                    case 0:
                        system("cls");
                        cancel = true;
                        exit = true;
                        main();
                        break;
                    default:
                        break;
                    }
                }
            }
        }

        else if (choice == 0)
        {
            system("cls");
            std::cout << "Exiting the program...\n"
                      << "Goodbye and have a great day!";
            exit = true;
            break;
            return 0;
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
    std::string username;
    std::string password;
    std::cout << "USERNAME: ";
    std::cin >> username;
    std::cout << "\nPASSWORD: ";
    std::cin >> password;

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
    std::string username;
    std::string password;
    std::cout << "USERNAME: ";
    std::cin >> username;
    std::cout << "\nPASSWORD: ";
    std::cin >> password;

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
        std::cout << "Welcome to Mobile Loading!\n"
                  << "Choose your Network Carrier:\n"
                  << "[1] " << networkCarrier[0] << "\t\t(" << loadStock[0] << " Pesos of balance available)\n"
                  << "[2] " << networkCarrier[1] << "\t\t(" << loadStock[01] << " Pesos of balance available)\n"
                  << "[3] " << networkCarrier[2] << "\t(" << loadStock[2] << " Pesos of balance available)\n"
                  << "[4] " << networkCarrier[3] << "\t\t\t(" << loadStock[3] << " Pesos of balance available)\n"
                  << "[5] " << networkCarrier[4] << "\t\t\t(" << loadStock[4] << " Pesos of balance available)\n"
                  << "Choose your option: ";
        std::cin >> productOption;
    } while (productOption > 5 || productOption < 0);
    switch (productOption)
    {
    case 0:
        return productOption;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        productOption -= 1;
        return productOption;
        break;
    default:
        break;
    }
    productOption -= 1;
    return productOption;
}

float mobileLoadingAmount()
{
    amount = 0;
    do
    {
        std::cout << "How much load?: ";
        std::cin >> amount;
        if (amount > loadStock[productOption])
        {
            std::cout << "We only have " << loadStock[productOption] << "...\n"
                      << "Please enter a value lower than the balance available...\n";
        }
        else if (amount < 0)
        {
            std::cout << "Please enter a positive value...\n";
        }
    } while (amount > loadStock[productOption] || amount < 0);

    std::cout << amount << " Php has been added to "
              << mobileNumberInput[0]
              << mobileNumberInput[1]
              << mobileNumberInput[2]
              << mobileNumberInput[3]
              << mobileNumberInput[4]
              << mobileNumberInput[5]
              << mobileNumberInput[6]
              << mobileNumberInput[7]
              << mobileNumberInput[8]
              << mobileNumberInput[9]
              << mobileNumberInput[10]
              << ".\n"
              << "Wait for a confirmation SMS.\n"
              << "Press Enter to continue...";
    std::cin.get();
    std::cin.get();
    loadStock[productOption] -= amount;
    return amount;
}

int adminMobileLoad()
{
    std::cout << "Maintainance of Loading Station:\n"
              << "[1] See Transaction History\n"
              << "[2] Load Balance Management\n"
              << "Enter your option: ";
    std::cin >> productOption;
    return productOption;
}

std::string mobileNumber()
{
    do
    {
        std::cout << "Enter your mobile number: ";
        std::cin >> mobileNumberInput[0];
        std::cin >> mobileNumberInput[1];
        std::cin >> mobileNumberInput[2];
        std::cin >> mobileNumberInput[3];
        std::cin >> mobileNumberInput[4];
        std::cin >> mobileNumberInput[5];
        std::cin >> mobileNumberInput[6];
        std::cin >> mobileNumberInput[7];
        std::cin >> mobileNumberInput[8];
        std::cin >> mobileNumberInput[9];
        std::cin >> mobileNumberInput[10];

        std::cout << "Your mobile number is: "
                  << mobileNumberInput[0]
                  << mobileNumberInput[1]
                  << mobileNumberInput[2]
                  << mobileNumberInput[3]
                  << mobileNumberInput[4]
                  << mobileNumberInput[5]
                  << mobileNumberInput[6]
                  << mobileNumberInput[7]
                  << mobileNumberInput[8]
                  << mobileNumberInput[9]
                  << mobileNumberInput[10]
                  << '\n';

        do
        {
            std::cout << "Is your input correct? [Y/N]";
            std::cin >> confirmInput;
            switch (confirmInput)
            {
            case 'Y':
            case 'y':
                numInput = true;
                return mobileNumberInput;
                break;
            case 'N':
            case 'n':
                break;
            default:
                std::cout << "Please enter a valid option\n";
                break;
            }
        } while (confirmInput != 'Y' && confirmInput != 'y' && confirmInput != 'n' && confirmInput != 'N');
    } while (numInput == false);

    return mobileNumberInput;
}

void transacHistoryMobileLoad()
{
    system("cls");
    std::cout << "Mobile Loading Transactions:\n";
    std::cout << "======================================================================\n";
    std::cout << "==============================START LIST==============================\n\n\n";
    for (i = 0; i < mobileTransacIndex; i++)
    {
        std::cout << "[" << i << "]\t"
                  << mobileHistory[i][0] << "\t\t"
                  << mobileHistory[i][1] << "\t\t"
                  << mobileHistory[i][2][0]
                  << mobileHistory[i][2][1]
                  << mobileHistory[i][2][2]
                  << mobileHistory[i][2][3]
                  << mobileHistory[i][2][4]
                  << mobileHistory[i][2][5]
                  << mobileHistory[i][2][6]
                  << mobileHistory[i][2][7]
                  << mobileHistory[i][2][8]
                  << mobileHistory[i][2][9]
                  << mobileHistory[i][2][10] << "\t"
                  << mobileCost[i] << " Pesos\t\t\n";
        loadTotal += mobileCost[i];
    }
    std::cout << "\n\nTotal Earnings of the Loading Service: " << loadTotal << " Pesos...";
    std::cout << "\n\n======================================================================\n";
    std::cout << "==============================END LIST================================\n";
    std::cout << "Press Enter to Continue: \n\n";
    std::cin.get();
    std::cin.get();
}

int inventoryMobileLoad()
{
    do
    {
        system("cls");
        std::cout << "Actions:\n"
                  << "[1] Increase balance to loading station\n"
                  << "[2] Decrease balance to loading station\n"
                  << "[3] Edit balance of loading station\n"
                  << "[0] Exit Category\n"
                  << "Enter you option: ";
        std::cin >> productOption;
        if (productOption > 3 || productOption < 0)
        {
            std::cout << "Please Enter a valid option...\n";
        }
        else if (productOption == 0)
        {
            return productOption;
        }
    } while (productOption > 3 || productOption < 0);

    switch (productOption)
    {
    case 1:
        do
        {
            system("cls");
            std::cout << "Which Network Carrier to increase?\n"
                      << "[1] " << networkCarrier[0] << '\n'
                      << "[2] " << networkCarrier[1] << '\n'
                      << "[3] " << networkCarrier[2] << '\n'
                      << "[4] " << networkCarrier[3] << '\n'
                      << "[5] " << networkCarrier[4] << '\n'
                      << "[0] "
                      << "Exit" << '\n'
                      << "Choose your option: ";
            std::cin >> productOption;
        } while (productOption > 5 || productOption < 0);
        switch (productOption)
        {
        case 1:
            std::cout << "How much would you like to add to " << networkCarrier[0] << "?: ";
            std::cin >> amount;
            loadStock[0] += amount;
            std::cout << amount << " has been added to " << networkCarrier[0] << " (now has a total of " << loadStock[0] << " Pesos)\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 2:
            std::cout << "How much would you like to add to " << networkCarrier[1] << "?: ";
            std::cin >> amount;
            loadStock[1] += amount;
            std::cout << amount << " has been added to " << networkCarrier[1] << " (now has a total of " << loadStock[1] << " Pesos)\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 3:
            std::cout << "How much would you like to add to " << networkCarrier[2] << "?: ";
            std::cin >> amount;
            loadStock[2] += amount;
            std::cout << amount << " has been added to " << networkCarrier[2] << " (now has a total of " << loadStock[2] << " Pesos)\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 4:
            std::cout << "How much would you like to add to " << networkCarrier[3] << "?: ";
            std::cin >> amount;
            loadStock[3] += amount;
            std::cout << amount << " has been added to " << networkCarrier[3] << " (now has a total of " << loadStock[3] << " Pesos)\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 5:
            std::cout << "How much would you like to add to " << networkCarrier[4] << "?: ";
            std::cin >> amount;
            loadStock[4] += amount;
            std::cout << amount << " has been added to " << networkCarrier[4] << " (now has a total of " << loadStock[4] << " Pesos)\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        default:
            break;
        }
        break;
    case 2:
        do
        {
            system("cls");
            std::cout << "Which Network Carrier to decrease?\n"
                      << "[1] " << networkCarrier[0] << '\n'
                      << "[2] " << networkCarrier[1] << '\n'
                      << "[3] " << networkCarrier[2] << '\n'
                      << "[4] " << networkCarrier[3] << '\n'
                      << "[5] " << networkCarrier[4] << '\n'
                      << "Choose your option: ";
            std::cin >> productOption;
        } while (productOption > 5 || productOption < 0);
        switch (productOption)
        {
        case 1:
            std::cout << "How much would you like to decrease to " << networkCarrier[0] << "?: ";
            std::cin >> amount;
            loadStock[0] -= amount;
            std::cout << amount << " has been decreased to " << networkCarrier[0] << " (now has a total of " << loadStock[0] << " Pesos)\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 2:
            std::cout << "How much would you like to decrease to " << networkCarrier[1] << "?: ";
            std::cin >> amount;
            loadStock[1] -= amount;
            std::cout << amount << " has been decrease to " << networkCarrier[1] << " (now has a total of " << loadStock[1] << " Pesos)\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 3:
            std::cout << "How much would you like to decrease to " << networkCarrier[2] << "?: ";
            std::cin >> amount;
            loadStock[2] -= amount;
            std::cout << amount << " has been decreased to " << networkCarrier[2] << " (now has a total of " << loadStock[2] << " Pesos)\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 4:
            std::cout << "How much would you like to decrease to " << networkCarrier[3] << "?: ";
            std::cin >> amount;
            loadStock[3] -= amount;
            std::cout << amount << " has been decreased to " << networkCarrier[3] << " (now has a total of " << loadStock[3] << " Pesos)\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 5:
            std::cout << "How much would you like to decrease to " << networkCarrier[4] << "?: ";
            std::cin >> amount;
            loadStock[4] -= amount;
            std::cout << amount << " has been decreased to " << networkCarrier[4] << " (now has a total of " << loadStock[4] << " Pesos)\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        }
        break;
    case 3:
        do
        {
            system("cls");
            std::cout << "Which Network Carrier to edit?\n"
                      << "[1] " << networkCarrier[0] << '\n'
                      << "[2] " << networkCarrier[1] << '\n'
                      << "[3] " << networkCarrier[2] << '\n'
                      << "[4] " << networkCarrier[3] << '\n'
                      << "[5] " << networkCarrier[4] << '\n'
                      << "Choose your option: ";
            std::cin >> productOption;
        } while (productOption > 5 || productOption < 0);
        switch (productOption)
        {
        case 1:
            std::cout << "Edit the load balance of " << networkCarrier[0] << ": ";
            std::cin >> amount;
            loadStock[0] = amount;
            std::cout << amount << " has been changed to " << networkCarrier[0] << " (now has a total of " << loadStock[0] << " Pesos)\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 2:
            std::cout << "Edit the load balance of " << networkCarrier[1] << ": ";
            std::cin >> amount;
            loadStock[1] = amount;
            std::cout << amount << " has been changed to " << networkCarrier[1] << " (now has a total of " << loadStock[1] << " Pesos)\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 3:
            std::cout << "Edit the load balance of " << networkCarrier[2] << ": ";
            std::cin >> amount;
            loadStock[2] = amount;
            std::cout << amount << " has been changed to " << networkCarrier[2] << " (now has a total of " << loadStock[2] << " Pesos)\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 4:
            std::cout << "Edit the load balance of " << networkCarrier[0] << ": ";
            std::cin >> amount;
            loadStock[3] = amount;
            std::cout << amount << " has been changed to " << networkCarrier[3] << " (now has a total of " << loadStock[3] << " Pesos)\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 5:
            std::cout << "Edit the load balance of " << networkCarrier[0] << ": ";
            std::cin >> amount;
            loadStock[4] = amount;
            std::cout << amount << " has been decreased to " << networkCarrier[4] << " (now has a total of " << loadStock[4] << " Pesos)\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        }
        break;
    default:
        system("cls");
        break;
    }
    return 1;
}

int foodOrder()
{
    system("cls");
    std::cout << "Welcome to Food Order!\n";
    do
    {
        std::cout << "Menu for today!\n"
                  << "[1] " << foodMenu[0] << "\t\t" << foodP[0] << " Pesos\t\t" << foodStock[0] << " Orders available\n"
                  << "[2] " << foodMenu[1] << "\t\t" << foodP[1] << " Pesos\t\t" << foodStock[1] << " Orders available\n"
                  << "[3] " << foodMenu[2] << "\t\t" << foodP[2] << " Pesos\t\t" << foodStock[2] << " Orders available\n"
                  << "[4] " << foodMenu[3] << '\t' << foodP[3] << " Pesos\t\t" << foodStock[3] << " Orders available\n"
                  << "[5] " << foodMenu[4] << '\t' << foodP[4] << " Pesos\t\t" << foodStock[4] << " Orders available\n\n"
                  << "[0] "
                  << "Exit Category\n"
                  << "Choose your option: ";
        std::cin >> productOption;
        if (productOption > 5 || productOption < 1)
        {
            system("cls");
            std::cout << "Please Enter a valid option\n";
        }
    } while (productOption > 5 || productOption < 0);
    if (productOption == 0)
    {
        productOption -= 1;
        return productOption;
    }
    productOption -= 1;
    return productOption;
}

float foodOrderAmount()
{
    amount = 0;
    do
    {
        std::cout << "How many?: ";
        std::cin >> amount;
        if (amount > foodStock[productOption])
        {
            std::cout << "We only have " << foodStock[productOption]
                      << " " << foodMenu[productOption] << "/s\n"
                      << "Please enter a value less than that...\n";
        }
    } while (amount > foodStock[productOption]);

    std::cout << amount << " " << foodMenu[productOption] << "/s coming right up!\n"
              << "Here you go!\n"
              << "That would be " << std::setprecision(2) << std::fixed << amount * foodP[productOption] << " Pesos.\n";
    foodStock[productOption] -= amount;
    std::cout << "Press ENTER to continue...\n";
    std::cin.get();
    std::cin.get();
    system("cls");

    return amount;
}

void transacHistoryFoodOrder()
{
    system("cls");
    std::cout << "Food Ordering Transactions:\n";
    std::cout << "\n\n=================================================================================\n";
    std::cout << "===============================START LIST===========================================\n\n\n";
    std::cout
        << "\tUser"
        << "\t\t"
        << "Food"
        << "\t\t"
        << "Quantity"
        << "\t\t"
        << "Total Cost"
        << "\t\t\n";
    for (i = 0; i < foodTransacIndex; i++)
    {
        std::cout << "[" << i << "]\t"
                  << foodHistory[i][0] << "\t\t"
                  << foodHistory[i][1] << "\t\t"
                  << quanRecord[i] << "\t\t"
                  << foodCost[i] << " Pesos\t\t\n";
        foodTotal += foodCost[i];
    }
    std::cout << "\n\nTotal Earnings of Food Orders: " << foodTotal << " Pesos";
    std::cout << "\n\n=================================================================================\n";
    std::cout << "==============================END LIST===============================================\n";
    std::cout << "\n\n";
    std::cout << "Press Enter to Continue: \n\n";
    std::cin.get();
    std::cin.get();
}

int inventoryFoodOrder()
{
    do
    {
        system("cls");
        std::cout << "Actions:\n"
                  << "[1] Edit the menu for today\n"
                  << "[2] Edit the price\n"
                  << "[3] Edit the quantity of food"
                  << "[0] Exit Category\n"
                  << "Enter you option: ";
        std::cin >> productOption;
        if (productOption > 2 || productOption < 0)
        {
            std::cout << "Please Enter a valid option...\n";
        }
        else if (productOption == 0)
        {
            return productOption;
        }
    } while (productOption > 2 || productOption < 0);

    switch (productOption)
    {
    case 1:
        do
        {
            system("cls");
            std::cout << "Which Food Menu to Edit?\n"
                      << "[1] " << foodMenu[0] << "\t\t" << foodP[0] << " Pesos\t\t" << foodStock[0] << " Orders available\n"
                      << "[2] " << foodMenu[1] << "\t\t" << foodP[1] << " Pesos\t\t" << foodStock[1] << " Orders available\n"
                      << "[3] " << foodMenu[2] << "\t\t" << foodP[2] << " Pesos\t\t" << foodStock[2] << " Orders available\n"
                      << "[4] " << foodMenu[3] << '\t' << foodP[3] << " Pesos\t\t" << foodStock[3] << " Orders available\n"
                      << "[5] " << foodMenu[4] << '\t' << foodP[4] << " Pesos\t\t" << foodStock[4] << " Orders available\n\n"
                      << "[0] "
                      << "Exit Category\n"
                      << "Choose your option: ";
            std::cin >> productOption;
        } while (productOption > 5 || productOption < 0);
        switch (productOption)
        {
        case 1:
            std::cout << "Edit the name of dish #1: ";
            std::getline(std::cin >> std::ws, foodMenu[0]);
            std::cout << "Price: ";
            std::cin >> foodP[0];
            std::cout << "Quantity: ";
            std::cin >> foodStock[0];
            std::cout << "New menu #1: " << foodMenu[0] << "\t\t" << foodP[0] << " Pesos\t\t" << foodStock[0] << " Orders available\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 2:
            std::cout << "Edit the name of dish #2: ";
            std::getline(std::cin >> std::ws, foodMenu[1]);
            std::cout << "Price: ";
            std::cin >> foodP[1];
            std::cout << "Quantity: ";
            std::cin >> foodStock[1];
            std::cout << "New menu #2: " << foodMenu[1] << "\t\t" << foodP[1] << " Pesos\t\t" << foodStock[1] << " Orders available\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 3:
            std::cout << "Edit the name of dish #3: ";
            std::getline(std::cin >> std::ws, foodMenu[2]);
            std::cout << "Price: ";
            std::cin >> foodP[2];
            std::cout << "Quantity: ";
            std::cin >> foodStock[2];
            std::cout << "New menu #3: " << foodMenu[2] << "\t\t" << foodP[2] << " Pesos\t\t" << foodStock[2] << " Orders available\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 4:
            std::cout << "Edit the name of dish #4: ";
            std::getline(std::cin >> std::ws, foodMenu[3]);
            std::cout << "Price: ";
            std::cin >> foodP[3];
            std::cout << "Quantity: ";
            std::cin >> foodStock[3];
            std::cout << "New menu #4: " << foodMenu[3] << "\t\t" << foodP[3] << " Pesos\t\t" << foodStock[3] << " Orders available\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 5:
            std::cout << "Edit the name of dish #5: ";
            std::getline(std::cin >> std::ws, foodMenu[4]);
            std::cout << "Price: ";
            std::cin >> foodP[4];
            std::cout << "Quantity: ";
            std::cin >> foodStock[4];
            std::cout << "New menu #4: " << foodMenu[4] << "\t\t" << foodP[4] << " Pesos\t\t" << foodStock[4] << " Orders available\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        default:
            break;
        }
        break;
    case 2:
        do
        {
            system("cls");
            std::cout << "Which Food Menu to edit the price?\n"
                      << "[1] " << foodMenu[0] << "\t\t" << foodP[0] << " Pesos\t\t" << foodStock[0] << " Orders available\n"
                      << "[2] " << foodMenu[1] << "\t\t" << foodP[1] << " Pesos\t\t" << foodStock[1] << " Orders available\n"
                      << "[3] " << foodMenu[2] << "\t\t" << foodP[2] << " Pesos\t\t" << foodStock[2] << " Orders available\n"
                      << "[4] " << foodMenu[3] << '\t' << foodP[3] << " Pesos\t\t" << foodStock[3] << " Orders available\n"
                      << "[5] " << foodMenu[4] << '\t' << foodP[4] << " Pesos\t\t" << foodStock[4] << " Orders available\n\n"
                      << "[0] "
                      << "Exit Category\n"
                      << "Choose your option: ";
            std::cin >> productOption;
        } while (productOption > 5 || productOption < 0);
        switch (productOption)
        {
        case 1:
            std::cout << "How much would you " << foodMenu[0] << " sell for?: ";
            std::cin >> foodP[0];
            std::cout << "New price for " << foodMenu[0] << " is " << foodP[0] << " Pesos each\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 2:
            std::cout << "How much would you " << foodMenu[1] << " sell for?: ";
            std::cin >> foodP[1];
            std::cout << "New price for " << foodMenu[1] << " is " << foodP[1] << " Pesos each\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 3:
            std::cout << "How much would you " << foodMenu[2] << " sell for?: ";
            std::cin >> foodP[2];
            std::cout << "New price for " << foodMenu[2] << " is " << foodP[2] << " Pesos each\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 4:
            std::cout << "How much would you " << foodMenu[3] << " sell for?: ";
            std::cin >> foodP[3];
            std::cout << "New price for " << foodMenu[3] << " is " << foodP[3] << " Pesos each\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 5:
            std::cout << "How much would you " << foodMenu[4] << " sell for?: ";
            std::cin >> foodP[4];
            std::cout << "New price for " << foodMenu[4] << " is " << foodP[4] << " Pesos each\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        }
        break;
    case 3:
        do
        {
            system("cls");
            std::cout << "Which food quantity to edit?\n"
                      << "[1] " << foodMenu[0] << "\t\t" << foodP[0] << " Pesos\t\t" << foodStock[0] << " Orders available\n"
                      << "[2] " << foodMenu[1] << "\t\t" << foodP[1] << " Pesos\t\t" << foodStock[1] << " Orders available\n"
                      << "[3] " << foodMenu[2] << "\t\t" << foodP[2] << " Pesos\t\t" << foodStock[2] << " Orders available\n"
                      << "[4] " << foodMenu[3] << '\t' << foodP[3] << " Pesos\t\t" << foodStock[3] << " Orders available\n"
                      << "[5] " << foodMenu[4] << '\t' << foodP[4] << " Pesos\t\t" << foodStock[4] << " Orders available\n\n"
                      << "[0] "
                      << "Exit Category\n"
                      << "Choose your option: ";
            std::cin >> productOption;
        } while (productOption > 5 || productOption < 0);
        switch (productOption)
        {
        case 1:
            std::cout << "How many " << foodMenu[0] << " is there?: ";
            std::cin >> foodStock[0];
            std::cout << "New quantity for " << foodMenu[0] << " is " << foodStock[0] << " Orders\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 2:
            std::cout << "How many " << foodMenu[1] << " is there?: ";
            std::cin >> foodStock[1];
            std::cout << "New quantity for " << foodMenu[1] << " is " << foodStock[1] << " Orders\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 3:
            std::cout << "How many " << foodMenu[2] << " is there?: ";
            std::cin >> foodStock[2];
            std::cout << "New quantity for " << foodMenu[2] << " is " << foodStock[2] << " Orders\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
            break;
        case 4:
            std::cout << "How many " << foodMenu[3] << " is there?: ";
            std::cin >> foodStock[3];
            std::cout << "New quantity for " << foodMenu[3] << " is " << foodStock[3] << " Orders\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        case 5:
            std::cout << "How many " << foodMenu[4] << " is there?: ";
            std::cin >> foodStock[4];
            std::cout << "New quantity for " << foodMenu[4] << " is " << foodStock[4] << " Orders\n"
                      << "Press Enter to Continue...";
            std::cin.get();
            std::cin.get();
            break;
        }
        break;
    default:
        system("cls");
        break;
    }
    return 1;
}

void transacHistoryOverall()
{
    system("cls");
    std::cout << "All Transactions:\n";
    std::cout << "\n\n=================================================================================\n";
    std::cout << "===============================START LIST===========================================\n\n\n";
    std::cout
        << "\tUser"
        << "\t\t"
        << "Network Carrier"
        << "\t\t"
        << "Number"
        << "\t\t"
        << "Total Cost"
        << "\t\t\n";
    for (i = 0; i < mobileTransacIndex; i++)
    {
        std::cout << "[" << i << "]\t"
                  << mobileHistory[i][0] << "\t\t"
                  << mobileHistory[i][1] << "\t\t"
                  << mobileHistory[i][2][0]
                  << mobileHistory[i][2][1]
                  << mobileHistory[i][2][2]
                  << mobileHistory[i][2][3]
                  << mobileHistory[i][2][4]
                  << mobileHistory[i][2][5]
                  << mobileHistory[i][2][6]
                  << mobileHistory[i][2][7]
                  << mobileHistory[i][2][8]
                  << mobileHistory[i][2][9]
                  << mobileHistory[i][2][10] << "\t"
                  << mobileCost[i] << " Pesos\t\t\n";
        loadTotal += mobileCost[i];
    }

    std::cout << "\n\nTotal Earnings of the Loading Service: " << loadTotal << " Pesos...\n\n\n";

    std::cout << "\n\n\n";
    std::cout
        << "\tUser"
        << "\t\t"
        << "Food"
        << "\t\t"
        << "Quantity"
        << "\t\t"
        << "Total Cost"
        << "\t\t\n";
    for (i = 0; i < foodTransacIndex; i++)
    {
        std::cout << "[" << i << "]\t"
                  << foodHistory[i][0] << "\t\t"
                  << foodHistory[i][1] << "\t\t"
                  << quanRecord[i] << "\t\t"
                  << foodCost[i] << " Pesos\t\t\n";
        foodTotal += foodCost[i];
    }

    std::cout << "\n\nTotal Earnings of Food Orders: " << foodTotal << " Pesos";

    std::cout << "\n\nTotal Earnings of the Shop: " << loadTotal + foodTotal << " Pesos";
    std::cout << "\n\n=================================================================================\n";
    std::cout << "==============================END LIST===============================================\n";
    std::cout << "\n\n";
    std::cout << "Press Enter to Continue: \n\n";
    std::cin.get();
    std::cin.get();
}
