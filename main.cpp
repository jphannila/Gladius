#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iterator>
#include <iostream>
using namespace std;

// Declaring functions
int DiceRoller(int);
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

// Roll a die with specified amount of sides when called
int DiceRoller(int nSides){
    int nRollResult = rand() % nSides + 1;
    return nRollResult;
}

// Returns the sum of the three highest rolls of four d6 rolls
int AttributeValue(){

    // Declare variables
    int nRollSum;
    int nDiceSides = 6;
    int nRolls = 4;
    int nLowestRoll = nDiceSides;

    // Declare array for dice roll results
    int nRollResult[nRolls];

    // Performs 'nRolls' and stores the results into nRollResult
    for(int nTimesRolled = 0; nTimesRolled < nRolls; nTimesRolled++){
        nRollResult[nTimesRolled] = DiceRoller(nDiceSides);
    }

    // Search the nRollResult array for the lowest roll result
    for(int i = 0; i < nRolls; i++){
        if(nRollResult[i] < nLowestRoll){
            nLowestRoll = nRollResult[i];
        }
    }

    nRollSum = nRollResult[0] + nRollResult[1] + nRollResult[2] + nRollResult[3] - nLowestRoll;

    // Debug print roll results
    cout << nRollResult[0] << ", "
         << nRollResult[1] << ", "
         << nRollResult[2] << ", "
         << nRollResult[3] << endl;
    return nRollSum;
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
