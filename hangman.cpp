#include <iostream>
#include <stdlib.h>
#include <time.h>

int main(){
    int counter = 0;
    int number = 0;
    int incorrect_guesses = 0;
    char attempt;
    std::string the_word;
    std::string blank;
    std::srand(time(0));
    number = rand() % 10;

    std::string words[] = {"inting", "aiming", "server", "game", "word", "fortune", "future", "blunder", "connect", "spike"};
    the_word = words[number];
    std::cout << the_word << "\n";

    std::string hidden(the_word.length(), '_');
    std::cout << hidden << "\n";

    for(int i = 0; i < the_word.length(); i++){
        blank += "_";
    }
    
    //std::cout << blank;

    while(incorrect_guesses < 9){
        std::cin >> attempt;

        for(int i = 0; i < the_word.length(); i++){


            if(attempt == the_word[i]){
                blank[i] = attempt; 
            }

            else{
                //incorrect_guesses++;
            }
            
        }

        if(the_word.find('attempt') == -1){
            incorrect_guesses++;
        }

        std::cout << blank;

        if(blank == the_word){
            std::cout << "You have won the game, here is your prize: https://www.youtube.com/watch?v=c3g_NK9_LtA" << "\n";
            return 0;
        }
    }
}
