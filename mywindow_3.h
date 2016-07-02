#ifndef MYWINDOW_3_H
#define MYWINDOW_3_H

#include <QString>
#include <QLineEdit>
#include <QTextEdit>
#include <QTcpSocket>
#include <QTcpServer>
#include <QWidget>
#include <QLabel>
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
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QRadioButton>
#include <stdio.h>
#include <QLCDNumber>
#include <QTimer>
#include "posix_qextserialport.h"
#include "proto.h"
#include "mywindow3.h"

#define MYCOM_DEVICE		"/dev/ttySAC0"

class mywindow_3:public QWidget,public Ui_Form
{

	Q_OBJECT
		Posix_QextSerialPort *mycom;
		QTimer *time;
	
		bool flag;
		int position;
		int tt;

	public:
	    mywindow_3(void);
	public slots:
				void myslot_back(void);
		    	void myslot_open_light(void);
				void myreadmycom(Posix_QextSerialPort *,UART_Format);
		    	void myslot_change(int);
		    	void myslot_time(void);
				void mywritemycom_zhengzhuan(void);
				void mywritemycom_fanzhuan(void);
				void mywritemycom_stop(void);
				void mywritemycom_light_on(void);
				void mywritemycom_light_off(void);

		/*		void mywritemycom_wendu_open(void);
				void mywritemycom_wendu_close(void);
				void mywritemycom_shidu_open(void);
				void mywritemycom_shidu_close(void);
				*/
		signals:
			void mysignal_back(void);
};

#endif
