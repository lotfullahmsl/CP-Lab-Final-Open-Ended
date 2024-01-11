#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>

using namespace std;

// Function to merge two arrays in ascending order
void AdjustArray(const int arr1[], int size1, const int arr2[], int size2, int AdjustedArray[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            AdjustedArray[k++] = arr1[i++];
        }
        else {
            AdjustedArray[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        AdjustedArray[k++] = arr1[i++];
    }

    while (j < size2) {
        AdjustedArray[k++] = arr2[j++];
    }
}

// Function to find common elements in two arrays
void common_ele(const int arr1[], int size1, const int arr2[], int size2) {
    cout << "Common elements: ";

    int i = 0, j = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            ++i;
            ++j;
        }
        else if (arr1[i] < arr2[j]) {
            ++i;
        }
        else {
            ++j;
        }
    }

    cout << endl;
}

// Function to check if a sentence is a palindrome
bool isPalindrome(const string& sentence) {
    int left = 0;
    int right = sentence.length() - 1;

    while (left < right) {
        if (sentence[left] != sentence[right]) {
            return false;
        }
        ++left;
        --right;
    }

    return true;
}

int main() {
    const int size1 = 5;
    const int size2 = 7;

    int arr1[size1], arr2[size2], mergedArray[size1 + size2];

    // Initialize arrays with user input or random values
    cout << "Enter " << size1 << " integers for the first array \n";
    for (int i = 0; i < size1; ++i) {
        cout << "Enter " << i+1 << " integer: ";   
        cin >> arr1[i];
    }

    cout << "\nEnter " << size2 << " integers for the second array \n";
    for (int i = 0; i < size2; ++i) {
        cout << "Enter " << i + 1 << " integer: ";
        cin >> arr2[i];
    }

    // Merge arrays and display the result
    AdjustArray(arr1, size1, arr2, size2, mergedArray);
    cout << "Merged array in ascending order: ";
    for (int i = 0; i < size1 + size2; ++i) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    // Find and display common elements
    common_ele(arr1, size1, arr2, size2);

    // Check if the input sentence is a palindrome
    string sentence;
    cout << "Enter a sentence to check if it's a palindrome: ";
    cin.ignore(); 
    getline(cin, sentence);

    if (isPalindrome(sentence)) {
        cout << "The sentence is a palindrome.\n";
    }
    else {
        cout << "The sentence is not a palindrome.\n";
    }

    return 0;
}