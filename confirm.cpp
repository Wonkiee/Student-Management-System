#include "confirm.h"

static bool correct = false;;	

Confirm::Confirm(QString pass, QString userN, QDialog *parent): QDialog(parent){
	USERNAME = "1";
	PASSWORD = "1";

	ui_confirm = new Ui_Confirm();
    if( !ui_confirm )
        return;
    ui_confirm -> setupUi(this);

    confirm = ui_confirm -> confirm;
    userName = ui_confirm -> password;
    password = ui_confirm -> userName;
    details = ui_confirm -> details;
    Register();
}

void Confirm::Register(){

	connect( confirm, SIGNAL( clicked() ), this, SLOT( onClickConfirm() ) );
}



void Confirm::onClickConfirm(){

	QString usrN = userName ->text();
	QString passW = password -> text();
	qDebug()<<usrN<<passW;
	qDebug()<<USERNAME<<PASSWORD;
	if( passW == PASSWORD && USERNAME == usrN ){
		correct = true;
		//hide();
		//setAttribute(Qt::WA_DeleteOnClose);
		close();
	}
	else{
		correct = false;
		details -> setText("Wrong Credentials");
	}

}

bool Confirm::isDetailsCorrect(){
	return correct;
}
