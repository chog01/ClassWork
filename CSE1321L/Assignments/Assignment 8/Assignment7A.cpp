#include <iostream>
#include <string>

using namespace std;

class AudioCD {
private:
    string cdTitle;
    string artists[4];
    int releaseYear;
    string genre;
    float condition;

public:
    AudioCD() {
        cdTitle = "";
        for (int i = 0; i < 4; i++) {
            artists[i] = "";
        }
        releaseYear = 1980;
        genre = "";
        condition = 0.0;
    };

    AudioCD(string t, string a[4], int ry, string g, float c) {
        cdTitle = t;
        if (c > 4) {
            cout << "You have entered too many artists. THe first four will be added"
                << endl;
            c = 4;
        }
        for (int i = 0; i < 4; i++) {
            artists[i] = a[i];
        }
        if (ry < 1980) {
            releaseYear = 1980;
        }
        else
            releaseYear = ry;
        genre = g;
        if (c < 0.0 || c > 5.0) {
            condition = 0.0;
        }
        else
            condition = c;
    };

    void toString();

    string getTitle() { return cdTitle; }
    string getArtists(int i) { return artists[i]; }
    int getRelease() { return releaseYear; }
    string getGenre() { return genre; }
    int getcondition() { return condition; }
};

class Assignment8A {
public:
    void main();
};

void AudioCD::toString() {
    cout << cdTitle << "(Soundtrack), " << releaseYear << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Artist (#" << (i + 1) << "): " << artists[i] << "\t";
    }

    cout << "Genre: " << genre << endl;
    cout << "Condition: " << condition << endl;
}

void Assignment8A::main() {
    int numCD, i, j = 0, k, p, a, choice;
    string title, genre, check;
    int release;
    float condition;
    bool menu = true;

    cout << "[Rate Audio CD Collection]" << endl
        << "How many CDs do you have lying around your car? ";
    cin >> numCD;

    AudioCD CDs[numCD];

    for (i = 0; i < numCD; i++) {
        string artist[6] = { "","","","","","" };
        cout << "CD #" << (i + 1) << endl;
        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter number of artists: ";
        cin >> a;
        for (j = 0; j < a; j++) {
            cin >> artist[j];
        }
        cout << "Enter Genre: ";
        cin >> genre;
        cout << "Enter Release Year: ";
        cin >> release;
        cout << "Enter Condition: ";
        cin >> condition;

        AudioCD c(title, artist, release, genre, condition);
        CDs[i] = c;
    }

    while (menu) {
        cout << "[Main Menu]\n" <<
            "1) Album Info\n2) Find a CD\n3)Find an artist\n4) Log off" << endl
            << "Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1: {
            cout << "Which CD do you want? ";
            cin >> k;
            if (k > numCD || k < 1) {
                cout << "Sorry, there\'s no CD that matches the criteria." << endl;
            }
            else CDs[k - 1].toString();
            break;
        }
        case 2: {
            string t;
            int f = 0;
            cout << "What is the CD\'s name? ";
            cin >> t;
            for (j = 0; j < numCD; j++) {
                title = CDs[j].getTitle();
                if (t == title) {
                    CDs[j].toString();
                    f = 1;
                    break;
                }
            }
            if (f == 0) cout << "No CD Found" << endl;
            break;
        }
        case 3: {
            string t;
            int f = 0;
            cout << "What artist are you lokking for? ";
            cin >> t;
            for (j = 0; j < numCD; j++) {
                for (i = 0; i < 4; i++) {
                    title = CDs[j].getArtists(i);
                    if (t == title) {
                        f++;
                        cout << "CD #" << f << " of Artist " << t << endl;
                        CDs[j].toString();
                        break;
                    }
                }
            }
            if (f == 0) cout << "No CD if found with that artist" << endl;
            break;
        }
        case 4: {
            menu = false;
            break;
        }
        default: cout << "Enter a Valid option" << endl;
        }
    }
}

int main() {
    Assignment8A A;
    A.main();
}