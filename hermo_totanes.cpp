#include<iostream>

using namespace std;

float f(float x);
void BisectionMethod();
void SecantMethod();
void FalsePositionMethod();
bool divisionByZero(float f0, float f1);
float getLeftEndpoint();
float getRightEndpoint();
int getIterations();
bool isLeftGreaterThanRight(float leftEndpoint, float rightEndpoint);

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
    cout << endl;

    switch (tolower(choice))
    {
    case 'a':
        // Bisection
        BisectionMethod();
        break;
    case 'b':
        // Secant
        SecantMethod();
        break;
    case 'c':
        // False Position
        FalsePositionMethod();
        break;
    default:
        cout << "Invalid entry." << endl << endl;
        break;
    }
    
    return 0;
}

float f(float x){
    return x*x - 1;
}

void BisectionMethod(){
    int i;
    float mid, p;
    float f1, f2;
    float leftEndpoint = getLeftEndpoint();
    float rightEndpoint = getRightEndpoint();
    int iterations;

    if (isLeftGreaterThanRight(leftEndpoint, rightEndpoint))
    {
        cout << "Invalid Entry. Left endpoint must be greater than right endpoint.";
        return;
    }

    iterations = getIterations();
    

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

void SecantMethod(){
    int i;
    float p2;
    float f0, f1;
    float leftEndpoint = getLeftEndpoint();
    float rightEndpoint = getRightEndpoint();
    int iterations;

    if (isLeftGreaterThanRight(leftEndpoint, rightEndpoint))
    {
        cout << "Invalid Entry. Left endpoint must be greater than right endpoint.";
        return;
    }

    iterations = getIterations();

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

void FalsePositionMethod(){
    int i;
    float p2;
    float leftEndpoint = getLeftEndpoint();
    float rightEndpoint = getRightEndpoint();
    int iterations;
    float fA, fB; // fA: function value of leftEndpoint; fB: function value of rightEndpoint
    
    if (isLeftGreaterThanRight(leftEndpoint, rightEndpoint))
    {
        cout << "Invalid Entry. Left endpoint must be greater than right endpoint.";
        return;
    }

    iterations = getIterations();

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

float getLeftEndpoint(){
    float leftEndpoint;
    cout << "Enter left interval endpoint: ";
    cin >> leftEndpoint;
    return leftEndpoint;
}

float getRightEndpoint(){
    float rightEndpoint;
    cout << "Enter right interval endpoint: ";
    cin >>  rightEndpoint;
    return rightEndpoint;
}

bool isLeftGreaterThanRight(float leftEndpoint, float rightEndpoint){
    if (leftEndpoint > rightEndpoint)
    {
        return true;
    }
    return false;
}

int getIterations(){
    int iterations;
    cout << "Enter maximum number of iterations: ";
    cin >> iterations;
    cout << endl;
    return iterations;
}