#include "stuff.h"


int main()
{
    system("color B");
    std::string name = RandomString(16) + ".exe";
    std::rename(path().c_str(), name.c_str());
    SetConsoleTitleA(RandomString(16).c_str());
    checkprivileges();
    system("cls");
    system("cls");
    std::cout << _xor_("\n    Initializing...") << "\n";
    system("cls");
    std::cout << _xor_("\n    [+] Press 1 to run 1909 Driver...") << "\n";
    std::cout << _xor_("\n    [+] Press 2 to run 20H2 Driver...") << "\n";
    int key_chosen = _getch();

    if(key_chosen == '1')
    {
        driver();
    }
    
    else if(key_chosen == '2')
    {
        driverr();
    }
    
    injection();
}
