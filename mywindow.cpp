#include "mywindow.h"

mywindow::mywindow(void)
{

	wendu = 0;
	shidu = 0;
	guang = 0;
	smoke = 0;

	QString tmp;
	QTime tt;
	tmp = tt.currentTime().toString();

	time = new QTimer;
	time->start(1000);
	this->setMaximumSize(800,480);
	this->setMinimumSize(800,480);

	QPalette palette;
	times = new QLCDNumber;

	times->setNumDigits(8);

	times->setMinimumSize(350,40);

	btn1 = new QPushButton;
	btn1->setIconSize(QSize(80,80));
	btn1->setIcon(QPixmap(":/pic/1.jpg"));
	btn1->setFlat(true);
	btn2 = new QPushButton;
	btn2->setIconSize(QSize(80,80));
	btn2->setIcon(QPixmap(":/pic/2.PNG"));
	btn2->setFlat(true);
	btn3 = new QPushButton;
	btn3->setIconSize(QSize(80,80));
	btn3->setIcon(QPixmap(":/pic/exit.jpg"));
	btn3->setFlat(true);
	btn4 = new QPushButton;
	btn4->setIconSize(QSize(80,80));
	btn4->setIcon(QPixmap(":/pic/leds.png"));
	btn4->setFlat(true);
	btn5 = new QPushButton;
	btn5->setIconSize(QSize(80,80));
	btn5->setIcon(QPixmap(":/pic/menjin.png"));
	btn5->setFlat(true);

	label = new QLabel;
	label1 = new QLabel;
	label2 = new QLabel;
	label3 = new QLabel;
	label4 = new QLabel;
	label1->setPixmap(QPixmap(":/pic/wenshidu.png").scaled(100,50));
	label2->setPixmap(QPixmap(":/pic/anfang.png").scaled(100,50));
	label3->setPixmap(QPixmap(":/pic/light.png").scaled(100,50));
	label4->setPixmap(QPixmap(":/pic/wenshidu.png").scaled(100,50));

	times->display(tmp);
	vlayout = new QVBoxLayout;
	hlayout1 = new QHBoxLayout;
	hlayout2 = new QHBoxLayout;
	hlayout3 = new QHBoxLayout;


	hlayout3->addWidget(label1);
	hlayout3->addWidget(label2);
	hlayout3->addWidget(times);
	hlayout3->addStretch();
	hlayout3->addWidget(label3);
	hlayout3->addWidget(label4);
	hlayout1->addWidget(btn1);
	hlayout1->addWidget(btn2);
	hlayout1->addStretch();
	hlayout1->addWidget(btn4);
	hlayout1->addWidget(btn5);
	hlayout2->addStretch();
	hlayout2->addWidget(btn3);
	hlayout2->addStretch();
	//	hlayout2->addWidget(btn4);

	b1 = new mywindow_1;
	b2 = new mywindow_2;
	b3 = new mywindow_3;
	b4 = new mywindow_4;

	vlayout->addWidget(label);
	vlayout->addLayout(hlayout3);
	vlayout->addLayout(hlayout1);
	vlayout->addLayout(hlayout2);

	setWindowFlags(Qt::CustomizeWindowHint);
	//setWindowFlags(Qt::WindowTitleHint);
	setLayout(vlayout);
	palette.setBrush(QPalette::Background,QPixmap(":/pic/background.jpg"));
	setAutoFillBackground(true);
	setPalette(palette); 

	connect(btn1,SIGNAL(clicked()),this,SLOT(myslot_b1()));
	connect(btn2,SIGNAL(clicked()),this,SLOT(myslot_b2()));
	connect(btn3,SIGNAL(clicked()),this,SLOT(myslot_exit()));
	connect(btn4,SIGNAL(clicked()),this,SLOT(myslot_b3()));
	connect(btn5,SIGNAL(clicked()),this,SLOT(myslot_b4()));
	connect(b1,SIGNAL(mysignal_back()),this,SLOT(myslot_show1()));
	connect(b2,SIGNAL(mysignal_back()),this,SLOT(myslot_show2()));
	connect(b3,SIGNAL(mysignal_back()),this,SLOT(myslot_show3()));
	connect(b4,SIGNAL(mysignal_back()),this,SLOT(myslot_show4()));
	connect(time,SIGNAL(timeout()),this,SLOT(myslot_time()));

	mysetmycom();

	myweb();
	connect(this,SIGNAL(mysignal_send(Posix_QextSerialPort *,UART_Format)),b1,SLOT(myreadmycom(Posix_QextSerialPort *,UART_Format)));
	connect(this,SIGNAL(mysignal_send(Posix_QextSerialPort *,UART_Format)),b2,SLOT(myreadmycom(Posix_QextSerialPort *,UART_Format)));
	connect(this,SIGNAL(mysignal_send(Posix_QextSerialPort *,UART_Format)),b3,SLOT(myreadmycom(Posix_QextSerialPort *,UART_Format)));
	connect(this,SIGNAL(mysignal_send(Posix_QextSerialPort *,UART_Format)),b4,SLOT(myreadmycom(Posix_QextSerialPort *,UART_Format)));

}
//myminwow
void mywindow::myslot_time(void)
{	
	QTime temp;
	QString aa;
	aa = temp.currentTime().toString();
	times->display(aa);
}
//time

void mywindow::myslot_exit(void)
{
	exit(0);
}
//exit

void mywindow::myslot_show4(void)
{
	show();
	b4->hide();
}
void mywindow::myslot_b4(void)
{
	b4->show();
	hide();
}
void mywindow::myslot_show3(void)
{
	show();
	b3->hide();
}
void mywindow::myslot_b3(void)
{
	b3->show();
	hide();
}
void mywindow::myslot_show2(void)
{
	show();
	b2->hide();
}
void mywindow::myslot_b2(void)
{
	b2->show();
	hide();
}
void mywindow::myslot_show1(void)
{
	show();
	b1->hide();
}
void mywindow::myslot_b1(void)
{
	b1->show();
	hide();
}

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
	/*
	   connect(this,SIGNAL(mysignal_send(Posix_QextSerialPort *)),b1,SLOT(myreadmycom(Posix_QextSerialPort *)));
	   connect(this,SIGNAL(mysignal_send(Posix_QextSerialPort *)),b2,SLOT(myreadmycom(Posix_QextSerialPort *)));
	   connect(this,SIGNAL(mysignal_send(Posix_QextSerialPort *)),b3,SLOT(myreadmycom(Posix_QextSerialPort *)));
	   connect(this,SIGNAL(mysignal_send(Posix_QextSerialPort *)),b3,SLOT(myreadmycom(Posix_QextSerialPort *)));

*/
}
//mysetmycom
void mywindow::myreadmycom(void) //读取串口数据并显示出来
{

	UART_Format msg;	
	//如果可用数据大于或等于16字节再读取
	if(mycom->bytesAvailable() == 16 ){
		mycom->readData((char *)&msg,(qint64)sizeof(msg));

		/*			connect(this,SIGNAL(mysignal_send(Posix_QextSerialPort *)),b1,SLOT(myreadmycom(Posix_QextSerialPort *)));
					connect(this,SIGNAL(mysignal_send(Posix_QextSerialPort *)),b2,SLOT(myreadmycom(Posix_QextSerialPort *)));
					connect(this,SIGNAL(mysignal_send(Posix_QextSerialPort *)),b3,SLOT(myreadmycom(Posix_QextSerialPort *)));
					connect(this,SIGNAL(mysignal_send(Posix_QextSerialPort *)),b3,SLOT(myreadmycom(Posix_QextSerialPort *)));
					*/	
		emit mysignal_send(mycom,msg);
		if(msg.Command == 1){
			if(msg.NodeID == 3)
			{
				int temp1;
				int temp2;
				temp1 = (msg.Data[0]*256+msg.Data[1])/100;
				temp2 = (msg.Data[2]*256+msg.Data[3])/100;
				wendu = temp1;
				shidu = temp2;
			}
			if(msg.NodeID == 2)
			{
				int tmp;
				tmp = (msg.Data[0]*256+msg.Data[1])/100;
				guang = tmp;
			}
			if(msg.NodeID == 7)
			{
				if(msg.Data[0] == 1)
				{	
					smoke = 1;
				}
				else
				{
					smoke = 0;
				}
			}

		}
	}
	else
	{
		mycom->readAll();
	}


}
//myreadmycom
void mywindow::myweb(void)
{
	tcp = new QTcpServer;
	tcp->listen(QHostAddress::Any,8888);
	connect(tcp,SIGNAL(newConnection()),this,SLOT(myslot_new()));
}

void mywindow::myslot_new(void)
{
	tcp_client = tcp->nextPendingConnection();
	connect(tcp_client,SIGNAL(readyRead()),this,SLOT(myslot_readall()));
}

void mywindow::myslot_readall(void)
{
	char *p;
	char buf[BUFSIZ];
	struct stat info;
	char file[1000];
	char head_type[50] = "Content-type: ";
	char *head = "HTTP/1.1 200 OK\r\n";
	char file_size[50] = "Content-length: ";
	int fd = -1,i;
	int n;
	char tmp[BUFSIZ];
	strcpy(tmp,tcp_client->readAll().data());
	strcpy(buf,explain(tmp));
	printf("%s\n",tmp);

	if(strcmp(buf,"show.html") == 0)
	{
		show_change(fd);
	}
	fd = ::open(buf,O_RDONLY);
	if(fd < 0)
	{
		return;
	}
	if(strcmp(buf,"control.html") == 0)
	{
		if((p = strstr(tmp,"Submit_water_off=")) != NULL)
		{
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
			printf("water_off\n");
		}
		if((p = strstr(tmp,"Submit_water_on="))!= NULL)
		{
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
			printf("water_on\n");
		}
		if((p = strstr(tmp,"Submit_light_off=")) != NULL)
		{
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
			printf("light_off\n");
		}
		if((p = strstr(tmp,"Submit_light_on="))!= NULL)
		{
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
			printf("light_on\n");
		}
		if((p = strstr(tmp,"Submit_fan_off=")) != NULL)
		{
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
			printf("fan_off\n");
		}
		if((p = strstr(tmp,"Submit_fan_on="))!= NULL)
		{
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
			printf("fan_on\n");
		}
		if((p = strstr(tmp,"Submit_curtain_up=")) != NULL)
		{
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
			printf("curtain_off\n");
		}
		if((p = strstr(tmp,"Submit_curtain_down="))!= NULL)
		{
			UART_Format msg;
			bzero((char*)&msg,sizeof(msg));	
			msg.Header_1 = 0xcc;
			msg.Header_2 = 0xee;
			msg.NodeSeq = 0x1;
			msg.NodeID = 0x9;
			msg.Command = 0xa;
			msg.Tailer = 0xff;
			//uart_send(&msg,sizeof(msg));
			mycom->writeData((char *)&msg,(qint64)sizeof(msg));
			printf("curtain_on\n");
		}
	}
	strcat(head_type,file_type(buf));
	strcat(head_type,"\r\n");

	lstat(buf,&info);
	sprintf(file_size,"%s%d",file_size,info.st_size);
	strcat(file_size,"\r\n\r\n");

	tcp_client->write(head,strlen(head));
	tcp_client->write(head_type,strlen(head_type));
	tcp_client->write(file_size,strlen(file_size));

		bzero(file,sizeof(file));
	while((n = read(fd,file,sizeof(file))) != 0)
	{
		//	i = send(acc_sock,file,n,0);
		i =	tcp_client->write(file,sizeof(file));
		bzero(file,sizeof(file));
		if(i == -1||i != n)
		{
			break;
		}
	}
	::close(fd);
}
char *mywindow::explain(char *buf)
{
	char text[BUFSIZ];
	char aaa[BUFSIZ];
	struct stat info;

	int length;
	char *tmp;

	sscanf(buf,"%s%s",aaa,text);	
	//取得HTTP头前两个字符串
	if(strcmp(text,"/") == 0)
	{    
		strcpy(text,"/index.html");
	}
	if(strcmp(aaa,"GET") == 0 || strcmp(aaa,"POST") == 0)
	{      
		//GET方法

		if((tmp = strchr(text,'?')) != NULL)
		{
			length = strlen(text) - strlen(tmp); 
			//对GET方法请求的参数进行解析
			strncpy(text,text,length);
			text[length] = '\0';
		}
		if(lstat(text+1,&info)== -1)
		{
			char *head = "HTTP/1.1 404 NOT FOUND\r\n\r\n";  
			//请求的文件不存在
		}
		return text+1;

	}
	return NULL;
}

char *mywindow::file_type(char *buf) 
	//对请求的文件类型进行解析匹配
{
	char *tmp;
	if((tmp = strrchr(buf,'.')) != NULL){
		tmp++;
		if(strcmp(tmp,"html") == 0)
		{
			tmp = "text/html";
			return tmp;
		}
		else if(strcmp(tmp,"jpg") == 0)
		{
			tmp = "image/jpeg";
			return tmp;
		}
		else if(strcmp(tmp,"mp3") == 0)
		{
			tmp = "audio/wave";
			return tmp;
		}
		else if(strcmp(tmp,"gif") == 0)
		{
			tmp = "image/gif";
			return tmp;
		}
		else if(strcmp(tmp,"zip") == 0|| strcmp(tmp,"bz2") == 0|| strcmp(tmp,"rar") == 0)
		{
			tmp = "application/x-tar";
			return tmp;
		}
		else
		{
			tmp = "text/html";
			return tmp;
		}

	}
}
void mywindow::show_change(int fd)
{
	char buf[BUFSIZ] = "";//8K
	char *p;
	int ffd;
	char ss[50] = "";
	int ret;
	char str_smoke[100] = "no_smoke";

	ffd = ::open("show.html",O_RDWR);
	ret = ::read(ffd,buf,sizeof(buf));

	p = strstr(buf,"ure:     ");	//ure:  
	sprintf(ss,"ure:%d",wendu);	//ure:26
	strncpy(p,ss,strlen(ss));

	p = strstr(buf,"ity:     ");
	sprintf(ss,"ity:%d",shidu);
	strncpy(p,ss,strlen(ss));

	p = strstr(buf,"ght:     ");
	sprintf(ss,"ght:%d",guang);
	strncpy(p,ss,strlen(ss));

	if(smoke == 1)
	{
		strcpy(str_smoke,"have_smoke");
	}
	else
	{
		strcpy(str_smoke,"no_smoke");
	}
	p = strstr(buf,"oke:               ");
	sprintf(ss,"oke:%s",str_smoke);

	printf("%d%d%d\n",wendu,shidu,guang);
	strncpy(p,ss,strlen(ss));
	//替换 :  换为 :26
	//	::ftruncate(ffd,ret);
	::write(fd,buf,ret);
	::close(ffd);
}
