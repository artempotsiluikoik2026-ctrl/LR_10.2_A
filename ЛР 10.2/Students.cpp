// Students.cpp 
#include <iostream>
#include <iomanip>
#include <string>
#include "Students.h"
using namespace std;

void Create(Student* p, const int N)
{
    int specialty;
    for (int i = 0; i < N; i++)
    {
        cout << "Student No " << i + 1 << ":" << endl;
        cin.get(); 
        cin.sync();

        cout << " surname: "; getline(cin, p[i].surname);
        do {
            cout << " course (1-6): "; cin >> p[i].course;
        } while (p[i].course < 1 || p[i].course > 6);
        do {
            cout << " specialty (0 - Computer Science, 1 - Informatics," << endl;
            cout << "   2 - Labor Training, 3 - Math and Economics," << endl;
            cout << "   4 - Physics and Informatics): ";
            cin >> specialty;
        } while (specialty < 0 || specialty > 4);
        p[i].specialty = (Specialty)specialty;
        do {
            cout << " Physics grade (1-5): "; cin >> p[i].physics;
        } while (p[i].physics < 1 || p[i].physics > 5);
        do {
            cout << " Maths grade (1-5): "; cin >> p[i].math;
        } while (p[i].math < 1 || p[i].math > 5);
        do {
            cout << " Informatics grade (1-5): "; cin >> p[i].informatics;
        } while (p[i].informatics < 1 || p[i].informatics > 5);
        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    string specialtyStr[] = { "Computer Science", "Informatics", "Labor Training", "Math and Economics",
                         "Physics and Informatics" };

    cout << "========================================================================================="
        << endl;
    cout << "| Student list                                                                          |"
        << endl;
    cout << "-----------------------------------------------------------------------------------------"
        << endl;
    cout << "| No  | Surname      | Course | Specialty               | Physics | Maths | Informatics |"
        << endl;
    cout << "-----------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(12) << left << p[i].surname << " "
            << "| " << setw(6) << right << p[i].course << " "
            << "| " << setw(23) << left << specialtyStr[p[i].specialty] << " "
            << "| " << setw(7) << right << p[i].physics << " "
            << "| " << setw(5) << right << p[i].math << " "
            << "| " << setw(11) << right << p[i].informatics << " |" << endl;
    }
    cout << "========================================================================================="
        << endl;
    cout << endl;
}

void Sort(Student* p, const int N)
{
    Student t;
    for (int i0 = 0; i0 < N - 1; i0++) 
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if ((p[i1].physics > p[i1 + 1].physics)
                ||
                (p[i1].physics == p[i1 + 1].physics &&
                    p[i1].specialty > p[i1 + 1].specialty)
                ||
                (p[i1].physics == p[i1 + 1].physics &&
                    p[i1].specialty == p[i1 + 1].specialty &&
                    p[i1].surname > p[i1 + 1].surname))
            {
                t = p[i1];
                p[i1] = p[i1 + 1];
                p[i1 + 1] = t;
            }
}

int* IndexSort(Student* p, const int N)
{ 
    int* I = new int[N]; 
    for (int i = 0; i < N; i++)
        I[i] = i; 

    int i, j, value; 
    for (i = 1; i < N; i++)
    {
        value = I[i];
        for (j = i - 1;
            j >= 0 && ((p[I[j]].physics > p[value].physics) ||
                (p[I[j]].physics == p[value].physics &&
                    p[I[j]].specialty > p[value].specialty) ||
                (p[I[j]].physics == p[value].physics &&
                    p[I[j]].specialty == p[value].specialty &&
                    p[I[j]].surname > p[value].surname));
            j--)
        {
            I[j + 1] = I[j];
        }
        I[j + 1] = value;
    }
    return I;
}

void PrintIndexSorted(Student* p, int* I, const int N)
{ 
    string specialtyStr[] = { "Computer Science", "Informatics", "Labor Training", "Math and Economics",
                         "Physics and Informatics" };

    cout << "========================================================================================="
        << endl;
    cout << "| Student list (index sorted)                                                           |"
        << endl;
    cout << "-----------------------------------------------------------------------------------------"
        << endl;
    cout << "| No  | Surname      | Course | Specialty               | Physics | Maths | Informatics |"
        << endl;
    cout << "-----------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(12) << left << p[I[i]].surname << " "
            << "| " << setw(6) << right << p[I[i]].course << " "
            << "| " << setw(23) << left << specialtyStr[p[I[i]].specialty] << " "
            << "| " << setw(7) << right << p[I[i]].physics << " "
            << "| " << setw(5) << right << p[I[i]].math << " "
            << "| " << setw(11) << right << p[I[i]].informatics << " |" << endl;
    }
    cout << "========================================================================================="
        << endl;
    cout << endl;
}

int BinSearch(Student* p, const int N, const string surname, const Specialty specialty, const int physics)
{
    int L = 0, R = N - 1, m;
    do {
        m = (L + R) / 2;
        if (p[m].surname == surname && p[m].specialty == specialty && p[m].physics == physics)
            return m;
        if ((p[m].physics < physics)
            ||
            (p[m].physics == physics &&
                p[m].specialty < specialty)
            ||
            (p[m].physics == physics &&
                p[m].specialty == specialty &&
                p[m].surname < surname))
        {
            L = m + 1;
        }
        else
        {
            R = m - 1;
        }
    } while (L <= R);
    return -1;
}