#ifndef LAB5_1_COMPLEX_H
#define LAB5_1_COMPLEX_H
#define _USE_MATH_DEFINES
#include <math.h>

class Complex {

	double r;
	double phi;
public:
	Complex()
	{
		r = 0.0;
		phi = 0.0;
	}
	Complex(double rc, double phic)
	{
		r = rc;
		phi = phic;
	}
	static Complex convertToMod(double re, double im)
	{
		double rRes, phiRes;
		rRes = sqrt(pow(re, 2) + pow(im, 2));
		phiRes = atan2(im, re);
		return Complex(rRes, phiRes);
	}
	Complex operator+(Complex a) const {
		double real, imag;
		real = Re() + a.Re();
		imag = Im() + a.Im();
		return convertToMod(real, imag);
	}
	Complex operator-(Complex a) {
		double real, imag;
		real = Re() - a.Re();
		imag = Im() - a.Im();
		return convertToMod(real, imag);
	}
	Complex operator/(Complex a) {
		double real, imag;
		real = (Re()*a.Re() + Im()*a.Im()) / (pow(a.Re(), 2) + pow(a.Im(), 2));
		imag = (Im()*a.Re() - Re()*a.Im()) / (pow(a.Re(), 2) + pow(a.Im(), 2));
		return convertToMod(real, imag);
	}
	Complex operator*(Complex a) const {
		double real, imag;
		real = Re() * a.Re() - Im() * a.Im();
		imag = Im() * a.Re() + Re() * a.Im();
		return convertToMod(real, imag);
	}
	double Re() const {
		return r * cos(phi);
	}
	double Im() const {
		return r * sin(phi);
	}
	double getR() const {
		return r;
	}
	double getPhi() const {
		return phi;
	}
	static Complex epow(const Complex &z)
	{
		double real, imag;
		double expR, expI;
		real = z.Re();
		imag = z.Im();
		expR = exp(real)*cos(imag);
		expI = exp(real)*sin(imag);
		return convertToMod(expR, expI);
	}
	static Complex sinComplex(const Complex &z) {
		Complex i = Complex(1, M_PI_2);
		Complex negI = convertToMod(0, -1);
		Complex mult = Complex(2, 0);
		return (epow(i*z) - epow(negI*z)) / (mult*i);

	}
	static Complex y(const Complex &z) {
		// i = Complex(1,3.141592653589793/2)
		Complex i = Complex(1.0, M_PI_2);
		Complex unit = Complex(-1.0, 0);

		//return (i - z * sinComplex(z + z));
		return ((z + z) + sinComplex(z + (unit*i)));
	}
};

#endif //LAB5_1_COMPLEX_H
