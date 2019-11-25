#include <iostream>
#include <string>

using namespace std;

string askText(string prompt);
int askNum(string prompt);
void tellStory(string name, string noun, int num, string bodyPart, string verb);

int main()
{
    cout << "Welcome to Mad lib.\n" << endl;
    cout << "Answer the following questions to help create a story." << endl;
    
    string name = askText("Please enter a name: ");
    string noun = askText("Please enter a plural noun: ");
    int num = askNum("Please enter a number: ");
    string bodyPart = askText("Please enter a body part: ");
    string verb = askText("Please enter a verb: ");
    
    tellStory(name, noun, num, bodyPart, verb);
    
    return 0;
}

string askText(string prompt)
{
    string text;
    cout << prompt;
    cin >> text;
    return text;
}

int askNum(string prompt)
{
    int num;
    cout << prompt;
    cin >> num;
    return num;
}

void tellStory(string name, string noun, int num, string bodyPart, string verb)
{
    cout << "Here's your story!" << endl;
    
    cout << "You are a psycho by the name of " << name << " who possesses a shiny meat " << noun << " that you made from " << num << " different vault hunters." << endl;
    cout << " Out of all the limbs you used, the " << bodyPart << " made the best part. Now you can " << verb << " to your next COV meeting." << endl;
    
}
