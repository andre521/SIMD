//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#ifndef MATRIX_SIMD_H
#define MATRIX_SIMD_H

#include "Vect4D_SIMD.h"

#include <xmmintrin.h>
#include <smmintrin.h> 

#define STUB_PLEASE_REPLACE(x) (x)

class Matrix_SIMD
{
public:
	Matrix_SIMD()
		:v0(_mm_set_ps1(0)), v1(_mm_set_ps1(0)), v2(_mm_set_ps1(0)), v3(_mm_set_ps1(0))
	{
	}

	Matrix_SIMD(const Matrix_SIMD &tmp)
		:v0(tmp.v0), v1(tmp.v1), v2(tmp.v2), v3(tmp.v3)
	{
	}

	Matrix_SIMD &operator=(const Matrix_SIMD &tmp)
	{

		v0 = _mm_set_ps(tmp.v0.w, tmp.v0.z, tmp.v0.y, tmp.v0.x);
		v1 = _mm_set_ps(tmp.v1.w, tmp.v1.z, tmp.v1.y, tmp.v1.x);
		v2 = _mm_set_ps(tmp.v2.w, tmp.v2.z, tmp.v2.y, tmp.v2.x);
		v3 = _mm_set_ps(tmp.v3.w, tmp.v3.z, tmp.v3.y, tmp.v3.x);

		return *this;
	}

	~Matrix_SIMD()
	{
	}

	Matrix_SIMD(const Vect4D_SIMD &tV0, const Vect4D_SIMD &tV1, const Vect4D_SIMD &tV2, const Vect4D_SIMD &tV3)
		:v0(tV0), v1(tV1), v2(tV2), v3(tV3)
	{
	}

	//Vect4D_SIMD operator * (const Vect4D_SIMD &v);

	//Matrix_SIMD operator * (const Matrix_SIMD &t);

	union
	{
		struct
		{
			Vect4D_SIMD v0;
			Vect4D_SIMD v1;
			Vect4D_SIMD v2;
			Vect4D_SIMD v3;
		};

		struct
		{
			float m0;
			float m1;
			float m2;
			float m3;
			float m4;
			float m5;
			float m6;
			float m7;
			float m8;
			float m9;
			float m10;
			float m11;
			float m12;
			float m13;
			float m14;
			float m15;
		};
	};

	friend class Mv;
	friend class MM;
	friend class MMM;
	friend class MMMM;
	friend class MMMMM;
	friend class MMMMMM;
	friend class MMMMMv;
	friend class vMMMMM;
};

// Start of Matrix Proxy

class MM
{
public:
	const Matrix_SIMD &m1;
	const Matrix_SIMD &m2;

	// Constructor
	MM(const Matrix_SIMD &t1, const Matrix_SIMD &t2)
		:m1(t1), m2(t2) {};

	// Copy constructor
	MM::MM(const MM &mm) : m1(mm.m1), m2(mm.m2) {};

	inline operator Matrix_SIMD()
	{

		/*Vect4D_SIMD tmp1 = _mm_set_ps(m2.m0, m2.m4, m2.m8, m2.m12);
		Vect4D_SIMD tmp2 = _mm_set_ps(m2.m1, m2.m5, m2.m9, m2.m13);
		Vect4D_SIMD tmp3 = _mm_set_ps(m2.m2, m2.m6, m2.m10, m2.m14);
		Vect4D_SIMD tmp4 = _mm_set_ps(m2.m3, m2.m7, m2.m11, m2.m15);

		Vect4D_SIMD fin1 = _mm_set_ps(m1.v0.realDot(tmp1), m1.v0.realDot(tmp2), m1.v0.realDot(tmp3), m1.v0.realDot(tmp4));
		Vect4D_SIMD fin2 = _mm_set_ps(m1.v1.realDot(tmp1), m1.v1.realDot(tmp2), m1.v1.realDot(tmp3), m1.v1.realDot(tmp4));
		Vect4D_SIMD fin3 = _mm_set_ps(m1.v2.realDot(tmp1), m1.v2.realDot(tmp2), m1.v2.realDot(tmp3), m1.v2.realDot(tmp4));
		Vect4D_SIMD fin4 = _mm_set_ps(m1.v3.realDot(tmp1), m1.v3.realDot(tmp2), m1.v3.realDot(tmp3), m1.v3.realDot(tmp4));
*/

		Vect4D_SIMD tmp1 = _mm_set_ps(m2.m12, m2.m8, m2.m4, m2.m0);
		Vect4D_SIMD tmp2 = _mm_set_ps(m2.m13, m2.m9, m2.m5, m2.m1);
		Vect4D_SIMD tmp3 = _mm_set_ps(m2.m14, m2.m10, m2.m6, m2.m2);
		Vect4D_SIMD tmp4 = _mm_set_ps(m2.m15, m2.m11, m2.m7, m2.m3);

		Vect4D_SIMD fin1 = _mm_set_ps(m1.v0.realDot(tmp4), m1.v0.realDot(tmp3), m1.v0.realDot(tmp2), m1.v0.realDot(tmp1));
		Vect4D_SIMD fin2 = _mm_set_ps(m1.v1.realDot(tmp4), m1.v1.realDot(tmp3), m1.v1.realDot(tmp2), m1.v1.realDot(tmp1));
		Vect4D_SIMD fin3 = _mm_set_ps(m1.v2.realDot(tmp4), m1.v2.realDot(tmp3), m1.v2.realDot(tmp2), m1.v2.realDot(tmp1));
		Vect4D_SIMD fin4 = _mm_set_ps(m1.v3.realDot(tmp4), m1.v3.realDot(tmp3), m1.v3.realDot(tmp2), m1.v3.realDot(tmp1));


		Matrix_SIMD mat = Matrix_SIMD(fin1, fin2, fin3, fin4);

		return mat;
	}

	MM& MM::operator=(const MM &c) = delete;
	MM& MM::operator>>(const MM &c) = delete;
	MM& MM::operator<<(const MM &c) = delete;
};

inline MM operator * (const Matrix_SIMD &a1, const Matrix_SIMD &a2)
{
	return MM(a1, a2);
}


class MMM
{
public:
	const Matrix_SIMD &m1;
	const Matrix_SIMD &m2;
	const Matrix_SIMD &m3;


	// Constructor
	MMM(const MM &t1, const Matrix_SIMD &t2)
		:m1(t1.m1), m2(t1.m2), m3(t2) {};

	// Copy constructor
	MMM::MMM(const MMM &mmm) : m1(mmm.m1), m2(mmm.m2), m3(mmm.m3) {};

	inline operator Matrix_SIMD()
	{
		return Matrix_SIMD(m1 * m2 * m3);
	}

	MMM& operator=(const MMM &c) = delete;
	MMM& operator>>(const MMM &c) = delete;
	MMM& operator<<(const MMM &c) = delete;
};

inline MMM operator * (const MM &a1, const Matrix_SIMD &a2)
{
	return MMM(a1, a2);
}

class MMMM
{
public:
	const Matrix_SIMD &m1;
	const Matrix_SIMD &m2;
	const Matrix_SIMD &m3;
	const Matrix_SIMD &m4;


	// Constructor
	MMMM(const MMM &t1, const Matrix_SIMD &t2)
		:m1(t1.m1), m2(t1.m2), m3(t1.m3), m4(t2) {};

	// Copy constructor
	MMMM::MMMM(const MMMM &MMMM) : m1(MMMM.m1), m2(MMMM.m2), m3(MMMM.m3), m4(MMMM.m4) {};

	inline operator Matrix_SIMD()
	{
		return Matrix_SIMD(m1 * m2 * m3 * m4);
	}

	MMMM& operator=(const MMMM &c) = delete;
	MMMM& operator>>(const MMMM &c) = delete;
	MMMM& operator<<(const MMMM &c) = delete;
};

inline MMMM operator * (const MMM &a1, const Matrix_SIMD &a2)
{
	return MMMM(a1, a2);
}

class MMMMM
{
public:
	const Matrix_SIMD &m1;
	const Matrix_SIMD &m2;
	const Matrix_SIMD &m3;
	const Matrix_SIMD &m4;
	const Matrix_SIMD &m5;


	// Constructor
	MMMMM(const MMMM &t1, const Matrix_SIMD &t2)
		:m1(t1.m1), m2(t1.m2), m3(t1.m3), m4(t1.m4), m5(t2) {};

	// Copy constructor
	MMMMM::MMMMM(const MMMMM &MMMMM) : m1(MMMMM.m1), m2(MMMMM.m2), m3(MMMMM.m3), m4(MMMMM.m4), m5(MMMMM.m5) {};

	inline operator Matrix_SIMD()
	{
		return Matrix_SIMD(m1 * m2 * m3 * m4 * m5);
	}

	MMMMM& operator=(const MMMMM &c) = delete;
	MMMMM& operator>>(const MMMMM &c) = delete;
	MMMMM& operator<<(const MMMMM &c) = delete;
};

inline MMMMM operator * (const MMMM &a1, const Matrix_SIMD &a2)
{
	return MMMMM(a1, a2);
}

class MMMMMv
{
public:
	const Matrix_SIMD &m1;
	const Matrix_SIMD &m2;
	const Matrix_SIMD &m3;
	const Matrix_SIMD &m4;
	const Matrix_SIMD &m5;
	const Vect4D_SIMD &v;


	// Constructor
	MMMMMv(const MMMMM &t1, const Vect4D_SIMD &t2)
		:m1(t1.m1), m2(t1.m2), m3(t1.m3), m4(t1.m4), m5(t1.m5), v(t2) {};

	// Copy constructor
	MMMMMv::MMMMMv(const MMMMMv &MMMMMv) : m1(MMMMMv.m1), m2(MMMMMv.m2),
		m3(MMMMMv.m3), m4(MMMMMv.m4), m5(MMMMMv.m5), v(MMMMMv.v) {};

	inline operator Vect4D_SIMD()
	{
		Vect4D_SIMD tmp1 = Vect4D_SIMD(m5.v0.realDot(v),
			m5.v1.realDot(v), m5.v2.realDot(v), m5.v3.realDot(v));

		Vect4D_SIMD tmp2 = Vect4D_SIMD(m4.v0.realDot(tmp1),
			m4.v1.realDot(tmp1), m4.v2.realDot(tmp1), m4.v3.realDot(tmp1));

		Vect4D_SIMD tmp3 = Vect4D_SIMD(m3.v0.realDot(tmp2),
			m3.v1.realDot(tmp2), m3.v2.realDot(tmp2), m3.v3.realDot(tmp2));

		Vect4D_SIMD tmp4 = Vect4D_SIMD(m2.v0.realDot(tmp3),
			m2.v1.realDot(tmp3), m2.v2.realDot(tmp3), m2.v3.realDot(tmp3));

		Vect4D_SIMD tmp5 = Vect4D_SIMD(m1.v0.realDot(tmp4),
			m1.v1.realDot(tmp4), m1.v2.realDot(tmp4), m1.v3.realDot(tmp4));
		
		return tmp5;

	}

	MMMMMv& operator=(const MMMMMv &c) = delete;
	MMMMMv& operator>>(const MMMMMv &c) = delete;
	MMMMMv& operator<<(const MMMMMv &c) = delete;
};

inline MMMMMv operator * (const MMMMM &a1, const Vect4D_SIMD &a2)
{
	return MMMMMv(a1, a2);
}


//class vM
//{
//public:
//	const Matrix_SIMD &m1;
//	const Vect4D_SIMD &v;

//	// Constructor
//	vM(const Matrix_SIMD &t1, const Vect4D_SIMD &t2)
//		:m1(t1), v(t2) {};

//	// Copy constructor
//	vM::vM(const vM &vm) : m1(vm.m1), v(vm.v) {};

//	operator Vect4D_SIMD()
//	{
//		Vect4D_SIMD xvect = Vect4D_SIMD(_mm_mul_ps(m1.v0._m, _mm_set_ps1(v.x)));
//		Vect4D_SIMD yvect = Vect4D_SIMD(_mm_mul_ps(m1.v1._m, _mm_set_ps1(v.y)));
//		Vect4D_SIMD zvect = Vect4D_SIMD(_mm_mul_ps(m1.v2._m, _mm_set_ps1(v.z)));
//		Vect4D_SIMD wvect = Vect4D_SIMD(_mm_mul_ps(m1.v3._m, _mm_set_ps1(v.w)));

//		Vect4D_SIMD tmp = _mm_add_ps(xvect._m, yvect._m);
//		Vect4D_SIMD tmp2 = _mm_add_ps(tmp._m, zvect._m);
//		return _mm_add_ps(tmp2._m, wvect._m);
//	}

//	vM& vM::operator=(const vM &c) = delete;
//	vM& vM::operator>>(const vM &c) = delete;
//	vM& vM::operator<<(const vM &c) = delete;
//};

// inline vM operator * (const Matrix_SIMD &a1, const Vect4D_SIMD &a2)
//{
//	return vM(a1, a2);
//}

class Mv
{
public:
	const Matrix_SIMD &m1;
	const Vect4D_SIMD &v;

	// Constructor
	Mv(const Matrix_SIMD &t1, const Vect4D_SIMD &a2)
		:m1(t1), v(a2) {};

	// Copy constructor
	Mv::Mv(const Mv &Mv) : m1(Mv.m1), v(Mv.v) {};

	inline operator Vect4D_SIMD()
	{
		return Vect4D_SIMD(m1.v0.realDot(v), m1.v1.realDot(v), m1.v2.realDot(v), m1.v3.realDot(v));
	}

	Mv& Mv::operator=(const Mv &c) = delete;
	Mv& Mv::operator>>(const Mv &c) = delete;
	Mv& Mv::operator<<(const Mv &c) = delete;
};

inline Mv operator * (const Matrix_SIMD &a1, const Vect4D_SIMD &a2)
{
	return Mv(a1, a2);
}

class vMMMMM
{
public:
	const Vect4D_SIMD &v;
	const Matrix_SIMD &m1;
	const Matrix_SIMD &m2;
	const Matrix_SIMD &m3;
	const Matrix_SIMD &m4;
	const Matrix_SIMD &m5;

	// Constructor
	vMMMMM(const MMMMM &t1, const Vect4D_SIMD &t2)
		: v(t2), m1(t1.m1), m2(t1.m2), m3(t1.m3), m4(t1.m4), m5(t1.m5) {};

	// Copy constructor
	vMMMMM::vMMMMM(const vMMMMM &vMMMMM)
		: v(vMMMMM.v), m1(vMMMMM.m1), m2(vMMMMM.m2), m3(vMMMMM.m3), m4(vMMMMM.m4), m5(vMMMMM.m5) {};

	inline operator Vect4D_SIMD()
	{

		Vect4D_SIMD tmp1 = Vect4D_SIMD(m1.v0.realDot(v), m1.v1.realDot(v), m1.v2.realDot(v), m1.v3.realDot(v));


		return Vect4D_SIMD(tmp1 * m2 * m3 * m4 * m5);
	}

	vMMMMM& vMMMMM::operator=(const vMMMMM &c) = delete;
	vMMMMM& vMMMMM::operator>>(const vMMMMM &c) = delete;
	vMMMMM& vMMMMM::operator<<(const vMMMMM &c) = delete;
};

inline vMMMMM operator * (const Vect4D_SIMD &a2, const MMMMM &a1)
{
	return vMMMMM(a1, a2);
}




#endif

// ---  End of File ---------------
