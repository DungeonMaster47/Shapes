#pragma once
#include "IMouseHandler.h"
#include "Shape.h"
#include "Line.h"
#include "DrawingField.h"

class LineMouseHandler : public IMouseHandler
{
public:
	LineMouseHandler(DrawingField* owner) noexcept;
	void mousePress(QMouseEvent* e) override;
	void mouseRelease(QMouseEvent* e) override;
private:
	bool m_isShapeSelected = false;
	Line m_currentLine;
};

