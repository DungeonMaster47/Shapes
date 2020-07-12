#include "MoveMouseHandler.h"

MoveMouseHandler::MoveMouseHandler(std::vector<std::unique_ptr<Shape>>& s) : shapes(s) { }

void MoveMouseHandler::mousePress(QMouseEvent * e)
{
	if (e->button() != Qt::MouseButton::LeftButton)
		return;

	for (auto& s : shapes)
	{
		if (s->rect().contains(e->pos()))
		{
			currentShape = &(*s);
			prevPos = e->pos();
			shapeSelected = true;
			break;
		}
	}
}

void MoveMouseHandler::mouseMove(QMouseEvent * e)
{
	if (shapeSelected)
	{
		currentShape->setPos(currentShape->pos() + (e->pos() - prevPos));
		prevPos = e->pos();
	}
}

void MoveMouseHandler::mouseRelease(QMouseEvent * e)
{
	if (e->button() != Qt::MouseButton::LeftButton)
		return;

	if (shapeSelected)
	{
		shapeSelected = false;
		currentShape = nullptr;
	}
}

