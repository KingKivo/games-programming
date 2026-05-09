#include <iostream>

int main(){
    int counter = 0;
    std::string answer1;
    std::cout << "What is the capital of France?" << "\n";
    std::cout << "1. London" << "\n" << "2. Dhaka \n" << "3. Berlin \n" << "4. Paris \n"; 
    std::cin >> answer1;

    if (stoi(answer1) == 4){
        std::cout << "You got it correct!" << "\n";
        counter++;
        std::cout << counter << "\n";
    }
    else{
        std::cout << "Incorrect." << "\n";
    }

    std::cout << "What is the capital of England?" << "\n";
    std::cout << "1. London" << "\n" << "2. Dhaka \n" << "3. Berlin \n" << "4. Paris \n"; 
    std::cin >> answer1;

    if (stoi(answer1) == 1){
        std::cout << "You got it correct!" << "\n";
        counter++;
        std::cout << counter << "\n";
    }
    else{
        std::cout << "Incorrect." << "\n";
    }

    std::cout << "What is the capital of Bangladesh?" << "\n";
    std::cout << "1. London" << "\n" << "2. Dhaka \n" << "3. Berlin \n" << "4. Paris \n"; 
    std::cin >> answer1;

    if (stoi(answer1) == 2){
        std::cout << "You got it correct!" << "\n";
        counter++;
        std::cout << counter << "\n";
    }
    else{
        std::cout << "Incorrect." << "\n";
    }

    
}
