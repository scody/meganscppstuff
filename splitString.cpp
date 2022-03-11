#include <iostream>

using namespace::std;

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

// this is just one of the tests, but they all work.
int main() {
    int size = 5;
    string arr[size];

    string testcase = "Bangkok,Berlin,Birmingham,Bogota,Busan,Baton Rouge,Beaumont,Boise,Budapest";
    char separator = ',';
    
    int numSplits = split(testcase, separator, arr, size);
    cout << "there are " << numSplits << " numsplits" << endl;

    for (int i=0; i <= size - 1; i++ ) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}