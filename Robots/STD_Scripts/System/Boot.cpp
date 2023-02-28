#include "OS.hpp"
#include "LogSys.hpp"
//#include "LogSys.hpp"
/*
   0- None
   1- 
*/

using namespace std;
using namespace RSys;
int main(){
   int error = Boot();
   switch(error){
      case 0: logger::LogData("[INFO]", "shutdown Complete"); break;
      case 1: logger::LogData("[CRITICAL]", "Core is not avaliable");break;
      
   }
}
