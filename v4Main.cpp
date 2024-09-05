# include <iostream>
# include <string> 
# include <vector>
# include <sstream>
# include <limits> 
# include <unistd.h>
# include <termios.h>

using namespace std;
/*v3- want to stream line !seegraphs version
    - want to add an option to select arrSize and enter random numbers
    X need to fix print to only print rows =< arr.max
Introduced
    - fix to printing empty rows
        new maxVal func that sorts array but doesnt change initial
            to find max val for printing 
    - merge and quick sort adding 
*/



// -----------------------------------------------------------------//
// TO-DO List
// -----------------------------------------------------------------//
/*
    -Error checking on user input

    - MAJOR LOGIC FLAW
        // Currently only prints the same number of columns as the
           size of the array 

    - Function Implementation

    - Ideas
        - condsider implementing sort selection with switch
        - consider different modes
            - random choice with user selecting number of elements
                this is a sort analyzer to see which is more efficient 
                through a series of test.
                    the user will enter
                        - number of tests
                        - number of elements in each test 
                        - will then complete all sorts and display stats at bottom
                        - sum results for different tests and display averages
        -eventually be able generate and read in files for input

    STILL NEED TO FIX:  
                formatting of individual slots
                lines and seperators in prints 
        
// -----------------------------------------------------------------//
// TO-DOING List
// -----------------------------------------------------------------//
    -Format better for multi digit numbers make sure they align with 
     X column
        // considering spaces per number spot(maybe 2/3)
        // however there is a limit on how many X's we can print to 
            make this excercise practical
                - consider limiting digits of number's entered 
                  and limit of total nums
// -----------------------------------------------------------------//
// TO-DONE List
// -----------------------------------------------------------------//
            X show graph
            X just statistics 
    - v1- no printing v2- scaling for printing (div by factor of 10)
            X add elements
            X consider switching to getline method
        X type of sort
*/

// -----------------------------------------------------------------//
// Functions
// -----------------------------------------------------------------//

/// @brief Find maxVal in array without changing original
/// @param arr 
/// @return an integer max Value of sorted array
int maxVal(const vector<int>& arr) {
    vector<int> arrCopy = arr; // Make a copy of the array
    int n = arrCopy.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrCopy[j] > arrCopy[j + 1]) {
                swap(arrCopy[j], arrCopy[j + 1]);
            }
        }
    }
    return arrCopy[n - 1]; // Return the last element of the copied (and now sorted) array
}
/// @brief // Function to wait for spacebar press
void waitForSpacebar() {
    cout << "\nPress the spacebar to continue..." << endl;

    struct termios orig_termios;
    tcgetattr(STDIN_FILENO, &orig_termios);

    struct termios new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != ' ');

    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
}

/// @brief initial print func
/// @param arr 
void printCurrent(vector<int>&arr){
    int n = arr.size();
    for (int i = n; i > 0; i--) { 
        if (i < maxVal(arr) + 1 )
        { 
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
    // int initialIndex = 0;
    int swapWithIndex = 0;
    waitForSpacebar();
    cout << "\n\n\n"
        << "------------------------------\n";
    
    int n = arr.size();
    for (int i = n; i > 0; i--) {  
        if (i < maxVal(arr) + 1 )
        { 
            for (int j = 0; j < n; j++) { 
            
                if (arr[j] > i-1 ){
                    if(j == swapped )
                    {
                        cout << " s ";
                        swapWithIndex = j;
                    }
                    else if( j == index)
                    {
                        cout << " i ";
                        // initialIndex = i;
                    }
                    else{
                        cout << " X ";
                    }
                }
                else{
                    cout << "   ";
                }
            }
            cout<< endl ;
        }
    }
    // -----------------------------------------//
    cout << "_______________\n"
    << " ";
    // print curr array
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << "  ";
    } 
    cout << endl;
    // print current swap
    for (int i = 0; i < arr.size(); i++) {
        if (i == swapWithIndex)
        {
            cout << " ^ ";
        }
        else if (i == index)
        {
            cout << " i ";
        }
        else
        {
            cout << "   ";
        } 
    } 
        cout << endl; 
    // print index 
        for (int i = 0; i < arr.size(); i++) {
        cout << "|" << i << "|";
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
/// @param seeGraph 
/// @param stepCnt 
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
/// @param seeGraph 
/// @param stepCnt 
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
/// @param seeGraph 
/// @param stepCnt 
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
/// @param seeGraph 
/// @param stepCnt 
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

//*********************** QUICK SORT **********************************************************
// Partition function using Lomuto partition scheme
int partition(vector<int>& arr, int low, int high, int &swapCnt, bool seeGraph, int &stepCnt) {
    int pivot = arr[high]; // Pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        stepCnt ++;
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
            swapCnt ++;
            if(seeGraph){
                printCurrent(arr, i, j, swapCnt);
            }
        }
    }
    swap(arr[i + 1], arr[high]);
    swapCnt ++;
    if(seeGraph){
        printCurrent(arr, i+1, high, swapCnt);
    }
    return (i + 1);
}

// QuickSort function
void quickSort(vector<int>& arr, int low, int high, int &swapCnt, bool seeGraph, int &stepCnt) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high, swapCnt, seeGraph, stepCnt);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1, swapCnt, seeGraph, stepCnt);
        quickSort(arr, pi + 1, high, swapCnt, seeGraph, stepCnt);
    }
}
//********************************************************************************************

//*********************** MERGE SORT **********************************************************


void merge(vector<int>& arr, int left, int mid, int right, int &swapCnt, bool seeGraph, int &stepCnt) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
        stepCnt ++;
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
        stepCnt ++;
    }

    // Merge the temp vectors back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        stepCnt ++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
            swapCnt ++;
            if(seeGraph){
                printCurrent(arr, k, i, swapCnt);
            }
        } else {
            arr[k] = R[j];
            j++;
            swapCnt ++;
            if(seeGraph){
                printCurrent(arr, k, j, swapCnt);
            }
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        stepCnt ++;
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        stepCnt ++;
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& arr, int left, int right, int &swapCnt, bool seeGraph, int &stepCnt) {
    if (left < right) {
        // Find the midpoint to split the array into two halves
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid, swapCnt, seeGraph, stepCnt);
        mergeSort(arr, mid + 1, right, swapCnt, seeGraph, stepCnt);

        // Merge the sorted halves
        merge(arr, left, mid, right, swapCnt, seeGraph, stepCnt);
    }
}
//********************************************************************************************

// -----------------------------------------------------------------//
// Main
// -----------------------------------------------------------------//
int main() {
    // declaring variables...
    int swapCnt = 0;
    int arrSize = 0;
    vector<int> arr;
    vector<int> initialArr;
    int stepCnt = 0;
    /*add elements*/
    bool userDone = false;
    string inputLine;
    int number;
    char yesOrNo = 'y';
    /*Type of Sort?*/
    bool validChoice = false;
    int userChoice = 0;
    bool firstTime = true;
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
    initialArr = arr;
    userDone = false;
    while(!userDone)
    {
        if (!firstTime)
        {
            arr = initialArr;
        }
        if(seeGraph)
        {
        // -----------------------------------------//
        // Initial Array
        // -----------------------------------------//
        cout << "******************************\n"
            << "     Your Initial Array:\n" 
            << "******************************\n";
        printCurrent(arr);
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        // -----------------------------------------//
        }
        stepCnt = 0;
        swapCnt = 0;
        validChoice = false;

        /*Type of Sort?*/
        while (!validChoice) {
            arrSize = arr.size();
            int low, high = 0; // for the quickSort parameters
            high = arrSize - 1;
            cout << "Enter what kind of sort do you want to perform:\n"
                << "0 | Bubble Sort \n"
                << "1 | Odd Even Sort \n"
                << "2 | Insertion Sort \n"
                << "3 | Selection Sort \n"
                << "4 | Quick Sort \n"
                << "5 | Merge Sort \n";
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
                case 4:
                    quickSort(arr, low, high, swapCnt, seeGraph, stepCnt);
                    validChoice = true;
                    break;
                case 5:
                    mergeSort(arr, low, high, swapCnt, seeGraph, stepCnt);
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
        if (userChoice == 0)
        {
            cout << "Bubble Sort\n";
        }
        if (userChoice == 1)
        {
            cout << "Odd Even Sort\n";
        }
        if (userChoice == 2)
        {
            cout << "Insertion Sort\n";
        }
        if (userChoice == 3)
        {
            cout << "Selection Sort\n";
        }
        if (userChoice == 4)
        {
            cout << "Quick Sort\n";
        }
        if (userChoice == 5)
        {
            cout << "Merge Sort\n";
        }
        cout << "Total Elements Input: " << arrSize << endl
            << "Total Swaps: " << swapCnt << "\n"
            << "Total Steps Taken: " << stepCnt << endl
            << "Swap to Input Ratio: " << swapCnt / fArraySize 
            << endl << "Steps to Input Ratio: " << stepCnt / fArraySize
            << endl << "ps. lower is better! ;)\n"
            << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        firstTime = false; // this is the flag for multiple sorts on same array
            cout << "\nWould you like to try with a different sort? (y/n)\n";
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
    cout << "\nExiting Program...\n";
    return 0;
}


