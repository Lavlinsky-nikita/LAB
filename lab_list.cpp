#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <list>

using namespace std;

class student
{
public:

	student(string gr, string ln)
	{
		group = gr;
		last_name = ln;
	}

	string group;
	string last_name;


	/*friend istream& operator >> (istream& is, student& st)
	{
		is >> st.group >> st.last_name;

		return is;
	}*/// Если нужен будет ввод с клавиатуры, то этот метод позволит сделать так: cin >> student;

	friend ostream& operator << (ostream& os, student& st)
	{
		os << st.group << " " << st.last_name;

		return os;
	}
};

int main()
{
	int n = 20;

	srand(time(0));
	setlocale(0, "Rus");

	list<student> students;
	vector<string> keys; // доп. вектор для уже выведенных групп

	string names[] = { "Боря", "Дима", "Коля", "Гена", "Лена", "Леша" };
	int length = sizeof(names) / sizeof(names[0]);


	for (int i = 0; i < n; i++)
	{
		students.push_back(student("201-32" + to_string(rand() % 5), names[rand() % length] + "(" + to_string(i + 1) + ")"));

		cout << students.back() << endl;
	}
	cout << "\n\n";
	for (auto& i : students)
	{
		string key = i.group; // берем название группы
		bool b = false; // нужно для более корректного переноса строки

		for (auto& st : students)
		{
			//если эта группа еще не выводилась и группа текущего студента равна ключу
			if (find(keys.begin(), keys.end(), key) == keys.end() && st.group == key)
			{
				cout << st << endl;
				b = true;
			}
		}
		keys.push_back(key); //добавляем группу в вектор, чтобы больше не выводить людей с этой группы

		if (b) cout << endl;
	}
}