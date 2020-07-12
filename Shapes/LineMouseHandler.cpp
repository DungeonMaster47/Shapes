#include "LineMouseHandler.h"

LineMouseHandler::LineMouseHandler(std::vector<std::unique_ptr<Shape>>& s, std::vector<Line>& l, const QColor& c) : shapes(s), lines(l), currentLine(s), color(c) { }

void LineMouseHandler::mousePress(QMouseEvent * e)
{
	if (e->button() != Qt::MouseButton::LeftButton)
		return;

	for (size_t i = 0; i < shapes.size(); ++i)
	{
		if (shapes[i]->rect().contains(e->pos()))
		{
			QColor selectedColor = shapes[i]->color(); //change shape color to more transparent to show selection
			selectedColor.setAlpha(127);
			shapes[i]->setColor(selectedColor);

			currentLine.setFirstShapeIndex(i);
			shapeSelected = true;
			break;
		}
	}
}

void LineMouseHandler::mouseRelease(QMouseEvent * e)
{
	if (e->button() != Qt::MouseButton::LeftButton)
		return;

	if (shapeSelected)
	{
		QColor oldColor = shapes[currentLine.firstShapeIndex()]->color(); //change shape color back
		oldColor.setAlpha(255);
		shapes[currentLine.firstShapeIndex()]->setColor(oldColor);

		for (size_t i = 0; i < shapes.size(); ++i)
		{
			if (shapes[i] == shapes[currentLine.firstShapeIndex()])
				continue;

			if (shapes[i]->rect().contains(e->pos()))
			{
				currentLine.setSecondShapeIndex(i);
				currentLine.setColor(color);
				lines.push_back(currentLine);
				break;
			}
		}
		shapeSelected = false;
	}
}
