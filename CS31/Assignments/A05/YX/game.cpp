#include <iostream>
#include <cstring>
#include "utilities.h"
using namespace std;

int playOneRound (const char words[][7], int nWords, int wordnum); // play one round of the game
bool in_array (const char array[][7], int n, char element[]); //test that the word is in the array
void gold_silver (const char old_hidden[], const char old_probe[]); //count the number of gold and silver


// play one round of the game
int playOneRound(const char words[][7], int nWords, int wordnum) {
    char hidden[7];
    strcpy(hidden, words[wordnum]);
    char probe[10000];
    int try_time = 1;
    
    //guess and feedback
    while (true) {
        cout << "Probe word: ";
        cin >> probe;
        
        bool all_lower = true;
        for (int i = 0; probe[i] != '\0'; i++) {
            if (!islower(probe[i])) {
                all_lower = false;
                break;
            }
        }
        
        if (strlen(probe) < 4 || strlen(probe) > 6 || all_lower == false) {
            cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
        }
    
        else if (!in_array(words, nWords, probe)) {
            cout << "I don't know that word." << endl;
        }
        
        else if (strcmp(probe, hidden) == 0) {
            break;
        }
        
        else {
            gold_silver(hidden, probe);
            try_time ++;
        }
    }
    return try_time;
}


//test that the word is in the array
bool in_array (const char array[][7], int n, char element[]) {
    for (int i = 0; i < n; i++) {
        if (strlen(array[i]) == strlen(element)) {
            int match = 0;
            for (int j = 0; j < strlen(element); j++) {
                if (array[i][j] == element[j]) {
                    match++;
                }
            }
            if (match == strlen(element)) {
                return true;
            }
        }
    }
    return false;
}


//count the number of gold and silver
void gold_silver (const char old_hidden[], const char old_probe[]) {
    char hidden[7];
    char probe[7];
    strcpy(hidden, old_hidden);
    strcpy(probe, old_probe);
    
    //count the number of gold
    int gold_num = 0;
    for (int i = 0; i < strlen(hidden) && i < strlen(probe); i++) {
        if (probe[i] == hidden[i]) {
            gold_num++;
            hidden[i] = '$';
            probe[i] = '#';
        }
    }
    
    //count the number of silver
    int silver_num = 0;
    for (int i = 0; i < strlen(hidden); i++) {
        if (strchr(probe, hidden[i]) != NULL && *strchr(probe, hidden[i]) != '#') {
            silver_num++;
            *strchr(probe, hidden[i]) = '#';
        }
    }
    cout << "Golds: "<< gold_num << ", Silvers: " << silver_num << endl;
}


int main() {
    char wordList[9000][7];
    const char WORDFILENAME[] = "/Users/xyx/Desktop/2022Fall/CS31/Project5/text.txt";
    int nWords = getWords(wordList, 9000, WORDFILENAME);
    
    if (nWords < 1) {
        cout << "No words were loaded, so I can't play the game." << endl;
        return -1;
    }
    
    cout << "How many rounds do you want to play? ";
    int total_round;
    cin >> total_round;
    
    int total_try = 0;
    int minimum = 10000;
    int maximum = 0;
    
    //play n rounds as the user required to
    for (double round = 1; round <= total_round; round++){
        std::cout.precision(0);
        std::cout<<std::fixed;
        cout << endl;
        cout << "Round " << round << endl;
        int wordnum = randInt(0, nWords - 1);
        if (nWords <= 0 || wordnum < 0 || wordnum >= nWords) {
            return -1;
        }
        cout << "The hidden word is " << strlen(wordList[wordnum]) << " letters long." << endl;
        int this_try_time = playOneRound(wordList, nWords, wordnum);
        
        //summeraize the statistics of this round and previous rounds
        if (this_try_time == 1) {
            cout << "You got it in 1 try." << endl;
        }
        else {
            cout << "You got it in " << this_try_time << " tries." << endl;
        }
        
        total_try += this_try_time;
        double average = total_try / round;
        if (this_try_time < minimum) {
            minimum = this_try_time;
        }
        if (this_try_time > maximum) {
            maximum = this_try_time;
        }
        std::cout.precision(2);
        std::cout<<std::fixed;
        cout << "Average: " << average << ", minimum: " << minimum << ", maximum: " << maximum << endl;
    }
}

