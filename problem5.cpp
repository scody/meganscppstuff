#include<iostream>
#include <string>
#include <strings.h>
#include <fstream>

using namespace::std;

class Movie{
    private:
        string title;
        string releaseYear;
    
    public:
        Movie();
        Movie(string _title, string _releaseYear);
        string getTitle();
        void setTitle(string _title);
        string getReleaseYear();
        void setReleaseYear(string _setReleaseYear);
};

// #include "Movie.h"

Movie::Movie(){
    title = "";
    releaseYear = "";
}

Movie::Movie(string _title, string _releaseYear){
    title = _title;
    releaseYear = _releaseYear;
}

string Movie::getTitle(){
    return title;
}

void Movie::setTitle(string _title){
    title = _title;
}

string Movie::getReleaseYear(){
    return releaseYear;
}

void Movie::setReleaseYear(string _releaseYear){
    releaseYear = _releaseYear;
}

class User{
    private:
        const static int size = 50;
        string username;
        int ratings[size];
        int numRatings;
        // static int size;
    
    public:
        User();
        User(string _username, int _ratings[], int _numRatings);
        string getUsername();
        void setUsername(string _username);
        int getRatingAt(int i);
        int setRatingAt(int index, int value);
        int getNumRatings();
        void setNumRatings(int _numRatings);
        int getSize();
};

User::User(){
    username = "";
    numRatings = 0;
    for (int i = 0; i < 50; i++){
    ratings[i] = 0;
    }
}


User::User(string _username, int _ratings[], int _numRatings){
    username = _username;
    numRatings = _numRatings;
    for (int i = 0; i < 50; i++){
        ratings[i] = 0;
    }
    for (int i = 0; i < _numRatings; i++){
        ratings[i] = _ratings[i];
    }
}

string User::getUsername(){
    return username;
}

void User::setUsername(string _username){
    username = _username;
}

int User::getNumRatings(){
    return numRatings;
}

void User::setNumRatings(int _numRatings){
    numRatings = _numRatings;
}

int User::getRatingAt(int i){
    //should be if not loop
    if (i >= size){
        return -1;
    }
    else if (i < size){
        return ratings[i];
    }
}

int User::setRatingAt(int i, int value){
    if (i <= size && value >= 0 && value <= 5){
        ratings[i] = value;
    }
    else{
        return false;
    }

    if (ratings[i] == value){
        return true;
    }
    else{
        return false;
    }
}
    
string toLower(string input){
    string newInput = "";

    for (int i = 0; i <= input.length(); i++){
        if (input[i] <= 90 && input[i] >= 65){
            newInput[i] = input[i] + 32;
            newInput += newInput[i];
            
        }
        else{
            newInput += input[i];
            
        }
        // newInput += newInput[i];
    }
    return newInput; 
    
}

int split(string inputStr, char separator, string returnArray[], int arraySize) {

    int elementIndex = 0;
    string currentString = "";

    // loop over each character of the string
    for(int i = 0; i <= inputStr.size(); i++) {

        // start by just placing the currentCharacter into 
        // a variable with an appropriate name. It just makes
        // it easier. if we do this, then we don't have to 
        // constantly use inputStr[i] each time we want to use
        // the character, easier to read
        char currentCharacter = inputStr[i];
        
        // if we have reached the separator, then we need
        // to add the currentString (that we have been building)
        // to the array, and increment elementIndex
        // ELSE continue building the string
        if(currentCharacter == separator) {

            // add the currentString to the index, and then 
            // we are going to start over, so set it to empty 
            // again, also, increase the elementIndex
            // because the NEXT string will be added to the next
            // index in the array.
            returnArray[elementIndex] = currentString;
            currentString = "";
            elementIndex ++;

            // handle the case where their are MORE elements in the string
            // then we have room for in the array
            if (elementIndex >= arraySize) {
                return -1;
            }
        } 
        else {
            currentString += currentCharacter;
        }
    }

    // if we have made it this far, the last currentString
    // needs to be added at the elementIndex.
    returnArray[elementIndex] = currentString;

    // can you guess why we add 1 to the elementIndex?
    // the answer is that we are using the index (which is 0 based) to indicate
    // the number of elements that we have added.
    // so, elementIndex might be 0,1,2,3... but the NUMBER of those items
    // is always 1 plus that.
    return elementIndex + 1;
}


    
int readRatings(string fileName, User users[], int numUsersStored, int usersArrSize, int maxRatings) {

    string line = "";
    int numUsersAdded = 0; 
    
    
    ifstream fin;
    fin.open(fileName);
    
    if (numUsersStored == usersArrSize){
        return -2;
    }
    
    if (fin.fail()){
        return -1;
    }

    while(getline(fin,line)) {
        // what to do if the line is blank?
        if(line == "") {
            continue;
        }
        
        string userStringArray[maxRatings + 1];

        // 1. split line into array
        int numObjects = split(line,',', userStringArray, maxRatings);

        // 2. create new tempUser object, set username to the new user
        User tempUser;
        tempUser.setUsername(userStringArray[0]);

        // 3. add ratings to tempUser object
        for (int i=1; i <numObjects; i++ ){
            tempUser.setRatingAt(i-1, stoi(userStringArray[i]));
        }

        // 4. add tempUser to user Array
        numUsersStored = numUsersStored + 1;
        users[numUsersStored] = tempUser;
        
        cout << line << endl;
    }

    return numUsersStored;
}

int main() {
    User users[10]; 
    int numUsers = 0; 
    int usersArrSize = 10; 
    int numUsersStored = 5;
    numUsersStored = readRatings("ratings.txt", users, numUsersStored , usersArrSize, 5);

    for(int i = 0; i < numUsersStored; i++) {
        cout << users[i].getUsername() << endl;
    }
}