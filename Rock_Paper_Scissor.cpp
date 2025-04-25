#include <iostream>
#include <vector>
#include <random>
using namespace std;

class game {
private:
    string choice[3] = {"stone", "paper", "scissor"};
    string player;
    int comScore, plyScore;

public:
    game(string player) {
        this->player = player;
        comScore = 0;
        plyScore = 0;
    }

    int randomGenerate();
    void startGame();
};

int game::randomGenerate() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, 2);
    return distr(gen);
}

void game::startGame() {
    char ch;
    do {
        string plyGuess;
        cout << "\nEnter your choice (stone/paper/scissor): ";
        getline(cin, plyGuess);

        int guess = randomGenerate();
        string comGuess = choice[guess];

        cout << "Computer chose: " << comGuess << endl;

        if (comGuess == plyGuess) {
            cout << "It's a draw!" << endl;
        }
        else if (
            (comGuess == "stone" && plyGuess == "paper") ||
            (comGuess == "paper" && plyGuess == "scissor") ||
            (comGuess == "scissor" && plyGuess == "stone")
        ) {
            cout << "Player wins!" << endl;
            plyScore++;
        }
        else {
            cout << "Player loses!" << endl;
            comScore++;
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> ch;
        cin.ignore(); // To consume leftover newline character

    } while (ch == 'Y' || ch == 'y');

    cout << "\nFinal Score:\n";
    cout << "Player Score: " << plyScore << endl;
    cout << "Computer Score: " << comScore << endl;
}

int main() {
    string playerName;
    cout << "Enter your name: ";
    getline(cin, playerName);

    game obj(playerName);
    obj.startGame();

    return 0;
}
