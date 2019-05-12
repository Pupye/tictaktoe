#include <iostream>
#include <vector>

void printTable(std::vector<int> gameTable);
int moveUpdater(int pos, std::vector<int> &gameTable, int turn);
bool isFinished(std::vector<int> &gameTable);

int main(){
    //gametable array of 0's 2's and 5's
    std::vector<int> gameTable; 
    //initializaton
    for(int i = 0; i < 9; i++){
        gameTable.push_back(0);
    }
    //determines whose turn
    int movePasser{0};
    int pos{-1};

    while(!isFinished(gameTable)){
        if(movePasser % 2 == 0){
            std::cout << "'x' make a move please \n"; 
        }else{
            std::cout << "'o' make a move please \n";
        }
        std::cin >> pos; 
        if(moveUpdater(pos, gameTable, movePasser % 2 ) == 0){
            std::cout << "you cannot move there \n";
            continue;
        }
        printTable(gameTable);

        movePasser++;
    }

    if((movePasser - 1) % 2 == 0){
        std::cout <<"x wins \n";
    }else{
        std::cout <<"o wins \n";
    }
    
    return 0; 
}

void printTable(std::vector<int> gameTable){
    int count{0}; 
    for(auto i = gameTable.begin(); i != gameTable.end(); i++){
        count++;
        if(*i == 5){
            std::cout<<"| o |";
        }else if (*i == 2){
            std::cout<<"| x |";
        }else{
            std::cout<<"|   |";
        }
        if(count == 3) {count = 0; std::cout<<'\n';}
    }
}

int moveUpdater(int pos, std::vector<int> &gameTable, int turn){
    if(pos <= 0 || pos > 9 || gameTable[pos - 1] != 0 /*if box is already taken*/) return 0; 
    if(turn == 0){
        gameTable[--pos] = 2;
    }
    else{
        gameTable[--pos] = 5;
    }
    return 1; 
}

bool isFinished(std::vector<int> &gameTable){
    int sum {0};
    for (size_t i = 0; i < 9; i++){
        sum += gameTable[i];
        if((i + 1) % 3 == 0){
            if(sum == 15 || sum == 6){
                return true;
            }
            sum = 0; 
        }
    }

    sum = 0; 
    for (size_t i = 0; i < 3; i++){
        for (size_t j = 0; j < 3; j++){
            sum += gameTable[i + j*3];
            if((j + 1) % 3 == 0){
                if(sum == 15 || sum == 6){
                    return true;
                }
                sum = 0; 
            }      
        }
    }
    int sumdiag1 {gameTable[0] + gameTable[4] + gameTable[8]};
    int sumdiag2 {gameTable[2] + gameTable[4] + gameTable[6]};

    if(sumdiag2 == 15 || sumdiag1 == 15 ||sumdiag2 == 6 || sumdiag1 == 6){
        return true;
    }
    return false; 
}