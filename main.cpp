#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QPainter>
#include <QTimer>

class PlayWidget : public QWidget
{
	int x;
	int y;
	int velx;
	int vely;
	QTimer *timer;
protected:
	void paintEvent(QPaintEvent *event)
	{
		if (x + velx < 0) {
			velx = -velx;
			velx++;
		} else if (750 < x + velx) {
			velx = -velx;
			velx--;
		}
		if (y + vely < 0) {
			vely = -vely;
			vely++;
		} else if (530 < y + vely) {
			vely = -vely;
			vely--;
		}
		x += velx;
		y += vely;
		QPainter painter(this);
		painter.setPen(Qt::black);
		painter.setBrush(Qt::red);
		QRect rectangle(x, y, 50, 50);
		painter.drawRect(rectangle);
			
	}

public:
	PlayWidget(QWidget *parent) :
		QWidget(parent),
		x(1),
		y(1),
		velx(2),
		vely(3)
	{
		timer = new QTimer(this);
		connect(
			timer,
			&QTimer::timeout,
			this,
			static_cast<void (QWidget::*)()>(&QWidget::update)
		);
		timer->start(16);	// around 60 fps
	}
};


int main(int argc, char *argv[])
{
	int retval;
	QApplication *app = new QApplication(argc, argv);
	QWidget *window = new QWidget();
	window->setFixedSize(800, 600);

	QPushButton *quit = new QPushButton(window);
	quit->setText("exit");
	quit->setGeometry(0, 0, 800, 20);
	QPushButton::connect(
		quit,
		&QPushButton::clicked,
		app,
		&QCoreApplication::quit,
		Qt::QueuedConnection
	);

	PlayWidget *play = new PlayWidget(window);
	play->setGeometry(0, 20, 800, 580);

	std::cout << "starting\n";
	window->show();
	retval = app->exec();

	delete quit;
	delete play;
	delete window;
	delete app;

	std::cout << "exiting\n";
	return retval;
}
