#include <QApplication>
#include <clock_widget.h>

int main(int ac, char* av[])
{
	QApplication a(ac, av);

    Clock theClock;
    theClock.show();

	QObject::connect(
			&a, SIGNAL(lastWindowClosed()),
			&a, SLOT(quit())
			);

	return a.exec();
}

