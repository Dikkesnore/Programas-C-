/********************************************************
*                                                       *
*                  Marcelo Teles TM b*                  *
*                     Geometry Code                     *
*                                                       *
*********************************************************/

#include <iostream>
#include <cmath>

// Structures
// Line struct --> y = incline * x + c
typedef struct{
	double incline;
	double c;
}
line;

// Calculate the middle point between P1(x1, y1) and P2(x2, y2).
// The point M(mx, my) represents the middle point (Pass by Reference).
void midpoint(double x1, double y1, double x2, double y2, 
	double& mx, double& my)
{
	mx = (x2 - x1) / 2;
	my = (y2 - y1) / 2;
}

// Creates a line structure given two points.
// P1(x1, y1) and P2(x2, y2).
line createLine(double x1, double y1, double x2, double y2)
{
	line L;
	L.incline = ((x2 - x1) != 0) ? (y2 - y1) / (x2 - x1) : 0;
	L.c = y1 - x1 * L.incline;
	return L;
}

// Calculates the intersection of two lines.
// The first line goes through the points P1(x1, y1) and P2(x2, y2)
// the second line goes through the points P3(x3, y3) and P4(x4, y4).
// The point I(ix, iy) is the intersection (Pass by Reference).
// If the lines don't interact both ix and iy are INFINITY.
void intersection(double x1, double y1, double x2, double y2,
	double x3, double y3, double x4, double y4,
	double &ix, double &iy)
{
	line L1 = createLine(x1, y1, x2, y2);
	line L2 = createLine(x3, y3, x4, y4);

	if (L1.incline == L2.incline)
	{
		ix = INFINITY;
		iy = INFINITY;
	}
	else
	{
		ix = (L2.c - L1.c) / (L1.incline - L2.incline);
		iy = L1.incline * ix + L1.c;
	}
}

// Just for testing the functions above.
int main()
{
	double intersectionX = 0, intersectionY = 0;

	intersection(0, 0, 1, 10, 0, 10, 1, 0, intersectionX, intersectionY);
	std::cout << "The intersection point is x = " << intersectionX
		<< " and y = " << intersectionY << '\n';

	return 0;
}