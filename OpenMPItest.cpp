// OpenMPItest.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

// 51 задание, OpenMP, /10 баллов

#include <iostream>
#include <omp.h>
#include <cmath>
using namespace std;

int main(int argc, char const* argv[])
{
    long long target_sum = 1000;
    long long int N = 1000;
    //double tbegin = omp_get_wtime();
    #pragma omp parallel shared(N, target_sum)
    {
    #pragma omp for
        for (long long int x = -N; x < N; x++)
        {
            for (long long int y = -N; y < N; y++)
            {
                for (long long int z = -N; z < N; z++)
                {
                    if ((x * x) + (y * y * y) + (z * z * z * z) == target_sum)
                        //if (pow(x, 2) + pow(y,3) + pow(z,4) == target_sum)
                    {
                        printf("%lld^2+%lld^3+%lld^4=%lld\n", x, y, z, target_sum);
                    }
                }
            }
        }
    }
    //double tend = omp_get_wtime();
    //cout << "parallel " << tend - tbegin << "\n";
    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
