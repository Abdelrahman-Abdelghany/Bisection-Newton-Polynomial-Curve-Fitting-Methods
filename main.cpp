#include<bits/stdc++.h>

using namespace std;

#define BISECTION 0.001 //We use it to correct error percentages after the decimal point

// the function
double f(double x) {
    float a = exp(x) - 3 * x * x;
    return a;
}

// first Dirv
double fprime(double x)
{
    float b = exp(x) - 6 * x;
    return b;
}

float newton_method(float x1 ,float e)
{
    float x, fx, fx1;
    int n = 0;
    cout.precision(4);
    cout.setf(ios::fixed);
    x = x1;
    fx = f(x);
    // Calculate the First Derivative ( f'(x) )
    fx1 = fprime(x);
    // Print the table
    cout << "n" << setw(11) << "x{n}" << setw(11) << "f(x)" << setw(11) << "f'(x)" << setw(11) << "x{n + 1}" << endl;

    do
    {
        x = x1;                /*make x equal to the last calculated value of x1*/
        fx = f(x);            //simplifying f(x)to fx
        fx1 = fprime(x);            //simplifying fprime(x) to fx1
        x1= x - (fx / fx1);            /*calculate x{1} from x, fx and fx1*/
        cout << n << setw(11) << x << setw(11) << fx << setw(11) << fx1 << setw(11) << x1 << endl;
        n++;
    } while (abs(x1 - x) >= e);
    cout << endl << "The root of the equation is: " << x1 << endl;
}

float function_of_equation(float x)
{
    //example is f(x)=x^3+4x^2-10 ; in [1,2]
    float z;
    z=(x*x*x)+((4*x*x)-10);
    return z;
}

void bisection_method(double a,double b)
{
    if (function_of_equation(a)*function_of_equation(b)>=0)
    {
        cout << "You have not enter the right values";
        return;
    }

    double c=a;
    while ((b-a)>=BISECTION)
    {
        c = (a+b)/2;
        if (function_of_equation(c)==0.0)
        {
            return;
        }
        else if (function_of_equation(c)*function_of_equation(a) < 0)
        {
            b=c;
        }
        else
        {
            a=c;
        }

    }
    cout <<"The value of root is : "<<c;
}


//Example to Test
/*
   n = 5 ;
   |-|--------------------------------------------------------------------------|
   |X| 1  2  3  4  5                                                            |
   |Y| 7.1  27.8  62.1  110  161                                                |
   |-|--------------------------------------------------------------------------|
   the Result a = 16411 and b = 95308
*/
int polynomial_curve_fitting(int numberOfPoints)
{
    int i;
    float xElements[numberOfPoints], yElements[numberOfPoints], sumX=0, sumOfXPower2=0, sumY=0, sumXY=0, a, b, A;

    for(i=1;i<=numberOfPoints;i++) // take the value of points
    {
        cout << "x"<<i<<"=";
        cin >> xElements[i];
        cout<<"\n";
        cout << "\ty"<< i <<"=";
        cin >> yElements[i];
        cout<<"\n";
    }


    for(i=1;i<=numberOfPoints;i++) //Summation of Numbers
    {
        sumX = sumX + log(xElements[i]) ; // Summation of X
        sumOfXPower2 = sumOfXPower2 + log(xElements[i])*log(xElements[i]); //Summation of X^2
        sumY = sumY + log(yElements[i]); //Summation of Y
        sumXY = sumXY + log(xElements[i])*log(yElements[i]); //Summation of XY
    }

    // Calculating A and b from two equation
    b = (numberOfPoints*sumXY-sumX*sumY)/(numberOfPoints*sumOfXPower2-sumX*sumX);
    A = (sumY - b*sumX)/numberOfPoints;

    // Transformation of A to a by : A = Ln(a)
    a = exp(A);

    /// Displaying The Result of a and b
    cout << "The Result : a = " << a << " and b = " << b;
}

int main()
{
    int x,a,b;
    cout<<"If you want newton method press 1 \n";
    cout<<"If you want bisection method press 2 \n";
    cout<<"If you want polynomial curve fitting press 3 \n";
    cin>>x;
    if(x==1)
    {
        cout<<"Enter range values : \n";
        cin>>a>>b;
        newton_method(a,b);
    }
    if(x==2)
    {
        cout<<"Enter range values for equation f(x)=x^3+4x^2-10 :\n";
        cin>>a>>b;
        bisection_method(a,b);
    }
    if(x==3)
    {
        cout<<"Enter number of points : \n";
        cin>>a;
        polynomial_curve_fitting(a);
    }

    return 0;
}

