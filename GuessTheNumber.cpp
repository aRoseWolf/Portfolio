#include <iostream>
#include <cstdlib> //generate random number
#include <ctime> //generate number with current time

using namespace std;

int main()
{
    bool is_running = true;
    srand(static_cast<unsigned int>(time(0))); //seed random number generator
    int secretNumber = rand() % 100 + 1; //random number between 1 and 100
    int tries = 0; //count number of tries used
    int guess = 0; //user input
    
    cout << "\tWelcome to Guess My Number\n" << endl;
    
    do
    {
        cout << "What is my number? ";
        cin >> guess;
        if (guess > secretNumber)
        {
            cout << "Too high" << endl;
            tries++;
        }
        else if (guess < secretNumber)
        {
            cout << "Too low" << endl;
            tries++;
        }
        else if (guess == secretNumber)
        {
            cout << "DING DING DING! WE HAVE A WINNER!!!!" << endl;
            cout << "You had " << tries << " attempts used" << endl;
            is_running = false;
        }
        else
            cout << "Invalid Input, try using a number" << endl;
        tries++;
        
    }while(is_running);
    
    return 0;
}
