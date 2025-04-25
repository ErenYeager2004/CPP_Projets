#include<iostream>
#include<vector>
#include<random>
using namespace std;

class game{
    private:
        string choice[3] = {"stone","paper","scissor"};
        string player;
        int comScore , plyScore;
    public:
        game(string player){
            this->player = player;
        }

        game(){
            comScore = 0;
            plyScore = 0;
        }

        void startGame(string *player,int guess);
        int randomGenerate();
};

int game ::randomGenerate(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, 2);

    int randomNumber = distr(gen);

    return randomNumber;

}
void game ::startGame(string *player,int guess){
    string comGuess = choice[guess];
    string plyGuess = *player;
    bool ply = true;
    while(true){
        if(comGuess == "stone" && plyGuess == "paper"){
            cout<<"Player win "<<endl;
            plyScore++;
        }
        else if(comGuess == "scissor" && plyGuess == "paper"){
            cout<<"Player Loose"<<endl;
            comScore++;
        }
        else if(comGuess == "scissor" && plyGuess == "stone"){
            cout<<"Player win"<<endl;
            plyScore++;
        }
        else if(comGuess == plyGuess){
            cout<<"Its a draw"<<endl;
        }
        else{
            cout<<"Player loose"<<endl;
            comScore++;
        }

        cout<<"Do you want to play again ?(Y/N):";
        
    }
}
int main(){
    string player;
    int guess;
    game *obj = new game(player);

    guess = obj->randomGenerate();
    
}