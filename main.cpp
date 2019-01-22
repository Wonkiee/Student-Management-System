#include <iostream>
//#include <sdtlib.h>
#include <string>

//QT Libraries
#include <QApplication>

// Header files
#include "Interface.h"
using namespace std;

int main(int argc, char **argv){
  
  QApplication app (argc, argv);
  Interface *interface_1 = new Interface();
  interface_1 -> show();
  return app.exec();
}
