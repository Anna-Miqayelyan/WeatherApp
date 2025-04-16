#include "weather.h"
#include "json.hpp" // For JSON parsing
#include <curl/curl.h>  // For HTTP requests
#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;
using json=nlohmann::json;

Weather::Weather(const  string& apiKey) : apiKey(apiKey){}

size_t WriteCallback(void* contents, size_t size,size_t nmemb, string* output){
    size_t totalSize=size*nmemb;

    output->append((char*)contents,totalSize);
    return totalSize;
}

string Weather::fetchWeatherData( const string& city){
    CURL* curl;
    CURLcode res;
    string read;
    


    stringstream url;
    url << "http://api.openweathermap.org/data/2.5/weather?q=" << city
    << "&appid=" << apiKey << "&units=metric";

    curl=curl_easy_init();
    if(curl){
        curl_easy_setopt(curl,CURLOPT_URL,url.str().c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,&read);
        
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            cout<<"Failed..."<<endl;
    }

curl_easy_cleanup(curl);
}
return read;}

WeatherInfo Weather::getWeather(const  string& city){
    string data=fetchWeatherData(city);
    json j= json::parse(data);

    WeatherInfo info;
    info.city=j["NAme"];
    info.temperature=j["main"]["temp"];
    info.humidity=j["main"]["humidity"];
    info.description=j["main"][0]["description"];
    return info;
}