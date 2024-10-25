#include <iostream>
#include <map>
#include <cmath>
#include <string>

using namespace std;

// Function to convert a string value from any base to decimal
long long convertToDecimal(const string& value, int base) {
    long long result = 0;
    for (char digit : value) {
        result = result * base + (isdigit(digit) ? digit - '0' : digit - 'a' + 10);
    }
    return result;
}

// Function to perform Lagrange Interpolation and find the constant term 'c'
long long lagrangeInterpolation(const map<int, long long>& points, int k) {
    long long constantTerm = 0;
    for (auto& p1 : points) {
        long long xi = p1.first;
        long long yi = p1.second;
        long long term = yi;

        for (auto& p2 : points) {
            if (p1.first != p2.first) {
                long long xj = p2.first;
                term = term * (-xj) / (xi - xj);
            }
        }
        constantTerm += term;
    }
    return constantTerm;
}

int main() {
    int n, k;
    cout << "Enter the number of roots provided (n): ";
    cin >> n;
    cout << "Enter the minimum number of roots required (k): ";
    cin >> k;

    map<int, pair<int, string>> rawPoints;
    cout << "Enter the roots in format (x base value):" << endl;

    for (int i = 0; i < n; i++) {
        int x, base;
        string value;
        cout << "Root " << i + 1 << " -> x: ";
        cin >> x;
        cout << "Base: ";
        cin >> base;
        cout << "Encoded value: ";
        cin >> value;
        rawPoints[x] = {base, value};
    }

    // Map to store (x, y) pairs in decimal
    map<int, long long> points;

    // Decode each value and store as (x, y) pairs
    for (auto& point : rawPoints) {
        int x = point.first;
        int base = point.second.first;
        string encodedValue = point.second.second;
        long long y = convertToDecimal(encodedValue, base);
        points[x] = y;
    }

    // Calculate the constant term using Lagrange Interpolation
    long long constantTerm = lagrangeInterpolation(points, k);

    // Output the result
    cout << "The constant term (secret) is: " << constantTerm << endl;

    return 0;
}
