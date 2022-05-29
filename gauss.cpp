#include <iostream>
#include <cmath>
using namespace std;
class Matrix
{
    float **mat;
    int unkown;

public:
    Matrix(int o)
    {
        unkown = o;
        mat = new float *[unkown];
        for (int i = 0; i < unkown; i++)
        {
            mat[i] = new float[unkown + 1];
        }
        for (int i = 0; i < unkown; i++)
        {
            for (int j = 0; j <= unkown; j++)
            {
                if (j == unkown)
                {
                    cout << "Enter constant term for Equation " << i + 1 << " ";
                    cin >> mat[i][j];
                    cout << endl;
                }
                else
                {
                    cout << "Enter Coefficient of x" << j + 1 << " for Equation " << i + 1 << " ";
                    cin >> mat[i][j];
                }
            }
        }
    }
    void Compute()
    {
        int count;
        for (int i = 0; i < unkown; i++)
        {
            if (mat[i][i] == 0)
            {
                cout << "Some error is there" << endl;
                exit(-1);
            }
            float temp1 = mat[i][i];
            for (int j = 0; j <= unkown; j++)
            {
                mat[i][j] = mat[i][j] / temp1;
            }
            for (int k = i + 1; k < unkown; k++)
            {
                float temp2 = mat[k][i];
                for (int j = 0; j <= unkown; j++)
                {
                    mat[k][j] -= ((temp2 * mat[i][j]));
                }
            }
        }
    }
    void backSubstitution(float *a)
    {
        float temp;
        for (int i = unkown - 1; i >= 0; i--)
        {
            temp = a[i] = 0;
            for (int j = unkown - 1; j > i; j--)
            {
                temp += mat[i][j] * a[j];
            }
            a[i] = mat[i][unkown] - temp;
        }
    }
    void display()
    {
        for (int i = 0; i < unkown; i++)
        {
            for (int j = 0; j <= unkown; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < unkown; i++)
        {
            delete mat[i];
        }
        delete[] mat;
    }
};
int main()
{
    int unkown;
    cout << "Enter how many unkown variables ? ";
    cin >> unkown;
    float answers[unkown];
    Matrix m1(unkown);
    m1.Compute();
    m1.backSubstitution(answers);
    cout << endl
         << endl;
    for (int i = 0; i < unkown; i++)
    {
        cout << "variable x" << i + 1 << " is " << answers[i] << endl;
    }
}