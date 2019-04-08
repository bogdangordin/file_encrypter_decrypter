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

struct LyricsStringsLowChar
{
    string convertA = "contemplating glinka ";
    string convertB = "the neverhood ";
    string convertC = "clitton klatton klogg ";
    string convertD = "they join crit unit b ";
    string convertE = "we behold its hoborg ";
    string convertF = "oh what the hey ";
    string convertG = "large robot bill cornholio odd ";
    string convertH = "crit unit spaghetti ";
    string convertI = "lol clock ticking bogdan ";
    string convertJ = "that frenchy frenchy gee ";
    string convertK = "and frenchy guy ";
    string convertL = "cccc clockwork beast ";
    string convertM = "thus with them ";
    string convertN = "ugh my this sucks hoborg ";
    string convertO = "hard to see mom ";
    string convertP = "kekekeke kiril ";
    string convertQ = "hmm what day is ";
    string convertR = "wow nasa ";
    string convertS = "he joins unit b ";
    string convertT = "man frenchy pal is with damn honestly ";
    string convertU = "whats it oh its hoborg ";
    string convertV = "klayman shuffle ";
    string convertW = "everybody way ohhh ";
    string convertX = "homina ";
    string convertY = "dum da dum doi doi ";
    string convertZ = "southern front porch whistle ";
};
struct LyricsStringsHighChar
{
    string convertA = "CONTEMPLATING GLINKA ";
    string convertB = "THE NEVERHOOD ";
    string convertC = "CLITTON KLATTON KLOGG ";
    string convertD = "THEY JOIN CRIT UNIT B ";
    string convertE = "WE BEHOLD ITS HOBORG ";
    string convertF = "OH WHAT THE HEY ";
    string convertG = "LARGE ROBOT BILL CORNHOLIO ODD ";
    string convertH = "CRIT UNIT SPAGHETTI ";
    string convertI = "LOL CLOCK TICKING BOGDAN ";
    string convertJ = "THAT FRENCHY FRENCHY GEE ";
    string convertK = "AND FRENCHY GUY ";
    string convertL = "CCCC CLOCKWORK BEAST ";
    string convertM = "THUS WITH THEM ";
    string convertN = "UGH MY THIS SUCKS HOBORG ";
    string convertO = "HARD TO SEE MOM ";
    string convertP = "KEKEKEKE KIRIL ";
    string convertQ = "HMM WHAT DAY IS ";
    string convertR = "WOW NASA ";
    string convertS = "HE JOINS UNIT B ";
    string convertT = "MAN FRENCHY PAL IS WITH DAMN HONESTLY ";
    string convertU = "WHATS IT OH ITS HOBORG ";
    string convertV = "KLAYMAN SHUFFLE ";
    string convertW = "EVERYBODY WAY OHHH ";
    string convertX = "HOMINA ";
    string convertY = "DUM DA DUM DOI DOI ";
    string convertZ = "SOUTHERN FRONT PORCH WHISTLE ";
};
struct LyricsStringsWeirdChar
{
    string convertPsik = "` ";
    string convertTotshka = "+ ";
    string convertSpace = "_ ";
    string convertDas = "~ ";
};

int counter = 0;
string tempWord;
char tempLetter;
int numOfWords;
int numOfLetters;
int numOfEncryption;
int numOfTest;


int main()
{
    cout << endl << endl << "\tHey there. Welcome to Bogdan's Gordin file encrypter." << endl << endl;
    LyricsStringsLowChar theLowCharStrings;
    LyricsStringsHighChar theHighCharStrings;
    LyricsStringsWeirdChar theWeirdCharStrings;

    cout << "Here is the original file: " << endl << endl << endl;

    ifstream gettyFile;
    gettyFile.open("Gettysburg.txt");

    if(!gettyFile)
    {
        cout << "Oops. Could not open." << endl;
        cout << "\tI am out of here." <<  endl;
        cout <<"\n\n\n\n...";
        return 0;
    }

    while(!gettyFile.eof())
    {
        gettyFile >> tempWord;
        cout << tempWord << " ";
        counter++;
    }
    tempWord = "";
    cout << endl << endl;

    string theOriginalGetty[counter];

    numOfWords = counter;
    counter = 0;
    gettyFile.close();


    gettyFile.open("Gettysburg.txt");
    while(!gettyFile.eof()) //To save in the original string array
    {
        gettyFile >> theOriginalGetty[counter];
    }
    gettyFile.close();


    gettyFile.open("Gettysburg.txt");
    while(!gettyFile.eof()) //to count the letters
    {
        gettyFile >> std::noskipws >> tempLetter;
        numOfLetters++;
    }

    char theOriginalGettyButInLetters[numOfLetters];
    gettyFile.close();


    gettyFile.open("Gettysburg.txt");
    while(!gettyFile.eof()) //to save the letters in the char array
    {
        gettyFile >> std::noskipws >> theOriginalGettyButInLetters[counter];
        counter++;
    }
    counter = 0;
    gettyFile.close();

    cout << endl << "\t Num of words: " << numOfWords << "." << "\tNum of letters: " << numOfLetters << "." << endl << endl;
    cout << "Ready to see the encyption? It'll be ridicuously giant.";
    cin.get();
    cout << "\tOK!" << endl << endl << endl;


    ofstream gobblyFile;
    gobblyFile.open("Gobblygook.txt");


    while (numOfLetters > counter)
    {
        if (theOriginalGettyButInLetters[counter] == 'a')//this is where the Low case starts.
        {
            gobblyFile << theLowCharStrings.convertA;
            cout << theLowCharStrings.convertA;
        }
        if (theOriginalGettyButInLetters[counter] == 'b')
        {
            gobblyFile << theLowCharStrings.convertB;
            cout << theLowCharStrings.convertB;
        }
        if (theOriginalGettyButInLetters[counter] == 'c')
        {
            gobblyFile << theLowCharStrings.convertC;
            cout << theLowCharStrings.convertC;
        }
        if (theOriginalGettyButInLetters[counter] == 'd')
        {
            gobblyFile << theLowCharStrings.convertD;
            cout << theLowCharStrings.convertD;
        }
        if (theOriginalGettyButInLetters[counter] == 'e')
        {
            gobblyFile << theLowCharStrings.convertE;
            cout << theLowCharStrings.convertE;
            numOfTest++;
        }
        if (theOriginalGettyButInLetters[counter] == 'f')
        {
            gobblyFile << theLowCharStrings.convertF;
            cout << theLowCharStrings.convertF;
        }
        if (theOriginalGettyButInLetters[counter] == 'g')
        {
            gobblyFile << theLowCharStrings.convertG;
            cout << theLowCharStrings.convertG;
        }
        if (theOriginalGettyButInLetters[counter] == 'h')
        {
            gobblyFile << theLowCharStrings.convertH;
            cout << theLowCharStrings.convertH;
        }
        if (theOriginalGettyButInLetters[counter] == 'i')
        {
            gobblyFile << theLowCharStrings.convertI;
            cout << theLowCharStrings.convertI;
        }
        if (theOriginalGettyButInLetters[counter] == 'j')
        {
            gobblyFile << theLowCharStrings.convertJ;
            cout << theLowCharStrings.convertJ;
        }
        if (theOriginalGettyButInLetters[counter] == 'k')
        {
            gobblyFile << theLowCharStrings.convertK;
            cout << theLowCharStrings.convertK;
        }
        if (theOriginalGettyButInLetters[counter] == 'l')
        {
            gobblyFile << theLowCharStrings.convertL;
            cout << theLowCharStrings.convertL;
        }
        if (theOriginalGettyButInLetters[counter] == 'm')
        {
            gobblyFile << theLowCharStrings.convertM;
            cout << theLowCharStrings.convertM;
        }
        if (theOriginalGettyButInLetters[counter] == 'n')
        {
            gobblyFile << theLowCharStrings.convertN;
            cout << theLowCharStrings.convertN;
        }
        if (theOriginalGettyButInLetters[counter] == 'o')
        {
            gobblyFile << theLowCharStrings.convertO;
            cout << theLowCharStrings.convertO;
        }
        if (theOriginalGettyButInLetters[counter] == 'p')
        {
            gobblyFile << theLowCharStrings.convertP;
            cout << theLowCharStrings.convertP;
        }
        if (theOriginalGettyButInLetters[counter] == 'q')
        {
            gobblyFile << theLowCharStrings.convertQ;
            cout << theLowCharStrings.convertQ;
        }
        if (theOriginalGettyButInLetters[counter] == 'r')
        {
            gobblyFile << theLowCharStrings.convertR;
            cout << theLowCharStrings.convertR;
        }
        if (theOriginalGettyButInLetters[counter] == 's')
        {
            gobblyFile << theLowCharStrings.convertS;
            cout << theLowCharStrings.convertS;
        }
        if (theOriginalGettyButInLetters[counter] == 't')
        {
            gobblyFile << theLowCharStrings.convertT;
            cout << theLowCharStrings.convertT;
        }
        if (theOriginalGettyButInLetters[counter] == 'u')
        {
            gobblyFile << theLowCharStrings.convertU;
            cout << theLowCharStrings.convertU;
        }
        if (theOriginalGettyButInLetters[counter] == 'v')
        {
            gobblyFile << theLowCharStrings.convertV;
            cout << theLowCharStrings.convertV;
        }
        if (theOriginalGettyButInLetters[counter] == 'w')
        {
            gobblyFile << theLowCharStrings.convertW;
            cout << theLowCharStrings.convertW;
        }
        if (theOriginalGettyButInLetters[counter] == 'x')
        {
            gobblyFile << theLowCharStrings.convertX;
            cout << theLowCharStrings.convertX;
        }
        if (theOriginalGettyButInLetters[counter] == 'y')
        {
            gobblyFile << theLowCharStrings.convertY;
            cout << theLowCharStrings.convertY;
        }
        if (theOriginalGettyButInLetters[counter] == 'z')
        {
            gobblyFile << theLowCharStrings.convertZ;
            cout << theLowCharStrings.convertZ;
        }

        if (theOriginalGettyButInLetters[counter] == ',')//This is where the weird char starts.
        {
            gobblyFile << theWeirdCharStrings.convertPsik;
            cout << theWeirdCharStrings.convertPsik;
        }
        if (theOriginalGettyButInLetters[counter] == '.')
        {
            gobblyFile << theWeirdCharStrings.convertTotshka;
            cout << theWeirdCharStrings.convertTotshka;
        }
        if (theOriginalGettyButInLetters[counter] == '-')
        {
            gobblyFile << theWeirdCharStrings.convertDas;
            cout << theWeirdCharStrings.convertDas;
        }
        if (theOriginalGettyButInLetters[counter] == ' ')
        {
            gobblyFile << theWeirdCharStrings.convertSpace;
            cout << theWeirdCharStrings.convertSpace;
        }

        if (theOriginalGettyButInLetters[counter] == 'A')//This is where the High Case starts.
        {
            gobblyFile << theHighCharStrings.convertA;
            cout << theHighCharStrings.convertA;
        }
        if (theOriginalGettyButInLetters[counter] == 'B')
        {
            gobblyFile << theHighCharStrings.convertB;
            cout << theHighCharStrings.convertB;
        }
        if (theOriginalGettyButInLetters[counter] == 'C')
        {
            gobblyFile << theHighCharStrings.convertC;
            cout << theHighCharStrings.convertC;
        }
        if (theOriginalGettyButInLetters[counter] == 'D')
        {
            gobblyFile << theHighCharStrings.convertD;
            cout << theHighCharStrings.convertD;
        }
        if (theOriginalGettyButInLetters[counter] == 'E')
        {
            gobblyFile << theHighCharStrings.convertE;
            cout << theHighCharStrings.convertE;
        }
        if (theOriginalGettyButInLetters[counter] == 'F')
        {
            gobblyFile << theHighCharStrings.convertF;
            cout << theHighCharStrings.convertF;
        }
        if (theOriginalGettyButInLetters[counter] == 'G')
        {
            gobblyFile << theHighCharStrings.convertG;
            cout << theHighCharStrings.convertG;
        }
        if (theOriginalGettyButInLetters[counter] == 'H')
        {
            gobblyFile << theHighCharStrings.convertH;
            cout << theHighCharStrings.convertH;
        }
        if (theOriginalGettyButInLetters[counter] == 'I')
        {
            gobblyFile << theHighCharStrings.convertI;
            cout << theHighCharStrings.convertI;
        }
        if (theOriginalGettyButInLetters[counter] == 'J')
        {
            gobblyFile << theHighCharStrings.convertJ;
            cout << theHighCharStrings.convertJ;
        }
        if (theOriginalGettyButInLetters[counter] == 'K')
        {
            gobblyFile << theHighCharStrings.convertK;
            cout << theHighCharStrings.convertK;
        }
        if (theOriginalGettyButInLetters[counter] == 'L')
        {
            gobblyFile << theHighCharStrings.convertL;
            cout << theHighCharStrings.convertL;
        }
        if (theOriginalGettyButInLetters[counter] == 'M')
        {
            gobblyFile << theHighCharStrings.convertM;
            cout << theHighCharStrings.convertM;
        }
        if (theOriginalGettyButInLetters[counter] == 'N')
        {
            gobblyFile << theHighCharStrings.convertN;
            cout << theHighCharStrings.convertN;
        }
        if (theOriginalGettyButInLetters[counter] == 'O')
        {
            gobblyFile << theHighCharStrings.convertO;
            cout << theHighCharStrings.convertO;
        }
        if (theOriginalGettyButInLetters[counter] == 'P')
        {
            gobblyFile << theHighCharStrings.convertP;
            cout << theHighCharStrings.convertP;
        }
        if (theOriginalGettyButInLetters[counter] == 'Q')
        {
            gobblyFile << theHighCharStrings.convertQ;
            cout << theHighCharStrings.convertQ;
        }
        if (theOriginalGettyButInLetters[counter] == 'R')
        {
            gobblyFile << theHighCharStrings.convertR;
            cout << theHighCharStrings.convertR;
        }
        if (theOriginalGettyButInLetters[counter] == 'S')
        {
            gobblyFile << theHighCharStrings.convertS;
            cout << theHighCharStrings.convertS;
        }
        if (theOriginalGettyButInLetters[counter] == 'T')
        {
            gobblyFile << theHighCharStrings.convertT;
            cout << theHighCharStrings.convertT;
        }
        if (theOriginalGettyButInLetters[counter] == 'U')
        {
            gobblyFile << theHighCharStrings.convertU;
            cout << theHighCharStrings.convertU;
        }
        if (theOriginalGettyButInLetters[counter] == 'V')
        {
            gobblyFile << theHighCharStrings.convertV;
            cout << theHighCharStrings.convertV;
        }
        if (theOriginalGettyButInLetters[counter] == 'W')
        {
            gobblyFile << theHighCharStrings.convertW;
            cout << theHighCharStrings.convertW;
        }
        if (theOriginalGettyButInLetters[counter] == 'X')
        {
            gobblyFile << theHighCharStrings.convertX;
            cout << theHighCharStrings.convertX;
        }
        if (theOriginalGettyButInLetters[counter] == 'Y')
        {
            gobblyFile << theHighCharStrings.convertY;
            cout << theHighCharStrings.convertY;
        }
        if (theOriginalGettyButInLetters[counter] == 'Z')
        {
            gobblyFile << theHighCharStrings.convertZ;
            cout << theHighCharStrings.convertZ;
        }
        counter++;
        numOfEncryption++;
    }
    gobblyFile.close();
    cout << endl << endl << endl << "\tNum of encryption done: " << numOfEncryption << "." << endl << endl;
    cout << "Scary stuff huh? Look up Neverhood Theme on the web. Its from an old point-and-click adventure game from the 90's. The best thing about the game is it's music composer Terry S. Taylor. The game is filled with this crazy soundtracks.";




    cout <<"\n\n\n\n..." << numOfTest;
    return 0;
}

