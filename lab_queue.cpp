#include <iostream>
#include <queue>

using namespace std;

void print_and_add(int t, std::queue<int>& q2, std::queue<int>& q3, std::queue<int>& q5)
{
    // 1 нас не устраивает по условию
    if (t != 1)
    {
        std::cout << t << ' ';
    }

    q2.push(t * 2); // добавляем число умноженное на 2
    q3.push(t * 3); // добавляем число умноженное на 3
    q5.push(t * 5); // добавляем число умноженное на 5
}

int main()
{
    std::cout << "Input number:\n";
    int n;
    std::cin >> n;

    std::queue<int> q2; // очередь для чисел содержащие как минимум множитель 2
    std::queue<int> q3; // очередь для чисел содержащие как минимум множитель 3
    std::queue<int> q5; // очередь для чисел содержащие как минимум множитель 5

    // добавляем минимальные числа, содержащие необходимые простые множители
    q2.push(2);
    q3.push(3);
    q5.push(5);

    int k = 0;

    //пока не выведем n необходимых чисел
    while (k != n)
    {
        int x = std::min({ q2.front(), q3.front(), q5.front() }); // выбираем наименьшее число из очередей

        print_and_add(x, q2, q3, q5); // выводим найденное число и добавляем числа, умноженные на 2 3 5 в очередь

        k++;

        // находим и убираем число из очередей т.к оно уже выведено
        if (x == q2.front())
            q2.pop(); 
        if (x == q3.front())
            q3.pop();
        if (x == q5.front())
            q5.pop();
    }

    return 0;
}