#include <iostream>
#include <stdlib.h>
#include <time.h>

int main(){
    int answer = 0;
    int random1 = 0;
    std::cout << "A random number will be generated. Guess what the number is. You will be told if you are too low or too high or right. Total guesses will be showed at the end" << "\n";
    std::srand(time(0));
    //std::cout << rand() % 100+1 << "\n";
    answer = rand() % 100+1;
    //std::cout << answer << "\n";


    while(random1 != answer){
        std::cout << "Please input your guess for the rng" << "\n"; 
        std::string input_answer;
        std::cin >> input_answer;
        random1 = stoi(input_answer);

        if(random1 < answer){
            std::cout << "Your guess is too small" << "\n";
        }
        else if(random1 > answer){
            std::cout << "Your guess is too large" << "\n";
        }
        else{
            std::cout << "Congratulations you have gussed correctly, here is your prize:https://www.youtube.com/watch?v=BjP2hLxUaKs" << "\n";
        }
        }
}
