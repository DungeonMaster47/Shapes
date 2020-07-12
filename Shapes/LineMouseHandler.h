#pragma once
#include "IMouseHandler.h"
#include "Shape.h"
#include "Line.h"

class LineMouseHandler : public IMouseHandler
{
public:
	LineMouseHandler(std::vector<std::unique_ptr<Shape>>& s, std::vector<Line>& l, const QColor& c);
	void mousePress(QMouseEvent* e) override;
	void mouseRelease(QMouseEvent* e) override;
private:
	std::vector<std::unique_ptr<Shape>>& shapes;
	std::vector<Line>& lines;
	bool shapeSelected = false;
	const QColor& color;
	Line currentLine;
};

