#pragma once
#include <QRect>
#include <QPainter>

class Shape
{
public:
	Shape(QPoint p, int w, int h, QColor c = Qt::black) noexcept;
	virtual QSize size() const noexcept; 
	virtual QRect rect() const noexcept;
	virtual QPoint center() const noexcept;
	virtual QPoint pos() const noexcept;
	virtual QColor color() const noexcept;
	virtual void setSize(QSize size) noexcept;
	virtual void setPos(QPoint pos) noexcept;
	virtual void setColor(QColor c) noexcept;
	virtual void draw(QPainter& qp) = 0;
	virtual ~Shape() { };

	constexpr static qreal PEN_WIDTH = 2;
protected:
	QColor m_color;
	int m_width;
	int m_height;
	QPoint m_position;
};

typedef std::vector<std::unique_ptr<Shape>> VecUnqPtrShape;
