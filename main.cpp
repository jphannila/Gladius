#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iterator>
#include <iostream>
using namespace std;

// Declaring functions
int DiceRoller(int&, int);
int AttributeValue();
void CharactersAttributes();

int main(int nNumberofArgs, char* pszArgs[]){

    // Initialize pseudo-random seed
    srand(time(NULL));

    CharactersAttributes();

    // wait until user is ready before terminating program
    // to allow the user to see the program results
    cout << "Press ENTER to continue..." << endl;
    cin.ignore(10, '\n');
    cin.get();
    return 0;
}

// Prints the characters basic abilities
void CharactersAttributes(){
    int nStrength, nDexterity, nConstitution, nVigilance, nWillpower, nCharisma, nPointTotal, nAverage;

    nStrength = AttributeValue();
    nDexterity = AttributeValue();
    nConstitution = AttributeValue();
    nVigilance = AttributeValue();
    nWillpower = AttributeValue();
    nCharisma = AttributeValue();
    nPointTotal = nStrength + nDexterity + nConstitution + nVigilance + nWillpower + nCharisma;
    nAverage = nPointTotal / 6;

    cout
    <<  "Character has a total of " << nPointTotal << " points." << '\n'
    <<  "With an average of " << nAverage << " per attribute." << '\n' << '\n'
    <<  "Strength:     " << nStrength << '\n'
    <<  "Dexterity:    " << nDexterity << '\n'
    <<  "Constitution: " << nConstitution << '\n'
    <<  "Vigilance:    " << nVigilance << '\n'
    <<  "Willpower:    " << nWillpower << '\n'
    <<  "Charisma:     " << nCharisma << endl;

    return;
}

// Roll a die with specified amount of sides when called
int DiceRoller(int& nRollResult,int nSides){
    nRollResult = rand() % nSides + 1;
    return nRollResult;
}

// AttributeValue returns the sum of three highest rolls of 4D6 dice rolls
int AttributeValue(){

    // Declare variables
    int nAttributeValue, nNumberRolled, nDieSize, nRolls;
    nDieSize = 6;
    nRolls = 3;
    nAttributeValue = 0;

    // Performs 'nRolls' and sums the results into nAttributeValue
    for(int nTimesRolled = 0; nTimesRolled < nRolls; nTimesRolled++){
        DiceRoller(nNumberRolled, nDieSize);
        nAttributeValue += nNumberRolled;
    }

    return nAttributeValue;
}
