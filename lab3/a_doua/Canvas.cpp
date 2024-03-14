#include"Canvas.h"
#include<iostream>
#include<cmath>

Canvas::Canvas(int wid, int hei)
{
	width = wid;
	height = hei;
	a = new char* [height];
	for (int i = 0; i <= height; i++)
	{
		a[i] = new char[width];
		for (int j = 0; j <= width; j++)
			a[i][j] = ' ';
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	if (x - ray<0 || y - ray<0 || x + ray>width || y + ray>height)
		std::cout << "eroare";
	else
		for (int i = y - ray; i <= y + ray; i++)
			for (int j = x - ray; j <= x + ray; j++)
				if ((y - i) * (y - i) + (x - j) * (x - j) == ray * ray)
					a[i][j] = ch;
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	if (x - ray<0 || y - ray<0 || x + ray>width || y + ray>height)
		std::cout << "eroare";
	else
		for (int i = y - ray; i <= y + ray; i++)
			for (int j = x - ray; j <= x + ray; j++)
				if ((y - i) * (y - i) + (x - j) * (x - j) < ray * ray)
					a[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	if (left<0 || left>width || right<0 || right>width || top<0 || top>height || bottom<0 || bottom>height)
		std::cout << "eroare";
	else
	{
		int aux;
		if (left > right)
		{
			aux = left;
			left = right;
			right = aux;
		}
		if (top > bottom)
		{
			aux = bottom;
			bottom = top;
			top = aux;
		}
		for (int i = left; i <= right; i++)
			a[top][i] = ch;
		for (int i = top; i <= bottom; i++)
			a[i][right] = ch;
		for (int i = right; i >= left; i--)
			a[bottom][i] = ch;
		for (int i = bottom; i >= top; i--)
			a[i][left] = ch;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	if (left<0 || left>width || right<0 || right>width || top<0 || top>height || bottom<0 || bottom>height)
		std::cout << "eroare";
	else
	{
		int aux;
		if (left > right)
		{
			aux = left;
			left = right;
			right = aux;
		}
		if (top > bottom)
		{
			aux = bottom;
			bottom = top;
			top = aux;
		}
		for (int i = top + 1; i < bottom; i++)
			for (int j = left + 1; j < right; j++)
				a[i][j] = ch;
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x<0 || y<0 || x>width || y>height)
		std::cout << "eroare";
	else
		a[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx, dy, sx, sy, error, e2;
	dx = abs(x2 - x1);
	if (x1 < x2)
		sx = 1;
	else
		sx = -1;
	dy = -abs(y2 - y1);
	if (y1 < y2)
		sy = 1;
	else
		sy = -1;
	error = dx + dy;
	while (true)
	{
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2)
			break;
		e2 = 2 * error;
		if (e2 >= dy)
		{
			if (x1 == x2)
				break;
			error = error + dy;
			x1 = x1 + sx;
		}
		if (e2 <= dx)
		{
			if (y1 == y2)
				break;
			error = error + dx;
			y1 = y1 + sy;
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i <= height; i++)
	{
		for (int j = 0; j <= width; j++)
			std::cout << a[i][j]<<' ';
		std::cout << '\n';
	}
}

void Canvas::Clear()
{
	for (int i = 0; i <= height; i++)
		for (int j = 0; j <= width; j++)
			a[i][j] = 32;
}