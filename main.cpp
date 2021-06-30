#include "stuff.h"


int main()
{
    system("color B");
    std::string name = RandomString(16) + ".exe";
    std::rename(path().c_str(), name.c_str());
    SetConsoleTitleA(RandomString(16).c_str());
    checkprivileges();
    system("cls");
    Sleep(1000);
    system("cls");
    SetConsoleTitleA(RandomString(16).c_str());
    std::cout << _xor_("\n    Initializing...") << "\n";
    Sleep(1000);
    system("cls");
    SetConsoleTitleA(RandomString(16).c_str());
    std::cout << _xor_("\n    [+] Press 1 to run 1909 Driver...") << "\n";
    std::cout << _xor_("\n    [+] Press 2 to run 20H2 Driver...") << "\n";
    int key_chosen = _getch();

    switch (key_chosen) {

    case '1':
        driver(); // open fortnite driver 
        injection(); // wait for fortnite to start
        break;
    case '2':
        driverr(); // open fortnite driver 
        injection(); // wait for fortnite to start
        break;
    }
}
