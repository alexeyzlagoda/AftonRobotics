#define PATH "LogSys/FullLog.txt"
#define SecurePath "Core/LogService/Log.txt"
#include <ctime>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#ifndef LoggerSystem
#define LoggerSystem
namespace logger{
    void LogData(string type, string info){
        ofstream out(PATH, ios::app);
        time_t now = time(0);
        char* dt = ctime(&now);
        if (type == "[CRITICAL]")
            out << dt;
        out << type << info<<endl;
        out.close();

        ofstream out1(SecurePath, ios::app);
        if (type == "[CRITICAL]")
            out1 << dt;
        out1 << type << info<<endl;
        out1.close();
    }
    void ClearLog(){
        ofstream out1(PATH, ios::trunc);
        out1 << "";
        out1.close();
    }
}
#endif