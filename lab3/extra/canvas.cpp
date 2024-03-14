#include"canvas.h"
#include<iostream>
#include<cstdarg>

Canvas::Canvas(int l, int c)
{
	lines = l;
	columns = c;
	a[lines][columns];
	clear();
}

// set the character at the position x and y to value
void Canvas::set_pixel(int x, int y, char value)
{
	if (x<0 || x>lines || y<0 || y>columns)
		std::cout << "eroare";
	else
		a[x][y] = value;
}

// tuples of x, y, value
void Canvas::set_pixels(int count, ...)
{
	va_list(args);
	va_start(args, count);
	for (int i = 1; i <= count; i++)
	{
		int x = va_arg(args, int);
		int y = va_arg(args, int);
		char value = va_arg(args, char);
		set_pixel(x, y, value);
	}
	va_end(args);
}

void Canvas::clear()
{
	for (int i = 0; i <= lines; i++)
		for (int j = 0; j <= columns; j++)
			a[i][j] = 32;
}

void Canvas::print() const
{
	for (int i = 0; i <= lines; i++)
	{
		for (int j = 0; j <= columns; j++)
			std::cout << a[i][j] << ' ';
		std::cout << '\n';
	}
}