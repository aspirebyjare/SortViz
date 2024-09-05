# include <iostream>
# include <string> 
# include <vector>
# include <sstream>
# include <limits> 

using namespace std;

// -----------------------------------------------------------------//
// TO-DO List
// -----------------------------------------------------------------//
/*
    -Error checking on user input
        X add elements
            X consider switching to getline method
        // type of sort

    -Format better for multi digit numbers make sure they align with 
     X column
        // considering spaces per number spot(maybe 2/3)
        // however there is a limit on how many X's we can print to 
            make this excercise practical
    
    - MAJOR LOGIC FLAW
        // Currently only prints the same number of columns as the
           size of the array 

    - Function Implementation
        // Still needs print functions
            X insertion
            X selection
    - Ideas
        - condsider implementing sort selection with switch
        - consider different modes
            X show graph
            X just statistics 
            - random choice with user selecting number of elements

*/

// -----------------------------------------------------------------//
// Functions
// -----------------------------------------------------------------//

/// @brief initial print func
/// @param arr 
void printCurrent(vector<int>&arr){
    int n = arr.size();
    for (int i = n; i > 0; i--) {   
        for (int j = 0; j < n; j++) { 
            if (arr[j] > i-1 ){
                cout << " X ";
            }
            else{
                cout << "   ";
            }
        }
        cout<< endl ;
    }
    // -----------------------------------------//
    cout << "_______________\n"
    << " ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << "  ";
    } 
        cout << endl
        << "---------------" << endl;     
    // -----------------------------------------// 
}
/// @brief print func swapping inside algo
/// @param arr array to be printed
/// @param index one of the indexes being swapped
/// @param swapped the other
/// @param swapCnt global counter for final stats
void printCurrent(vector<int>&arr, int index, int swapped, int swapCnt){
    cout << "\n\n\n"
        << "------------------------------\n";
    int n = arr.size();
    for (int i = n; i > 0; i--) {   
        for (int j = 0; j < n; j++) { 
            if (arr[j] > i-1 ){
                cout << " X ";
            }
            else{
                cout << "   ";
            }
        }
        cout<< endl ;
    }
    // -----------------------------------------//
    cout << "_______________\n"
    << " ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << "  ";
    } 
        cout << endl
        << "---------------" << endl;     
    // -----------------------------------------// 
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "------------------------------\n"
    << "SWAP OCCURED at indexes " << index << " and " 
    << swapped << endl
    <<"current count: "
    << swapCnt << endl
    << "------------------------------\n";
}

/// @brief Bubble sort implementation
/// @param arr 
/// @param swapCnt 
void bubbleSort(vector<int>& arr, int &swapCnt, bool seeGraph, int &stepCnt) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {   
        stepCnt ++;
        for (int j = 0; j < n-i-1; j++) {
            stepCnt ++;
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);

                swapCnt ++;
                if(seeGraph){
                    printCurrent(arr, j, j+1, swapCnt);
                }    
 
            }
        }
    }
}

/// @brief Odd Even Sort 
/// @param arr 
/// @param swapCnt 
void oddEvenSort(vector<int>& arr, int &swapCnt, bool seeGraph, int &stepCnt) {
    int n = arr.size();
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;

        // Odd phase
        for (int i = 1; i <= n-2; i = i+2) {
            stepCnt ++;
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                isSorted = false;

                swapCnt ++;
                if(seeGraph){
                printCurrent(arr, i, i+1,swapCnt);
                }
            }
        }

        // Even phase
        for (int i = 0; i <= n-2; i = i+2) {
            stepCnt ++;
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                isSorted = false;

                swapCnt ++;
                if(seeGraph){
                printCurrent(arr, i, i+1, swapCnt);
                }
            }
        }
    }
}

/// @brief Insertion Sort 
/// @param arr 
/// @param swapCnt 
void insertionSort(vector<int>& arr, int &swapCnt, bool seeGraph, int &stepCnt) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        stepCnt ++;
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            stepCnt ++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        swapCnt ++;
        if(seeGraph){
            printCurrent(arr, j+1, j, swapCnt);
        }
    }
}
/// @brief Selection Sort
/// @param arr 
/// @param swapCnt 
void selectionSort(vector<int>& arr, int &swapCnt, bool seeGraph, int &stepCnt) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        stepCnt ++;
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            stepCnt ++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        swap(arr[min_idx], arr[i]);

        swapCnt ++;
        if(seeGraph){
            printCurrent(arr, min_idx, i, swapCnt);
        }
    }
}

// -----------------------------------------------------------------//
// Main
// -----------------------------------------------------------------//
int main() {
    int swapCnt = 0;
    int arrSize = 0;
    vector<int> arr;
    int stepCnt = 0;
    /*add elements*/
    bool userDone = false;
    string inputLine;
    int number;
    char yesOrNo = 'y';
    /*Type of Sort?*/
    bool validChoice = false;
    int userChoice = 0;
    /*See graph?*/
    bool seeGraph = true;
    /*Sorted Result */
    float fArraySize = 0.0;
    
    /*add elements*/
    while (!userDone) {
        cout << "Enter the elements you would like to add to your array,"
            << " separated by spaces:\n"
            << "(hit enter when finished)\n";

        getline(cin, inputLine); // Read the entire line
        stringstream ss(inputLine); // Use stringstream to process the line

        arr.clear(); // Clear any previous values in the array

        bool invalidInput = false;
        while (ss >> number) { // Attempt to extract each number
            arr.push_back(number); // Add the number to the array
        }
        
        // Check if extraction failed and not at end of file
        if (ss.fail() && !ss.eof()) { 
            cout << "Invalid input detected. Please enter only numbers"
            <<", separated by spaces:\n";
            ss.clear(); // Clear error flags
            invalidInput = true;
        }

        if (invalidInput) {
            continue; // Skip the rest of the loop and start over
        }

        cout << "Would you like to add more? (y/n)\n";
        cin >> yesOrNo;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        if (yesOrNo == 'y') {
            userDone = false;
        } else if (yesOrNo == 'n') {
            userDone = true;
        } else {
            cout << "Invalid choice. Please enter 'y' or 'n'.\n";
            userDone = false; // Assume user wants to continue if invalid input
        }
    }
    // -----------------------------------------//
    // Initial Array
    // -----------------------------------------//
    cout << "******************************\n"
        << "     Your Initial Array:\n" 
        << "******************************\n";
    printCurrent(arr);
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    // -----------------------------------------//

    /*Type of Sort?*/
    while (!validChoice) {
        arrSize = arr.size();
        cout << "Enter what kind of sort do you want to perform:\n"
            << "0 | Bubble Sort \n"
            << "1 | Odd Even Sort \n"
            << "2 | Insertion Sort \n"
            << "3 | Selection Sort \n";
        cin >> userChoice;

        /*See graph?*/
        cout << "Would you like to see graphs? (y/n)\n";
        cin >> yesOrNo;
        seeGraph = (yesOrNo == 'y');

        switch (userChoice) {
            case 0:
                bubbleSort(arr, swapCnt, seeGraph, stepCnt);
                validChoice = true;
                break;
            case 1:
                oddEvenSort(arr, swapCnt, seeGraph, stepCnt);
                validChoice = true;
                break;
            case 2:
                insertionSort(arr, swapCnt, seeGraph, stepCnt);
                validChoice = true;
                break;
            case 3:
                selectionSort(arr, swapCnt, seeGraph, stepCnt);
                validChoice = true;
                break;
            default:
                cout << "\nInvalid choice for sort selection." 
                << "Please enter a number between 0 and 3.\n\n";
                break;
        }
    }
    
    
    /*Sorted Result          */
    cout << "************************************************************\n"
        << "       Sorted Array:\n" 
        << "************************************************************\n";

    cout << endl;
    printCurrent(arr);
    fArraySize = arrSize;
    cout << "Total Elements Input: " << arrSize << endl
        << "Total Swaps: " << swapCnt << "\n"
        << "Total Steps Taken: " << stepCnt << endl
        << "Swap to Input Ratio: " << swapCnt / fArraySize 
        << endl << "Steps to Input Ratio: " << stepCnt / fArraySize
        << endl << "ps. lower is better! ;)\n"
        << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    
    return 0;
}

    // print loop
    //for (int i = 0; i < arr.size(); i++) {
    //    cout << arr[i] << " ";
    //}


