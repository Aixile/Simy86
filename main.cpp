#include "y86sim.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	y86sim w;
	w.show();
	return a.exec();
}
