#include <iostream>

using namespace std;

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to convert Fahrenheit to Kelvin
double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}

// Function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Kelvin to Fahrenheit
double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}

int main() {
    double temp;
    char unit;

    cout << "Temperature Conversion Program" << endl;
    cout << "Enter the temperature value: ";
    cin >> temp;
    cout << "Enter the unit (C for Celsius, F for Fahrenheit, K for Kelvin): ";
    cin >> unit;

    switch (toupper(unit)) {
        case 'C':
            cout << temp << " Celsius is equal to " << celsiusToFahrenheit(temp) << " Fahrenheit" << endl;
            cout << temp << " Celsius is equal to " << celsiusToKelvin(temp) << " Kelvin" << endl;
            break;
        case 'F':
            cout << temp << " Fahrenheit is equal to " << fahrenheitToCelsius(temp) << " Celsius" << endl;
            cout << temp << " Fahrenheit is equal to " << fahrenheitToKelvin(temp) << " Kelvin" << endl;
            break;
        case 'K':
            cout << temp << " Kelvin is equal to " << kelvinToCelsius(temp) << " Celsius" << endl;
            cout << temp << " Kelvin is equal to " << kelvinToFahrenheit(temp) << " Fahrenheit" << endl;
            break;
        default:
            cout << "Invalid unit. Please enter C for Celsius, F for Fahrenheit, or K for Kelvin." << endl;
            break;
    }

    return 0;
}
