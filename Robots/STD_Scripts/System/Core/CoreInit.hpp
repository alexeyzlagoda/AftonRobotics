#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#ifndef CORE 
#define CORE
namespace Core{
    class Serial{
        private:
            string Dataport;
        public:
            int SetPort(string port){
                Dataport = port;
            }
            string ReadCom(){
                ifstream port("/dev/"+Dataport);
                if (!port.is_open()){
                    logger::LogData("[CRITICAL]", " "+Dataport+"is not open");
                    return "";
                }
                string s = "";
                port >> s;
                port.close();
            }
            int WritePort(string Data){
                ofstream port("/dev/"+Dataport, ios::app);
                if (!port.is_open()){
                    logger::LogData("[CRITICAL]", " "+Dataport+"is not open");
                    return -1;
                }
                port << Data;
                port.close();
            }
    };
    class transform{
        public:
            float X;
            float Y;
            float Z;
            
    };
    class vector{
        private:
            transform Dot1;
            transform Dot2;
        public:
            float angleX(vector Vec){}
            float angleY(vector Vec){}
            float angleZ(vector Vec){}
            
    };
    class DataCompilation{
        private:
            vector FaceVec;
            transform RobotPos;
        public:
            void MapMaker(float dist1, float dist2, float angle1, float angle2);
            transform AvalMove(vector Vec){}
            transform RobotPosition(){}
            vector RobotVecFace(){}
    };
}
#endif