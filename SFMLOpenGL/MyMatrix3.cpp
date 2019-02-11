#include "MyMatrix3.h"
#define PI           3.14159265358979323846

MyMatrix3::MyMatrix3()
{
	m_11 = 0;
	m_12 = 0;
	m_13 = 0;
	m_21 = 0;
	m_22 = 0;
	m_23 = 0;
	m_31 = 0;
	m_32 = 0;
	m_33 = 0;
}

MyMatrix3::MyMatrix3(double t_a11, double t_a12, double t_a13, double t_a21, double t_a22, double t_a23, double t_a31, double t_a32, double t_a33)
{
	m_11 = t_a11;
	m_12 = t_a12;
	m_13 = t_a13;
	m_21 = t_a21;
	m_22 = t_a22;
	m_23 = t_a23;
	m_31 = t_a31;
	m_32 = t_a32;
	m_33 = t_a33;
}

MyMatrix3::MyMatrix3(MyVector3 t_row1, MyVector3 t_row2, MyVector3 t_row3)
{
	m_11 = t_row1.x;
	m_12 = t_row1.y;
	m_13 = t_row1.z;
	m_21 = t_row2.x;
	m_22 = t_row2.y;
	m_23 = t_row2.z;
	m_31 = t_row3.x;
	m_32 = t_row3.y;
	m_33 = t_row3.z;
}

MyMatrix3::~MyMatrix3()
{
}

std::string MyMatrix3::toString() const
{
	const std::string output = "[" + std::to_string(m_11) + " " + std::to_string(m_12) + " " + std::to_string(m_13) + " "
		+ std::to_string(m_21) + " " + std::to_string(m_22) + " " + std::to_string(m_23) + " "
		+ std::to_string(m_31) + " " + std::to_string(m_32) + " " + std::to_string(m_33) + "]";
	return output;
}

bool MyMatrix3::operator==(const MyMatrix3 t_other) const
{
	const bool answer{ m_11 == t_other.m_11 && m_12 == t_other.m_12 && m_13 == t_other.m_13 &&
		m_21 == t_other.m_21 && m_22 == t_other.m_22 && m_23 == t_other.m_23 &&
		m_31 == t_other.m_31 && m_32 == t_other.m_32 && m_33 == t_other.m_33 };
	return answer;
}

bool MyMatrix3::operator!=(const MyMatrix3 t_other) const
{
	const bool answer{ m_11 != t_other.m_11 || m_12 != t_other.m_12 || m_13 != t_other.m_13 ||
		m_21 != t_other.m_21 || m_22 != t_other.m_22 || m_23 != t_other.m_23 ||
		m_31 != t_other.m_31 || m_32 != t_other.m_32 || m_33 != t_other.m_33 };

	return answer;
}

MyMatrix3 MyMatrix3::operator+(const MyMatrix3 t_other) const
{

	return MyMatrix3{ m_11 + t_other.m_11, m_12 + t_other.m_12, m_13 + t_other.m_13,
		m_21 + t_other.m_21, m_22 + t_other.m_22, m_23 + t_other.m_23,
		m_31 + t_other.m_31, m_32 + t_other.m_32, m_33 + t_other.m_33 };
}

MyMatrix3 MyMatrix3::operator-(const MyMatrix3 t_other) const
{
	return MyMatrix3{ m_11 - t_other.m_11, m_12 - t_other.m_12, m_13 - t_other.m_13,
		m_21 - t_other.m_21, m_22 - t_other.m_22, m_23 - t_other.m_23,
		m_31 - t_other.m_31, m_32 - t_other.m_32, m_33 - t_other.m_33 };
}

MyMatrix3 MyMatrix3::operator*(const MyMatrix3 t_other) const
{
	return MyMatrix3{ m_11 * t_other.m_11, m_12 * t_other.m_12, m_13 * t_other.m_13,
		m_21 * t_other.m_21, m_22 * t_other.m_22, m_23 * t_other.m_23,
		m_31 * t_other.m_31, m_32 * t_other.m_32, m_33 * t_other.m_33 };
}

MyVector3 MyMatrix3::operator*(const MyVector3 t_vector) const
{
	return MyVector3{ m_11 * t_vector.x + m_12 * t_vector.y + m_13 * t_vector.z,
		m_21 * t_vector.x + m_22 * t_vector.y + m_23 * t_vector.z,
		m_31 * t_vector.x + m_32 * t_vector.y + m_33 * t_vector.z };
}

MyMatrix3 MyMatrix3::operator*(const double t_scale) const
{
	return MyMatrix3{ m_11 * t_scale, m_12 * t_scale, m_13 * t_scale,
		m_21 * t_scale, m_22 * t_scale, m_23 * t_scale,
		m_31 * t_scale, m_32 * t_scale, m_33 * t_scale };
}

MyMatrix3 MyMatrix3::transpose() const
{
	return MyMatrix3(m_11, m_21, m_31,
		m_12, m_22, m_32,
		m_13, m_23, m_33);
}

double MyMatrix3::determinant() const
{
	double det = m_11 * (m_22*m_33 - m_23 * m_32) - m_21 * (m_33*m_12 - m_32 * m_13) + m_31 * (m_23*m_12 - m_22 * m_13);
	return det;
}

MyMatrix3 MyMatrix3::inverse() const
{
	MyMatrix3 inversedMatrix;
	double det = m_11 * (m_22*m_33 - m_23 * m_32) - m_21 * (m_33*m_12 - m_32 * m_13) + m_31 * (m_23*m_12 - m_22 * m_13);

	MyMatrix3 temp = { (m_33*m_22) - (m_32*m_23), (m_32*m_13) - (m_33*m_12), (m_23*m_12) - (m_22*m_13),
		(m_31*m_23) - (m_33*m_21), (m_33*m_11) - (m_31*m_13), (m_21*m_13) - (m_23*m_11),
		(m_32*m_21) - (m_31*m_22), (m_31*m_12) - (m_32*m_11), (m_22*m_11) - (m_21*m_12) };

	if (det != 0)
	{
		inversedMatrix = temp * (1 / det);
	}

	return inversedMatrix;
}

MyVector3 MyMatrix3::row(const int t_row) const
{
	MyVector3 temp;
	if (t_row == 0)
	{
		temp = { m_11,m_12,m_13 };
	}
	if (t_row == 1)
	{
		temp = { m_21,m_22,m_23 };
	}
	if (t_row == 2)
	{
		temp = { m_31,m_32,m_33 };
	}

	return temp;
}

MyVector3 MyMatrix3::column(const int t_column) const
{
	MyVector3 temp;
	if (t_column == 0)
	{
		temp = { m_11,m_21,m_31 };
	}
	if (t_column == 1)
	{
		temp = { m_12,m_22,m_32 };
	}
	if (t_column == 2)
	{
		temp = { m_13,m_23,m_33 };
	}

	return temp;
}

MyMatrix3 MyMatrix3::rotationZ(const double t_angleRadians)
{
	return MyMatrix3{ cos(t_angleRadians), -sin(t_angleRadians), 0,
		sin(t_angleRadians), cos(t_angleRadians), 0,
		0, 0, 1 };
}

MyMatrix3 MyMatrix3::rotationY(const double t_angleRadians)
{
	return MyMatrix3{ cos(t_angleRadians), 0 , sin(t_angleRadians),
		0 , 1 , 0,
		-sin(t_angleRadians), 0, cos(t_angleRadians) };
}

MyMatrix3 MyMatrix3::rotationX(const double t_angleRadians)
{
	return MyMatrix3{ 1, 0, 0,
		0, cos(t_angleRadians), -sin(t_angleRadians),
		0, sin(t_angleRadians), cos(t_angleRadians) };
}

MyMatrix3 MyMatrix3::translation(const MyVector3 t_displacement)
{
	return MyMatrix3(1, 0, t_displacement.x,
		0, 1, t_displacement.y,
		0, 0, 1);
}

MyMatrix3 MyMatrix3::scale(const double t_scalingfactor)
{
	return MyMatrix3(t_scalingfactor, 0, 0
		, 0, t_scalingfactor, 0
		, 0, 0, t_scalingfactor);
}