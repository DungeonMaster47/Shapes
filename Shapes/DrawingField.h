#pragma once
#include <QtWidgets/QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <memory>
#include <vector>
#include "IMouseHandler.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Line.h"

class DrawingField : public QWidget
{
	Q_OBJECT

public:
	DrawingField(QWidget* parent);
	void setColor(const QColor& c);
	void setMouseHandler(std::unique_ptr<IMouseHandler>&& h);
	const QColor& color();

	std::vector<std::unique_ptr<Shape>> shapes;
	std::vector<Line> lines;
private:
	std::unique_ptr<IMouseHandler> mouseHandler;
	void paintEvent(QPaintEvent* e) override;
	void mousePressEvent(QMouseEvent* e) override;
	void mouseMoveEvent(QMouseEvent* e) override;
	void mouseReleaseEvent(QMouseEvent* e) override;

	QColor colour;
};