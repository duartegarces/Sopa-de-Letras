#pragma once
class Point
{
private:
	int x;
	int y;

public:
	Point();
	Point(int,int);
	inline int GetX() const { return x; }
	inline int GetY() const { return y; }
	bool SetX(int);
	bool SetY(int);

	bool IsValid(void);
	bool Ask2Set(void);
	void Show(void);

	bool operator == (const Point P) const;

	~Point();
};

