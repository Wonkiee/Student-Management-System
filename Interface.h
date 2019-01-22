#include <iostream>

//QT libraries
#include <QDialog>
#include <QtGui>
//headers
#include "MainPage.h"
#include "ui_loginWindow.h"
using namespace std;

typedef char* str_T;

class Interface: public QDialog{
Q_OBJECT

public:
  Interface(QDialog *parent = 0);
private:
  //variables
  Ui_LoginWindow *ui_loginWindow;
  QPushButton *go;
  QLabel *lbl_loginError; 
  QLineEdit *le_userName;
  QLineEdit *le_password;
  str_T userName;
  str_T password;
  //Functions
  void Refresh();

  MainPage *mainPage;
  
private slots:
  void Login();
};
