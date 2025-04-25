#include<iostream>
#include<vector>
using namespace std;

class game{
    private:
        string choice[3] = {"stone","paper","scissor"};
        string user;
    public:
        game(string user){
            this->user = user;
        }
};

int main(){
    string user;
    game *obj = new game(user);
    
}