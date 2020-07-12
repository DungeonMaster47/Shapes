#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setGeometry(0, 0, 640, 480);
	frame = new DrawingField(this);
	setCentralWidget(frame);
	createToolbar();
}

void MainWindow::createToolbar()
{
	toolbar = addToolBar("toolbar");

	QAction* openFile = new QAction(QIcon(":MainWindow/icons/open.ico"), "Open file", this);
	connect(openFile, &QAction::triggered, this, &MainWindow::onOpenFile);
	toolbar->addAction(openFile);

	QAction* saveFile = new QAction(QIcon(":MainWindow/icons/save.ico"), "Save file", this);
	connect(saveFile, &QAction::triggered, this, &MainWindow::onSaveFile);
	toolbar->addAction(saveFile);

	toolbar->addSeparator();
	
	QAction* circle = new QAction(QIcon(":MainWindow/icons/circle.ico"), "Circle", this);
	circle->setCheckable(true);
	connect(circle, &QAction::toggled, this, &MainWindow::onCircle);
	toolbar->addAction(circle);
	
	QAction* rectangle = new QAction(QIcon(":MainWindow/icons/rectangle.ico"), "Rectangle", this);
	connect(rectangle, &QAction::toggled, this, &MainWindow::onRectangle);
	rectangle->setCheckable(true);
	toolbar->addAction(rectangle);
	
	QAction* triangle = new QAction(QIcon(":MainWindow/icons/triangle.ico"), "Triangle", this);
	connect(triangle, &QAction::toggled, this, &MainWindow::onTriangle);
	triangle->setCheckable(true);
	toolbar->addAction(triangle);

	QAction* line = new QAction(QIcon(":MainWindow/icons/line.ico"), "Line", this);
	connect(line, &QAction::toggled, this, &MainWindow::onLine);
	line->setCheckable(true);
	toolbar->addAction(line);
	
	QAction* move = new QAction(QIcon(":MainWindow/icons/move.ico"), "Move", this);
	connect(move, &QAction::toggled, this, &MainWindow::onMove);
	move->setCheckable(true);
	toolbar->addAction(move);

	toolbar->addSeparator();

	QPixmap black = QPixmap(64, 64);
	black.fill(Qt::black);
	color = new QAction(QIcon(black), "Color", this);
	connect(color, &QAction::triggered, this, &MainWindow::onColor);
	toolbar->addAction(color);
}

void MainWindow::uncheckToolButtons()
{
	for (auto a : toolbar->actions())
	{
		if (a->isChecked() && a != sender())
		{
			a->setChecked(false);
		}
	}
}

void MainWindow::onOpenFile()
{
	QMessageBox::information(this, "Placeholder", "Open file placeholder");
}

void MainWindow::onSaveFile()
{
	QMessageBox::information(this, "Placeholder", "Save file placeholder");
}

void MainWindow::onCircle(bool checked)
{
	if (checked)
	{
		uncheckToolButtons();
		frame->setMouseHandler(std::make_unique<ShapeMouseHandler<Circle>>(frame->color(), frame->shapes));
	}
	else
	{
		frame->setMouseHandler(std::make_unique<DefaultMouseHandler>());
	}
}

void MainWindow::onRectangle(bool checked)
{
	if (checked)
	{
		uncheckToolButtons();
		frame->setMouseHandler(std::make_unique<ShapeMouseHandler<Rectangle>>(frame->color(), frame->shapes));
	}
	else
	{
		frame->setMouseHandler(std::make_unique<DefaultMouseHandler>());
	}
}

void MainWindow::onTriangle(bool checked)
{
	if (checked)
	{
		uncheckToolButtons();
		frame->setMouseHandler(std::make_unique<ShapeMouseHandler<Triangle>>(frame->color(), frame->shapes));
	}
	else
	{
		frame->setMouseHandler(std::make_unique<DefaultMouseHandler>());
	}
}

void MainWindow::onLine(bool checked)
{
	if (checked)
	{
		uncheckToolButtons();
		frame->setMouseHandler(std::make_unique<LineMouseHandler>(frame->shapes, frame->lines, frame->color()));
	}
	else
	{
		frame->setMouseHandler(std::make_unique<DefaultMouseHandler>());
	}
}

void MainWindow::onMove(bool checked)
{
	if (checked)
	{
		uncheckToolButtons();
		frame->setMouseHandler(std::make_unique<MoveMouseHandler>(frame->shapes));
	}
	else
	{
		frame->setMouseHandler(std::make_unique<DefaultMouseHandler>());
	}
}

void MainWindow::onColor()
{
	QColor newColor = QColorDialog::getColor();
	if (newColor.isValid())
	{
		frame->setColor(newColor);
		QPixmap newIcon = QPixmap(64, 64);
		newIcon.fill(newColor);
		color->setIcon(QIcon(newIcon));
	}
}