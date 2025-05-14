#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Declare 2 empty vectors of integers named
    // vector 1 and vector2, respectively.
    vector<int> vector1;
    vector<int> vector2;

    // Add 10 and 20 to vector1 dynamically using push_back.
    // Display the elements in vector1 using the at() method as well as its size using the size() method
    vector1.push_back(10);
    vector1.push_back(20);

    cout << "vector1 element at position 0: " << vector1.at(0) << endl;
    cout << "vector1 element at position 1: " << vector1.at(1) << endl;
    cout << "vector1 has " << vector1.size() << " elements." << endl;

    // Add 100 and 200 to vector2 dynamically using push_back.
    // Display the elements in vector2 using the at() method as well as its size using the size() method
    vector2.push_back(100);
    vector2.push_back(200);

    cout << "vector2 element at position 0: " << vector2.at(0) << endl;
    cout << "vector2 element at position 1: " << vector2.at(1) << endl;
    cout << "vector2 has " << vector2.size() << " elements." << endl;

    // Declare an empty 2D vector called vector_2d
    // Remember that a 2D vector is a vector of vector<int>
    vector<vector<int>> vector_2d;

    // Add vector1 to vector_2d dynamically using push_back
    // Add vector2 to vector_2d dynamically using push_back
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    // Display the elements in vector_2d using the at() method
    cout << "vector_2d element at position 0 - 0: " << vector_2d.at(0).at(0) << endl;
    cout << "vector_2d element at position 0 - 1: " << vector_2d.at(0).at(1) << endl;
    cout << "vector_2d element at position 1 - 0: " << vector_2d.at(1).at(0) << endl;
    cout << "vector_2d element at position 1 - 1: " << vector_2d.at(1).at(1) << endl;
    cout << endl;

    // Change vector1.at(0) to 1000
    cout << "Changing vector1 element 0 to 1000" << endl << endl;
    vector1.at(0) = 1000;

    // Display the elements in vector_2d using the at() method
    cout << "vector_2d element at position 0 - 0: " << vector_2d.at(0).at(0) << endl;
    cout << "vector_2d element at position 0 - 1: " << vector_2d.at(0).at(1) << endl;
    cout << "vector_2d element at position 1 - 0: " << vector_2d.at(1).at(0) << endl;
    cout << "vector_2d element at position 1 - 1: " << vector_2d.at(1).at(1) << endl;
    cout << endl;

    return 0;
}
