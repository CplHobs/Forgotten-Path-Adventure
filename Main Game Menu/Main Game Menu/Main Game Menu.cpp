// Purpose of this code is to act as the foundation all group members will add to.
// just using the basic header file, we can add others as needed:
#include <iostream>

using namespace std;

// here is where we declare our functions: 
void testFunction();

int main()
{
    int user_choice=0;
    // Basic into text, currently a placeholder for now
    cout << "This is where we will add the text intro for the user to explain our code/game" << endl;
    
    // The main loop of our game that contols what the input will do set to 20 for now 
    while (user_choice != 20) {

        cout << "MENU:" << endl
            << "1: Path" << endl
            << "2: Path" << endl
            << "3: Path" << endl
            << "4: Path" << endl
            << "5: Path" << endl
            << "6: Path" << endl
            << "7: Path" << endl
            << "8: Path" << endl
            << "9: Path" << endl
            << "20: Path" << endl;
        // For getting the user input to select what option in the game menu to select
        cin >> user_choice;
        // switch statment to control the user options currenly set to 9 cases with the option to add or remove as needed:
        switch (user_choice)
        {
        case 1: {
            // code to be exicuted here:
        }
        case 2: {
            // code to be exicuted here:
        }
        case 3: {
            // code to be exicuted here:
        }
        case 4: {
            // code to be exicuted here:
        }
        case 5: {
            // code to be exicuted here:
        }
        case 6: {
            // code to be exicuted here:
        }
        case 7: {
            // code to be exicuted here:
        }
        case 8: {
            // code to be exicuted here:
        }
        case 9: {
            // code to be exicuted here:
        }
        default: {
            // set this to the exit code in case the user enters a random input that way it terminates the code:
            user_choice = 20;
            break;
        }
        }
    }


    return 0;
}

// here is where we will define our functions 
void testFunction() {
    // Place holder funtion to be removed
}

