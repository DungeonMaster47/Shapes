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
	void setColor(const QColor& c) noexcept;
	void setMouseHandler(std::unique_ptr<IMouseHandler>&& h);
	QColor color() const noexcept;

	VecUnqPtrShape shapes;
	std::vector<Line> lines;
private:
	std::unique_ptr<IMouseHandler> m_mouseHandler;
	void paintEvent(QPaintEvent* e) override;
	void mousePressEvent(QMouseEvent* e) override;
	void mouseMoveEvent(QMouseEvent* e) override;
	void mouseReleaseEvent(QMouseEvent* e) override;

	QColor m_color = Qt::black;
};