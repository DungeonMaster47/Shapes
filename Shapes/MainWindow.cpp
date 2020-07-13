#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setGeometry(0, 0, 640, 480);
	m_frame = new DrawingField(this);
	setCentralWidget(m_frame);
	createToolbar();
}

void MainWindow::createToolbar()
{
	m_toolbar = addToolBar("toolbar");

	QAction* openFile = new QAction(QIcon(":MainWindow/icons/open.ico"), "Open file", this);
	connect(openFile, &QAction::triggered, this, &MainWindow::onOpenFileBtn);
	m_toolbar->addAction(openFile);

	QAction* saveFile = new QAction(QIcon(":MainWindow/icons/save.ico"), "Save file", this);
	connect(saveFile, &QAction::triggered, this, &MainWindow::onSaveFileBtn);
	m_toolbar->addAction(saveFile);

	m_toolbar->addSeparator();
	
	QAction* circle = new QAction(QIcon(":MainWindow/icons/circle.ico"), "Circle", this);
	circle->setCheckable(true);
	connect(circle, &QAction::toggled, this, &MainWindow::onShapeBtn<Circle>);
	m_toolbar->addAction(circle);
	
	QAction* rectangle = new QAction(QIcon(":MainWindow/icons/rectangle.ico"), "Rectangle", this);
	connect(rectangle, &QAction::toggled, this, &MainWindow::onShapeBtn<Rectangle>);
	rectangle->setCheckable(true);
	m_toolbar->addAction(rectangle);
	
	QAction* triangle = new QAction(QIcon(":MainWindow/icons/triangle.ico"), "Triangle", this);
	connect(triangle, &QAction::toggled, this, &MainWindow::onShapeBtn<Triangle>);
	triangle->setCheckable(true);
	m_toolbar->addAction(triangle);

	QAction* line = new QAction(QIcon(":MainWindow/icons/line.ico"), "Line", this);
	connect(line, &QAction::toggled, this, &MainWindow::onLineBtn);
	line->setCheckable(true);
	m_toolbar->addAction(line);
	
	QAction* move = new QAction(QIcon(":MainWindow/icons/move.ico"), "Move", this);
	connect(move, &QAction::toggled, this, &MainWindow::onMoveBtn);
	move->setCheckable(true);
	m_toolbar->addAction(move);

	m_toolbar->addSeparator();

	QPixmap black = QPixmap(ICON_SIZE, ICON_SIZE);
	black.fill(Qt::black);
	m_color = new QAction(QIcon(black), "Color", this);
	connect(m_color, &QAction::triggered, this, &MainWindow::onColorBtn);
	m_toolbar->addAction(m_color);
}

void MainWindow::checkToolButtons(bool check)
{
	for (auto a : m_toolbar->actions())
	{
		if (a->isChecked() && a != sender())
		{
			a->setChecked(check);
		}
	}
}

void MainWindow::onOpenFileBtn()
{
	QMessageBox::information(this, "Placeholder", "Open file placeholder");
}

void MainWindow::onSaveFileBtn()
{
	QMessageBox::information(this, "Placeholder", "Save file placeholder");
}

void MainWindow::onLineBtn(bool checked)
{
	if (checked)
	{
		checkToolButtons(false);
		m_frame->setMouseHandler(std::make_unique<LineMouseHandler>(m_frame));
	}
	else
	{
		m_frame->setMouseHandler(std::make_unique<DefaultMouseHandler>(m_frame));
	}
}

void MainWindow::onMoveBtn(bool checked)
{
	if (checked)
	{
		checkToolButtons(false);
		m_frame->setMouseHandler(std::make_unique<MoveMouseHandler>(m_frame));
	}
	else
	{
		m_frame->setMouseHandler(std::make_unique<DefaultMouseHandler>(m_frame));
	}
}

void MainWindow::onColorBtn()
{
	QColor newColor = QColorDialog::getColor();
	if (newColor.isValid())
	{
		m_frame->setColor(newColor);
		QPixmap newIcon = QPixmap(ICON_SIZE, ICON_SIZE);
		newIcon.fill(newColor);
		m_color->setIcon(QIcon(newIcon));
	}
}