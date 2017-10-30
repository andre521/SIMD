//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#ifndef VECT4D_SIMD_H
#define VECT4D_SIMD_H

#include <xmmintrin.h>
#include <smmintrin.h>  

#define STUB_PLEASE_REPLACE(x) (x)

class Matrix_SIMD;

class Vect4D_SIMD
{
public:
	Vect4D_SIMD() 
		: x(0.0), y(0.0), z(0.0), w(0.0)
	{
	};

	Vect4D_SIMD(const Vect4D_SIMD &t)
		:_m(t._m)
	{
	}

	Vect4D_SIMD(const __m128 t)
		:_m(t)
	{
	}


	Vect4D_SIMD &operator = (const Vect4D_SIMD &tmp)
	{
		this->_m = _mm_set_ps(tmp.w ,tmp.z, tmp.y, tmp.x);
		//_m = tmp._m;

		return *this;
	}

	~Vect4D_SIMD()
	{
	};


	Vect4D_SIMD(const float tx, const float ty, const float tz, const float tw)
	{
		// quick hack to shut up warnings
		x = y = z = w = 0.0f;

		this->_m = _mm_set_ps(tw, tz, ty, tx);

		/*x = tx;
		y = ty;
		z = tz;
		w = tw;*/

	}

	void set(const float xVal, const float yVal, const float zVal, const float wVal )
	{

		this->_m = _mm_set_ps(wVal, zVal, yVal, xVal);

		/*x = xVal;
		y = yVal;
		z = zVal;
		w = wVal;*/
	}

	Vect4D_SIMD operator * (const float t)
	{
		return Vect4D_SIMD(_mm_mul_ps(this->_m, _mm_set1_ps(t)));
	}

	Vect4D_SIMD operator + (const Vect4D_SIMD &tmp) const
	{
		return Vect4D_SIMD(_mm_add_ps(_m,tmp._m));
	}

	Vect4D_SIMD & operator += (const Vect4D_SIMD &tmp)
	{
		_m =  (_mm_add_ps(_m, tmp._m));
		return *this;
	}

	Vect4D_SIMD operator - (const Vect4D_SIMD &tmp) const
	{
		
		return Vect4D_SIMD(_mm_sub_ps(_m,tmp._m));
	}

	Vect4D_SIMD & operator -= (const Vect4D_SIMD &tmp)
	{
		_m = (_mm_sub_ps(_m, tmp._m));
		return *this;
	}

	Vect4D_SIMD operator * (const Vect4D_SIMD &tmp) const
	{
		return Vect4D_SIMD(_mm_mul_ps(_m, tmp._m));
	}

	Vect4D_SIMD & operator *= (const Vect4D_SIMD &tmp)
	{
		_m = (_mm_mul_ps(_m, tmp._m));
		return *this;
	}

	Vect4D_SIMD operator / (const Vect4D_SIMD &tmp) const
	{
		return Vect4D_SIMD(_mm_div_ps(_m,tmp._m));
	}

	Vect4D_SIMD &operator /= (const Vect4D_SIMD &tmp)
	{
		_m = (_mm_div_ps(_m, tmp._m));
		return *this;
	}

	float dot(const Vect4D_SIMD &t) const
	{
		// Only do the inner product for {x,y,z}
		//return Vect4D_SIMD(_mm_dp_ps(_m, t._m, 0x78)).w;

		Vect4D_SIMD tmp = _mm_mul_ps(_m, t._m);

		return tmp.x + tmp.y + tmp.z;


	}

	float realDot(const Vect4D_SIMD &t) const
	{
		// Only do the inner product for {x,y,z}
		//return Vect4D_SIMD(_mm_dp_ps(_m, t._m, 0xF8)).w;

		Vect4D_SIMD tmp = _mm_mul_ps(_m, t._m);

		return tmp.x + tmp.y + tmp.z + tmp.w;

	}

	Vect4D_SIMD operator * (const Matrix_SIMD &m) const;

public:

	// anonymous union
	union
	{
		__m128	_m;

		// anonymous struct
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};
};

#endif

// ---  End of File ---------------
