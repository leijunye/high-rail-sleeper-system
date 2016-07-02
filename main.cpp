#include <QApplication>
#include "mywindow.h"

int main(int argc,char **argv)
{
	QApplication app(argc,argv);
	mywindow demo;
	demo.show();
	app.exec();
	return 0;
}

