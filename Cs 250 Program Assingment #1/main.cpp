/*
* Name: Michael Maher
* Course: CS 250
* Last Update: 9/25/2024
* Program: Number one
*
* Description:
* Assign passenger seats on an airplane using arrays/vectors.
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
using namespace std;

int rows; // global variable
int columns;

// Function prototypes
void displaySeating(const vector<vector<char>>& seating);
bool assignSeat(vector<vector<char>>& seating, int row, int column);
bool checksSeats(const vector<vector<char>>& seating);
void displayTakenSeats(const vector<vector<char>>& seating);

int main() {
    cout << "Number of rows on the plane: ";
    cin >> rows;

    cout << "Number of columns on the plane: ";
    cin >> columns;

    // Initialize seating with '0' for available
    vector<vector<char>> availableSeats(rows, vector<char>(columns, '0'));

    // Display header
    char header[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    cout << "  ";
    for (int k = 0; k < columns; k++) {
        cout << "     " << header[k];
    }
    cout << endl;

    // Print initial seating chart
    displaySeating(availableSeats);

    char input;
    while (checksSeats(availableSeats)) {
        cout << "Do you want to assign a seat? (input y or n): ";
        cin >> input;

        if (input == 'y') {
            int row, column;
            cout << "Enter row number (1 to " << rows << ") and column letter (A to " << header[columns - 1] << "): ";
            cin >> row;

            char columnLetter;
            cin >> columnLetter;
            column = columnLetter - 'A'; // Convert letter to index

            // Validate row and column
            if (row < 1 || row > rows || column < 0 || column >= columns) {
                cout << "Invalid input. Please try again." << endl;
                continue;
            }

            // Assign seat
            if (assignSeat(availableSeats, row - 1, column)) {
                cout << "Seat assigned" << endl;
            } else {
                cout << "Seat already taken. Please choose another seat." << endl;
            }

            // Display updated seating chart
            displaySeating(availableSeats);
        }
    }

    cout << "Final seating arrangement:" << endl;
    displaySeating(availableSeats);
    cout << "Seats taken:" << endl;
    displayTakenSeats(availableSeats);

    return 0;
}

// displays the seat chart
void displaySeating(const vector<vector<char>>& seating) {
    for (int i = 0; i < seating.size(); i++) {
        cout << i + 1;
        for (char seat : seating[i]) {
            cout << "      " << seat;
        }
        cout << endl;
    }
}

// Function to assign a seat
bool assignSeat(vector<vector<char>>& seating, int row, int column) {
    if (seating[row][column] == '0') {
        seating[row][column] = 'X'; // Mark seat as taken
        return true;
    }
    return false; // Seat already taken
}

// checks ti see if there are available seats
bool checksSeats(const vector<vector<char>>& seating) {
    for (const auto& row : seating) {
        for (char seat : row) {
            if (seat == '0') return true; // Found an available seat
        }
    }
    return false; // No available seats
}

// displays taken seats
void displayTakenSeats(const vector<vector<char>>& seating) {
    for (int i = 0; i < seating.size(); i++) {
        for (int j = 0; j < seating[i].size(); j++) {
            if (seating[i][j] == 'X') {
                cout << "Row " << (i + 1) << " Seat " << static_cast<char>('A' + j) << endl;
            }
        }
    }
}

