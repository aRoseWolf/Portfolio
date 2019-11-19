//
//  main.cpp
//  Hangman
//
//  Created by Amanda Fabans on 11/18/19.
//  Copyright © 2019 Fabans. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype> //part of standard library that deals with converting characters to uppercase

using namespace std;

int main()
{
    //setup
    const int MAX_WRONG = 8; //hard code it for now until I can use this for unique words
    vector<string> words;//create a group of words
    words.push_back("Zero");
    words.push_back("Maya");
    words.push_back("Assassin");
    words.push_back("Siren");
    words.push_back("Amara");
    words.push_back("Angel");
    
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end()); //pick a random word from the group as the secret word
    const string WORD = words[0];
    int wrong = 0;
    string soFar(WORD.size(), '-');
    string used = "";
    
    char guess;
    
    cout << "Welcome to Borderlands Hangman" << endl;
    
    //while player hasnt made too many incorrect guesss and hasnt guessed the word
    while( (wrong < MAX_WRONG) && soFar != WORD )
    {
        //tell player how many incorrect guesses he or she has left
        cout << "You have " << (MAX_WRONG - wrong) << " tries left" << endl;
        //show player the letters they've guessed.
        cout << "Letters tried: " << used << endl;
        //show player how much of the secret word he or she guessed
        cout << "The word is: " << soFar << endl;
        
        //get player's next guess
        cout << "Enter your guess: ";
        cin >> guess;
        
        //while player has entered a letter that she already guessed
        while(used.find(guess) != string::npos)
        {
            //get player's guess
            cout << "You've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }
        //add the new guess to the group of used letters
        used += guess;
        
        //if the guess is in the secret word
        if (WORD.find(guess) != string::npos)
        {
            //tell the player the guess is correct
            cout << "Got it! " << guess << " is in the word." << endl;
            //update the word guessed so far with the new letter
            for (int i = 0; i < WORD.length(); i++)
            {
                if(WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            //tell the player the guess is incorrect
            cout << "Try again." << endl;
            //increment the number of incorrect guesses the player has made
            wrong++;
        }
    }
    
    //shut down
    //if the player has made too many incorrect guesses
    if(wrong == MAX_WRONG)
    {
        //tell the player theyve been hanged
        cout << "You've been hung" << endl;
    }
    else
    {
        //congratulate the player on guessing the secret word
        cout << "The word was " << WORD << endl;
    }
    
    return 0;
}
