#include <iostream>
#include <string>
using namespace std;

int palindrome(string word1, string word2) {
    // First word
    // Converting string to char array
    int i = word1.length(); // Get the length of the string
    char word11[i + 1]; // Create an array with the length of the string + 1 for null terminator
    strcpy(word11, word1.c_str()); // Function to convert from string to char array
    
    // Reverse array in C++
    char a[i + 1];
    for (int j = i - 1; j >= 0; j--) {
        a[i - 1 - j] = word11[j];
    }
    a[i] = '\0'; // Add null terminator
    
    // Convert from char array to string
    string str(a, i);
    
    // Second word
    int k = word2.length(); // Get the length of the string
    char word111[k + 1]; // Create an array with the length of the string + 1 for null terminator
    strcpy(word111, word2.c_str());
    
    // Reverse array in C++
    char b[k + 1];
    for (int j = k - 1; j >= 0; j--) {
        b[k - 1 - j] = word111[j];
    }
    b[k] = '\0'; // Add null terminator
    
    // Convert from char array to string
    string str2(b, k);
    
    // Compare the two input words and their reverses
    int q = word1.compare(str);
    int w = word2.compare(str2);
    
    // Display results
    cout << "For your first input word" << endl;
    if (q == 0)
        cout << "This word is a palindrome" << endl;
    else
        cout << "This word is not a palindrome" << endl;
    
    cout << "For your second input word" << endl;
    if (w == 0)
        cout << "This word is a palindrome" << endl;
    else
        cout << "This word is not a palindrome" << endl;
    
    return 0;
}

int main() {
    string word1;
    string word2;
    cout << "Input two words that are palindromes or anagrams respectively:" << endl;
    
    cin >> word1;
    cin >> word2;
    
    palindrome(word1, word2);
}