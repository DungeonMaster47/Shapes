#pragma once
#include "IMouseHandler.h"
#include "Shape.h"
#include "DrawingField.h"

class MoveMouseHandler : public IMouseHandler
{
public:
	MoveMouseHandler(DrawingField* owner) noexcept;
	void mousePress(QMouseEvent* e) override;
	void mouseMove(QMouseEvent* e) override;
	void mouseRelease(QMouseEvent* e) override;
private:
	Shape* m_currentShape = nullptr;
	QPoint m_prevPos;
	bool m_isShapeSelected = false;
};

