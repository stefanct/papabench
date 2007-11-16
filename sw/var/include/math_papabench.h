#ifndef MATH_PAPABENCH_H
#define MATH_PAPABENCH_H 

#define M_PI 3.141592653589793238462643
#define HALFPI 1.57079632679489661923
#define sin(x)		(pp_sin(x))
#define atan2(x,y)	(pp_atan2(x,y))
#define sqrt(x)		(pp_sqrt(x))
#define cos(x)		(pp_sin(x+HALFPI)) 	/*cosinus [radians]*/
#define fabs(x)		(pp_fabs(x))
#define pp_fabs(x)	((x)< 0. ? -(x) : (x)) 	/*floating absolute value*/
#define Max(x,y)	(pp_Max(x,y))
#define pp_Max(x,y)	((x) >= (y) ? (x) : (y))
#define Min(x,y)	(pp_Min(x,y))
#define pp_Min(x,y)	((x) <= (y) ? (x) : (y))

//#define tan(x)		(sin(x)/cos(x)) 	/*tang[radians]*/
//#define abs(x)		((x)<0 ? -(x) : (x)) 	/*Integer absolute value*/
//#define ln(x) 		(log(x)) 		/*Natural log*/
//#define mod(x,y)	((x)%(y))		/* Integer modulo */
//#define mod(x,y)	((x)%(y))		/* Integer modulo */
extern double pp_sin(double x);
extern double pp_sqrt(double x);
extern double pp_atan2(double x, double y);
/*static double pow(double y, double x)
{
	typedef union {
		double d;
		unsigned u[4];
	} DBL;
	double z, w, p, p2, q, re;
	int iz;
	DBL *yp, *zp, *wp;

	yp = (DBL *)&y;
	if (yp->d <= 0.0) y = -y;
	z = 0.0;
	zp = (DBL *)&z;
	zp->u[3] = yp->u[3] & ~0100017; // save exponens 
	iz = (zp->u[3] >> 4)-1023;
	if ((yp->d - zp->d) == 0.0)
		z = (double)iz;
	else {
		yp->u[3] -= ++iz << 4; // arrange for range 0.5 to 0.99999999999 
		yp->d *= 1.4142135623730950488;  // shift for 1/sqrt(2) to sqrt(2) 
		p = (yp->d - 1.0) / (yp->d + 1.0);
		p2 = p * p;
		z = p  * (2.000000000046727 +	// Polynomial approximation 
		    p2 * (0.666666635059382 +	// from: COMPUTER APPROXIMATIONS
		    p2 * (0.4000059794795   +	// Hart, J.F. et al. 1968 
		    p2 * (0.28525381498     +
		    p2 *  0.2376245609 ))));
		z = z * 1.442695040888634 + (double)iz	- 0.5;
	}
	z *= x;
	w = 0.0;
	wp = (DBL *)&w;
	if(zp->d > 1023.0 || zp->d < -1023.0) return (1E307);
	iz = (int) zp->d;
	wp->u[3] += (iz + 1023) << 4;
	wp->u[3] &= ~0100017;
	if ((zp->d -= (double) iz) == 0.0) return(wp->d);
	while (zp->d < 0.0) {
	      wp->u[3] -= 1 << 4;
	      wp->u[3] &= ~0100017;
	      zp->d++;
	}
	if (zp->d >= 0.5) {  // adjust to range 0-0.5 
		zp->d -= 0.5;
		re = 1.41421356237309504880;
	}
	else re = 1.0;
	p2 = zp->d * zp->d;
	p = zp->d * (7.2152891511493 +
	       p2 *  0.0576900723731);
	q =	    20.8189237930062 +
	       p2 ;
	zp->d = re * wp->d * (q + p) / (q - p);
	return(zp->d);
}*/


/*static  double log(double x)
{
	typedef union {
		double d;
		unsigned u[4];
	} DBL;
	double y, z, z2;
	int ix;
	DBL *xp, *yp;

	xp = (DBL *)&x;
	if (xp->d <= 0.0) return(y);
	y = 0.0;
	yp = (DBL *)&y;
	yp->u[3] = xp->u[3] & ~0100017; // save exponens 
	ix = (yp->u[3] >> 4)-1023;
	if ((xp->d - yp->d) == 0.0) return( .693147180559945 * (double)ix);
	xp->u[3] -= ++ix << 4; // arrange for range 0.5 to 0.99999999999 
	xp->d *= 1.4142135623730950488;  // shift for 1/sqrt(2) to sqrt(2) 
	z = (xp->d - 1.0) / (xp->d + 1.0);
	z2 = z * z;
	y = z  * (2.000000000046727 +	// Polynomial approximation
	    z2 * (0.666666635059382 +	// from: COMPUTER APPROXIMATIONS
	    z2 * (0.4000059794795   +	// Hart, J.F. et al. 1968 
	    z2 * (0.28525381498     +
	    z2 *  0.2376245609 ))));
	y = y + .693147180559945 * ((double)ix	- 0.5);
	return(yp->d);
}*/

/* EXP.C
 * Calculates exponens of x to base e
 * Range: +/- exp(88)
 * Precision: +/- .000,000,000,1
 */
/*static  double exp(double xi)
 {
	double y, ex, px, nn, ds;

	if (xi > 88.0) return(1.7014117331926443e38);
	if (xi < -88.0) return(0.0);
	ex = 1.0;
	while( xi > 1.0) {
		ex *= 2.718281828459; // const. e 
		xi--;
	}
	while( xi < -1.0) {
		ex *= .367879441171;  // 1/e 
		xi++;
	}
// Slow, but more precise Taylor expansion series 
	y = ds = 1.0; nn = 0.0;
	while ((ds < 0.0 ? -ds : ds) > 0.000000000001) {
		px = xi/++nn;	      // above precision required
		ds *= px;
		y += ds;
	}
       y *= ex;
       return(y);
}*/

/* ATAN.C
 * Calculates arctan(x)
 * Range: -infinite <= x <= infinite (Output -pi/2 to +pi/2)
 * Precision: +/- .000,000,04
 * Header: math.h
 * Author: Max R. D^Arsteler 9/15/83
 */

/*static  double atan(double x)
{
	double xi, q, q2, y;

	xi = (x < 0. ? -x : x);
	q = (xi - 1.0) / (xi + 1.0); q2 = q * q;
	y = ((((((( - .0040540580 * q2
		     + .0218612286) * q2
		     - .0559098861) * q2
		     + .0964200441) * q2
		     - .1390853351) * q2
		     + .1994653599) * q2
		     - .3332985605) * q2
		     + .9999993329) * q + 0.785398163397;
	return(x < 0. ? -y: y);
}*/

#endif MATH_PAPABENCH_H
