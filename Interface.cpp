#include "Interface.h"

Interface::Interface(QDialog *parent): QDialog(parent){
 
  go = NULL;
  lbl_loginError = NULL;
  le_userName = NULL;
  le_password = NULL;
  mainPage = NULL;
  userName = "rajitha";
  password = "11";
  ui_loginWindow = new Ui_LoginWindow();
  if(!ui_loginWindow)
    return;
  ui_loginWindow->setupUi(this);
  Refresh();

}

void Interface::Refresh(){
  go = ui_loginWindow -> btn_go;
  lbl_loginError = ui_loginWindow -> lbl_loginError;
  le_password = ui_loginWindow -> lineE_password;
  le_userName = ui_loginWindow -> lineE_userName;
  connect( go, SIGNAL(clicked()), this, SLOT(Login()) );
}

void Interface::Login(){
  str_T user_Name = (str_T)qPrintable(le_userName->text());
  str_T pssword = (str_T)qPrintable(le_password->text());
  if( strcmp(user_Name,userName) || strcmp(pssword,password) )
    lbl_loginError->setText("Incorret Details"); 
  else{
      hide();
      mainPage = new MainPage(NULL);
      mainPage->show();
  }
}
