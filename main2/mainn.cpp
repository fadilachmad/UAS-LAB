#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Seat {
    int row;
    int col;
    bool isBooked;
};

struct Movie {
    string title;
    int duration; // in minutes
    vector<Seat> seats;
};

void initializeSeats(Movie* movie, int rows, int cols) {
    movie->seats.resize(rows * cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Seat seat = {i, j, false};
            movie->seats[i * cols + j] = seat;
        }
    }
}

void displaySeats(const Movie* movie, int rows, int cols) {
    cout << "Seating arrangement for " << movie->title << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << (movie->seats[i * cols + j].isBooked ? "[X]" : "[O]") << " ";
        }
        cout << endl;
    }
}