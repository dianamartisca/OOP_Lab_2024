class Number
{
	char* s;
	int b;
	unsigned int l;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(long int x);
	~Number();
	Number(const Number& n);
	Number(Number&& n);
	Number& operator=(const Number& n);
	Number& operator=(const char* t);
	Number& operator=(long int x);
	long int GetBase10Value() const;
	void SwitchBase(int newBase);
	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);
	Number& operator+=(const Number& n);
	Number& operator-=(const Number& n);
	char operator[](int k);
	bool operator>(const Number& n);
	bool operator<(const Number& n);
	bool operator<=(const Number& n);
	bool operator>=(const Number& n);
	bool operator==(const Number& n);
	bool operator!=(const Number& n);
	Number& operator--(int x);
	Number& operator--();
	void Print();
	int GetDigitsCount(); // returns the number of digits for the current number
	int GetBase(); // returns the current base
};

