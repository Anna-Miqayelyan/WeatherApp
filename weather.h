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
    Weather(const string& apiKey);
    WeatherInfo getWeather(const string& city);
private:
    string apiKey;
    string fetchWeatherData(const string& city);

};

#endif