/********************************************************************************
 ** Form generated from reading ui file 'window_3.ui'
 **
 ** Created: Wed Jun 15 17:23:13 2016
 **      by: Qt User Interface Compiler version 4.5.0
 **
 ** WARNING! All changes made in this file will be lost when recompiling ui file!
 ********************************************************************************/

#ifndef MYWINDOW3_H
#define MYWINDOW3_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
	public:
		QWidget *widget;
		QVBoxLayout *verticalLayout_3;
		QHBoxLayout *horizontalLayout_7;
		QVBoxLayout *verticalLayout;
		QLabel *label_5;
		QHBoxLayout *horizontalLayout;
		QLabel *label;
		QLCDNumber *lcdNumber;
		QHBoxLayout *horizontalLayout_2;
		QLabel *label_2;
		QLabel *label_3;
		QHBoxLayout *horizontalLayout_3;
		QLabel *label_4;
		QLCDNumber *lcdNumber_2;
		QVBoxLayout *verticalLayout_2;
		QLabel *label_6;
		QHBoxLayout *horizontalLayout_4;
		QLabel *label_7;
		QLabel *label_8;
		QHBoxLayout *horizontalLayout_5;
		QLabel *label_9;
		QSlider *horizontalSlider;
		QHBoxLayout *horizontalLayout_6;
		QLabel *label_10;
		QPushButton *pushButton;
		QPushButton *pushButton_2;

		void setupUi(QWidget *Form)
		{

			QPalette rpalette;
			rpalette.setBrush(QPalette::Background,QPixmap(":/pic/background4.jpg"));
			Form->setPalette(rpalette); 
			if (Form->objectName().isEmpty())
				Form->setObjectName(QString::fromUtf8("Form"));
			Form->resize(800, 480);
			widget = new QWidget(Form);
			widget->setObjectName(QString::fromUtf8("widget"));
			widget->setGeometry(QRect(0, 0, 801, 481));
			verticalLayout_3 = new QVBoxLayout(widget);
			verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
			verticalLayout_3->setContentsMargins(0, 0, 0, 0);
			horizontalLayout_7 = new QHBoxLayout();
			horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
			verticalLayout = new QVBoxLayout();
			verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
			label_5 = new QLabel(widget);
			label_5->setObjectName(QString::fromUtf8("label_5"));

			verticalLayout->addWidget(label_5);

			horizontalLayout = new QHBoxLayout();
			horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
			label = new QLabel(widget);
			label->setObjectName(QString::fromUtf8("label"));

			horizontalLayout->addWidget(label);

			lcdNumber = new QLCDNumber(widget);
			lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

			horizontalLayout->addWidget(lcdNumber);


			verticalLayout->addLayout(horizontalLayout);

			horizontalLayout_2 = new QHBoxLayout();
			horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
			label_2 = new QLabel(widget);
			label_2->setObjectName(QString::fromUtf8("label_2"));

			horizontalLayout_2->addWidget(label_2);

			label_3 = new QLabel(widget);
			label_3->setObjectName(QString::fromUtf8("label_3"));

			horizontalLayout_2->addWidget(label_3);


			verticalLayout->addLayout(horizontalLayout_2);

			horizontalLayout_3 = new QHBoxLayout();
			horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
			label_4 = new QLabel(widget);
			label_4->setObjectName(QString::fromUtf8("label_4"));

			horizontalLayout_3->addWidget(label_4);

			lcdNumber_2 = new QLCDNumber(widget);
			lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));

			horizontalLayout_3->addWidget(lcdNumber_2);


			verticalLayout->addLayout(horizontalLayout_3);


			horizontalLayout_7->addLayout(verticalLayout);

			verticalLayout_2 = new QVBoxLayout();
			verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
			label_6 = new QLabel(widget);
			label_6->setObjectName(QString::fromUtf8("label_6"));

			verticalLayout_2->addWidget(label_6);

			horizontalLayout_4 = new QHBoxLayout();
			horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
			label_7 = new QLabel(widget);
			label_7->setObjectName(QString::fromUtf8("label_7"));

			horizontalLayout_4->addWidget(label_7);

			label_8 = new QLabel(widget);
			label_8->setObjectName(QString::fromUtf8("label_8"));

			horizontalLayout_4->addWidget(label_8);


			verticalLayout_2->addLayout(horizontalLayout_4);

			horizontalLayout_5 = new QHBoxLayout();
			horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
			label_9 = new QLabel(widget);
			label_9->setObjectName(QString::fromUtf8("label_9"));

			horizontalLayout_5->addWidget(label_9);

			horizontalSlider = new QSlider(widget);
			horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
			horizontalSlider->setOrientation(Qt::Horizontal);


			horizontalLayout_5->addStretch();
			horizontalLayout_5->addWidget(horizontalSlider);
			horizontalLayout_5->addStretch();


			verticalLayout_2->addLayout(horizontalLayout_5);

			horizontalLayout_6 = new QHBoxLayout();
			horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
			label_10 = new QLabel(widget);
			label_10->setObjectName(QString::fromUtf8("label_10"));

			horizontalLayout_6->addWidget(label_10);

			pushButton = new QPushButton(widget);
			pushButton->setObjectName(QString::fromUtf8("pushButton"));

			horizontalLayout_6->addWidget(pushButton);
			horizontalLayout_6->addStretch();


			verticalLayout_2->addLayout(horizontalLayout_6);


			horizontalLayout_7->addLayout(verticalLayout_2);


			verticalLayout_3->addLayout(horizontalLayout_7);

			pushButton_2 = new QPushButton(widget);
			pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

			verticalLayout_3->addWidget(pushButton_2);


			retranslateUi(Form);

			QMetaObject::connectSlotsByName(Form);
		} 
		// setupUi

		void retranslateUi(QWidget *Form)
		{
			Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
		//	label_5->setText(QApplication::translate("Form", "\346\225\260\346\215\256\351\207\207\351\233\206", 0, QApplication::UnicodeUTF8));
			label->setText(QApplication::translate("Form", "\345\205\211\347\205\247\345\200\274\357\274\232", 0, QApplication::UnicodeUTF8));
			label->setPixmap(QPixmap(":/pic/light_c.png").scaled(100,50));
		//	label_2->setText(QApplication::translate("Form", "\345\205\211\347\205\247\345\274\272\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
			label_2->setPixmap(QPixmap(":/pic/light_power.png").scaled(100,50));
	//		label_3->setText(QApplication::translate("Form", "\345\274\272/\345\274\261", 0, QApplication::UnicodeUTF8));
			label_3->setPixmap(QPixmap(":/pic/big.png").scaled(100,50));
			//    label_4->setText(QApplication::translate("Form", "\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));
			label_4->setPixmap(QPixmap(":/pic/wendu_3.png").scaled(100,50));
		//	label_6->setText(QApplication::translate("Form", "\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
	//		label_7->setText(QApplication::translate("Form", "\347\252\227\345\270\230\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
			label_7->setPixmap(QPixmap(":/pic/w_status.png").scaled(100,50));
//			label_8->setText(QApplication::translate("Form", "\345\215\212\351\201\256", 0, QApplication::UnicodeUTF8));
			label_8->setPixmap(QPixmap(":/pic/all.png").scaled(100,50));
			//label_9->setText(QApplication::translate("Form", "\346\211\213\345\212\250\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
			label_9->setPixmap(QPixmap(":/pic/shoudongtiaojie.png").scaled(100,50));
		//	label_10->setText(QApplication::translate("Form", "\345\256\244\347\201\257", 0, QApplication::UnicodeUTF8));
			label_10->setPixmap(QPixmap(":/pic/shideng.png").scaled(100,50));
			//	pushButton->setText(QApplication::translate("Form", "\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));

			pushButton->setFlat(true);
			pushButton->setIcon(QPixmap(":/pic/off.bmp"));
			pushButton->setIconSize(QSize(100,80));

			pushButton_2->setIcon(QPixmap(":/pic/back.png"));
			pushButton_2->setIconSize(QSize(80,80));
			pushButton_2->setMaximumSize(80,80);
			pushButton_2->setMinimumSize(80,80);
			pushButton_2->setFlat(true);
			Q_UNUSED(Form);
		}
	   	// retranslateUi

};

namespace Ui 
{
	class Form: public Ui_Form {};
} 
// namespace Ui

QT_END_NAMESPACE

#endif 
// MYWINDOW_3_H
