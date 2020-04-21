#include <iostream>
#include <ctime>

void PrintASCIIArt() {
std::cout << std::endl;
std::cout << "##################################################################################"<<std::endl;
std::cout << "#                          TRIPLE X GAME by Caleb                                #"<<std::endl;
std::cout <<"#                                   /\\                                           #"<< std::endl;
std::cout <<"#                              /\\  //\\\\                                          #"<< std::endl;
std::cout <<"#                       /\\    //\\\\///\\\\\\        /\\                               #"<< std::endl;
std::cout <<"#                      //\\\\  ///\\\\////\\\\\\  /\\  //\\\\                              #"<< std::endl;
std::cout <<"#         /\\          /  ^ \\/^ ^/^  ^  ^ \\/^ \\/  ^ \\                             #"<< std::endl;
std::cout <<"#        / ^\\    /\\  / ^   /  ^/ ^ ^ ^   ^\\ ^/  ^^  \\                            #"<< std::endl;
std::cout <<"#       /^   \\  / ^\\/ ^ ^   ^ / ^  ^    ^  \\/ ^   ^  \\       *                   #"<< std::endl;
std::cout <<"#      /  ^ ^ \\/^  ^\\ ^ ^ ^   ^  ^   ^   ____  ^   ^  \\     /|\\                  #"<< std::endl;
std::cout <<"#     / ^ ^  ^ \\ ^  _\\___________________|  |_____^ ^  \\   /||o\\                 #"<< std::endl;
std::cout <<"#    / ^^  ^ ^ ^\\  /______________________________\\ ^ ^ \\ /|o|||\\                #"<< std::endl;
std::cout <<"#   /  ^  ^^ ^ ^  /________________________________\\  ^  /|||||o|\\               #"<< std::endl;
std::cout <<"#  /^ ^  ^ ^^  ^    ||___|___||||||||||||___|__|||      /||o||||||\\       |      #"<< std::endl;
std::cout <<"# / ^   ^   ^    ^  ||___|___||||||||||||___|__|||          | |           |      #"<< std::endl;
std::cout <<"#/ ^ ^ ^  ^  ^  ^   ||||||||||||||||||||||||||||||oooooooooo| |ooooooo  |        #"<< std::endl;
std::cout <<"#ooooooooooooooooooooooooooooooooooooooooooooooooooooooooo                       #"<< std::endl;
}

void PrintIntroduction(int Difficulty) 
{
//Print welcome message to terminal
    std::cout << "\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room.. \nEnter the correct codes to continue...\n\n";
}
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    //Declaring the values of the lock that the person must guess
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const  int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodePrduct to the terminal
    std::cout << std::endl;
    std::cout << "There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply together to give: " << CodeProduct << std::endl;

    // Elicit and store the player guess
    int GuessA, GuessB, GuessC;
    std::cout << "What is your guess?\n";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) 
    {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***\n";
        return true;
    }
    else 
    {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }
}

//This is the inner workings of the game
int main () 
{   
    srand(time(NULL)); // create new random sequence based on time of day
    PrintASCIIArt();
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) //Loops game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete) {
            ++LevelDifficulty;
        }
    }
    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
    return 0;
}