#ifndef MYWINDOW_2_H
#define MYWINDOW_2_H

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
#include <QPushButton>
#include <QHBoxLayout>
#include <stdio.h>
#include <QLCDNumber>
#include <QTimer>
#include <QMovie>
#include "posix_qextserialport.h"
#include "proto.h"

#define MYCOM_DEVICE		"/dev/ttySAC0"

class mywindow_2:public QWidget
{
	Q_OBJECT
		QLabel *main;

	QPushButton *btn;
	QPushButton *btn_open;
	QVBoxLayout *layout;
	QHBoxLayout *layout1;
	QHBoxLayout *layout2;
	QHBoxLayout *layout3;
	bool flag;
	QMovie *movie;
	QLabel *label1;
	QLabel *label2;
	QLabel *label3;
	Posix_QextSerialPort *mycom;

	public:
		mywindow_2(void);
	public slots:
		void myslot_back(void);
		void myslot_open(void);
		void myreadmycom(Posix_QextSerialPort *,UART_Format);
		void mywritemycom_f_close(void);
		void mywritemycom_f_open(void);
signals:
	void mysignal_back(void);
};

#endif
