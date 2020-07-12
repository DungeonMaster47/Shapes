#include "DrawingField.h"

DrawingField::DrawingField(QWidget* parent) : QWidget(parent) 
{
	mouseHandler = std::make_unique<DefaultMouseHandler>();
	colour = Qt::black;
}

void DrawingField::setColor(const QColor& c)
{
	colour = c;
}

void DrawingField::setMouseHandler(std::unique_ptr<IMouseHandler>&& h)
{
	mouseHandler = std::move(h);
}

const QColor& DrawingField::color()
{
	return colour;
}

void DrawingField::paintEvent(QPaintEvent* e)
{
	QPainter qp(this);
	qp.setRenderHint(QPainter::RenderHint::Antialiasing);

	for (auto& s : shapes)
	{
		s->draw(qp);
	} 

	for (auto l : lines)
	{
		l.draw(qp);
	}
}

void DrawingField::mousePressEvent(QMouseEvent* e)
{
	mouseHandler->mousePress(e);
	update();
}

void DrawingField::mouseMoveEvent(QMouseEvent* e)
{
	mouseHandler->mouseMove(e);
	update();
}

void DrawingField::mouseReleaseEvent(QMouseEvent* e)
{
	mouseHandler->mouseRelease(e);
	update();
}