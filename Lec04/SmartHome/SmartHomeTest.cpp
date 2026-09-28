#include "SmartHome.h"

int main() {
    // Instantiate the smart home control system
    SmartHome myHome;

    // 1. Initial State Display
    myHome.showStatus();


    cout << "\n[Step 1] Controlling Appliances Manually" << endl;
    myHome.setLight(true, 80);
    myHome.setAirConditioner(true, 24);
    myHome.setTimer(20); // Set 20 minutes timer
    myHome.showStatus();

 
    cout << "\n[Step 2] Simulating Sensor Updates (Heatwave event)" << endl;
    myHome.updateSensors(31.5, 55.0);


    myHome.runPeriodicRoutine();

    myHome.runPeriodicRoutine();


    myHome.showStatus();
    myHome.printNotifications();

    return 0;
}
