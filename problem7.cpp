#include<iostream>
#include <string>
#include <strings.h>

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
    
int getCountWatchedMovies(string username, User users[], int numUsersStored, int numMoviesStored){
    bool didFindUser = false;
    User foundUser;
    bool didFindMovie = false;
    int rating = 0;
    int ratingCount = 0;
    
    // step 1) find user or return -3
    for(int i = 0; i < numUsersStored; i++){

        //cout << "username: " << username << " users[i].getUsername()" << users[i].getUsername() << endl;
        
        if (toLower(username) == toLower(users[i].getUsername())){
            didFindUser = true;
            foundUser = users[i];
        }
    }
    if (didFindUser == false){
        return -3;
    }
    

    if (numMoviesStored <= 0){
        return -3;
    }

    // step 2) find how many movies they rated with users[size]
    for(int i = 0; i <= numMoviesStored -1; i++){

        //something is making this if always true, but we don't want it to always be true
        if (foundUser.getRatingAt(i) != 0) { //&& users[i].getRatingAt(i) <= 0 && users[i].getRatingAt(i) >= 5);
            ratingCount ++;            
        }
    }
    if (ratingCount == 0){
        return -3;
    }
    return ratingCount;
}


int main() {
    //Creating 2 users 
    User users[2]; 
    //Setting username and ratings for User1 
    users[0].setUsername("User1"); 
    users[0].setNumRatings(2); 
    users[0].setRatingAt(0,2); 
    users[0].setRatingAt(1,2); 
    //Setting username and ratings for User2 
    users[1].setUsername("User2"); 
    users[1].setNumRatings(4); 
    users[1].setRatingAt(0,4); 
    users[1].setRatingAt(1,4);
    // getCountWatchedMovies for User2 
    cout << getCountWatchedMovies("User2",users,2,3);
}