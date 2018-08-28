 /*

Bogdan Gordin
5/5/17
Hwrk12B: File Decrypter

Below are notes:

    *First, display on the screen the un-decrypted version,
     followed by the fully decrypted version.

    *It should appear exactly like your original source
     document, Gettysburg.txt.

*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

struct AlphabetLowChars
{
    char bringBackA = 'a';
    char bringBackB = 'b';
    char bringBackC = 'c';
    char bringBackD = 'd';
    char bringBackE = 'e';
    char bringBackF = 'f';
    char bringBackG = 'g';
    char bringBackH = 'h';
    char bringBackI = 'i';
    char bringBackJ = 'j';
    char bringBackK = 'k';
    char bringBackL = 'l';
    char bringBackM = 'm';
    char bringBackN = 'n';
    char bringBackO = 'o';
    char bringBackP = 'p';
    char bringBackQ = 'q';
    char bringBackR = 'r';
    char bringBackS = 's';
    char bringBackT = 't';
    char bringBackU = 'u';
    char bringBackV = 'v';
    char bringBackW = 'w';
    char bringBackX = 'x';
    char bringBackY = 'y';
    char bringBackZ = 'z';
};
struct AlphabetWeirdChars
{
    char bringBackPsik = ',';
    char bringBackTotshka = '.';
    char bringBackDash = '-';
    char bringBackSpace = ' ';
};
struct AlphabetHighChars
{
    char bringBackA = 'A';
    char bringBackB = 'B';
    char bringBackC = 'C';
    char bringBackD = 'D';
    char bringBackE = 'E';
    char bringBackF = 'F';
    char bringBackG = 'G';
    char bringBackH = 'H';
    char bringBackI = 'I';
    char bringBackJ = 'J';
    char bringBackK = 'K';
    char bringBackL = 'L';
    char bringBackM = 'M';
    char bringBackN = 'N';
    char bringBackO = 'O';
    char bringBackP = 'P';
    char bringBackQ = 'Q';
    char bringBackR = 'R';
    char bringBackS = 'S';
    char bringBackT = 'T';
    char bringBackU = 'U';
    char bringBackV = 'V';
    char bringBackW = 'W';
    char bringBackX = 'X';
    char bringBackY = 'Y';
    char bringBackZ = 'Z';
};
struct LyricsStringsLowChar
{
    string convertA = "contemplating klayman";
    string convertB = "the neverhood";
    string convertC = "clitton klatton klogg";
    string convertD = "they join crit unit b";
    string convertE = "we behold its hoborg";
    string convertF = "oh what the hey";
    string convertG = "big robot bill is odd";
    string convertH = "crit unit a";
    string convertI = "the clock work beast";
    string convertJ = "that frenchy frenchy gee";
    string convertK = "and frenchy guy";
    string convertL = "cccc clockwork beast";
    string convertM = "and with them";
    string convertN = "ha ha ha ha hoborg";
    string convertO = "hard to see crit unit a";
    string convertP = "kkkk klogg";
    string convertQ = "oh what a day";
    string convertR = "kkkk klayman";
    string convertS = "he joins unit b";
    string convertT = "the frenchy guy is with them honestly";
    string convertU = "whats it oh its hoborg";
    string convertV = "klayman shuffle";
    string convertW = "everybody way oh";
    string convertX = "homina";
    string convertY = "dum da dum doi doi";
    string convertZ = "southern front porch whistle";
};
struct LyricsStringsHighChar
{
    string convertA = "CONTEMPLATING KLAYMAN";
    string convertB = "THE NEVERHOOD";
    string convertC = "CLITTON KLATTON KLOGG";
    string convertD = "THEY JOIN CRIT UNIT B";
    string convertE = "WE BEHOLD ITS HOBORG";
    string convertF = "OH WHAT THE HEY";
    string convertG = "BIG ROBOT BILL IS ODD";
    string convertH = "CRIT UNIT A";
    string convertI = "THE CLOCK WORK BEAST";
    string convertJ = "THAT FRENCHY FRENCHY GEE";
    string convertK = "AND FRENCHY GUY";
    string convertL = "CCCC CLOCKWORK BEAST";
    string convertM = "AND WITH THEM";
    string convertN = "HA HA HA HA HOBORG";
    string convertO = "HARD TO SEE CRIT UNIT A";
    string convertP = "KKKK KLOGG";
    string convertQ = "OH WHAT A DAY";
    string convertR = "KKKK KLAYMAN";
    string convertS = "HE JOINS UNIT B";
    string convertT = "THE FRENCHY GUY IS WITH THEM HONESTLY";
    string convertU = "WHATS IT OH ITS HOBORG";
    string convertV = "KLAYMAN SHUFFLE";
    string convertW = "EVERYBODY WAY OH";
    string convertX = "HOMINA";
    string convertY = "DUM DA DUM DOI DOI";
    string convertZ = "SOUTHERN FRONT PORCH WHISTLE";
};
struct LyricsStringsWeirdChar
{
    string convertPsik = "`";
    string convertTotshka = "+";
    string convertSpace = "_";
    string convertDas = "~";
};

int counter = 0;
string tempWord;
char tempLetter;
int numOfWords;
int numOfLetters;
int numOfDecryption;
char theDecryptedGook[1471];
int numOfTest;
int decryptionCounter;


int main()
{
    cout << endl << endl << "\tHey there. Welcome to Bogdan's Gordin file Decrypter." << endl << endl;
    AlphabetLowChars theLowChar;
    AlphabetHighChars theHighChar;
    AlphabetWeirdChars theWeirdChar;
    LyricsStringsLowChar theLowCharStrings;
    LyricsStringsHighChar theHighCharStrings;
    LyricsStringsWeirdChar theWeirdCharStrings;

    cout << "Here is the encrypted file: (Hit Enter)";
    cin.get();
    cout << endl << endl << endl;
    ifstream gobblyFile;

    gobblyFile.open("Gobblygook.txt");

    if(!gobblyFile)//This is in case the file is not there.
    {
        cout << "Oops. Could not open." << endl;
        cout << "\tI am out of here." <<  endl;
        cout <<"\n\n\n\n...";
        return 0;
    }

    while(!gobblyFile.eof())//To count the words in the gook text.
    {
        gobblyFile >> tempWord;
        cout << tempWord << " ";
        counter++;
    }
    tempWord = "";
    numOfWords = counter;
    string theNonesenseGookStrings[counter];
    counter = 0;
    gobblyFile.close();

    gobblyFile.open("Gobblygook.txt");
    while(!gobblyFile.eof())//To save the gook in string array.
    {
        gobblyFile >> theNonesenseGookStrings[counter];
        counter++;
    }
    counter = 0;
    gobblyFile.close();

    gobblyFile.open("Gobblygook.txt");
    while(!gobblyFile.eof())//To count the letters.
    {
        gobblyFile >> std::noskipws >> tempLetter;
        counter++;
    }
    char theNonesenseGookChars[counter];
    numOfLetters = counter;
    counter = 0;
    gobblyFile.close();

    gobblyFile.open("Gobblygook.txt");
    while(!gobblyFile.eof())//To save the letters in the char array.
    {
        gobblyFile >> std::noskipws >> theNonesenseGookChars[counter];
        counter++;
    }
    counter = 0;
    gobblyFile.close();

    cout << endl << endl << endl << "\tThere are " << numOfWords << " words." << "\tAnd there are " << numOfLetters << " letters." << endl << endl;
    cout << "Ready to see the decryption? This will be fast. No text file will be created.";
    cin.get();
    cout << "\tOK!" << endl << endl << endl;

    while (numOfWords > counter)//The decryption
    {
        if(theNonesenseGookStrings[counter] == "contemplating" && theNonesenseGookStrings[++counter] == "glinka")//The low strings.
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackA;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "the" && theNonesenseGookStrings[++counter] == "neverhood")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackB;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "clitton" && theNonesenseGookStrings[++counter] == "klatton" && theNonesenseGookStrings[++counter] == "klogg")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackC;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "they" && theNonesenseGookStrings[++counter] == "join" && theNonesenseGookStrings[++counter] == "crit" && theNonesenseGookStrings[++counter] == "unit" && theNonesenseGookStrings[++counter] == "b")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackD;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "we" && theNonesenseGookStrings[++counter] == "behold" && theNonesenseGookStrings[++counter] == "its" && theNonesenseGookStrings[++counter] == "hoborg")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackE;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "oh" && theNonesenseGookStrings[++counter] == "what" && theNonesenseGookStrings[++counter] == "the" && theNonesenseGookStrings[++counter] == "hey")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackF;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "large" && theNonesenseGookStrings[++counter] == "robot" && theNonesenseGookStrings[++counter] == "bill" && theNonesenseGookStrings[++counter] == "cornholio" && theNonesenseGookStrings[++counter] == "odd")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackG;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "crit" && theNonesenseGookStrings[++counter] == "unit" && theNonesenseGookStrings[++counter] == "spaghetti")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackH;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "lol" && theNonesenseGookStrings[++counter] == "clock" && theNonesenseGookStrings[++counter] == "ticking" && theNonesenseGookStrings[++counter] == "bogdan")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackI;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "the" && theNonesenseGookStrings[++counter] == "frenchy" && theNonesenseGookStrings[++counter] == "frenchy" && theNonesenseGookStrings[++counter] == "gee")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackJ;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "and" && theNonesenseGookStrings[++counter] == "frenchy" && theNonesenseGookStrings[++counter] == "guy")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackK;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "cccc" && theNonesenseGookStrings[++counter] == "clockwork" && theNonesenseGookStrings[++counter] == "beast")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackL;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "thus" && theNonesenseGookStrings[++counter] == "with" && theNonesenseGookStrings[++counter] == "them")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackM;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "ugh" && theNonesenseGookStrings[++counter] == "my" && theNonesenseGookStrings[++counter] == "this" && theNonesenseGookStrings[++counter] == "sucks" && theNonesenseGookStrings[++counter] == "hoborg")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackN;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "hard" && theNonesenseGookStrings[++counter] == "to" && theNonesenseGookStrings[++counter] == "see" && theNonesenseGookStrings[++counter] == "mom")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackO;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "kekekeke" && theNonesenseGookStrings[++counter] == "kiril")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackP;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "hmm" && theNonesenseGookStrings[++counter] == "what" && theNonesenseGookStrings[++counter] == "day" && theNonesenseGookStrings[++counter] == "is")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackQ;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "wow" && theNonesenseGookStrings[++counter] == "nasa")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackR;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "he" && theNonesenseGookStrings[++counter] == "joins" && theNonesenseGookStrings[++counter] == "unit" && theNonesenseGookStrings[++counter] == "b")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackS;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "man" && theNonesenseGookStrings[++counter] == "frenchy" && theNonesenseGookStrings[++counter] == "pal" && theNonesenseGookStrings[++counter] == "is" && theNonesenseGookStrings[++counter] == "with"  && theNonesenseGookStrings[++counter] == "damn" && theNonesenseGookStrings[++counter] == "honestly")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackT;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "whats" && theNonesenseGookStrings[++counter] == "it" && theNonesenseGookStrings[++counter] == "oh" && theNonesenseGookStrings[++counter] == "its" && theNonesenseGookStrings[++counter] == "hoborg")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackU;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "klayman" && theNonesenseGookStrings[++counter] == "shuffle")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackV;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "everybody" && theNonesenseGookStrings[++counter] == "way" && theNonesenseGookStrings[++counter] == "ohhh")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackW;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "dum" && theNonesenseGookStrings[++counter] == "da" && theNonesenseGookStrings[++counter] == "dum" && theNonesenseGookStrings[++counter] == "doi" && theNonesenseGookStrings[++counter] == "doi")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackY;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "homina")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackX;
            cout << theDecryptedGook[decryptionCounter];
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "southern" && theNonesenseGookStrings[++counter] == "front" && theNonesenseGookStrings[++counter] == "porch" && theNonesenseGookStrings[++counter] == "whistle")
        {
            theDecryptedGook[decryptionCounter] = theLowChar.bringBackZ;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "_")//the weird strings
        {
            theDecryptedGook[decryptionCounter] = theWeirdChar.bringBackSpace;
            cout << theDecryptedGook[decryptionCounter];
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "~")
        {
            theDecryptedGook[decryptionCounter] = theWeirdChar.bringBackDash;
            cout << theDecryptedGook[decryptionCounter];
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "`")
        {
            theDecryptedGook[decryptionCounter] = theWeirdChar.bringBackPsik;
            cout << theDecryptedGook[decryptionCounter];
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "+")
        {
            theDecryptedGook[decryptionCounter] = theWeirdChar.bringBackTotshka;
            cout << theDecryptedGook[decryptionCounter];
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "CONTEMPLATING" && theNonesenseGookStrings[++counter] == "GLINKA")//The high strings.
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackA;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "THE" && theNonesenseGookStrings[++counter] == "NEVERHOOD")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackB;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "CLITTON" && theNonesenseGookStrings[++counter] == "KLATTON" && theNonesenseGookStrings[++counter] == "KLOGG")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackC;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "THEY" && theNonesenseGookStrings[++counter] == "JOIN" && theNonesenseGookStrings[++counter] == "CRIT" && theNonesenseGookStrings[++counter] == "UNIT" && theNonesenseGookStrings[++counter] == "B")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackD;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "WE" && theNonesenseGookStrings[++counter] == "BEHOLD" && theNonesenseGookStrings[++counter] == "ITS" && theNonesenseGookStrings[++counter] == "HOBORG")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackE;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "OH" && theNonesenseGookStrings[++counter] == "WHAT" && theNonesenseGookStrings[++counter] == "THE" && theNonesenseGookStrings[++counter] == "HEY")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackF;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "LARGE" && theNonesenseGookStrings[++counter] == "ROBOT" && theNonesenseGookStrings[++counter] == "BILL" && theNonesenseGookStrings[++counter] == "IS" && theNonesenseGookStrings[++counter] == "ODD")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackG;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "CRIT" && theNonesenseGookStrings[++counter] == "UNIT" && theNonesenseGookStrings[++counter] == "SPAGHETTI")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackH;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "LOL" && theNonesenseGookStrings[++counter] == "CLOCK" && theNonesenseGookStrings[++counter] == "TICKING" && theNonesenseGookStrings[++counter] == "BOGDAN")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackI;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "THE" && theNonesenseGookStrings[++counter] == "FRENCHY" && theNonesenseGookStrings[++counter] == "FRENCHY" && theNonesenseGookStrings[++counter] == "GEE")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackJ;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "AND" && theNonesenseGookStrings[++counter] == "FRENCHY" && theNonesenseGookStrings[++counter] == "GUY")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackK;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "CCCC" && theNonesenseGookStrings[++counter] == "CLOCKWORK" && theNonesenseGookStrings[++counter] == "BEAST")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackL;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "THUS" && theNonesenseGookStrings[++counter] == "WITH" && theNonesenseGookStrings[++counter] == "THEM")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackM;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "UGH" && theNonesenseGookStrings[++counter] == "MY" && theNonesenseGookStrings[++counter] == "THIS" && theNonesenseGookStrings[++counter] == "SUCKS" && theNonesenseGookStrings[++counter] == "HOBORG")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackN;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "HARD" && theNonesenseGookStrings[++counter] == "TO" && theNonesenseGookStrings[++counter] == "SEE" && theNonesenseGookStrings[++counter] == "MOM")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackO;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "KEKEKEKE" && theNonesenseGookStrings[++counter] == "KIRIL")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackP;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "HMM" && theNonesenseGookStrings[++counter] == "WHAT" && theNonesenseGookStrings[++counter] == "DAY" && theNonesenseGookStrings[++counter] == "IS")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackQ;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "WOW" && theNonesenseGookStrings[++counter] == "NASA")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackR;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "HE" && theNonesenseGookStrings[++counter] == "JOINS" && theNonesenseGookStrings[++counter] == "UNIT" && theNonesenseGookStrings[++counter] == "B")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackS;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "MAN" && theNonesenseGookStrings[++counter] == "FRENCHY" && theNonesenseGookStrings[++counter] == "PAL" && theNonesenseGookStrings[++counter] == "IS" && theNonesenseGookStrings[++counter] == "WITH"  && theNonesenseGookStrings[++counter] == "DAMN" && theNonesenseGookStrings[++counter] == "HONESTLY")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackT;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "WHATS" && theNonesenseGookStrings[++counter] == "IT" && theNonesenseGookStrings[++counter] == "OH" && theNonesenseGookStrings[++counter] == "ITS" && theNonesenseGookStrings[++counter] == "HOBORG")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackU;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "KLAYMAN" && theNonesenseGookStrings[++counter] == "SHUFFLE")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackV;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "EVERYBODY" && theNonesenseGookStrings[++counter] == "WAY" && theNonesenseGookStrings[++counter] == "OHHH")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackW;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "DUM" && theNonesenseGookStrings[++counter] == "DA" && theNonesenseGookStrings[++counter] == "DUM" && theNonesenseGookStrings[++counter] == "DOI" && theNonesenseGookStrings[++counter] == "DOI")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackY;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "HOMINA")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackX;
            cout << theDecryptedGook[decryptionCounter];
            decryptionCounter++;
        }
        if(theNonesenseGookStrings[counter] == "SOUTHERN" && theNonesenseGookStrings[++counter] == "FRONT" && theNonesenseGookStrings[++counter] == "PORCH" && theNonesenseGookStrings[++counter] == "WHISTLE")
        {
            theDecryptedGook[decryptionCounter] = theHighChar.bringBackZ;
            cout << theDecryptedGook[decryptionCounter];
            counter--;
            counter--;
            counter--;
            decryptionCounter++;
        }
        counter++;
        numOfDecryption++;
    }
    counter = 0;



    cout <<"\n\n\n\n...";
    return 0;
}

