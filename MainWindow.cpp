#include "MainWindow.h"

#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPlainTextEdit>
#include <QtQuick/QQuickView>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent)
{
	QGraphicsView *graphicsView = new QGraphicsView;
	setCentralWidget(graphicsView);
	graphicsView->setScene(new QGraphicsScene(graphicsView));
	QQuickView *view = new QQuickView(QUrl("qrc:/main.qml"));
	QPlainTextEdit *edit = new QPlainTextEdit;
	edit->setFixedSize(200, 200);
	QWidget *containter = QWidget::createWindowContainer(view);
	containter->setParent(edit);
	containter->move(50, 50);

	// Commenting this line and uncommenting line below will show up everything fine!
	graphicsView->scene()->addWidget(edit);
//	edit->show();
}

MainWindow::~MainWindow()
{
}
