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
void AllAttributes();

int main(int nNumberofArgs, char* pszArgs[]){

    cout << "The rolled dice results were:" << endl;

    // Initialize pseudo-random seed
    srand(time(NULL));

    AllAttributes();

    // wait until user is ready before terminating program
    // to allow the user to see the program results
    cout << "\nPress ENTER to continue..." << endl;
    cin.ignore(10, '\n');
    cin.get();
    return 0;
}

// Roll a die with 'nSides' amount of sides when called
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

    // Declare array for storing DiceRoller() results
    int nRollResult[nRolls];

    // Performs 'nRolls' and stores the results into nRollResult
    for(int nTimesRolled = 0; nTimesRolled < nRolls; nTimesRolled++){
        nRollResult[nTimesRolled] = DiceRoller(nDiceSides);
    }

    // Find the lowest roll result, value is always at least 'nDiceSides'
    for(int i = 0; i < nRolls; i++){
        if(nRollResult[i] < nLowestRoll){
            nLowestRoll = nRollResult[i];
        }
    }

    // Calculate the sum of the rolls and subtract the lowest roll
    nRollSum = nRollResult[0] + nRollResult[1] + nRollResult[2] + nRollResult[3] - nLowestRoll;

    // Debug print roll results
    cout << nRollResult[0] << ", "
         << nRollResult[1] << ", "
         << nRollResult[2] << ", "
         << nRollResult[3] << endl;
    return nRollSum;
}

// Prints the characters basic abilities
void AllAttributes(){
    int nStrength, nDexterity, nConstitution, nVigilance, nWillpower, nCharisma, nPointTotal;

    nStrength = AttributeValue();
    nDexterity = AttributeValue();
    nConstitution = AttributeValue();
    nVigilance = AttributeValue();
    nWillpower = AttributeValue();
    nCharisma = AttributeValue();
    nPointTotal = nStrength + nDexterity + nConstitution + nVigilance + nWillpower + nCharisma;

    cout
    <<  "\nThe character has a total of " << nPointTotal << " attribute points." << '\n'
    <<  "Strength:     " << nStrength << '\n'
    <<  "Dexterity:    " << nDexterity << '\n'
    <<  "Constitution: " << nConstitution << '\n'
    <<  "Vigilance:    " << nVigilance << '\n'
    <<  "Willpower:    " << nWillpower << '\n'
    <<  "Charisma:     " << nCharisma << endl;

    return;
}
