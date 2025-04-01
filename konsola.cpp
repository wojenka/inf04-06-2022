#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> create_filled_array(int number_of_elements = 50) {
    vector<int> arr;
    for (int i = 0; i < number_of_elements; ++i) {
        arr.push_back(rand() % 100 + 1);
    }
    return arr;
}

int find_element(const vector<int>& haystack, int needle) {
    vector<int> haystack_copy = haystack;
    haystack_copy.push_back(needle);  

    int watcher_index = haystack_copy.size() - 1;

    for (int i = 0; i < haystack_copy.size(); ++i) {
        if (haystack_copy[i] == needle && i != watcher_index) {
            return i;  
        }
    }

    return -1;
}

int main() {
    srand(time(0));

    vector<int> array_of_elements = create_filled_array(50);

    int element_to_find;
    cout << "Jaką liczbę wyszukać?\n";
    cout << "Wyszukaj: ";
    cin >> element_to_find;

    int element_position = find_element(array_of_elements, element_to_find);

    cout << "Przeszukiwana tablica: " << endl;
    for (int el : array_of_elements) {
        cout << el << " ";
    }
    cout << endl;

    if (element_position == -1) {
        cout << "Szukanego elementu nie ma w tej tablicy." << endl;
    } else {
        cout << "Szukany element został znaleziony po raz pierwszy na pozycji " << element_position << "." << endl;
    }

    return 0;
}