/********************************************************************************
** Form generated from reading UI file 'loginWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *line;
    QLabel *label_2;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QLabel *lbl_loginError;
    QLabel *label_4;
    QLineEdit *lineE_userName;
    QLabel *label_5;
    QLineEdit *lineE_password;
    QFrame *line_3;
    QPushButton *btn_go;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->setEnabled(true);
        LoginWindow->resize(400, 296);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginWindow->sizePolicy().hasHeightForWidth());
        LoginWindow->setSizePolicy(sizePolicy);
        LoginWindow->setMaximumSize(QSize(400, 296));
        gridLayout = new QGridLayout(LoginWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(LoginWindow);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        line = new QFrame(LoginWindow);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        line_2 = new QFrame(LoginWindow);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(LoginWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lbl_loginError = new QLabel(LoginWindow);
        lbl_loginError->setObjectName(QStringLiteral("lbl_loginError"));

        horizontalLayout->addWidget(lbl_loginError);


        verticalLayout_2->addLayout(horizontalLayout);

        label_4 = new QLabel(LoginWindow);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        lineE_userName = new QLineEdit(LoginWindow);
        lineE_userName->setObjectName(QStringLiteral("lineE_userName"));

        verticalLayout_2->addWidget(lineE_userName);

        label_5 = new QLabel(LoginWindow);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        lineE_password = new QLineEdit(LoginWindow);
        lineE_password->setObjectName(QStringLiteral("lineE_password"));

        verticalLayout_2->addWidget(lineE_password);


        verticalLayout->addLayout(verticalLayout_2);

        line_3 = new QFrame(LoginWindow);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        btn_go = new QPushButton(LoginWindow);
        btn_go->setObjectName(QStringLiteral("btn_go"));
        btn_go->setMaximumSize(QSize(85, 27));

        verticalLayout->addWidget(btn_go);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "Student Record", 0));
        label->setText(QApplication::translate("LoginWindow", "Student Records ", 0));
        label_2->setText(QApplication::translate("LoginWindow", "Faculty of Engineering,University of Peradeniya", 0));
        label_3->setText(QApplication::translate("LoginWindow", "Login", 0));
        lbl_loginError->setText(QString());
        label_4->setText(QApplication::translate("LoginWindow", "User Name", 0));
        label_5->setText(QApplication::translate("LoginWindow", "Password", 0));
        btn_go->setText(QApplication::translate("LoginWindow", "Go", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
