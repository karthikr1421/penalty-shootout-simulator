#include<iostream>
#include<ctime>
#include<string>

const int TOTAL_ROUNDS = 5;

int main()
{
    system("chcp 65001");
    srand(time(0));

    int round;
    int userChoice;
    std::string kickOutcome; // '❌'- shot saved , '⚽' - goal scored
    int userScore = 0;
    int computerScore = 0;
    std::string user[12];
    std::string computer[12];
    int u = 0, c = 0; // Indexes to mark the kick by each team

    std::cout << "\033[1;36m*********** PENALTY SHOOTOUT SIMULATOR ***********\033[0m\n";

    for (round = 0; round < TOTAL_ROUNDS; round++) {

        std::cout << "\n\033[1;35m Round " << round + 1 << "\033[0m\n";

        // User's turn to kick
        std::cout << "Your Kick ⚽ \n";
        std::cout << "Choose the direction of your kick (1-Bottom right, 2-Bottom left, 3-Top right, 4-Top left): ";
        std::cin >> userChoice;

        while (userChoice < 1 || userChoice > 4) {
            std::cout << "Invalid choice. Please enter a number between 1 and 4: ";
            std::cin >> userChoice;
        }

        std::cout << "You shoot towards " << userChoice << std::endl;

        int computerChoice = rand() % 4 + 1;
        std::cout << "Computer dives towards " << computerChoice << std::endl;

        if (userChoice == computerChoice) {
            kickOutcome = "❌";
            std::cout << "\033[1;31mSAVE! 🧤\033[0m\n";
        } else {
            kickOutcome = "⚽";
            std::cout << "\033[1;32mGOAL! 🎯\033[0m\n";
            userScore++;
        }
        user[u++] = kickOutcome;

        // Computer's turn to kick
        std::cout << "\nComputer's kick ⚽\n";
        computerChoice = rand() % 4 + 1;

        std::cout << "Choose the direction of your dive (1-Bottom right, 2-Bottom left, 3-Top right, 4-Top left): ";
        std::cin >> userChoice;

        while (userChoice < 1 || userChoice > 4) {
            std::cout << "Invalid choice. Please enter a number between 1 and 4: ";
            std::cin >> userChoice;
        }

        std::cout << "Computer shoots towards " << computerChoice << std::endl;
        std::cout << "You dived towards " << userChoice << std::endl;

        if (userChoice == computerChoice) {
            kickOutcome = "❌";
            std::cout << "\033[1;31mSAVE! 🧤\033[0m\n";
        } else {
            kickOutcome = "⚽";
            std::cout << "\033[1;32mGOAL! 🎯\033[0m\n";
            computerScore++;
        }
        computer[c++] = kickOutcome;

        std::cout << "End of Round " << round + 1 << "\n";
        std::cout << "Score: You " << userScore << " : " << computerScore << " Computer\n";
    }

    // Final score display
    std::cout << "\nYour Team    : ";
    for (int i = 0; i < TOTAL_ROUNDS; i++) {
        std::cout << user[i] << "\t";
    }

    std::cout << "\nComputer Team: ";
    for (int i = 0; i < TOTAL_ROUNDS; i++) {
        std::cout << computer[i] << "\t";
    }

    std::cout << '\n';

    if (userScore > computerScore) {
        std::cout << "\033[1;32mYou Won the match!\033[0m\n";
    } else if (userScore < computerScore) {
        std::cout << "\033[1;31mComputer Won the match!\033[0m\n";
    } else {
        std::cout << "\033[1;33mIt's a Draw.\033[0m\n";
    }

    return 0;
}