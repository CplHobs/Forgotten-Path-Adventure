// Purpose of this code is to act as the foundation all group members will add to.
// just using the basic header file, we can add others as needed:
#include <iostream>

using namespace std;

// here is where we declare our functions for the paths: 
void pathToArchives();
void pathToLearningCommons();

// Functions to be used in our paths
int getUserIntInput(int min, int max);

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
            void pathToArchives();
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
}

// here is where we will define our functions 
void pathToArchives() {
    int user_choice = 0;

    cout << "You Selected the Archives and Special Collections path." << endl
        << "Menu:" << endl
        << "1: Proceed to the right and past the main desk" << endl
        << "2: " << endl
        << "3: " << endl;
    user_choice = getUserIntInput(1, 3);
    switch (user_choice)
    {
    case 1: {
        cout << "After moving past the main desk you see a large open area with the windows and students to your right: " << endl
            << "Menu: " << endl
            << "1: " << endl
            << "2: " << endl
            << "3: " << endl;
        user_choice = getUserIntInput(1, 3);
    }
    case 2: {

    }
    case 3: {

    }default: {
        cout << "Error in switch value." << endl;
    }
    }


}

void pathToLearningCommons() {

}

int getUserIntInput(int min, int max) {
    // takes in the min value from the menu options and the max value. 
    // Insures user enters a valid value to select the option from the menu.
    // Returns a valid user int value for the menu. 
    int user_choice = 0;
    while (true)
    {
        cin >> user_choice;
        if (user_choice >= min && user_choice <= max) {
            return user_choice;
        }
        else
        {
            cout << "You have entered a value outside of " << min << " and " << max << endl
                << "Please try again." << endl;
        }
    }

}
