#include "Collider.h"

Collider::Collider(Point* position, Rect dimensions) : position(position)
{
	setDimensions(dimensions);
}

void Collider::setDimensions(Rect dimensions)
{
	top = dimensions.y;
	bottom = dimensions.y + dimensions.h - 1;
	left = dimensions.x;
	right = dimensions.x + dimensions.w - 1;
}

bool Collider::hitTest(Point colliderPoint)
{
	if(colliderPoint.x >= position->x + left && colliderPoint.x <= position->x + right && 
		 colliderPoint.y >= position->y + top && colliderPoint.y <= position->y + bottom) return true;
	else return false;
}

bool Collider::hitTest(Collider collider, Point offset)
{
	if(position->x + left + offset.x > collider.getPosition()->x + collider.getRight() || collider.getPosition()->x + collider.getLeft() > position->x + right + offset.x ||
	   position->y + top + offset.y > collider.getPosition()->y + collider.getBottom() || collider.getPosition()->y + collider.getTop() > position->y + bottom + offset.y) return false;
	else return true;
}