#ifndef MYWINDOW_1_H
#define MYWINDOW_1_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
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
#include <QHBoxLayout>
#include <stdio.h>
#include <QLCDNumber>
#include <QTimer>
#include "posix_qextserialport.h"
#include "proto.h"

#define MYCOM_DEVICE		"/dev/ttySAC0"

class mywindow_1:public QWidget
{
	Q_OBJECT
		QLabel *main;
	QLabel *wendu;
	QLabel *wendu_a;
	QLabel *shidu;
	QLabel *shidu_a;

	QLabel *status1;
	QLabel *status2;
	bool f_wendu;
	bool f_shidu;

	QLCDNumber *wd;
	QLCDNumber *sd;
	
	Posix_QextSerialPort *mycom; 
	QPushButton *btn_wendu;
	QPushButton *btn_shidu;

	QVBoxLayout *layout;

	QHBoxLayout *layout1;
	QHBoxLayout *layout2;
	QHBoxLayout *layout3;
	QHBoxLayout *layout4;


	QPushButton *btn;
	public:
		mywindow_1(void);
	public slots:
		void myslot_back(void);
		void myslot_open_wendu(void);
		void myslot_open_shidu(void);
		void myreadmycom(Posix_QextSerialPort *,UART_Format);
		void mywritemycom_wendu_open(void);
		void mywritemycom_wendu_close(void);
		void mywritemycom_shidu_open(void);
		void mywritemycom_shidu_close(void);
signals:
	void mysignal_back(void);
};

#endif
