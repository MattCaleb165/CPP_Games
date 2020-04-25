#include <iostream>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>

std::string Explorer_Name;
char response;
int UserWantsToPlay = false;


void PrintIntroduction() 
{

//Get the user to initialize their explorer name
std::cout << "\n\nWelcome Explorer to the Oregon Trail Game, remade by Sn1p3r22\n";
std::cout << "Your explorer name is: ";
std::cin >> Explorer_Name;
std::cout << std::flush;
system ("CLS");
}

bool GettingReadyToStart()
{
std::cout << "\n\nGreat to meet you, " << Explorer_Name << ". Are you ready to start the game?\n";
std::cout << "Y or N: ";
std::cin >> response;
    
    if (response == 'Y')
    {
        std::cout << std::flush;
        system ("CLS");
        std::cout << "\n\nLet's get on our way then!";
        return UserWantsToPlay = true;
    }
    else if (response == 'N')
    {
        std::cout << std::flush;
        system ("CLS");
        std::cout << "\n\nAre you sure? Y or N: ";
        
        std::cin >> response;

            if (response == 'Y') 
            {
                std::cout << std::flush;
                system ("CLS");
                std::cout << "\n\nOkay then! Goodbye!";
                return UserWantsToPlay;
            }
            
            else if (response == 'N') 
            {
                std::cout << std::flush;
                system ("CLS");
                std::cout << "\n\nOkay you indecisive fool, let's get started!\n";
                return UserWantsToPlay = true;
            }
    }   
}

using std::cout;
using std::flush;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

void slow_print(const string&, unsigned int);

void slow_print(const string& message, unsigned int millis_per_char) 
{
    for (const char c: message) 
    {
        cout << c << flush;
        sleep_for(milliseconds(millis_per_char));
    }
}


//This function is here to allow the user to escape the slow print
bool stop = false;
void loop() 
{
    while (!stop) 
    {
    string message = "\n\nWelcome, " + Explorer_Name + " to the Oregon Trail. You are a settler headed west. The Oregon Trail was a roughly 2,000-mile route from Independence, Missouri, to Oregon City, Oregon, which was used by hundreds\n of thousands of American pioneers in the mid-1800s to emigrate west. The trail was arduous and snaked through Missouri and present-day Kansas, Nebraska, Wyoming, Idaho and finally into Oregon. Without\n the Oregon Trail and the passing of the Oregon Donation Land Act in 1850, which encouraged settlement in the Oregon Territory, American pioneers would have been slower to settle the American West\n in the 19th century.\n";
    slow_print(message, 50);  
    }
}

//This will be the main game.
bool PlayGame(int Health) 
{
    char Escape;
    std::thread t(loop);
    t.detach();
    
    std::cin >> response;

    system ("PAUSE");
    std::cin >> Escape;

    return false;
}

int main() 
{
    PrintIntroduction();
    GettingReadyToStart();

    if (UserWantsToPlay) 
    {

        int CurrentHealth = 100;
        int const MinHealth = 0;
    
    while (CurrentHealth > MinHealth)
    {
        bool OnAnAdventure = PlayGame(CurrentHealth);
    }
    
    exit(0);
    return 0;

    }
}