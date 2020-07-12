#pragma once
#include "IMouseHandler.h"
#include "Shape.h"

class MoveMouseHandler : public IMouseHandler
{
public:
	MoveMouseHandler(std::vector<std::unique_ptr<Shape>>& s);
	void mousePress(QMouseEvent* e) override;
	void mouseMove(QMouseEvent* e) override;
	void mouseRelease(QMouseEvent* e) override;
private:
	std::vector<std::unique_ptr<Shape>>& shapes;
	Shape* currentShape = nullptr;
	QPoint prevPos;
	bool shapeSelected = false;
};

