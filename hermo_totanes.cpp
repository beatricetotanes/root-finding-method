#include<iostream>

using namespace std;

float f(float x);
void BisectionMethod(float leftEndpoint, float rightEndpoint, int iterations);
void SecantMethod(float leftEndpoint, float rightEndpoint, int iterations);
void FalsePositionMethod(float leftEndpoint, float rightEndpoint, int iterations);
bool divisionByZero(float f0, float f1);

int main(){
    char choice;
    float leftEndpoint;
    float rightEndpoint;
    int iterations;

    
    cout << "Choose which root finding method to use. Select the appropriate letter." << endl;
    cout << "a) Bisection Method" << endl;
    cout << "b) Secant Method" << endl;
    cout << "c) False Position Method" << endl;
    cout << "Choice: ";
    cin >> choice;
    cout << "Enter left interval endpoint: ";
    cin >> leftEndpoint;
    cout << "Enter right interval endpoint: ";
    cin >> rightEndpoint;
    cout << "Enter maximum number of iterations: ";
    cin >> iterations;

    switch (tolower(choice))
    {
    case 'a':
        // Bisection
        BisectionMethod(leftEndpoint, rightEndpoint, iterations);
        break;
    case 'b':
        // Secant
        SecantMethod(leftEndpoint, rightEndpoint, iterations);
        break;
    case 'c':
        // False Position
        FalsePositionMethod(leftEndpoint, rightEndpoint, iterations);
        break;
    default:
        break;
    }
    
    return 0;
}

float f(float x){
    return x*x - 1;
}

void BisectionMethod(float leftEndpoint, float rightEndpoint, int iterations){
    int i;
    float mid, p;
    float f1, f2;

    for (i = 0; i < iterations; i++)
    {
        mid = (leftEndpoint + rightEndpoint) / 2;
        p = mid;
        cout << "Iteration: " << i << " Approx: " << p << endl;
        f1 = f(p);
        f2 = f(leftEndpoint);

        if (f1 * f2 > 0)
        {
            leftEndpoint = p;
        } else {
            rightEndpoint = p;
        }

        cout << "New interval is [" << leftEndpoint << ", " << rightEndpoint << "]" << endl << endl; 
        
    }
}

void SecantMethod(float leftEndpoint, float rightEndpoint, int iterations){
    int i;
    float p2;
    float f0, f1;

    // p0 = leftEndpoint, p1 = rightEndpoint
    for (i = 0; i < iterations; i++)
    {
        f0 = f(leftEndpoint);
        f1 = f(rightEndpoint);
        if (divisionByZero(f0, f1))
        {
            cout << "Cannot proceed. Division by zero. Exiting..." << endl;
            break;
        }
        
        p2 = rightEndpoint - (f1 * (rightEndpoint - leftEndpoint)) / (f1 - f0);
        cout << "Iteration: " << i << " Approx: " << p2 << endl;

        leftEndpoint = rightEndpoint;
        rightEndpoint = p2;

        cout << "New interval is [" << leftEndpoint << ", " << rightEndpoint << "]" << endl << endl; 
    }
    
}

void FalsePositionMethod(float leftEndpoint, float rightEndpoint, int iterations){
    int i;
    float p2;
    float fA, fB; // fA: function value of leftEndpoint; fB: function value of rightEndpoint

    for (i = 0; i < iterations; i++)
    {
        fA = f(leftEndpoint);
        fB = f(rightEndpoint);

        if (divisionByZero(fA, fB))
        {
            cout << "Cannot proceed. Division by zero. Exiting..." << endl;
            break;
        }
    
        p2 = leftEndpoint - ((fA * (rightEndpoint - leftEndpoint)) / (fB - fA));
        cout << "Iteration: " << i << " Approx: " << p2 << endl;

        if (fA * f(p2) < 0)
        {
            rightEndpoint = p2;
        } else {
            leftEndpoint = p2;
        }
        cout << "New interval is [" << leftEndpoint << ", " << rightEndpoint << "]" << endl << endl;
    }
}

bool divisionByZero(float f0, float f1){
    if (f1 - f0 == 0)
    {
        return true;
    } else return false;
}

