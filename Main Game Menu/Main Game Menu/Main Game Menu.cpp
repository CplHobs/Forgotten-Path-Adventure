// Purpose of this code is to act as the foundation all group members will add to.
// just using the basic header file, we can add others as needed:

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Structures that you want to use for your path:
struct ArchivesPathNodes
{
    string location;
    string description;
    int minigame_code;
    ArchivesPathNodes(string loc, string des, int minigame)
        : location(loc), description(des), minigame_code(minigame) {};
};

// here is where we declare our functions for the paths: 
void pathToArchives();
void pathToLearningCommons();

// Functions to be used in our paths
int getUserIntInput(int min, int max);
void pathMenu();
void pathControl(ArchivesPathNodes main[4], ArchivesPathNodes left[4], ArchivesPathNodes right[4]);
void pathLeft(int, ArchivesPathNodes left[4]);
void pathCenter(int, ArchivesPathNodes main[4]);
void pathRight(int, ArchivesPathNodes right[4]);
void playMiniGame(ArchivesPathNodes);

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
                << "Please enter a new destination using number 1-3.\n";
        }
        }
    }


// here is where we will define our functions 
void pathToArchives() {
    

    ArchivesPathNodes main_path[4] = {
        ArchivesPathNodes("Long hallway", "Just pased the main desk leading to a large open area.", ((rand() % 6) + 1)),
        ArchivesPathNodes("Open Area in the Middle", "A large open area in the middle of the library with windows to your left and students sitting at desks.", ((rand() % 6) + 1)),
        ArchivesPathNodes("Pendulum Stairs", "A staircase that leads to the second and third floors.", ((rand() % 6) + 1)),
        ArchivesPathNodes("Archives and Special Collections", "The archives and special collections area of the library you are looking for.", ((rand() % 6) + 1)),
    };
    ArchivesPathNodes left_path[4] = {
        ArchivesPathNodes("Book Drop", "An area that looks like a spot to return any books you checked out.", ((rand() % 6) + 1)),                             
        ArchivesPathNodes("ARLIS Entrance", "An area called Alaska Resources Library and Information Services.", ((rand() % 6) + 1)),                          
        ArchivesPathNodes("Walkway to Testing Center", "A walkway on the second floor that leads to the testing center.", ((rand() % 6) + 1)),                 
        ArchivesPathNodes("Instruction and Research", "An area called The instruction and research department of the library.", ((rand() % 6) + 1)),                                                              
    };
    ArchivesPathNodes right_path[4] = {
        ArchivesPathNodes("Main Desk", "An area to get help from staff members.", ((rand() % 6) + 1)),
        ArchivesPathNodes("Study Space", "An area with a lot of desks for students to use for studying.", ((rand() % 6) + 1)),
        ArchivesPathNodes("Alaska Medical Library", "An area of the library to find medical information documents.", ((rand() % 6) + 1)),
        ArchivesPathNodes("Dean's Office", "The office of the Dean of the Library.", ((rand() % 6) + 1)),
    };

    cout << "You Selected the Archives and Special Collections path." << endl;
    pathControl(main_path, left_path,right_path);
    
    
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

void pathControl(ArchivesPathNodes mainpath[4],ArchivesPathNodes left[4],ArchivesPathNodes right[4]) {
    // Main control function for Archives path.
    // Takes in 2 arrays of ArchivesPathNodes data types, mainpath is set to 4 and sidepaths set to 8.
    // Has 4 int variables 1 for user menu selection input, and 3 to control what element in the above arrays to access depending on user choice between left, forward or, right.
    
    int user_choice = 0;
    int left_path = 0, center_path = 0 , right_path=0;
    while (center_path < 4)
    {
        pathMenu();
        user_choice = getUserIntInput(1, 3);
        switch (user_choice)
        {
        case 1: {
            pathLeft(left_path, left);
            cout << "Now you go to " << mainpath[center_path].location << endl;
            break;
        }
        case 2: {
            pathCenter(center_path, mainpath);
            break;
        }
        case 3: {
            pathRight(right_path, right);
            cout << "Now you go to " << mainpath[center_path].location << endl;
            break;
        }
        default:
            cout << "Error in pathControl function" << endl;
            break;
        }
        left_path++;;  
        center_path++;
        right_path++;  
    }
    cout << "Great job in reaching the end of the path." << endl;
}

void pathLeft(int round,ArchivesPathNodes left[4]) {
    // Used when user selects left from pathMenu() function. Takes in 2 arguments int for what round ie element to select in the ArchivesPathNodes array.
    // Will send the current rounds ArchivesPathNodes element to the playMiniGame Function to start the minigame for this node.
    // Outputs the location and discription string for the current node on this path. 
    ArchivesPathNodes current_node = left[round];
    
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

void pathRight(int round, ArchivesPathNodes right[4]) {
    // Used when user selects right from pathMenu() function. Takes in 2 arguments int for what round ie element to select in the ArchivesPathNodes array.
    // Will send the current rounds ArchivesPathNodes element to the playMiniGame Function to start the minigame for this node.
    // Outputs the location and discription string for the current node on this path.
    ArchivesPathNodes current_node = right[round];

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