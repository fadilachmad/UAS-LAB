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