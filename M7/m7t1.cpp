#include <iostream>
using namespace std;

// CSC 134
// M7T1 - Restaurant Rating
// Abdullah Zalzala
// 12/1/2025
// Use Restaurant class to store user ratings

// Next time we'll put the class in a separate file

// If you want a plain struct, you can keep this.
// But you were not using it correctly, so I fixed the syntax.
struct rest {
    string name;
    double rating;
};

class Restaurant {
private:
    string name;    // the name
    double rating;  // 0 to 5 stars

public:
    // constructor 
    Restaurant(string n, double r) {
        name = n;
        rating = r;
    }

    // default constructor (NEEDED if you declare Restaurant Breakfast; )
    Restaurant() {
        name = "";
        rating = 0.0;
    }

    // setters
    void setName(string n) {
        name = n;
    }

    void setRating(double r) {
        if (r >= 0 && r <= 5) {
            rating = r;
        }
    }

    // getters
    string getName() const { return name; }
    double getRating() const { return rating; }

    void printinfo() {
        cout << "Restaurant: " << name << endl;
        cout << "Rating: " << rating << " (out of 5)" << endl << endl;
    }
};

int main() {
    cout << "M7T1 - Restaurant Reviews" << endl << endl;

    // Correct object creation
    Restaurant Breakfast("Canes", 4.5);
    Restaurant lunch("Mcdonalds", 4.0);

    // Print restaurant info
    Breakfast.printinfo();
    lunch.printinfo();

    return 0;
}