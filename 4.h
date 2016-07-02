/********************************************************************************
** Form generated from reading ui file '4.ui'
**
** Created: Fri Jun 24 09:29:12 2016
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef _4_H
#define _4_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_1
{
public:
    QPushButton *pushButton_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(800, 480);
        QPalette palette;
		palette.setBrush(QPalette::Background,QPixmap(":/pic/background5.jpg"));
		Form->setPalette(palette); 
		pushButton_4 = new QPushButton(Form);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20,400, 85, 27));
        widget = new QWidget(Form);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 771, 380));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_2);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } 
	// setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        pushButton_4->setIcon(QPixmap(":/pic/back.png"));
	    pushButton_4->setIconSize(QSize(80,80));
		pushButton_4->setMaximumSize(80,80);
		pushButton_4->setMinimumSize(80,80);
		pushButton_4->setFlat(true);

//		pushButton_4->setText(QApplication::translate("Form", "PushButton", 0, QApplication::UnicodeUTF8));
        label->setPixmap(QPixmap(":/pic/waimen_1.png").scaled(100,50));
//		label->setText(QApplication::translate("Form", "\345\244\226\351\227\250", 0, QApplication::UnicodeUTF8));
        //label_2->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setPixmap(QPixmap(":/pic/waimenstatus.png").scaled(100,50));
        
		//label_7->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_6->setPixmap(QPixmap(":/pic/waimen.png").scaled(100,50));
        
	//	label_6->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_7->setPixmap(QPixmap(":/pic/no.png").scaled(100,50));
        //pushButton_2->setText(QApplication::translate("Form", "PushButton", 0, QApplication::UnicodeUTF8));
      
	 // 	label_3->setText(QApplication::translate("Form", "\345\206\205\351\227\250", 0, QApplication::UnicodeUTF8));
        label_3->setPixmap(QPixmap(":/pic/neimen_1.png").scaled(100,50));
        label_4->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setPixmap(QPixmap(":/pic/neimen.png").scaled(100,50));
        //pushButton->setText(QApplication::translate("Form", "PushButton", 0, QApplication::UnicodeUTF8));
       // label_5->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_5->setPixmap(QPixmap(":/pic/mendeng.png").scaled(100,50));
       // pushButton_3->setText(QApplication::translate("Form", "PushButtonttttt", 0, QApplication::UnicodeUTF8));
        pushButton_3->setIcon(QPixmap(":/pic/off.bmp"));
	    pushButton_3->setIconSize(QSize(80,80));
		pushButton_3->setMaximumSize(80,80);
		pushButton_3->setMinimumSize(80,80);
		pushButton_3->setFlat(true);
        pushButton_2->setIcon(QPixmap(":/pic/off.bmp"));
	    pushButton_2->setIconSize(QSize(80,80));
		pushButton_2->setMaximumSize(80,80);
		pushButton_2->setMinimumSize(80,80);
		pushButton_2->setFlat(true);
        pushButton->setIcon(QPixmap(":/pic/off.bmp"));
	    pushButton->setIconSize(QSize(80,80));
		pushButton->setMaximumSize(80,80);
		pushButton->setMinimumSize(80,80);
		pushButton->setFlat(true);
        Q_UNUSED(Form);
    }
   	// retranslateUi

};

namespace Ui_1 {
    class Form: public Ui_Form_1 {};
} 
// namespace Ui

QT_END_NAMESPACE

#endif 
// _4_H
