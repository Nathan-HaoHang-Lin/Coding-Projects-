/******************************************************************************
PSEUDO CODE

Function numVowels(input):
    count = 0
    len = length of input
    for i from 0 to len - 1:
        letter = uppercase(input[i])
        if letter is between A and Z:
            if letter is vowel:
                incrememnt count
    return count

Function numConson(input):
    count = 0;
    len = length of input
    for i from 0 to len - 1:
        letter = uppercase(input[i])
        if letter is between A and Z:
            if letter is not vowel:
                incrememnt count`
    return count

Main:

    set size of array
    declare character array with size
    create var to store choice

    grab user input

    do:
        read menu choice
        choice = uppercase

        switch:
            case A:
                function call
                print
            case B:
                function call
                print
            case C:
                function call
                function call
                print
            case D:
                grab user input
    while not E;

*******************************************************************************/
#include <iostream>
#include <cstring>

using namespace std;

//function prototypes

int numVowels(const char *);
int numConson(const char *);

//Function to count the number of vowels

int numVowels(const char* input) {

    //intialize counter variable

    int count = 0;

    //intialize len to know when to end for loop

    int len = strlen(input);

    //for loop

    for (int i = 0; i < len; i++) {

        // store each letter of the cstring in char variable called letter
        //capitlize each letter to avoid the need to check lower and upper case letters. Just upper

        char letter = toupper(input[i]);

        //if statement to check it is a letter and not a special character or space

        if (letter >= 'A' && letter <= 'Z') {

            //if statement to check if it is a vowel

            if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U') {

                //incrememnt count by 1 since letter is a vowel

                count ++;
            }
        }
    }

    //return number of vowels

    return count;
}

//function to count the number of constants

int numConson(const char* input) {

    //intialize counter variable

    int count = 0;

    //intialize len to know when to end for loop

    int len = strlen(input);

    //for loop

    for (int i = 0; i < len; i++) {

        // store each letter of the cstring in char variable called letter
        //capitlize each letter to avoid the need to check lower and upper case letters. Just upper

        char letter = toupper(input[i]);

        //if statement to check it is a letter and not a special character or space

        if (letter >= 'A' && letter <= 'Z') {

            //if statement to make sure it is not a vowel, thus a consonant

            if (letter != 'A' && letter != 'E' && letter != 'I' && letter != 'O' && letter != 'U') {

                //incremement count by 1 since it is a consonant

                count++;
            }
        }
    }

    //return the number of consonants

    return count;
}

//main

int main()
{

    //create our charaacter array (cstring)
    const int SIZE = 100000;
    char input[SIZE];

    //variable to store user menu choices

    char choice;

    //get string
    cout << "Enter a string: ";
    cin.getline(input, SIZE);

    // do while loop to iterate until user selects to exit menu

    do {
        // Display menu choices to the user
        
        cout << "\nMenu Options:\n";
        cout << "A. Count the number of vowels in the string\n";
        cout << "B. Count the number of consonants in the string\n";
        cout << "C. Count both vowels and consonants\n";
        cout << "D. Enter another string\n";
        cout << "E. Exit the program\n";
        cout << "Enter your choice: ";

        //grab user menu input

        cin >> choice;
        choice = toupper(choice);
        cin.ignore();

        //switch case to make user menu selection

        switch (choice) {

            //case A for counting vowels

            case 'A': {

                //call function to count vowels and store that in variable called vowels

                int vowels = numVowels(input);

                //print out number of vowels

                cout << "The string has " << vowels << " vowels." << endl;
                break;
            }

            //case B for counting number of consonants

            case 'B': {

                //call function to count consonants and store that in a variable called conson

                int conson = numConson(input);

                //print out number of consonants

                cout << "The string has " << conson << " consonants." << endl;
                break;
            }

            // case C for counting both vowels and consonants

            case 'C': {

                //call functions to count consonants and vowels and store them in conson and vowels respectively

                int conson = numConson(input);
                int vowels = numVowels(input);

                //print out number of consonants and vowels

                cout << "The string has " << vowels << " vowels and " << conson << " consonants." << endl;
                break;
            }

            //case D for inputting another string

            case 'D': {
                cin.getline(input, SIZE);
                break;
            }

        }

    } while (choice != 'E');

    return 0;
}
