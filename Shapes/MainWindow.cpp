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
	QString filename = QFileDialog::getOpenFileName(this, "Open File", QString(), "Text file (*.txt)");
	if (filename.isEmpty())
		return;
	
	m_frame->hide();

	m_frame->lines.clear();
	m_frame->shapes.clear();

	QFile file(filename);
	file.open(QIODevice::ReadOnly);
	if (!readShapesFromFile(file))
		QMessageBox::warning(this, "Error", "Error reading from file");

	m_frame->show();
	m_frame->update();
}

void MainWindow::onSaveFileBtn()
{
	QString filename = QFileDialog::getSaveFileName(this, "Save File", QString(), "Text file (*.txt)");
	if (filename.isEmpty())
		return;

	QFile file(filename);
	file.open(QIODevice::WriteOnly | QIODevice::Truncate);
	if (!writeShapesToFile(file))
		QMessageBox::warning(this, "Error", "Error writing to file");
	QMessageBox::information(this, "Success", "Successfully saved to " + filename);
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

bool MainWindow::writeShapesToFile(QFile& file)
{
	if(!file.isOpen())
		return false;

	QTextStream out(&file);

	for (auto&& s : m_frame->shapes)
	{
		try
		{
			dynamic_cast<Circle&>(*s);
			out << "Circle" << endl;
		}
		catch (std::bad_cast) {}
		try
		{
			dynamic_cast<Rectangle&>(*s);
			out << "Rectangle" << endl;
		}
		catch (std::bad_cast) {}
		try
		{
			dynamic_cast<Triangle&>(*s);
			out << "Triangle" << endl;
		}
		catch (std::bad_cast) {}

		int r, g, b, a;
		s->color().getRgb(&r, &g, &b, &a);

		out << r << ' ' << g << ' ' << b << ' ' << a << ' ' << s->pos().x() << ' ' << s->pos().y() << ' ' << s->size().width() << ' ' << s->size().height() << endl;
	}

	for (auto&& l : m_frame->lines)
	{
		int r, g, b, a;
		l.color().getRgb(&r, &g, &b, &a);

		out << "Line" << endl;
		out << r << ' ' << g << ' ' << b << ' ' << a << ' ' << l.firstShapeIndex() << ' ' << l.secondShapeIndex() << endl;
	}

	return true;
}

bool MainWindow::readShapesFromFile(QFile& file)
{
	if (!file.isOpen())
		return false;

	QTextStream in(&file);

	while (!in.atEnd())
	{
		QString name = in.readLine();
		if (name.isEmpty())
			continue;
		
		int r, g, b, a;

		if (in.atEnd())
			return false;
		
		in >> r;
		in >> g;
		in >> b;
		in >> a;

		if (name == "Line")
		{
			int firstIndex, secondIndex;

			in >> firstIndex;
			in >> secondIndex;

			if (in.status() != QTextStream::Status::Ok)
				return false;

			m_frame->lines.emplace_back(m_frame->shapes, firstIndex, secondIndex, QColor(r,g,b,a));
		}
		else
		{
			QPoint pos;
			int w, h;
			in >> pos.rx();
			in >> pos.ry();
			in >> w;
			in >> h;

			if (in.status() != QTextStream::Status::Ok)
				return false;

			if (name == "Circle")
			{
				m_frame->shapes.push_back(std::make_unique<Circle>(pos, w, h, QColor(r, g, b, a)));
			}
			else if (name == "Rectangle")
			{
				m_frame->shapes.push_back(std::make_unique<Circle>(pos, w, h, QColor(r, g, b, a)));
			}
			else if (name == "Triangle")
			{
				m_frame->shapes.push_back(std::make_unique<Circle>(pos, w, h, QColor(r, g, b, a)));
			}
			else
				return false;
		}
	}

	return true;
}
