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

bool bookSeat(Movie* movie, int row, int col, int rows, int cols) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        cout << "Invalid seat number.\n";
        return false;
    }

    Seat* seat = &movie->seats[row * cols + col];
    if (seat->isBooked) {
        cout << "Seat is already booked.\n";
        return false;
    } else {
        seat->isBooked = true;
        cout << "Seat booked successfully.\n";
        return true;
    }
}

void showMenu() {
    cout << "\n1. Display Seats\n";
    cout << "2. Book Seat\n";
    cout << "3. Select Movie\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

void displayMovies(const vector<Movie>& movies) {
    cout << "Available movies:\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". " << movies[i].title << " (" << movies[i].duration << " minutes)\n";
    }
}

int main() {
    vector<Movie> movies = {
        {"Avengers: Endgame", 181},
        {"Inception", 148},
        {"The Matrix", 136},
        {"Interstellar", 169}
    };

    int rows = 5;
    int cols = 5;

    for (auto& movie : movies) {
        initializeSeats(&movie, rows, cols);
    }

    int selectedMovieIndex = 0;
    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                displaySeats(&movies[selectedMovieIndex], rows, cols);
                break;
            case 2: {
                int row, col;
                cout << "Enter row (0-" << rows-1 << "): ";
                cin >> row;
                cout << "Enter col (0-" << cols-1 << "): ";
                cin >> col;
                bookSeat(&movies[selectedMovieIndex], row, col, rows, cols);
                break;
            }
            case 3:
                displayMovies(movies);
                cout << "Select movie number: ";
                cin >> selectedMovieIndex;
                if (selectedMovieIndex < 1 || selectedMovieIndex > movies.size()) {
                    cout << "Invalid movie number. Selecting the first movie by default.\n";
                    selectedMovieIndex = 0;
                } else {
                    selectedMovieIndex -= 1;
                }
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}