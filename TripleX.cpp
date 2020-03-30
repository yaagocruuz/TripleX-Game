#include <iostream>
#include <ctime>

// Max difficulty of the game
int const MaxDifficulty = 5;

void PrintIntroduction(int Difficulty) {
    // Print introductory text to the player
    std::cout << "\n\nYou are a secret agent breaking into a Level " << Difficulty << " secure server room!\n";
    std::cout << "Enter the correct code to continue...\n";
}

bool PlayGame(int Difficulty) 
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + 1;
    const int CodeB = rand() % Difficulty + 1;
    const int CodeC = rand() % Difficulty + 1;

    const int CodeSum     = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << "\n+ There are 3 numbers in the code";
    std::cout << "\n+ The numbers add-up to: " << CodeSum;
    std::cout << "\n+ The numbers multiply to give: " << CodeProduct << std::endl;    

    // Store player's guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum     = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Win condition check
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        if (Difficulty != MaxDifficulty) // prints the message to the next level
        {
            std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
        }
        return true;
    }
    else 
    {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }
}


int main() 
{
    srand(time(NULL)); // Create a new random sequence based on time of day

    int LevelDifficulty = 1;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelCompleted = false;
        bLevelCompleted = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelCompleted) {
            ++LevelDifficulty;
        }
    }

    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
    return 0;
}