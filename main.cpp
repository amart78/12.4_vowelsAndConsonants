/***************************************************************************************
12.4 VOWELS AND CONSONANTS

This program allows a user to input a c-string and view a menu of actions.
The user can calculate the number of vowels, number of consonants, and/or 
number of both vowels and consonants. They can also choose to input different 
strings to find out its aforementioned data. They may continue to make requests 
until they choose the 'Exit' option.
****************************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void displayMenu();
int vowelCount(char *);
int consonantCount(char *);
int vowAndConCount(char *);

int main(){
    const int LENGTH = 101;
    char userInput[LENGTH],
         actionSelect;

    // Gets a string from the user.
    cout << "\nPlease enter a string up to " << LENGTH-1 << " characters: ";
    cin.getline(userInput, LENGTH);

    do{
        // Shows user action options for their string.
        displayMenu();

        // Promps user for action selection and outputs accordingly.
        cout << "\nEnter the letter that corresponds with the action you'd like to select: ";
		cin  >> actionSelect;
		actionSelect = toupper(actionSelect);
        
        switch (actionSelect){
			case 'A': 
                cout << "Number of Vowels: " << vowelCount(userInput);
				break;
			case 'B': 
                cout << "Number of Consonants: " << consonantCount(userInput);
				break;
			case 'C': 
                cout << "Number of Vowels & Consonants: " << vowAndConCount(userInput);
				break;
			case 'D': 
                cout << "Please enter a string up to " << LENGTH-1 << " characters: \n";
		 		cin.ignore();
		 		cin.getline(userInput, LENGTH);
		}	
	} while (actionSelect != 'E');
   
    return 0;
}

// displayMenu:
// This function outputs a menu of actions
void displayMenu(){
    cout << "\n\nPlease review the menu below:\n"
    << "A. Count the number of vowels in the string \n" 
    << "B. Count the number of consonants in the string \n"
    << "C. Count both the vowels and consonants in the string \n"
    << "D. Enter another string \n"
    << "E. Exit the program \n";
}

// vowelCount:
// This function finds and returns the number of vowels in a c-string 
// by looping through the string and incrementing `count` by 1 every time
// the current char is equal to a vowel
int vowelCount(char *input){
    int count = 0;

    for (int i = 0; i < strlen(input); i++){
        if( tolower(input[i]) == 'a' || 
            tolower(input[i]) == 'e' || 
            tolower(input[i]) == 'i' || 
            tolower(input[i]) == 'o' || 
            tolower(input[i]) == 'u') {        
                count++;
        } 
    }
    return count;
}

// consonantCount:
// This function finds and returns the number of consonants in a c-string 
// by looping through the string by first, incrementing `count` by 1 
// every time the current char is alphabetic, and then, subtracting the
// number of vowels from that total count.
int consonantCount(char *input){
    int count = 0;

    for (int i = 0; i < strlen(input); i++){
        if(isalpha(input[i])){
            count++;
        }
    }
    return count - vowelCount(input);
}

// vowAndConCount:
// This function returns the sum of the number of vowels and consonants
int vowAndConCount(char *input){
    return vowelCount(input) + consonantCount(input);
}