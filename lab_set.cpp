#include <iostream>
#include <string>
#include <unordered_set>
#include <ctime>

using namespace std;

class pupil
{
public:

	pupil(string s, int m)
	{
		account = s;
		mark = m;
	}

	string account;
	int mark;

	friend ostream& operator << (ostream& os, pupil p)
	{
		os << p.account << ": " << p.mark;

		return os;
	}

	//перегрузка оператора == для корректного сравнения двух Pupil
	bool operator == (const pupil& p) const
	{
		return p.account == account;
	}
};

// структура для собственного хэша. Одинаковые аккаунты будут давать одинаковый хэш => множество сданных тестов с одного аккаунта не будут засчитаны, только 1ый тест
struct pupil_hash
{
	size_t operator()(const pupil& v) const
	{
		return hash<string>{}(v.account); // возвращает хэш на основе строки. Используется стандартная функция hash
	}
};

int main()
{
	// указываем тип, который будет храниться в set и структуру pupil_hash, которая будет использоваться для сравнения объектов
	unordered_set<pupil, pupil_hash> pupils;

	srand(time(0));

	int n = 10;

	cout << "All pupils attempts:\n\n";
	for (int i = 0; i < n; i++)
	{
		pupil p("account " + to_string(1 + rand() % 10), rand() % 101);

		cout << p << endl;

		pupils.insert(p);
	}
	cout << "\nAccepted attempts:\n";
	for (auto& i : pupils) cout << i << endl;

	return 0;
}
