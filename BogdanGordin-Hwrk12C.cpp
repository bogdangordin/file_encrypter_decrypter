 /*

Bogdan Gordin
5/5/17
Hwrk12A: File Encrypter

Below are notes:

    *The encrypted file that you will be creating
     should be called Gobblygook.txt.

    *After you have read in the original file,
     display it on the screen, and then also
     display the encrypted result.

*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int counter = 0;
char tempLetter;
int numOfLetters;
int numOfSpaces;
int numOfCar;
int numOfDash;


int main()
{
    cout << endl << endl << "\tMorning. Welcome to Bogdan's Gordin Gettysburg counter." << endl << endl << endl;

    ifstream gettyFile;
    gettyFile.open("Gettysburg.txt");

    if(!gettyFile)
    {
        cout << "Oops. Could not open." << endl;
        cout << "\tI am out of here." <<  endl;
        cout <<"\n\n\n\n...";
        return 0;
    }

    while(!gettyFile.eof())//To count the letters
    {
        gettyFile >> std::noskipws >> tempLetter;
        counter++;
    }

    char theOriginalGetty[counter];

    numOfLetters = counter;
    counter = 0;
    gettyFile.close();


    gettyFile.open("Gettysburg.txt");
    while(!gettyFile.eof()) //To save in the original char array
    {
        gettyFile >> std::noskipws >> theOriginalGetty[counter];
        if(theOriginalGetty[counter] == ' ')
        {
            numOfSpaces++;
        }
        if(theOriginalGetty[counter] == '\n')
        {
            numOfCar++;
        }
        if(theOriginalGetty[counter] == '-')
        {
            numOfDash++;
        }
        counter++;
    }
    gettyFile.close();

    cout << "This are the numbers. " << endl << endl;
    cout << "Spaces:\t" << "\tCarriage:" << "\tDashes:" << endl;
    cout << numOfSpaces << "\t\t" << numOfCar << "\t\t" << numOfDash;





    cout <<"\n\n\n\n...";
    return 0;
}

