#ifndef MYWINDOW_4_H
#define MYWINDOW_4_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <stdio.h>
#include <QLCDNumber>
#include <QTimer>
#include "posix_qextserialport.h"
#include "proto.h"
#include "4.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QString>
#include <QChar>
#include <QToolBar>
#include <QMainWindow>
#include <QAction>
#include <QMenuBar>
#include <QTreeWidget>
#include <QFileDialog>
#include <QStringList>
#include <iostream>
#include <QTextStream>
#include <QTabWidget>

#define MYCOM_DEVICE		"/dev/ttySAC0"

class mywindow_4:public QWidget,public Ui_Form_1
{

	Q_OBJECT
		Posix_QextSerialPort *mycom;
		QTimer *time;
	
		bool neimen;
		bool waimen;
		bool light;
		int position;
		int tt;

	public:
	    mywindow_4(void);
	public slots:
				void myslot_back(void);
		    	void myslot_open_light(void);
		    	void myslot_open_neimen(void);
		    	void myslot_open_waimen(void);
				void myreadmycom(Posix_QextSerialPort *,UART_Format);
	//	    	void myslot_change(int);
	//	    	void myslot_time(void);
	//			void mywritemycom_zhengzhuan(void);
	//			void mywritemycom_fanzhuan(void);
	//			void mywritemycom_stop(void);
				void mywritemycom_light_on(void);
			void mywritemycom_light_off(void);

				void mywritemycom_neimen_open(void);
				void mywritemycom_neimen_close(void);
				void mywritemycom_waimen_open(void);
				void mywritemycom_waimen_close(void);
		signals:
			void mysignal_back(void);
};

#endif
