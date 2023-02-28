#include <bits/stdc++.h>
#include "LogSys.hpp"
#include "Config/RobotData.hpp"
#include "Config/BootData.hpp"
#include "Core/CoreInit.hpp"

using namespace std;
using namespace Core;
namespace RSys{
  void MainFlow(){
    bool err = 0;
    while (!err){
        string Command;
        cout << "USR: ";
        cin >> Command;  
        if (Command== "Shutdown"){
          logger::LogData("[INFO]", " User Command: Shutdown");
          return;
        }
        else if (Command== "ClearLog"){
          logger::LogData("[WARNING]", "LOG CLEARED BY USER");
          logger::ClearLog();
        }
        else if (Command== "Info"){
          logger::LogData("[INFO]", " User Command: Info");
          cout << "RobotName:   " << RobotName    << endl;
          cout << "RobotSysVer: " << RobotSysVer  << endl;
        }
        else if (Command==  "All_Info"){
          logger::LogData("[INFO]", " User Command: All_Info");
          cout << "RobotName:   " << RobotName    << endl;
          cout << "RobotID:     " << RobotID      << endl;
          cout << "RobotVer:    " << RobotVer     << endl;
          cout << "RobotSysVer: " << RobotSysVer  << endl;
        }
        else if (Command==  "Ports"){
          logger::LogData("[INFO]", " User Command: Ports");
          cout << "HeadPort:        " << EyePort          << endl;
          cout << "BodyPort:        " << BodyPort         << endl;
          cout << "ServicePort:     " << ServicePort      << endl;
        }
        else if (Command==  "Help"){
          cout << "Help" << endl;
          cout << "ClearLog" << endl;
          cout << "Info" << endl;
          cout << "All_Info" << endl;
          cout << "Ports" << endl;
          cout << "Shutdown" << endl;
        }
        else
          cout << "Unknown command"<<endl;
          
        }
              
  }
  int Boot(){
    logger::LogData("[INFO]","System Started");
    if (ShowDebugInfo){
      logger::LogData("[INFO]",RobotID);
      logger::LogData("[INFO]",Mode);
      logger::LogData("[INFO]",RobotSysVer);
      logger::LogData("WARNING", "Activated Testimg Mode");
    }
    #ifndef CORE
    return 1;
    #endif
    MainFlow();
    return 0;
  }
  //void Console();
  
  
}
