#include "MyVector3.h"
#include <string.h>
#define PI           3.14159265358979323846

/// <summary>
/// Defautl constructor set all 3 values to zero
/// </summary>
MyVector3::MyVector3() :
	x{ 0.0 },
	y{ 0.0 },
	z{ 0.0 }
{
}

/// <summary>
/// default destructor
/// nothing to release because we only have
/// primitive type data
/// </summary>
MyVector3::~MyVector3()
{
}

/// <summary>
/// 
/// </summary>
/// <returns>the vector as a string surrounded by square brackets and seperated by commas</returns>
std::string MyVector3::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	return output;
}

MyVector3::MyVector3(double t_x, double t_y, double t_z) :// the null vector
	x{ t_x },
	y{ t_y },
	z{ t_z }
{
}

MyVector3::MyVector3(sf::Vector3f t_sfVector)// changing the vector to float values
{
	x = static_cast<float>(t_sfVector.x);
	y = static_cast<float>(t_sfVector.y);
	z = static_cast<float>(t_sfVector.z);
}

MyVector3::MyVector3(sf::Vector3i t_sfVector)// changing the vector to int values
{
	x = static_cast<int>(t_sfVector.x);
	y = static_cast<int>(t_sfVector.y);
	z = static_cast<int>(t_sfVector.z);
}

MyVector3::MyVector3(sf::Vector2i t_sfVector)// changing the 2D vector to int values
{
	x = static_cast<int>(t_sfVector.x);
	y = static_cast<int>(t_sfVector.y);
	z = static_cast<int>(0);
}

MyVector3::MyVector3(sf::Vector2u t_sfVector)// changing the 2D vector to unsigned int values
{
	x = static_cast<unsigned int>(t_sfVector.x);
	y = static_cast<unsigned int>(t_sfVector.y);
	z = static_cast<unsigned int>(0);
}

MyVector3::MyVector3(sf::Vector2f t_sfVector)// changing the 2D vector to float values
{
	x = static_cast<float>(t_sfVector.x);
	y = static_cast<float>(t_sfVector.y);
	z = static_cast<float>(0.0f);
}

bool MyVector3::operator==(const MyVector3 t_right) const// seeing if the values are equal to each other
{
	const bool result{ x == t_right.x && y == t_right.y && z == t_right.z };
	return result;
}

bool MyVector3::operator!=(const MyVector3 t_right) const// seeing if the values aren't equal to each other
{
	const bool result{ x != t_right.x || y != t_right.y || z == t_right.z };
	return result;
}

MyVector3 MyVector3::operator+(const MyVector3 t_right) const// adding the vectors to each other
{
	return MyVector3(x + t_right.x, y + t_right.y, z + t_right.z);
}

MyVector3 MyVector3::operator-(const MyVector3 t_right) const// subtracting the vectors from each other
{
	return MyVector3(x - t_right.x, y - t_right.y, z - t_right.z);
}

MyVector3 MyVector3::operator*(const double t_scalar) const// multiplying the vectors by a scalar
{
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}

MyVector3 MyVector3::operator/(const double t_divisor) const
{
	if (t_divisor != 0)
	{
		return MyVector3(x / t_divisor, y / t_divisor, z / t_divisor);// dividing vector by a diviser
	}
	return MyVector3();
}

MyVector3 MyVector3::operator+=(const MyVector3 t_right)// adding a vector to itself
{
	x += t_right.x;
	y += t_right.y;
	z += t_right.z;

	return MyVector3(x, y, z);
}

MyVector3 MyVector3::operator-=(const MyVector3 t_right)// subtracting a vector from itself
{
	x -= t_right.x;
	y -= t_right.y;
	z -= t_right.z;

	return MyVector3();
}

MyVector3 MyVector3::operator-()// making a vector negative
{
	return MyVector3(-x, -y, -z);
}

double MyVector3::length() const// calculations for the vectors length
{

	return sqrt(x * x + y * y + z * z);
}

double MyVector3::lengthSquared() const// squaring a vectors lenght
{
	return (sqrt(x * x + y * y + z * z)) * (sqrt(x * x + y * y + z * z));
}

double MyVector3::dot(const MyVector3 t_other) const// getting the dot product of a vector
{
	return (x * t_other.x) + (y * t_other.y) + (z * t_other.z);
}

MyVector3 MyVector3::crossProduct(const MyVector3 t_other) const// getting the cross product of a vector
{
	return MyVector3((y * t_other.z - z * t_other.y), (z * t_other.x - x * t_other.z), (y * t_other.x - x * t_other.y));
}

double MyVector3::angleBetween(const MyVector3 t_other) const// calculations to get the angle between vectors
{
	const double cosine = unit().dot(t_other.unit());
	const double angleRadians = std::acos(cosine);
	const double angleDegrees = angleRadians * 180 / PI;
	return angleDegrees;
}

MyVector3 MyVector3::unit() const// calculations for the vectors unit
{
	if (x != 0 || y != 0 || z != 0)
	{
		return MyVector3(x / length(), y / length(), z / length());
	}
	else
	{
		return MyVector3(x, y, z);
	}
}

MyVector3 MyVector3::normalise()// calculations for the normalisation of a vector 
{
	MyVector3 normaliseVec;
	double vectorLenght = this->length();
	if (vectorLenght != 0)
	{
		normaliseVec.x = x / vectorLenght;
		normaliseVec.y = y / vectorLenght;
		normaliseVec.z = z / vectorLenght;
	}
	return normaliseVec;


}

MyVector3 MyVector3::projection(const MyVector3 t_other) const// calculations to get the projection of a vector
{
	double newX = x * dot(t_other) / lengthSquared();
	double newY = y * dot(t_other) / lengthSquared();
	double newZ = z * dot(t_other) / lengthSquared();

	return MyVector3(newX, newY, newZ);
}

MyVector3 MyVector3::rejection(const MyVector3 t_other) const// calculations to get the rejection of a vector
{
	return MyVector3(MyVector3(t_other) - projection(t_other));
}
