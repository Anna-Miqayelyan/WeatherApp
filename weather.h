#pragma once
#ifndef WEATHER_H
#define WEATHER_H

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#define _HAS_STD_BYTE 0 
#include <windows.h>
#undef byte

#include <string>
#include <memory> 

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