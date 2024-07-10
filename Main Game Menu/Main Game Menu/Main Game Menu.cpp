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
  
    cout << "Welcome to the Consortium Library!" << endl;
    cout << "Where would you like to go?" << endl;

    cout << "MENU:" << endl
        << "1: Archives and Special Collections" << endl
        << "2: Natural Science Building" << endl
        << "3: Learning Commons" << endl;
    // For getting the user input to select what option in the game menu to select
    cin >> user_choice;

    // switch statment to control the user options currenly set to 9 cases with the option to add or remove as needed:
    switch (user_choice) {
        case 1:
            // call function for path to Archives
            pathToArchives();
            break;
        case 2:
            // call function for path to Science Building
            break;
        case 3:
            // call function for path to Learning Commons
            pathToLearningCommons();
            break;
        default:
            // set this to the exit code in case the user enters a random input that way it terminates the code:
            cout << "You have entered a value outside of 1-3.\n"
                << "Please enter a new destination using number 1-3.\n";
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
    cout << "You will need to go right moving beyond the front desk.\n"
        << "1. Go beyond the front desk\n"
        << "2. Investigate the vending machine\n"
        << "3. Search the area for a cookie\n";
    int userInput = 0, userTool = 0, numCookies = 0;
    cin >> userInput;

    while (userInput < 1 || userInput > 3) {
        cout << "You have enter an invalid input. Pleasse select again\n";
        cin >> userInput;
    }
    // take the user through their first set of options on their path
    if (userInput == 1) {
        cout << "You begin your journey to the learning commons.\n";
        cout << "A small dog approaches. What would you like to do?\n";
        userInput = 0;
    }

    if (userInput == 2) {
        cout << "You walk up to the vending machine just beyond the entrance.\n"
            << "Inside you see many possible tools for the journey.\n"
            << "Select which item you would like to gain:\n"
            << "1: Cardstock of Memory\n"
            << "2: Pencil of Piercing\n"
            << "3: Ballistic Eraser\n";
        // add variable to indicate the user has one of these tools
        userInput = 0;

    }

    if (userInput == 3) {
        cout << "You check around the area for a snack\n"
            << "There looks to be something shiny in the bookshelf\n"
            << "You gain one cookie\n";
        numCookies++;
        userInput = 0;

    }
    cout << "";

    cout << "You arrive at the second main desk. From here you can ask the staff if you\n"
        << "have any questions. Beyond the desk likely on your spiraling staircase and \n"
        << "a tall pendulum.To your left there will be the computer lab."
        << "1. To move East towards the Learning Commons.\n"
        << "2. Go investigate the pendulum.\n"
        << "3. Explore the computer lab.\n";

    // add events that trigger if the player goes to 2 or 3

    if (userInput == 1) {
        cout << "You continue on the straight path resolute to find its end.\n";
        userInput = 0;
    }

    // present options as they arrive at the "crossroads"
    cout << "The next place your exploration is an intersection.\n"
    << "1. Go left in the direction of food.\n"
        << "2. Continue East in search of the Learning Commons.\n"
        << "3. Explore the video section of the libary towards the right.\n";

    if (userInput == 2) {
        cout << "You press on to the Learning Commons. In a few seconds you arrive\n"
            << "exactly where you need to be.\n";
    }

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
      