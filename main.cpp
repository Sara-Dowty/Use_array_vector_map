/*CS360 Object Orientation C++
*Instructor: Tim Harrison
 *Author: Sara Dowty
 * Last updated: April 4, 2025
 */

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <cctype> //used for tolower

using namespace std;

//Declarations
array<string, 3> arr_string = {"The quick brown fox jumps over the lazy dog.",
    "The fox is quick and the dog is lazy.",
    "Is the quick fox faster than the lazy dog?"}; //Creates an array
vector<string> words; //Creates a vector to store words
map<string, int> word_ct_map; //Creates a map to count words

//add words from string in array to vector as string
void add_words() {
    for (int i = 0; i < arr_string.size(); i++) {
        stringstream ss(arr_string[i]);
        string word;
        //splitting the sentence into words then adding to word vector
        while (ss >> word) {
            //removing punctuation in the front of and behind each word
            word.erase(0, word.find_first_not_of(".,?!;:"));
            word.erase(word.find_last_not_of(".,?!;:") +1);
            //adding word to the vector
            if (!word.empty()) {
                words.push_back(word);
                //cout << word << endl; //DEBUG STATEMENT
            }
        }
    }
}

//transfer words tolowercase for easy comparison
string words_tolowercase(const string &s) {
    string lower_word = s; //for easy comparison
    transform(lower_word.begin(), lower_word.end(), lower_word.begin(), ::tolower);
    return lower_word;
}

//add words to map without duplicating & counting words
void add_words_to_map() {
    for (const string &word : words) {
        //converting word to lowercase
        string lower_word = words_tolowercase(word);
        //incrementing to count word to add to the map.
        word_ct_map[lower_word]++;
    }
}

//using words from vector create a map to print map
void print_words() {
    //looping map to print each word with the count.
    for (const auto& pair : word_ct_map) {
            cout << pair.first << " " << pair.second << endl;
    }
}

int main() {
    /*for (int i = 0; i < 3; i++) {
        cout << arr_string[i] << endl;
    } DEBUG STATEMENT*/
    //Using a function to add words from array to the vector.
    add_words();
    //using function to add words
    add_words_to_map();
    //printing words and count from the map
    print_words();
    return 0;
}
