#include "mywindow_4.h"

mywindow_4::mywindow_4(void)
{
	setWindowFlags(Qt::CustomizeWindowHint);
	neimen = true;
	waimen = true;
	light = true;
	position = 0;
	tt = 0;
	setupUi(this);
	time = new QTimer;
	time->start(1000);
	time->stop();

//	horizontalSlider->setRange(0,10);
//	connect(horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(myslot_change(int)));
	connect(pushButton,SIGNAL(clicked()),this,SLOT(myslot_open_neimen()));
	connect(pushButton_2,SIGNAL(clicked()),this,SLOT(myslot_open_waimen()));
	connect(pushButton_3,SIGNAL(clicked()),this,SLOT(myslot_open_light()));
	connect(pushButton_4,SIGNAL(clicked()),this,SLOT(myslot_back()));
//	connect(time,SIGNAL(timeout()),this,SLOT(myslot_time()));
}
/*
void mywindow::mysetmycom()
{
	QTimer *readTimer;
	mycom = new Posix_QextSerialPort(MYCOM_DEVICE,QextSerialBase::Polling);

	readTimer = new QTimer(this);
	readTimer->start(100);
	//信号和槽函数关联，延时一段时间，进行读串口操作
	connect(readTimer,SIGNAL(timeout()),this,SLOT(myreadmycom()));

	//定义串口对象，指定串口名和查询模式，这里使用事件驱动EventDriven
	//以读写方式打开串口
	mycom->open(QIODevice::ReadWrite);
	//波特率设置，我们设置为9600
	mycom->setBaudRate(BAUD115200);
	//数据位设置，我们设置为8位数据位
	mycom->setDataBits(DATA_8);
	//奇偶校验设置，我们设置为无校验
	mycom->setParity(PAR_NONE);
	//停止位设置，我们设置为1位停止位
	mycom->setStopBits(STOP_1);
	//数据流控制设置，我们设置为无数据流控制
	mycom->setFlowControl(FLOW_OFF);
	//延时设置，我们设置为延时10ms
	mycom->setTimeout(10);
	//信号和槽函数关联，当串口缓冲区有数据时，进行读串口操作
	connect(mycom,SIGNAL(readyRead()),this,SLOT(myreadmycom()));
	   connect(this,SIGNAL(mysignal_send(Posix_QextSerialPort *)),b1,SLOT(myreadmycom(Posix_QextSerialPort *)));
	   connect(this,SIGNAL(mysignal_send(Posix_QextSerialPort *)),b2,SLOT(myreadmycom(Posix_QextSerialPort *)));
	   connect(this,SIGNAL(mysignal_send(Posix_QextSerialPort *)),b3,SLOT(myreadmycom(Posix_QextSerialPort *)));

}
*/
void mywindow_4::myslot_open_light(void)
{
	if(light == true)
	{
        pushButton_3->setIcon(QPixmap(":/pic/on.bmp"));
		mywritemycom_light_on();
	}
	else
	{
        pushButton_3->setIcon(QPixmap(":/pic/off.bmp"));
		mywritemycom_light_off();
	}
	light = !light;
}
void mywindow_4::myslot_open_neimen(void)
{
	if(neimen == true)
	{
        pushButton_2->setIcon(QPixmap(":/pic/on.bmp"));
		mywritemycom_neimen_open();
	}
	else
	{
        pushButton_2->setIcon(QPixmap(":/pic/off.bmp"));
		mywritemycom_neimen_close();
	}
	neimen = !neimen;
}
void mywindow_4::myslot_open_waimen(void)
{
	if(waimen == true)
	{
        pushButton->setIcon(QPixmap(":/pic/on.bmp"));
		mywritemycom_waimen_open();
	}
	else
	{
        pushButton->setIcon(QPixmap(":/pic/off.bmp"));
		mywritemycom_waimen_close();
	}
	waimen = !waimen;
}
void mywindow_4::myslot_back(void)
{
	emit mysignal_back();
}
void mywindow_4::myreadmycom(Posix_QextSerialPort *tmp,UART_Format t1) //读取串口数据并显示出来
{
	mycom = tmp;
	UART_Format msg = t1;	
	//如果可用数据大于或等于16字节再读取
	//	if(mycom->bytesAvailable() == 16 )
	//	{
	//		mycom->readData((char *)&msg,(qint64)sizeof(msg));
	if(msg.NodeID == 8 && msg.Command == 1)
	{
		if(msg.Data[0] == 0)
		{
			myslot_open_waimen();	
			myslot_open_neimen();	
            label_7->setPixmap(QPixmap(":/pic/yes.png").scaled(100,50));
		}
		else
		{
			myslot_open_waimen();	
			myslot_open_neimen();	
        label_7->setPixmap(QPixmap(":/pic/no.png").scaled(100,50));
		}
		
	}
	//	}
	//	else
	//	{
	//		mycom->readAll();
	//	}
}

void mywindow_4::mywritemycom_light_on(void) //写数据
{
	//以ASCII码形式将数据写入串口
	//UART_Format msg;	
	UART_Format msg;
	bzero((char*)&msg,sizeof(msg));	
	msg.Header_1 = 0xcc;
	msg.Header_2 = 0xee;
	msg.NodeSeq = 0x1;
	msg.NodeID = 0x9;
	msg.Command = 0xc;
	msg.Tailer = 0xff;
	//uart_send(&msg,sizeof(msg));
	mycom->writeData((char *)&msg,(qint64)sizeof(msg));
	//	qDebug() << "write: "<<mycom->bytesToWrite()<<"bytes";
}
void mywindow_4::mywritemycom_light_off(void) //写数据
{
	//以ASCII码形式将数据写入串口
	//UART_Format msg;	
	UART_Format msg;
	bzero((char*)&msg,sizeof(msg));	
	msg.Header_1 = 0xcc;
	msg.Header_2 = 0xee;
	msg.NodeSeq = 0x1;
	msg.NodeID = 0x9;
	msg.Command = 0xd;
	msg.Tailer = 0xff;
	//uart_send(&msg,sizeof(msg));
	mycom->writeData((char *)&msg,(qint64)sizeof(msg));
	//	qDebug() << "write: "<<mycom->bytesToWrite()<<"bytes";
}
void mywindow_4::mywritemycom_waimen_open(void) //写数据
{
	//以ASCII码形式将数据写入串口
	//UART_Format msg;	
	UART_Format msg;
	bzero((char*)&msg,sizeof(msg));	
	msg.Header_1 = 0xcc;
	msg.Header_2 = 0xee;
	msg.NodeSeq = 0x1;
	msg.NodeID = 0x9;
	msg.Command = 0x9;
	msg.Tailer = 0xff;
	//uart_send(&msg,sizeof(msg));
	mycom->writeData((char *)&msg,(qint64)sizeof(msg));
	//	qDebug() << "write: "<<mycom->bytesToWrite()<<"bytes";
}
void mywindow_4::mywritemycom_waimen_close(void) //写数据
{
	//以ASCII码形式将数据写入串口
	//UART_Format msg;	
	UART_Format msg;
	bzero((char*)&msg,sizeof(msg));	
	msg.Header_1 = 0xcc;
	msg.Header_2 = 0xee;
	msg.NodeSeq = 0x1;
	msg.NodeID = 0x9;
	msg.Command = 0xb;
	msg.Tailer = 0xff;
	//uart_send(&msg,sizeof(msg));
	mycom->writeData((char *)&msg,(qint64)sizeof(msg));
	//	qDebug() << "write: "<<mycom->bytesToWrite()<<"bytes";
}

void mywindow_4::mywritemycom_neimen_open(void) //写数据
{
	//以ASCII码形式将数据写入串口
	//UART_Format msg;	
	UART_Format msg;
	bzero((char*)&msg,sizeof(msg));	
	msg.Header_1 = 0xcc;
	msg.Header_2 = 0xee;
	msg.NodeSeq = 0x1;
	msg.NodeID = 0x9;
	msg.Command = 0x9;
	msg.Tailer = 0xff;
	//uart_send(&msg,sizeof(msg));
	mycom->writeData((char *)&msg,(qint64)sizeof(msg));
	//	qDebug() << "write: "<<mycom->bytesToWrite()<<"bytes";
}
void mywindow_4::mywritemycom_neimen_close(void) //写数据
{
	//以ASCII码形式将数据写入串口
	//UART_Format msg;	
	UART_Format msg;
	bzero((char*)&msg,sizeof(msg));	
	msg.Header_1 = 0xcc;
	msg.Header_2 = 0xee;
	msg.NodeSeq = 0x1;
	msg.NodeID = 0x9;
	msg.Command = 0xb;
	msg.Tailer = 0xff;
	//uart_send(&msg,sizeof(msg));
	mycom->writeData((char *)&msg,(qint64)sizeof(msg));
	//	qDebug() << "write: "<<mycom->bytesToWrite()<<"bytes";
}

