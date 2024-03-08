#pragma once

class Movie
{
private:
	char name[256];
	unsigned int year;
	double score;
	unsigned int length;

public:
	void set_name(const char s[]);
	char* get_name();
	void set_year(unsigned int x);
	unsigned get_year();
	void set_score(double x);
	double get_score();
	void set_length(unsigned int x);
	unsigned int get_length();
	unsigned int get_passed_years();
};

class movieseries
{
private:
	unsigned int count;
	Movie* v[16];

public:
	void init();
	void add(Movie *a);
	void print();
	void sort();
};