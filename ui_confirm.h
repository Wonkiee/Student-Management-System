/********************************************************************************
** Form generated from reading UI file 'confirm.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRM_H
#define UI_CONFIRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Confirm
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *userName;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *password;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *confirm;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_8;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_11;
    QLabel *details;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *Confirm)
    {
        if (Confirm->objectName().isEmpty())
            Confirm->setObjectName(QStringLiteral("Confirm"));
        Confirm->resize(400, 300);
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        Confirm->setFont(font);
        gridLayout_2 = new QGridLayout(Confirm);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 65, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(Confirm);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(151, 17));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        userName = new QLineEdit(Confirm);
        userName->setObjectName(QStringLiteral("userName"));
        sizePolicy.setHeightForWidth(userName->sizePolicy().hasHeightForWidth());
        userName->setSizePolicy(sizePolicy);
        userName->setMaximumSize(QSize(146, 27));
        userName->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(userName);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        password = new QLineEdit(Confirm);
        password->setObjectName(QStringLiteral("password"));
        sizePolicy.setHeightForWidth(password->sizePolicy().hasHeightForWidth());
        password->setSizePolicy(sizePolicy);
        password->setMaximumSize(QSize(146, 27));
        password->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(password);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        confirm = new QPushButton(Confirm);
        confirm->setObjectName(QStringLiteral("confirm"));
        sizePolicy.setHeightForWidth(confirm->sizePolicy().hasHeightForWidth());
        confirm->setSizePolicy(sizePolicy);
        confirm->setMaximumSize(QSize(146, 27));

        horizontalLayout_4->addWidget(confirm);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(57, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 1, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 0, 0, 1, 1);

        details = new QLabel(Confirm);
        details->setObjectName(QStringLiteral("details"));
        sizePolicy.setHeightForWidth(details->sizePolicy().hasHeightForWidth());
        details->setSizePolicy(sizePolicy);
        details->setMinimumSize(QSize(156, 19));
        details->setMaximumSize(QSize(156, 19));
        QFont font2;
        font2.setPointSize(10);
        details->setFont(font2);
        details->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(details, 0, 1, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 1, 1, 1);


        retranslateUi(Confirm);

        QMetaObject::connectSlotsByName(Confirm);
    } // setupUi

    void retranslateUi(QDialog *Confirm)
    {
        Confirm->setWindowTitle(QApplication::translate("Confirm", "Dialog", 0));
        label->setText(QApplication::translate("Confirm", "Confirm Details", 0));
        userName->setPlaceholderText(QApplication::translate("Confirm", "User Name", 0));
        password->setPlaceholderText(QApplication::translate("Confirm", "Password", 0));
        confirm->setText(QApplication::translate("Confirm", "Confirm", 0));
        details->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Confirm: public Ui_Confirm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRM_H
