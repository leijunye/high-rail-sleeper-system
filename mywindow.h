#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QString>
#include <stdio.h>
#include "mywindow_1.h"
#include "mywindow_2.h"
#include "mywindow_3.h"
#include "mywindow_4.h"
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
#include "posix_qextserialport.h"
#include "proto.h"
#include <QTime>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <QTcpServer>
#include <QTcpSocket>


class mywindow:public QWidget
{
	Q_OBJECT
		Posix_QextSerialPort *mycom;
		int wendu;
		int shidu;
		int guang;
		int smoke;

		QTcpServer *tcp;
		QTcpSocket *tcp_client;
		QLCDNumber *times;
		QTimer *time;
		QLabel *label;
		QLabel *label1;
		QLabel *label2;
		QLabel *label3;
		QLabel *label4;
		
		QPushButton *btn1;
		QPushButton *btn2;
 		QPushButton *btn3;
		QPushButton *btn4;
		QPushButton *btn5;
		
		QVBoxLayout *vlayout;
		QHBoxLayout *hlayout1;
		QHBoxLayout *hlayout3;
		QHBoxLayout *hlayout2;


		mywindow_1 *b1;
		mywindow_2 *b2;
		mywindow_3 *b3;
		mywindow_4 *b4;
		char *explain(char *buf);
		char *file_type(char *buf);
		void mysetmycom(void);
		void myweb(void);
		void show_change(int fd);
	public:
    	mywindow(void);
	public slots:
		void myslot_exit(void);
		void myslot_b1(void);
		void myslot_b2(void);
		void myslot_b3(void);
		void myslot_b4(void);
		void myslot_show4(void);
		void myslot_show1(void);
		void myslot_show2(void);
		void myslot_show3(void);
		void myslot_time(void);
		void myreadmycom(void);
		void myslot_readall(void);
		void myslot_new(void);
signals:
		void mysignal_send(Posix_QextSerialPort *,UART_Format);	
};

#endif
