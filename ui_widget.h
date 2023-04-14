/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_11;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_10;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBoxTwo;
    QCheckBox *checkBoxOne;
    QCheckBox *checkBoxPoint;
    QPushButton *pushButtonSendMode;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTextEdit *textEditSend;
    QCheckBox *checkBoxSendHex;
    QCheckBox *checkBoxSendText;
    QPushButton *pushButtonSendSend;
    QPushButton *pushButtonSendClear;
    QGroupBox *groupBoxInch_2;
    QGridLayout *gridLayout_7;
    QLineEdit *lineEditPointSpeed;
    QGridLayout *gridLayout_6;
    QPushButton *pushButtonPointAdd;
    QPushButton *pushButtonPointSub;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_18;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QPushButton *pushButtonClearRecv;
    QTextEdit *textEditRecv;
    QCheckBox *checkBoxRecvHex;
    QCheckBox *checkBoxRecvText;
    QGridLayout *gridLayout_9;
    QGroupBox *leftTopGroupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QComboBox *comboBoxNum;
    QPushButton *pushButtonUpdateCom;
    QComboBox *comboBoxBaund;
    QComboBox *comboBoxName;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButtonOpen;
    QPushButton *pushButtonReset;
    QPushButton *pushButtonStopFast;
    QGroupBox *groupBoxRight;
    QGridLayout *gridLayout_8;
    QLabel *label_6;
    QComboBox *comboBoxDirOne;
    QLabel *label_5;
    QLineEdit *lineEditSpeedOne;
    QLineEdit *lineEditAngleOne;
    QPushButton *pushButtonSetOne;
    QLineEdit *lineEditPulesOne;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QGroupBox *groupBoxRight_2;
    QGridLayout *gridLayout;
    QLabel *label_10;
    QComboBox *comboBoxDirTwo;
    QLineEdit *lineEditLengthTwo;
    QLabel *label_11;
    QLineEdit *lineEditSpeedTwo;
    QLabel *label_9;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(913, 522);
        Widget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_11 = new QGridLayout(Widget);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_10 = new QGridLayout(groupBox_3);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setHorizontalSpacing(30);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer, 0, 3, 1, 1);

        checkBoxTwo = new QCheckBox(groupBox_3);
        checkBoxTwo->setObjectName(QString::fromUtf8("checkBoxTwo"));
        checkBoxTwo->setAutoExclusive(true);

        gridLayout_10->addWidget(checkBoxTwo, 0, 1, 1, 1);

        checkBoxOne = new QCheckBox(groupBox_3);
        checkBoxOne->setObjectName(QString::fromUtf8("checkBoxOne"));
        checkBoxOne->setChecked(true);
        checkBoxOne->setAutoExclusive(true);

        gridLayout_10->addWidget(checkBoxOne, 0, 0, 1, 1);

        checkBoxPoint = new QCheckBox(groupBox_3);
        checkBoxPoint->setObjectName(QString::fromUtf8("checkBoxPoint"));
        checkBoxPoint->setAutoExclusive(true);

        gridLayout_10->addWidget(checkBoxPoint, 0, 2, 1, 1);

        pushButtonSendMode = new QPushButton(groupBox_3);
        pushButtonSendMode->setObjectName(QString::fromUtf8("pushButtonSendMode"));
        pushButtonSendMode->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(255, 85, 0);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"	\n"
"	\n"
"	background-color: rgb(42, 218, 165);\n"
"}"));

        gridLayout_10->addWidget(pushButtonSendMode, 0, 4, 1, 1);


        gridLayout_11->addWidget(groupBox_3, 2, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(9, 9, 9, 9);
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textEditSend = new QTextEdit(groupBox_2);
        textEditSend->setObjectName(QString::fromUtf8("textEditSend"));

        gridLayout_2->addWidget(textEditSend, 0, 0, 1, 4);

        checkBoxSendHex = new QCheckBox(groupBox_2);
        checkBoxSendHex->setObjectName(QString::fromUtf8("checkBoxSendHex"));
        checkBoxSendHex->setChecked(true);
        checkBoxSendHex->setAutoExclusive(true);

        gridLayout_2->addWidget(checkBoxSendHex, 1, 0, 1, 1);

        checkBoxSendText = new QCheckBox(groupBox_2);
        checkBoxSendText->setObjectName(QString::fromUtf8("checkBoxSendText"));
        checkBoxSendText->setAutoExclusive(true);

        gridLayout_2->addWidget(checkBoxSendText, 1, 1, 1, 1);

        pushButtonSendSend = new QPushButton(groupBox_2);
        pushButtonSendSend->setObjectName(QString::fromUtf8("pushButtonSendSend"));

        gridLayout_2->addWidget(pushButtonSendSend, 1, 2, 1, 1);

        pushButtonSendClear = new QPushButton(groupBox_2);
        pushButtonSendClear->setObjectName(QString::fromUtf8("pushButtonSendClear"));

        gridLayout_2->addWidget(pushButtonSendClear, 1, 3, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBoxInch_2 = new QGroupBox(Widget);
        groupBoxInch_2->setObjectName(QString::fromUtf8("groupBoxInch_2"));
        gridLayout_7 = new QGridLayout(groupBoxInch_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        lineEditPointSpeed = new QLineEdit(groupBoxInch_2);
        lineEditPointSpeed->setObjectName(QString::fromUtf8("lineEditPointSpeed"));
        lineEditPointSpeed->setReadOnly(true);

        gridLayout_7->addWidget(lineEditPointSpeed, 3, 1, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        pushButtonPointAdd = new QPushButton(groupBoxInch_2);
        pushButtonPointAdd->setObjectName(QString::fromUtf8("pushButtonPointAdd"));

        gridLayout_6->addWidget(pushButtonPointAdd, 0, 0, 1, 1);

        pushButtonPointSub = new QPushButton(groupBoxInch_2);
        pushButtonPointSub->setObjectName(QString::fromUtf8("pushButtonPointSub"));

        gridLayout_6->addWidget(pushButtonPointSub, 0, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 1, 1, 1, 1);

        label_4 = new QLabel(groupBoxInch_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_7->addWidget(label_4, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_2, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer, 0, 1, 1, 1);

        label_18 = new QLabel(groupBoxInch_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_7->addWidget(label_18, 3, 2, 1, 1);


        gridLayout_4->addWidget(groupBoxInch_2, 0, 2, 1, 1);

        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        pushButtonClearRecv = new QPushButton(groupBox);
        pushButtonClearRecv->setObjectName(QString::fromUtf8("pushButtonClearRecv"));

        gridLayout_5->addWidget(pushButtonClearRecv, 1, 2, 1, 1);

        textEditRecv = new QTextEdit(groupBox);
        textEditRecv->setObjectName(QString::fromUtf8("textEditRecv"));
        textEditRecv->setReadOnly(false);

        gridLayout_5->addWidget(textEditRecv, 0, 0, 1, 3);

        checkBoxRecvHex = new QCheckBox(groupBox);
        checkBoxRecvHex->setObjectName(QString::fromUtf8("checkBoxRecvHex"));
        checkBoxRecvHex->setChecked(true);
        checkBoxRecvHex->setAutoExclusive(true);

        gridLayout_5->addWidget(checkBoxRecvHex, 1, 0, 1, 1);

        checkBoxRecvText = new QCheckBox(groupBox);
        checkBoxRecvText->setObjectName(QString::fromUtf8("checkBoxRecvText"));
        checkBoxRecvText->setChecked(false);
        checkBoxRecvText->setAutoExclusive(true);

        gridLayout_5->addWidget(checkBoxRecvText, 1, 1, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        gridLayout_4->setColumnStretch(0, 1);

        gridLayout_11->addLayout(gridLayout_4, 0, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(9, 9, 9, 9);
        leftTopGroupBox = new QGroupBox(Widget);
        leftTopGroupBox->setObjectName(QString::fromUtf8("leftTopGroupBox"));
        leftTopGroupBox->setMaximumSize(QSize(16777215, 16777215));
        leftTopGroupBox->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(leftTopGroupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(leftTopGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        comboBoxNum = new QComboBox(leftTopGroupBox);
        comboBoxNum->addItem(QString());
        comboBoxNum->addItem(QString());
        comboBoxNum->addItem(QString());
        comboBoxNum->addItem(QString());
        comboBoxNum->addItem(QString());
        comboBoxNum->addItem(QString());
        comboBoxNum->addItem(QString());
        comboBoxNum->addItem(QString());
        comboBoxNum->setObjectName(QString::fromUtf8("comboBoxNum"));

        gridLayout_3->addWidget(comboBoxNum, 2, 1, 1, 1);

        pushButtonUpdateCom = new QPushButton(leftTopGroupBox);
        pushButtonUpdateCom->setObjectName(QString::fromUtf8("pushButtonUpdateCom"));
        pushButtonUpdateCom->setStyleSheet(QString::fromUtf8("background-color:rgb(127,255,212);"));

        gridLayout_3->addWidget(pushButtonUpdateCom, 3, 1, 1, 1);

        comboBoxBaund = new QComboBox(leftTopGroupBox);
        comboBoxBaund->addItem(QString());
        comboBoxBaund->addItem(QString());
        comboBoxBaund->addItem(QString());
        comboBoxBaund->addItem(QString());
        comboBoxBaund->addItem(QString());
        comboBoxBaund->addItem(QString());
        comboBoxBaund->addItem(QString());
        comboBoxBaund->setObjectName(QString::fromUtf8("comboBoxBaund"));

        gridLayout_3->addWidget(comboBoxBaund, 1, 1, 1, 1);

        comboBoxName = new QComboBox(leftTopGroupBox);
        comboBoxName->setObjectName(QString::fromUtf8("comboBoxName"));

        gridLayout_3->addWidget(comboBoxName, 0, 1, 1, 1);

        label = new QLabel(leftTopGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(leftTopGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        pushButtonOpen = new QPushButton(leftTopGroupBox);
        pushButtonOpen->setObjectName(QString::fromUtf8("pushButtonOpen"));
        pushButtonOpen->setStyleSheet(QString::fromUtf8("background-color:rgb(127,255,212);"));

        gridLayout_3->addWidget(pushButtonOpen, 3, 0, 1, 1);

        pushButtonReset = new QPushButton(leftTopGroupBox);
        pushButtonReset->setObjectName(QString::fromUtf8("pushButtonReset"));

        gridLayout_3->addWidget(pushButtonReset, 4, 0, 1, 1);

        pushButtonStopFast = new QPushButton(leftTopGroupBox);
        pushButtonStopFast->setObjectName(QString::fromUtf8("pushButtonStopFast"));

        gridLayout_3->addWidget(pushButtonStopFast, 4, 1, 1, 1);


        gridLayout_9->addWidget(leftTopGroupBox, 0, 0, 1, 1);

        groupBoxRight = new QGroupBox(Widget);
        groupBoxRight->setObjectName(QString::fromUtf8("groupBoxRight"));
        groupBoxRight->setStyleSheet(QString::fromUtf8(""));
        gridLayout_8 = new QGridLayout(groupBoxRight);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_6 = new QLabel(groupBoxRight);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_8->addWidget(label_6, 1, 0, 1, 1);

        comboBoxDirOne = new QComboBox(groupBoxRight);
        comboBoxDirOne->addItem(QString());
        comboBoxDirOne->addItem(QString());
        comboBoxDirOne->setObjectName(QString::fromUtf8("comboBoxDirOne"));

        gridLayout_8->addWidget(comboBoxDirOne, 0, 1, 1, 1);

        label_5 = new QLabel(groupBoxRight);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_8->addWidget(label_5, 0, 0, 1, 1);

        lineEditSpeedOne = new QLineEdit(groupBoxRight);
        lineEditSpeedOne->setObjectName(QString::fromUtf8("lineEditSpeedOne"));

        gridLayout_8->addWidget(lineEditSpeedOne, 2, 1, 1, 1);

        lineEditAngleOne = new QLineEdit(groupBoxRight);
        lineEditAngleOne->setObjectName(QString::fromUtf8("lineEditAngleOne"));

        gridLayout_8->addWidget(lineEditAngleOne, 1, 1, 1, 1);

        pushButtonSetOne = new QPushButton(groupBoxRight);
        pushButtonSetOne->setObjectName(QString::fromUtf8("pushButtonSetOne"));

        gridLayout_8->addWidget(pushButtonSetOne, 5, 1, 1, 1);

        lineEditPulesOne = new QLineEdit(groupBoxRight);
        lineEditPulesOne->setObjectName(QString::fromUtf8("lineEditPulesOne"));
        lineEditPulesOne->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        lineEditPulesOne->setReadOnly(true);

        gridLayout_8->addWidget(lineEditPulesOne, 4, 1, 1, 1);

        label_8 = new QLabel(groupBoxRight);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_8->addWidget(label_8, 4, 0, 1, 1);

        label_7 = new QLabel(groupBoxRight);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_8->addWidget(label_7, 2, 0, 1, 1);

        label_12 = new QLabel(groupBoxRight);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_8->addWidget(label_12, 1, 2, 1, 1);

        label_13 = new QLabel(groupBoxRight);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_8->addWidget(label_13, 2, 2, 1, 1);

        label_14 = new QLabel(groupBoxRight);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_8->addWidget(label_14, 4, 2, 1, 1);


        gridLayout_9->addWidget(groupBoxRight, 0, 1, 1, 1);

        groupBoxRight_2 = new QGroupBox(Widget);
        groupBoxRight_2->setObjectName(QString::fromUtf8("groupBoxRight_2"));
        groupBoxRight_2->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(groupBoxRight_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_10 = new QLabel(groupBoxRight_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        comboBoxDirTwo = new QComboBox(groupBoxRight_2);
        comboBoxDirTwo->addItem(QString());
        comboBoxDirTwo->addItem(QString());
        comboBoxDirTwo->setObjectName(QString::fromUtf8("comboBoxDirTwo"));

        gridLayout->addWidget(comboBoxDirTwo, 2, 1, 1, 1);

        lineEditLengthTwo = new QLineEdit(groupBoxRight_2);
        lineEditLengthTwo->setObjectName(QString::fromUtf8("lineEditLengthTwo"));

        gridLayout->addWidget(lineEditLengthTwo, 0, 1, 1, 1);

        label_11 = new QLabel(groupBoxRight_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 0, 0, 1, 1);

        lineEditSpeedTwo = new QLineEdit(groupBoxRight_2);
        lineEditSpeedTwo->setObjectName(QString::fromUtf8("lineEditSpeedTwo"));

        gridLayout->addWidget(lineEditSpeedTwo, 1, 1, 1, 1);

        label_9 = new QLabel(groupBoxRight_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        label_15 = new QLabel(groupBoxRight_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 0, 2, 1, 1);

        label_16 = new QLabel(groupBoxRight_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 1, 2, 1, 1);


        gridLayout_9->addWidget(groupBoxRight_2, 0, 2, 1, 1);

        gridLayout_9->setColumnStretch(0, 1);
        gridLayout_9->setColumnStretch(1, 1);
        gridLayout_9->setColumnStretch(2, 1);

        gridLayout_11->addLayout(gridLayout_9, 1, 0, 1, 1);

        label_17 = new QLabel(Widget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_11->addWidget(label_17, 3, 0, 1, 1);

        gridLayout_11->setRowStretch(0, 4);

        retranslateUi(Widget);

        comboBoxNum->setCurrentIndex(0);
        comboBoxBaund->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\215\225\350\275\264\346\255\245\350\277\233\347\263\273\347\273\237\346\216\247\345\210\266\345\267\245\345\205\267", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "\346\250\241\345\274\217\351\200\211\346\213\251", nullptr));
        checkBoxTwo->setText(QCoreApplication::translate("Widget", "\345\257\270\345\212\250", nullptr));
        checkBoxOne->setText(QCoreApplication::translate("Widget", "\347\224\265\346\234\272\346\216\247\345\210\266", nullptr));
        checkBoxPoint->setText(QCoreApplication::translate("Widget", "\347\202\271\345\212\250", nullptr));
        pushButtonSendMode->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\344\277\241\346\201\257\345\214\272:", nullptr));
        checkBoxSendHex->setText(QCoreApplication::translate("Widget", "HEX", nullptr));
        checkBoxSendText->setText(QCoreApplication::translate("Widget", "\346\226\207\346\234\254\346\230\276\347\244\272", nullptr));
        pushButtonSendSend->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        pushButtonSendClear->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244\345\217\221\351\200\201", nullptr));
        groupBoxInch_2->setTitle(QCoreApplication::translate("Widget", "\347\202\271\345\212\250", nullptr));
        lineEditPointSpeed->setText(QString());
        lineEditPointSpeed->setPlaceholderText(QString());
        pushButtonPointAdd->setText(QCoreApplication::translate("Widget", "\346\255\243\345\220\221", nullptr));
        pushButtonPointSub->setText(QCoreApplication::translate("Widget", "\345\217\215\345\220\221", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\351\200\237\345\272\246\357\274\232", nullptr));
        label_18->setText(QCoreApplication::translate("Widget", "x(10^-4)rad/s", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\344\277\241\346\201\257\345\214\272", nullptr));
        pushButtonClearRecv->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272\346\216\245\346\224\266", nullptr));
        checkBoxRecvHex->setText(QCoreApplication::translate("Widget", "HEX", nullptr));
        checkBoxRecvText->setText(QCoreApplication::translate("Widget", "\346\226\207\346\234\254\346\230\276\347\244\272", nullptr));
        leftTopGroupBox->setTitle(QCoreApplication::translate("Widget", "\344\270\262\345\217\243", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        comboBoxNum->setItemText(0, QCoreApplication::translate("Widget", "1", nullptr));
        comboBoxNum->setItemText(1, QCoreApplication::translate("Widget", "2", nullptr));
        comboBoxNum->setItemText(2, QCoreApplication::translate("Widget", "4", nullptr));
        comboBoxNum->setItemText(3, QCoreApplication::translate("Widget", "8", nullptr));
        comboBoxNum->setItemText(4, QCoreApplication::translate("Widget", "16", nullptr));
        comboBoxNum->setItemText(5, QCoreApplication::translate("Widget", "32", nullptr));
        comboBoxNum->setItemText(6, QCoreApplication::translate("Widget", "64", nullptr));
        comboBoxNum->setItemText(7, QCoreApplication::translate("Widget", "128", nullptr));

        pushButtonUpdateCom->setText(QCoreApplication::translate("Widget", "\345\210\267\346\226\260\344\270\262\345\217\243", nullptr));
        comboBoxBaund->setItemText(0, QCoreApplication::translate("Widget", "115200", nullptr));
        comboBoxBaund->setItemText(1, QCoreApplication::translate("Widget", "38400", nullptr));
        comboBoxBaund->setItemText(2, QCoreApplication::translate("Widget", "19200", nullptr));
        comboBoxBaund->setItemText(3, QCoreApplication::translate("Widget", "9600", nullptr));
        comboBoxBaund->setItemText(4, QCoreApplication::translate("Widget", "4800", nullptr));
        comboBoxBaund->setItemText(5, QCoreApplication::translate("Widget", "2400", nullptr));
        comboBoxBaund->setItemText(6, QCoreApplication::translate("Widget", "1200", nullptr));

        label->setText(QCoreApplication::translate("Widget", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\347\273\206\345\210\206\346\225\260\351\207\217\357\274\232", nullptr));
        pushButtonOpen->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        pushButtonReset->setText(QCoreApplication::translate("Widget", "\345\244\215\344\275\215", nullptr));
        pushButtonStopFast->setText(QCoreApplication::translate("Widget", "\346\200\245\345\201\234", nullptr));
        groupBoxRight->setTitle(QCoreApplication::translate("Widget", "\347\224\265\346\234\272\346\216\247\345\210\266", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\350\247\222\345\272\246\357\274\232", nullptr));
        comboBoxDirOne->setItemText(0, QCoreApplication::translate("Widget", "\346\255\243\350\275\254", nullptr));
        comboBoxDirOne->setItemText(1, QCoreApplication::translate("Widget", "\345\217\215\350\275\254", nullptr));

        label_5->setText(QCoreApplication::translate("Widget", "\346\226\271\345\220\221\357\274\232", nullptr));
        pushButtonSetOne->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\350\204\211\345\206\262\346\225\260\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\350\275\254\351\200\237\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("Widget", "x(10^-4)rad", nullptr));
        label_13->setText(QCoreApplication::translate("Widget", "x(10^-4)rad/s", nullptr));
        label_14->setText(QCoreApplication::translate("Widget", "\344\270\252", nullptr));
        groupBoxRight_2->setTitle(QCoreApplication::translate("Widget", "\345\257\270\345\212\250 (\346\242\257\345\275\242\345\212\240\345\207\217\351\200\237)", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "\351\200\237\345\272\246\357\274\232", nullptr));
        comboBoxDirTwo->setItemText(0, QCoreApplication::translate("Widget", "\345\217\215\350\275\254", nullptr));
        comboBoxDirTwo->setItemText(1, QCoreApplication::translate("Widget", "\346\255\243\350\275\254", nullptr));

        label_11->setText(QCoreApplication::translate("Widget", "\351\225\277\345\272\246\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "\346\226\271\345\220\221\357\274\232", nullptr));
        label_15->setText(QCoreApplication::translate("Widget", "x(10^-2)mm", nullptr));
        label_16->setText(QCoreApplication::translate("Widget", "x(10^-4)rad/s", nullptr));
        label_17->setText(QCoreApplication::translate("Widget", "Author: DuskyBook    Github : https://github.com/jinsechaochen/Epigynous-Computer-for-Single-axis-Stepper-Motor-System     Version: 2.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
