#include <string>
#include <iostream>
using namespace std;

int main(){
    string word1, word2, word3;
    string sentence;

    cout << "Enter the first word: ";
    cin >> word1;

    cout << "Enter the second word: ";
    cin >> word2;

    cout << "Enter the third word: ";
    cin >> word3;

    sentence = word1 + " " + word2 + " " + word3 + ".";
    cout << sentence << endl;

    cout << "Length of first word: " << word1.length() << endl;
    cout << "Length of second word: " << word2.length() << endl;
    cout << "Length of third word: " << word3.length() << endl;
    cout << "Length of sentence: " << sentence.length() << endl;

    string sentence2 = sentence;

    if(sentence2.length() >= 12) {
        sentence2.replace(9, 3, "xxx");
    }

    cout << "Sentence 1: " << sentence << endl;
    cout << "Sentence 2: " << sentence2 << endl;


    string sentence_start;

    if(sentence.length() >= 5){
        sentence_start = sentence.substr(0, 5);
    }
    else{
        sentence_start = sentence;
    }

    cout << "Sentence 1: " << sentence << endl;
    cout << "Sentence start: " << sentence_start << endl;
}