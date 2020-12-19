#include <clock_widget.h>

#include <QPainter>
#include <QTime>
#include <iostream>

Clock::Clock(QWidget* parent)
	: QWidget(parent)
	, _hours(0)
	, _minutes(0)
	, _seconds(0)
{
	setMinimumSize(100,100);
	startTimer(1000);
}

void Clock::timerEvent(QTimerEvent*)
{
	QTime t  = QTime::currentTime();
	_hours   = t.hour();
	_minutes = t.minute();
	_seconds = t.second();

	update();
	std::cout << "Tick" << std::endl;
}


void drawArrow(QPainter& p)
{
	p.drawLine(0,0,  0,10);

}

void Clock::paintEvent(QPaintEvent*)
{
	QPainter p(this);
	QPoint center(width()/2, height()/2);
    p.translate(center);

	// seconds
	p.save();
    p.rotate((_seconds+30) * 6);
    p.scale(5,10);
    p.setPen(Qt::blue);
	drawArrow(p);
    p.restore();

    // minutes
    p.save();
    p.rotate((_minutes-30) * 6);
    p.scale(5,10);
    p.setPen(Qt::green);
    drawArrow(p);
    p.restore();

    // hours
    p.save();
    p.rotate(_hours * 6);
    p.scale(5,10);
    p.setPen(Qt::red);
    drawArrow(p);
    p.restore();


    //lines
    for (size_t i = 0; i < 360; i+=6)
        {
            p.save();
            p.rotate(i);
            if (i % 5 == 0)
            {
                p.scale(5,1);
                p.drawLine(0,140,0, 105);
            }
            else
            {
                p.drawLine(0, 130, 0, 105);
            }
            p.restore();
        }

    //numbers

    p.drawText(45,  -75, "1");
    p.drawText(80,  -43, "2");
    p.drawText(93,  6,   "3");
    p.drawText(80,  55,  "4");
    p.drawText(45,  87,  "5");
    p.drawText(-4,  102, "6");
    p.drawText(-52, 89,  "7");
    p.drawText(-90, 55,  "8");
    p.drawText(-103, 6,   "9");
    p.drawText(-90, -40, "10");
    p.drawText(-54, -75, "11");
    p.drawText(-8,  -85, "12");



}

