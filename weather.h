#ifndef WEATHER_H
#define WEATHER_H
#include <string>
using namespace std;

struct WeatherInfo{
    string city;
    double temperature;
    int humidity;
    string description;
};
class Weather{
    public:
    Weather(string& apiKey);
    WeatherInfo getWeather(string& city);

    string apiKey;
    string fetchWeatherData(string& city);

};

#endif