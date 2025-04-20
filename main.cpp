#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#define _HAS_STD_BYTE 0

#include "windows.h"
#undef byte  

#include<iostream>
#include "weather.h"

using namespace std;
int main(){
string apiKey="53cb61827ddc3646971789fd39f53d66";

string city;
cout<<"City name: "<<endl;
getline(cin,city);

try {
    Weather weatherApp(apiKey);
    WeatherInfo info = weatherApp.getWeather(city);
    cout << "\nWeather in " << info.city << "\n";
    cout << "Temperature: " << info.temperature << "°C"<<endl;
    cout << "Humidity: " << info.humidity << "%"<<endl;
    cout << "Description: " << info.description << "\n";
} catch (const std::exception& e) {
    cerr << "Error: " << e.what() << "\n";
}


return 0;
}