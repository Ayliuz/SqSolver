#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SqSo_infinite_roots -1

//************************************
/// Compares double parameter with 0.
///
/// Parameters: [in] double x
///
/// Output: 1 if variable equals to 0 (less than 0.000001),\n
///         0 if variable is bigger than 0.000001
//************************************

int iszero( double* x ){

    if ( fabs( *x )<0.000001 ){

        *x = 0.0;
        return 1;

    }

    return 0;
}

//***********************************************
/// Checks if parameters is NaN or Infinite.
///
/// Parameters: [in] double a,\n
///             [in] double b,\n
///             [in] double c
///
/// Output: 1 if all the parameters are finite,
///         otherwise outputs 0
//************************************************

int CoefCheck( double a, double b, double c ){

    int a_finite = isfinite(a), b_finite = isfinite(b), c_finite = isfinite(c);

    if (!a_finite && !b_finite && !c_finite){

            return 0;

    }

    return 1;
}

//********************************************
/// Solves a square equation a*x^2 + b*x + c = 0
///
/// Parameters: [in] double a,\n [in] double b,\n [in] double c,\n [out] double* x1,\n [out] double* x2
///
/// Output: the number of roots of the equation, returns the roots as x1 and x2
///
//******************************************

int SquareSolver ( double a, double b, double c, double* x1, double* x2 ){

    if ( iszero( &a ) ){

            return Eq_solver( b, c, x1);

    }

    else{

        double d=b*b-4*a*c;

        if ( d>0 ){

            double sqrt_d = sqrt(d);
            *x1 = (-b+sqrt_d)/2/a;
            *x2 = (-b-sqrt_d)/2/a;
            return 2;

        }
        if ( iszero( &d ) ){

            *x1 = -b/2/a;
            return 1;

        }

        if ( d<0 ){

            return 0;

        }

    }
}

//********************************************
/// Solves a linear equation  b*x + c = 0
///
/// Parameters: [in] double b,\n [in] double c,\n [out] double* x1
///
/// Output: the number of roots of the equation, returns the root as x1
///
//******************************************

int Eq_solver( double b, double c, double* x1){

    if( iszero( &b ) ){

        if ( iszero( &c ) ){

            printf(&b,&c);
            return SqSo_infinite_roots;

        }
        else {

            return 0;

        }

    }


    else{

        *x1=-c/b;

    }

            return 1;

}


int main()
{
    printf( "~ Square equation Solver\n" );
    printf( "~         Zuev, 19.08.2018\n\n" );

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0 ;

    printf( "~ Enter equation coefficient a: " );
    scanf( "%lf",&a);

    printf( "~ Enter equation coefficient b: " );
    scanf( "%lf", &b);

    printf( "~ Enter equation coefficient c: " );
    scanf( "%lf", &c);


    int check = CoefCheck( a, b, c);

    if ( !check ){

        printf( "Not suitable coefficients" );
        return 0;

    }

    int Root_amount=SquareSolver( a, b, c, &x1, &x2);

    iszero( &x1 );
    iszero( &x2 );

    printf( "~ Answer: " );
    switch (Root_amount){

        case 0:

            printf( "No roots\n" );
            break;

        case 1:

            printf( "%6f\n", x1);
            break;

        case 2:

            printf( "x1 = %6f\n", x1);
            printf( "\t  x2 = %6f\n", x2);
            break;

        case SqSo_infinite_roots:

            printf( "Any number\n" );
            break;

        default:

            printf( "main(): Error: Amount of roots: %d\n", Root_amount);

    }

    return 0;

}
