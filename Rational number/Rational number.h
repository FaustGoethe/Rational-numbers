#pragma once
#ifndef _RATIONAL_NUMBERS_H
#define _RATIONAL_NUMBERS_H
#include <iostream>

namespace RATIONAL_NUMBERS
{
	template<typename T>
	class RatNum
	{
	private:
		T numerator;
		T denominator;

		RatNum& Reduction() {
			T nod = NOD(numerator, denominator);
			numerator /= nod;
			denominator /= nod;

			return *this;
		}

		T NOD(T lhs, T rhs) const {
			int a = lhs;
			int b = rhs;

			if (a < 0) {
				a *= -1;
			}
			while (b){
				a %= b;
				std::swap(a, b);
			}
			return a;
		} 
		T NOK(T lhs, T rhs) const {
			return lhs*rhs / NOD(lhs, rhs);
		}
	public:
		RatNum();
		RatNum(T, T);
		RatNum(const RatNum&);

		RatNum operator+(const RatNum& vv) const;
		RatNum operator-(const RatNum& vv) const;
		RatNum operator*(const RatNum& vv) const;
		RatNum operator/(const RatNum& vv) const;
		RatNum& operator=(const RatNum& vv);

		operator double() const;
		operator int() const;

		inline T get_numerator() const {
			return numerator;
		}
		inline T get_denominator() const {
			return denominator;
		}

		template<typename T> friend std::ostream& operator<<(std::ostream& os, const RatNum<T>& vv) {
			os << vv.numerator << "/" << vv.denominator;
			return os;
		}
	};
}
namespace RatNum = RATIONAL_NUMBERS;
#include "Rational number.cpp"
#endif