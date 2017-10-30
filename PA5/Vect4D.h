//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#ifndef VECT4D_H
#define VECT4D_H

#include "Trace.h"

#define STUB_PLEASE_REPLACE(x) (x)

class Matrix;

class Vect4D
{
public:
	Vect4D() 
		:x(0.0), y(0.0), z(0.0), w(0.0)
	{
	};

	Vect4D(const Vect4D &t)
		:x(t.x), y(t.y), z(t.z), w(t.w)
	{
	}

	Vect4D &operator = (const Vect4D &tmp)
	{
		x = tmp.x;
		y = tmp.y;
		z = tmp.z;
		w = tmp.w;
		return *this;
	}

	~Vect4D()
	{
	}

	Vect4D( const float tx, const float ty, const float tz, const float tw )
	{
		// quick hack to shut up warnings
		x = y = z = w = 0.0f;
		x = tx;
		y = ty;
		z = tz;
		w = tw;
	}

	void set(const float xVal, const float yVal, const float zVal, const float wVal )
	{
		x = xVal;
		y = yVal;
		z = zVal;
		w = wVal;
	}

	void Print(const char * s)
	{
		Trace::out("%s: %f %f %f %f\n", s, x, y, z, w);
	}

	Vect4D operator + (const Vect4D &t) const
	{

		return Vect4D(x + t.x, y+t.y, z+t.z, w+t.w);
	}

	Vect4D & operator += (const Vect4D &t)
	{
		x += t.x;
		y += t.y;
		z += t.z;
		w += t.w;
		return *this;
	}

	Vect4D operator - (const Vect4D &t) const
	{
		return Vect4D(x - t.x, y - t.y, z - t.z, w - t.w);
	}

	Vect4D & operator -= (const Vect4D &t)
	{
		x -= t.x;
		y -= t.y;
		z -= t.z;
		w -= t.w;
		return *this;
	}

	Vect4D operator * (const Vect4D &t) const
	{
		return Vect4D((x * t.x), (y * t.y), (z*t.z), (w*t.w));
		//DOT PRODUCT?: return Vect4D( (x * t.x) + (y * t.z), (x * t.y) + (y * t.w), (z*t.x)+(w*t.z), (z*t.y)+(w*t.w));
	}

	Vect4D operator * (const float s) const
	{
		return Vect4D(x * s, y * s, z * s,w * s);
	}

	Vect4D &operator *= (const Vect4D &t)
	{
		x *= t.x;
		y *= t.y;
		z *= t.z;
		w *= t.w;
		return *this;
	}

	Vect4D operator / (const Vect4D &t) const
	{
		return Vect4D((x / t.x), (y / t.y), (z/t.z), (w/t.w));
	}

	Vect4D &operator /= (const Vect4D &t)
	{
		x /= t.x;
		y /= t.y;
		z /= t.z;
		w /= t.w;
		return *this;
	}
	
	Vect4D operator * (const Matrix &m)const;

	float dot( const Vect4D &t ) const
	{
		// Only do the inner product for {x,y,z}
		return x*t.x + y*t.y + z*t.z;
	}

	float realDot(const Vect4D &t) const
	{
		// Only do the inner product for {x,y,z}
		return x*t.x + y*t.y + z*t.z + w*t.w;
	}

public:
	float x;
	float y;
	float z;
	float w;
};

#endif

// ---  End of File ---------------
