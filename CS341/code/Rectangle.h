// Class Declaration (.h == Header File)
//
// Lecture #2
//
// By: Dr. Ryan Rybarczyk
class Rectangle
{
	public:		
		// Default Constructor
		Rectangle();
		Rectangle(int x, int y);
		~Rectangle() {};
		// Accessor Method

		virtual double getArea();

		int getX();
	private:
		// Private member attributes (NOTE: trailing underscore)
		int x_, y_;
};