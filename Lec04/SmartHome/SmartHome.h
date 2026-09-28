#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SmartHome {
private:
    // Appliance states
    bool lightOn;
    int lightBrightness; // 0 to 100
    bool acOn;
    int acTemperature;   // Celsius degree
    int timerMinutes;    // Remaining timer in minutes

    double currentTemperature;
    double currentHumidity;


    vector<string> notifications;

public:

    SmartHome() {
        lightOn = false;
        lightBrightness = 0;
        acOn = false;
        acTemperature = 24;
        timerMinutes = 0;
        currentTemperature = 22.5;
        currentHumidity = 45.0;
    }


    void setLight(bool status, int brightness = 50) {
        lightOn = status;
        if (lightOn) {
            lightBrightness = (brightness < 0) ? 0 : (brightness > 100 ? 100 : brightness);
            cout << "[Device] Light turned ON (Brightness: " << lightBrightness << "%)" << endl;
        }
        else {
            lightBrightness = 0;
            cout << "[Device] Light turned OFF" << endl;
        }
    }

    void setAirConditioner(bool status, int temp = 24) {
        acOn = status;
        if (acOn) {
            acTemperature = temp;
            cout << "[Device] AC turned ON (Target Temp: " << acTemperature << "C)" << endl;
        }
        else {
            cout << "[Device] AC turned OFF" << endl;
        }
    }

    void setTimer(int minutes) {
        timerMinutes = (minutes < 0) ? 0 : minutes;
        cout << "[Timer] Automation timer set for " << timerMinutes << " minutes." << endl;
    }

    void updateSensors(double temp, double humidity) {
        currentTemperature = temp;
        currentHumidity = humidity;
        cout << "[Sensors] Environment Updated -> Temp: " << currentTemperature << "C, Humidity: " << currentHumidity << "%" << endl;

       
        if (currentTemperature > 30.0) {
            addNotification("ALERT: High temperature detected (" + to_string(currentTemperature) + "C)!");
        }
        else if (currentTemperature < 5.0) {
            addNotification("ALERT: Low temperature detected (" + to_string(currentTemperature) + "C)! Risk of freezing.");
        }

        if (currentHumidity > 70.0) {
            addNotification("WARNING: High humidity level (" + to_string(currentHumidity) + "%).");
        }
    }

   
    void runPeriodicRoutine() {
        cout << "\n--- [System] Running Periodic Automated Routine ---" << endl;

       
        if (currentTemperature > 28.0 && !acOn) {
            addNotification("Auto-Routine: Temperature is hot. Turning on AC automatically.");
            setAirConditioner(true, 22);
        }

      
        if (timerMinutes > 0) {
            timerMinutes -= 10; // Simulate 10 minutes passing
            if (timerMinutes <= 0) {
                timerMinutes = 0;
                addNotification("Auto-Routine: Timer expired. Shutting down active devices.");
                setLight(false);
                setAirConditioner(false);
            }
            else {
                cout << "[Timer] " << timerMinutes << " minutes remaining on the active timer." << endl;
            }
        }
        cout << "---------------------------------------------------\n" << endl;
    }

   
    void addNotification(string message) {
        notifications.push_back(message);
        cout << "[Notification Center] " << message << endl;
    }

    void showStatus() {
        cout << "\n================ [SMART HOME STATUS] ================" << endl;
        cout << " Light : " << (lightOn ? "ON" : "OFF") << " (" << lightBrightness << "%)" << endl;
        cout << " AC    : " << (acOn ? "ON" : "OFF") << " (" << acTemperature << "C)" << endl;
        cout << " Timer : " << timerMinutes << " mins remaining" << endl;
        cout << " Sensors: Temp=" << currentTemperature << "C, Humidity=" << currentHumidity << "%" << endl;
        cout << "=====================================================" << endl;
    }

    void printNotifications() {
        cout << "\n--- [System Notification Logs] ---" << endl;
        if (notifications.empty()) {
            cout << " No notifications logged." << endl;
        }
        else {
            for (size_t i = 0; i < notifications.size(); i++) {
                cout << " [" << i + 1 << "] " << notifications[i] << endl;
            }
        }
        cout << "----------------------------------" << endl;
    }
};
