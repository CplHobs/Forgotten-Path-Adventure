// Purpose of this code is to act as the foundation all group members will add to.
// just using the basic header file, we can add others as needed:

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#include <thread>
#include <conio.h>

using namespace std;

// Structures that you want to use for your path:
struct ArchivesPathNodes
{
    string location;
    string description;
    int minigame_code;
    bool lastnode;
    ArchivesPathNodes(string loc, string des, int minigame, bool last)
        : location(loc), description(des), minigame_code(minigame), lastnode(last) {};
};

// here is where we declare our functions for the paths: 
void pathToArchives();
void pathToLearningCommons();

// Functions to be used in our paths
int getUserIntInput(int min, int max);
void pathMenu();
void pathControl(ArchivesPathNodes main[4], ArchivesPathNodes side[8]);
void pathLeft(int, ArchivesPathNodes side[8]);
void pathCenter(int, ArchivesPathNodes main[4]);
void pathRight(int, ArchivesPathNodes side[8]);
void playMiniGame(ArchivesPathNodes);
int playPendulumGame(); // when player interacts with pendulum run a timing game
void labGame(); // creates an image if player goes to the computer lab

int main()
{
    srand(time(NULL)); // added for any random numbers we want to use for our mini-games.
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
        default:{
            // set this to the exit code in case the user enters a random input that way it terminates the code:
            cout << "You have entered a value outside of 1-3.\n"
                << "Please enter a new destination using numbers 1-3.\n";
        }
        }
    }


// here is where we will define our functions 
void pathToArchives() {
    

    ArchivesPathNodes main_path[4] = {
        ArchivesPathNodes("Long hallway", "Just pased the main desk leading to a large open area.", ((rand() % 6) + 1), false),
        ArchivesPathNodes("Open Area in the Middle", "A large open area in the middle of the library with windows to your left and students sitting at desks.", ((rand() % 6) + 1), false),
        ArchivesPathNodes("Pendulum Stairs", "A staircase that leads to the second and third floors.", ((rand() % 6) + 1), false),
        ArchivesPathNodes("Archives and Special Collections", "The archives and special collections area of the library you are looking for.", ((rand() % 6) + 1), true),
    };
    ArchivesPathNodes side_paths[8] = {
        ArchivesPathNodes("Book Drop", "An area that looks like a spot to return any books you checked out.", ((rand() % 6) + 1), false),                             // 0 left
        ArchivesPathNodes("Main Desk", "An area to get help from staff members.", ((rand() % 6) + 1), false),                                                         // 1 right
        ArchivesPathNodes("ARLIS Entrance", "An area called Alaska Resources Library and Information Services.", ((rand() % 6) + 1), false),                          // 2 left
        ArchivesPathNodes("Study Space", "An area with a lot of desks for students to use for studying.", ((rand() % 6) + 1), false),                                 // 3 right
        ArchivesPathNodes("Walkway to Testing Center", "A walkway on the second floor that leads to the testing center.", ((rand() % 6) + 1), false),                 // 4 left
        ArchivesPathNodes("Alaska Medical Library", "An area of the library to find medical information documents.", ((rand() % 6) + 1), false),                      // 5 right
        ArchivesPathNodes("Instruction and Research", "An area called The instruction and research department of the library.", ((rand() % 6) + 1), false),           // 6 left
        ArchivesPathNodes("Dean's Office", "The office of the Dean of the Library.", ((rand() % 6) + 1), false),                                                      // 7 right
    };
    

    cout << "You Selected the Archives and Special Collections path." << endl;
    pathControl(main_path, side_paths);
    
    
}

void pathToLearningCommons() {
    cout << "You will need to go right moving beyond the front desk.\n"
        << "1. Go beyond the front desk\n"
        << "2. Investigate the vending machine\n"
        << "3. Search the area for a cookie\n";
    int userChoiceStop1 = 0, reactionToDog = 0, userChoiceStop2 = 0, userChoiceStop3 = 0, userTool = 0, numCookies = 0;
    string dogLocation = "noWhere";
    cin >> userChoiceStop1;

    while (userChoiceStop1 < 1 || userChoiceStop1 > 3) {
        cout << "You have enter an invalid input. Pleasse select again\n";
        cin >> userChoiceStop1;
    }
    // take the user through their first set of options on their path
    if (userChoiceStop1 == 1) {
        cout << "You begin your journey to the learning commons.\n";
        cout << "A small dog approaches. What would you like to do?\n";
        userChoiceStop1 = 0;
        cout << "1. Pet the dog\n"
            << "2. Give the dog one a cookie\n"
            << "3. Run from the dog\n";
        cin >> reactionToDog;
        // new options if user meets dog
        switch (reactionToDog) {
        case 1:
            cout << "The dogs lets you pet them and then runs to the computer lab ahead.\n";
            break;
        case 2:
            cout << "The dog takes the cookie greatfully. You blink and the dog disappears. In its place you find two more cookies.\n";
            numCookies++;
            break;
        case 3:
            cout << "You run like the wind away from the dog. In your panic you hit a wall head on and fall unconscious.\n";
            // add function to play mini game of some kind (hangman maybe)
            break;
        default: {
            // set this to the exit code in case the user enters a random input that way it terminates the code:
            cout << "You have entered a value outside of 1-3.\n"
                << "Please enter a new destination using numbers 1-3.\n";
        }
        }
        userChoiceStop1 = 0; // stops the other first branches from runnning on accident.
    }

    if (userChoiceStop1 == 2) { // set userTool to one of the numbers selected by the player
        cout << "You walk up to the vending machine just beyond the entrance.\n"
            << "Inside you see many possible tools for the journey.\n"
            << "Select which item you would like to gain:\n"
            << "1: Cardstock of Memory\n"
            << "2: Pencil of Piercing\n"
            << "3: Ballistic Eraser\n";
        // add variable to indicate the user has one of these tools
        userChoiceStop1 = 0;

    }

    if (userChoiceStop1 == 3) {
        cout << "You check around the area for a snack\n"
            << "There looks to be something shiny in the bookshelf\n"
            << "You gain one cookie. Then walk towards the open area nearby.\n";
        numCookies++;
        userChoiceStop1 = 0;

    }
    cout << "";

    cout << "You arrive at the second main desk. From here you can ask the staff if you\n"
        << "have any questions. On your right is a spiraling staircase and \n"
        << "a tall pendulum.To your left there will be the computer lab.\n"
        << "1. To move East towards the Learning Commons.\n"
        << "2. Go investigate the pendulum.\n"
        << "3. Explore the computer lab.\n";
    cin >> userChoiceStop2;

    // add events that trigger if the player goes to 2 or 3

    switch (userChoiceStop2) {
    case 1:
        cout << "You continue on the straight path resolute to find its end.\n";
        break;
    case 2:
        cout << "Here you see the pendulum has stopped swinging. Push the pendulum to resume its normal path.\n";
        cout << "Note: Tapping keys in quick succession will cause the program to check each tap of the key.\n"
            << "This can take a while to resolve so it is not recommended. "
            << "Click Enter to continue.\n";
        cin.get();
        // add function to play pendulum game
        playPendulumGame();
        numCookies++;
        break;
    case 3:
        cout << "You go over to the computer lab. It seems to have many computers available to students.\n"
            << "There is a cascade of clicking noises behind you.\n"
            << "You turn around just in time to see a colossal centipede.\n";
        // add function to play mini game including the centipede if there is time...
        cout << "The creature chases you until something falls from your pocket.\n"
            << "It stops to eat whatever fell.\n";
            numCookies--;
        break;
    default: {
        // set this to the exit code in case the user enters a random input that way it terminates the code:
        cout << "You have entered a value outside of 1-3.\n"
            << "Please enter a new destination using numbers 1-3.\n";
    }
    }

    // present options as they arrive at the "crossroads"
    cout << "The next location of your your exploration is an intersection.\n"
    << "1. Go left in the direction of food.\n"
        << "2. Continue East in search of the Learning Commons.\n"
        << "3. Explore the video section of the libary towards the right.\n";
    cin >> userChoiceStop3;

    switch (userChoiceStop3) {
    case 1:
        cout << "You find a cookie under the table there.\n"
            << "Recalling your end goal you head out of the break area.\n"
            << "Going towards the elevators you spot the Learning Commons on your left\n";
        numCookies++;
        break;
    case 2: 
        break;
    case 3:
        cout << "Here you find a small gnome perusing the films.\n"
            << "He turns to you and says \'They will never believe you.\'\n"
            << "The gnome snatches anything he can reach and is gone in a flash.\n";
        numCookies--;
        break;
    }

    if (userChoiceStop3 == 2) {
        cout << "You press on to the Learning Commons. In a few seconds you arrive... \n"
            << "exactly where you need to be.\n";
    }
    cout << "You found " << numCookies << "cookies on your adventure. "
        << "Next time will you collect even more?\n\n"
        << "*** Thanks for playing! ***\n";

}

void labGame() {

    
    return;
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

void pathMenu() {
    // Function to display the menu for user to select a path, left, forward, or right.
    cout << "Menu:" << endl
         << "You decide to go..." << endl
         << "1: Left" << endl
         << "2: Forward" << endl
         << "3: Right" << endl;
}

void pathControl(ArchivesPathNodes mainpath[4],ArchivesPathNodes sidepaths[8]) {
    // Main control function for Archives path.
    // Takes in 2 arrays of ArchivesPathNodes data types, mainpath is set to 4 and sidepaths set to 8.
    // Has 4 int variables 1 for user menu selection input, and 3 to control what element in the above arrays to access depending on user choice between left, forward or, right.
    
    int user_choice = 0;
    int left_path = 0, center_path = 0 , right_path=1;
    while (center_path < 4)
    {
        pathMenu();
        user_choice = getUserIntInput(1, 3);
        switch (user_choice)
        {
        case 1: {
            pathLeft(left_path, sidepaths);
            cout << "Now you go to " << mainpath[center_path].location << endl;
            break;
        }
        case 2: {
            pathCenter(center_path, mainpath);
            break;
        }
        case 3: {
            pathRight(right_path, sidepaths);
            cout << "Now you go to " << mainpath[center_path].location << endl;
            break;
        }
        default:
            cout << "Error in pathControl function" << endl;
            break;
        }
        left_path = left_path + 2; // updates by 2 so all even elements are for left path 
        center_path++;
        right_path = right_path + 2; // updates by 2 so all odd elements are for right path 
    }
    cout << "Great job in reaching the end of the path." << endl;
}

void pathLeft(int round,ArchivesPathNodes sidepaths[8]) {
    // Used when user selects left from pathMenu() function. Takes in 2 arguments int for what round ie element to select in the ArchivesPathNodes array.
    // Will send the current rounds ArchivesPathNodes element to the playMiniGame Function to start the minigame for this node.
    // Outputs the location and discription string for the current node on this path. 
    ArchivesPathNodes current_node = sidepaths[round];
    
    cout << "You are at " << current_node.location << endl 
         << current_node.description << endl;

    playMiniGame(current_node);
}

void pathCenter(int round, ArchivesPathNodes mainpath[4]) {
    // Used when user selects forward from pathMenu() function. Takes in 2 arguments int for what round ie element to select in the ArchivesPathNodes array.
    // Will send the current rounds ArchivesPathNodes element to the playMiniGame Function to start the minigame for this node.
    // Outputs the location and discription string for the current node on this path.
    ArchivesPathNodes current_node = mainpath[round];

    cout << "You are at " << current_node.location << endl 
         << current_node.description << endl;

    playMiniGame(current_node);
}

void pathRight(int round, ArchivesPathNodes sidepaths[8]) {
    // Used when user selects right from pathMenu() function. Takes in 2 arguments int for what round ie element to select in the ArchivesPathNodes array.
    // Will send the current rounds ArchivesPathNodes element to the playMiniGame Function to start the minigame for this node.
    // Outputs the location and discription string for the current node on this path.
    ArchivesPathNodes current_node = sidepaths[round];

    cout << "You are at " << current_node.location << endl
         << current_node.description << endl;

    playMiniGame(current_node);
}

void playMiniGame(ArchivesPathNodes path) {
    // Plays the minigame based off random number generated between 1 and 6 for the current path node it recieved. ie ArchivesPathNodes path.minigame_code
    int game = path.minigame_code;

    switch (game)
    {
    case 1: {
        cout << "Play minigame: " << game << endl;
        break;
    }case 2: {
        cout << "Play minigame: " << game << endl;
        break;
    }
    case 3: {
        cout << "Play minigame: " << game << endl;
        break;
    }
    case 4: {
        cout << "Play minigame: " << game << endl;
        break;
    }
    case 5: {
        cout << "Play minigame: " << game << endl;
        break;
    }
    case 6: {
        cout << "Play minigame: " << game << endl;
        break;
    }
    default: {
        cout << "Error in minigame logic" << endl;
        break;
    }
    }

}

int playPendulumGame() {
    srand(time(0)); // seed random number generator

    bool gameOver = false;


    while (!gameOver) {
        int timeToPress = rand() % 3 + 1; // generate a random time to press the key (1-3 seconds)
        cout << "Get ready to press a key...\n";
        this_thread::sleep_for(chrono::seconds(timeToPress)); // wait for the random time
        cout << "PRESS A KEY NOW!\n";
        fflush(stdout); // make sure the output is displayed immediately
        auto start = chrono::high_resolution_clock::now(); // start timer
        _getch(); // wait for a key press
        fflush(stdin); // clear the input buffer
        auto end = chrono::high_resolution_clock::now(); // stop timer
        chrono::duration<double> diff = end - start; // calculate time difference
        if (diff.count() < 0.5) {
            cout << "Too quick! You pressed the key in " << diff.count() << " seconds.\n";
        }
        else if (diff.count() > 1.5) {
            cout << "Too late! You pressed the key in " << diff.count() << " seconds.\n";
        }
        else {
            cout << "Perfect! You pressed the key in " << diff.count() << " seconds.\n";
            gameOver = true;
        }
        if (!gameOver) {
            cout << "Press any key to play again...\n";
            _getch(); // wait for a key press
            fflush(stdin); // clear the input buffer
        }
    }

    cout << "Congratulations, you won a cookie! Press any key to continue...\n";
    _getch(); // wait for a key press
    fflush(stdin); // clear the input buffer

    return 0;
}
