#include "mywindow_1.h"

mywindow_1::mywindow_1(void)
{
	mycom = NULL;
	f_wendu = true;
	f_shidu = true;
	this->setMaximumSize(800,480);
	this->setMinimumSize(800,480);

	setWindowFlags(Qt::CustomizeWindowHint);
	QPalette palette;
	main = new QLabel;
	wendu = new QLabel;
	wendu->setPixmap(QPixmap(":/pic/wendu.png").scaled(200,100));
	wendu_a = new QLabel;
	wendu_a->setPixmap(QPixmap(":/pic/wenzheng.bmp").scaled(200,100));

	shidu = new QLabel;
	shidu->setPixmap(QPixmap(":/pic/shidu.png").scaled(200,100));
	shidu_a = new QLabel;
	shidu_a->setPixmap(QPixmap(":/pic/shizheng.bmp").scaled(200,100));


	status1 = new QLabel;
	status1->setPixmap(QPixmap(":/pic/kongkai.bmp").scaled(100,80));
	status2 = new QLabel;
	status2->setPixmap(QPixmap(":/pic/jiashikai.bmp").scaled(100,80));
	btn_wendu = new QPushButton;
	btn_wendu->setFlat(true);
	btn_wendu->setIcon(QPixmap(":/pic/off.bmp"));
	btn_wendu->setIconSize(QSize(100,80));
	btn_shidu = new QPushButton;
	btn_shidu->setFlat(true);
	btn_shidu->setIcon(QPixmap(":/pic/off.bmp"));
	btn_shidu->setIconSize(QSize(100,80));

	wd = new QLCDNumber;
	sd = new QLCDNumber;
	layout1 = new QHBoxLayout;
	layout2 = new QHBoxLayout;
	layout3 = new QHBoxLayout;
	layout4 = new QHBoxLayout;

	layout = new QVBoxLayout;
	btn = new QPushButton;

	layout1->addWidget(wendu);
	layout1->addWidget(wendu_a);
	layout1->addWidget(wd);
	layout2->addWidget(shidu);
	layout2->addWidget(shidu_a);
	layout2->addWidget(sd);
	layout3->addWidget(status1);
	layout3->addWidget(btn_wendu);
	layout3->addStretch();
	layout3->addWidget(status2);
	layout3->addWidget(btn_shidu);
	layout4->addWidget(btn);

	btn->setIcon(QPixmap(":/pic/back.png"));
	btn->setIconSize(QSize(80,80));
	btn->setMaximumSize(80,80);
	btn->setMinimumSize(80,80);
	btn->setFlat(true);

	layout->addWidget(main);
	layout->addLayout(layout1);
	layout->addLayout(layout2);
	layout->addLayout(layout3);
	layout->addLayout(layout4);
	setLayout(layout);

	palette.setBrush(QPalette::Background,QPixmap(":/pic/background2.jpg"));
	setPalette(palette); 
	
	connect(btn,SIGNAL(clicked()),this,SLOT(myslot_back()));
	connect(btn_wendu,SIGNAL(clicked()),this,SLOT(myslot_open_wendu()));
	connect(btn_shidu,SIGNAL(clicked()),this,SLOT(myslot_open_shidu()));
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
void mywindow_1::myslot_open_wendu(void)
{

	if(f_wendu == true)
	{
		btn_wendu->setIcon(QPixmap(":/pic/on.bmp"));
		mywritemycom_wendu_open();
	}
	else
	{
		btn_wendu->setIcon(QPixmap(":/pic/off.bmp"));
		mywritemycom_wendu_close();
	}
	f_wendu = !f_wendu;
}
void mywindow_1::myslot_open_shidu(void)
{
	if(f_shidu == true)
	{
		btn_shidu->setIcon(QPixmap(":/pic/on.bmp"));
		mywritemycom_shidu_open();
	}
	else
	{
		btn_shidu->setIcon(QPixmap(":/pic/off.bmp"));
		mywritemycom_shidu_close();
	}
	f_shidu = !f_shidu;

}
void mywindow_1::myslot_back(void)
{
	emit mysignal_back();
}
void mywindow_1::myreadmycom(Posix_QextSerialPort *tmp,UART_Format t1) 
	//读取串口数据并显示出来
{
	UART_Format msg = t1;	
	mycom = tmp;
	//如果可用数据大于或等于16字节再读取
//	if(mycom->bytesAvailable() == 16 )
//	{
//		mycom->readData((char *)&msg,(qint64)sizeof(msg));
		if(msg.NodeID == 3 && msg.Command == 1)
		{
			int temp1,temp2;
			temp1 = (msg.Data[0]*256+msg.Data[1])/100;
			if(temp1 > 35)
			{
				wendu_a->setPixmap(QPixmap(":/pic/gaowen.bmp").scaled(200,100));
				btn_wendu->setIcon(QPixmap(":/pic/on.bmp"));
				mywritemycom_wendu_open();
			}
			else
			{
				wendu_a->setPixmap(QPixmap(":/pic/wenzheng.bmp").scaled(200,100));
				btn_wendu->setIcon(QPixmap(":/pic/off.bmp"));
				mywritemycom_wendu_close();
			}
			wd->display(temp1);
			//显示温度
			temp2 = (msg.Data[2]*256+msg.Data[3])/100;
			if(temp2 > 75)
			{
				shidu_a->setPixmap(QPixmap(":/pic/gaoshi.bmp").scaled(200,100));
				btn_shidu->setIcon(QPixmap(":/pic/on.bmp"));
				mywritemycom_shidu_open();
			}
			else
			{
				shidu_a->setPixmap(QPixmap(":/pic/shizheng.bmp").scaled(200,100));
				btn_shidu->setIcon(QPixmap(":/pic/off.bmp"));
				mywritemycom_shidu_close();
			}
			sd->display(temp2);
			//显示适度
		}
//	}
//	else
//	{
//		mycom->readAll();
//	}
}

void mywindow_1::mywritemycom_wendu_open(void) //写数据
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

void mywindow_1::mywritemycom_wendu_close(void) //写数据
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
void mywindow_1::mywritemycom_shidu_open(void) //写数据
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

void mywindow_1::mywritemycom_shidu_close(void) //写数据
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
