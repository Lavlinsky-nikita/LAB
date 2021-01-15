#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main()
{
	//для корректного отображения кириллицы
	setlocale(0, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	map<string, int> all_words; //словарь [слово, кол-во слов]

	char text[1000];
	cin.getline(text, sizeof(text)); // получили весь текст из консоли

	char seps[] = " ,\t\n"; // разделители, по которым весь текст делится на слова
	char* remained_text = NULL; // весь текст кроме текущего слова
	char* cur_word = strtok_s(text, seps, &remained_text); // по разделителям делим текст на массив слов. Первое слово возвращаем, остаток текста записывается в remained_text

	int words_count = 0; // всего слов
	while (cur_word != NULL) // пока есть слово
	{
		all_words[cur_word]++; // по ключу, равному текущему слову, увеличиваем кол-во этих слов на 1
		words_count++;

		cur_word = strtok_s(NULL, seps, &remained_text); // берем следующее слово из текста
	}
	cout << "\n\n";

	for (auto& word : all_words)
	{
		cout << word.second << "  " << word.first << " (" << setprecision(2) << (double)word.second / words_count * 100 << "%)" << endl;
	}
}
