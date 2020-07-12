#pragma once
#include <QRect>
#include <QPainter>

constexpr qreal PEN_WIDTH = 2;

class Shape
{
public:
	Shape(QPoint p, int w, int h, QColor c = Qt::black);
	virtual QRect rect() const;
	virtual QPoint center() const;
	virtual QPoint pos() const;
	virtual QColor color() const;
	virtual void setSize(QSize size);
	virtual void setPos(QPoint pos);
	virtual void setColor(QColor c);
	virtual void draw(QPainter& qp) = 0;
	virtual ~Shape() { };
protected:
	QColor colour;
	int width;
	int height;
	QPoint position;
};

