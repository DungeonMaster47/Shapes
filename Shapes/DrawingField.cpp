#include "DrawingField.h"

DrawingField::DrawingField(QWidget* parent) : QWidget(parent) 
{
	m_mouseHandler = std::make_unique<DefaultMouseHandler>(this);
	m_color = Qt::black;
}

void DrawingField::setColor(const QColor& c) noexcept
{
	m_color = c;
}

void DrawingField::setMouseHandler(std::unique_ptr<IMouseHandler>&& h)
{
	m_mouseHandler = std::move(h);
}

QColor DrawingField::color() const noexcept
{
	return m_color;
}

void DrawingField::paintEvent(QPaintEvent* e)
{
	QPainter qp(this);
	qp.setRenderHint(QPainter::RenderHint::Antialiasing);

	for (auto& s : shapes)
	{
		s->draw(qp);
	} 

	for (auto&& l : lines)
	{
		l.draw(qp);
	}
}

void DrawingField::mousePressEvent(QMouseEvent* e)
{
	m_mouseHandler->mousePress(e);
	update();
}

void DrawingField::mouseMoveEvent(QMouseEvent* e)
{
	m_mouseHandler->mouseMove(e);
	update();
}

void DrawingField::mouseReleaseEvent(QMouseEvent* e)
{
	m_mouseHandler->mouseRelease(e);
	update();
}