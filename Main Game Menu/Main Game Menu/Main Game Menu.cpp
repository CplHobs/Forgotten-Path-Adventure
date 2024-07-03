// Purpose of this code is to act as the foundation all group members will add to.
// just using the basic header file, we can add others as needed:
#include <iostream>

using namespace std;

// here is where we declare our functions: 
void testFunction();

int main()
{
    int user_choice = 0;
    // Basic intro text
    cout << "Welcome to the Consortium Library" << endl;
    cout << "Where would you like to go?" << endl;
    
    // The main loop of our game that contols what the input will do set to 20 for now 
    while (user_choice != 20) {

        cout << "MENU:" << endl
        << "1: Archives and Special Collections" << endl
            << "2: Natural Science Building" << endl
            << "3: Learning Commons" << endl;
        // For getting the user input to select what option in the game menu to select
        cin >> user_choice;

        // switch statment to control the user options currenly set to 9 cases with the option to add or remove as needed:
        switch (user_choice)
        {
        case 1: {
            // call function for path to Archives
        }
        case 2: {
            // call function for path to Science Building
        }
        case 3: {
            // call function for path to Learning Commons
            void pathToLearningCommons();
        }
        default: {
            // set this to the exit code in case the user enters a random input that way it terminates the code:
            user_choice = 20;
            cout << "You have entered a value outside of 1-3.\n"
            << "Directing you to a random path.\n";
            
            // add code to pick a random path for the user or offer them a new selection

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


void pathToLearningCommons() {
    cout << "You will need to go right moving beyond the front desk.\n"
        << "1. Go beyond the front desk\n"
        << "2. Investigate the vending machine\n"
        << "3. Search the area for a cookie\n";
    int userInput = 0, userTool = 0, numCookies = 0;
    cin >> userInput;

    while (userInput <= 1 || userInput >= 3) {
        cout << "You have enter an invalid input. Pleasse select again\n";
        cin >> userInput;
    }
    // take the user through their first set of options on their path
    if (userInput == 1) {
        cout << "You begin your journey to the learning commons.\n";
        cout << "A small dog approaches. What would you like to do?\n";
    }

    if (userInput == 2) {
        cout << "You walk up to the vending machine just beyond the entrance.\n"
            << "Inside you see many possible tools for the journey.\n"
            << "Select which item you would like to gain:\n"
            << "1: Cardstock of Memory\n"
            << "2: Pencil of Piercing\n"
            << "3: Ballistic Eraser\n";
    }

    if (userInput == 3) {
        cout << "You check around the area for a snack\n"
            << "There looks to be something shiny in the bookshelf\n"
            << "You gain one cookie\n";
        numCookies++;
    }
    cout << "";
}
