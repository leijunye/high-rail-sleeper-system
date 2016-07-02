#include "mywindow_2.h"

mywindow_2::mywindow_2(void)
{

	setWindowFlags(Qt::CustomizeWindowHint);
	flag = true;
	this->setMaximumSize(800,480);
	this->setMinimumSize(800,480);

	QPalette palette;

	label1 = new QLabel;
	label1->setPixmap(QPixmap(":/pic/ledOff.png").scaled(200,100));
	label2 = new QLabel;
	label2->setPixmap(QPixmap(":/pic/wujingbao1.png").scaled(200,100));
	movie = new QMovie(":/pic/pen.gif");
	label3 = new QLabel;
	movie->start();
	movie->stop();
	label3->setMovie(movie);

	btn_open = new QPushButton;
	btn_open->setFlat(true);
	btn_open->setIcon(QPixmap(":/pic/off.bmp"));
	btn_open->setIconSize(QSize(100,80));

	btn = new QPushButton;
	btn->setIcon(QPixmap(":/pic/back.png"));
	btn->setIconSize(QSize(80,80));
	btn->setMaximumSize(80,80);
	btn->setMinimumSize(80,80);
	btn->setFlat(true);

	layout = new QVBoxLayout;
	layout1 = new QHBoxLayout;
	layout2 = new QHBoxLayout;
	layout3 = new QHBoxLayout;

	layout1->addStretch();
	layout1->addWidget(label1);
	layout1->addStretch();
	layout1->addWidget(label2);
	layout1->addStretch();
	layout2->addStretch();
	layout2->addWidget(label3);
	layout2->addStretch();
	layout2->addWidget(btn_open);
	layout2->addStretch();
	layout3->addWidget(btn);

	layout->addStretch();
	layout->addLayout(layout1);
	layout->addLayout(layout2);
	layout->addLayout(layout3);

	setLayout(layout);

	palette.setBrush(QPalette::Background,QPixmap(":/pic/back3.jpg"));
	setPalette(palette); 

	connect(btn,SIGNAL(clicked()),this,SLOT(myslot_back()));
	connect(btn_open,SIGNAL(clicked()),this,SLOT(myslot_open()));
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

void mywindow_2::myslot_open(void)
{
	if(flag == true)
	{
		btn_open->setIcon(QPixmap(":/pic/on.bmp"));
		movie->start();
		mywritemycom_f_open();
	}
	else
	{
		btn_open->setIcon(QPixmap(":/pic/off.bmp"));
		movie->stop();
		mywritemycom_f_close();
	}
	flag = !flag;
}
void mywindow_2::myslot_back(void)
{
	emit mysignal_back();
}
void mywindow_2::myreadmycom(Posix_QextSerialPort *tmp,UART_Format t1)  
	//读取串口数据并显示出来
{
	mycom = tmp;
	UART_Format msg = t1;
	//如果可用数据大于或等于16字节再读取
	//	if(mycom->bytesAvailable() == 16 )
	//	{
	//		mycom->readData((char *)&msg,(qint64)sizeof(msg));
	if(msg.NodeID == 7 && msg.Command == 1)
	{
		if(msg.Data[0] == 1)
		{
			mywritemycom_f_open();
			label2->setPixmap(QPixmap(":/pic/youweixian1.png").scaled(200,100));
			btn_open->setIcon(QPixmap(":/pic/on.bmp"));
			movie->start();
		}
		else
		{
			mywritemycom_f_close();
			label2->setPixmap(QPixmap(":/pic/wujingbao1.png").scaled(200,100));
			btn_open->setIcon(QPixmap(":/pic/off.bmp"));
			movie->stop();
		}
	}
	//	}
	//	else
	//	{
	//		mycom->readAll();
	//	}
}

void mywindow_2::mywritemycom_f_open(void) //写数据
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

void mywindow_2::mywritemycom_f_close(void) //写数据
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
