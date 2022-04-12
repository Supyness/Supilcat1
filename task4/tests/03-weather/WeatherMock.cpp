//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherMock.h"
using json = nlohmann::json;

TEST(A3, B3) {
    Weather t;
    try {
        json tmp = t.GetResponseForCity("YA", "http://api.openweathermap.org/data/2.5/weather");
    }
    catch (...) {

    }
    try {
        t.GetTemperature("Moscow");
    }
    catch (...) {
    }
    try {
        t.GetDifferenceString("Moscow", "London");
    }
    catch (...) {
    }
    try {
        t.FindDiffBetweenTwoCities("Moscow", "London");
    }
    catch (...) {
    }
    t.SetApiKey("1");
    try {
        t.GetTomorrowTemperature("Moscow");
    }
    catch (...) {
    }
    try {
        t.GetTomorrowDiff("London");
    }
    catch (...) {
    }
}