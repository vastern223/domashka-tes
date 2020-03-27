#include "Header.h"
#include"iostream"
#include"fstream"
#include"string"
using namespace std;
string fileName = "Quiz.txt";//зміна яка хранить назву нашого файлу
quiz* quize;//основний масив струтури quiz
int coutquize = 0;

void init()
{
	ifstream fin;//відкриваємо потік для зчитування в файл
	fin.open(fileName);// відкриваємо файл
	bool isOpen = fin.is_open(); //створюємо зміну для перевірки чи файл відкрився
	string data1;//зміна в яку буде записуватися інформація з файла 
	int num = 0;// кількість екзаменів
	int currentString = 0; //поточний рядок з файла 
	if (isOpen == false)//перевірка чи файл відкритий
	{
		cout << "Error" << endl;//ошибка якщо файл невідкрився
	}
	else
	{
		while (!fin.eof())//проходися циклом по всьому файлу
		{
			getline(fin, data1);
			num++;//рахує кількість рядків
		}
		coutquize = (num - 1) / 11;//шукаємо кількість екзаменів
	}
	fin.close();//закриваємо файл
	if (coutquize > 0)//перевіряємо чи кількість екзаменів не менша 0
	{
		fin.open(fileName);//відкриваємо файл
		quiz* new1quiz = new quiz[coutquize];//створюємо тимчасовий масив
		bool isOpen1 = fin.is_open();//створюємо зміну для перевірки чи файл відкрився
		if (isOpen1 == false)//перевірка чи файл відкритий
		{
			cout << "Error" << endl;//ошибка якщо файл невідкрився
		}
		else {
			int i = 0;//зміна для запитань та відповідей (масив)
			int k = 0;//зміна для назв екзаменів (масив)
			while (!fin.eof())//проходися циклом по всьому файлу
			{
				currentString++;//зібльшили кількість рядків
				getline(fin, data1);
				for (int j = k; j < coutquize;)//для заповненя всіх екзаменів
				{
					if (currentString == 1)//перевірка яка заре строка
					{
						new1quiz[k].question = new Answer[5];//створюємо масив для підструктури для того щоб заповняти питаня та відповіді
						new1quiz[k].name_quiz = data1;//присвоюємо першу строку з іменем екзамена в екзамен номер 0
						break;
					}
					else if (currentString == 2)
					{
						new1quiz[k].question[i].question1 = data1;
						break;
					}
					else if (currentString == 3)
					{
						new1quiz[k].question[i].ansver1 = data1;
						i++;
						break;
					}
					else if (currentString == 4)
					{
						new1quiz[k].question[i].question1 = data1;
						break;
					}
					else if (currentString == 5)
					{
						new1quiz[k].question[i].ansver1 = data1;
						i++;
						break;
					}
					else if (currentString == 6)
					{
						new1quiz[k].question[i].question1 = data1;
						break;
					}
					else if (currentString == 7)
					{
						new1quiz[k].question[i].ansver1 = data1;

						break;
					}
					else if (currentString == 8)
					{
						new1quiz[k].question[i].question1 = data1;

						break;
					}
					else if (currentString == 9)
					{
						new1quiz[k].question[i].ansver1 = data1;
						i++;
						break;
					}
					else if (currentString == 10)
					{
						new1quiz[k].question[i].question1 = data1;
						break;
					}
					else if (currentString == 11)
					{
						new1quiz[k].question[i].ansver1 = data1;
						currentString = 0;
						i = 0;
						k++;
						break;
					}
				}
			}
		}
		fin.close();//закриваємо файл
		quize = new1quiz; //перепресвоюємо тимчасовий масив в основний 
		delete[] new1quiz;//удаляємо память тимчасового масиву
	}
}



void addquiz()
{
	ofstream fout;
	fout.open(fileName, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true)
	{
		quiz* temp = new quiz[coutquize + 1];
		for (int i = 0; i < coutquize; i++)
		{
			temp[i] = quize[i];
		}
		temp[coutquize].question = new  Answer[5];
	
		cout << "enter name_quiz->";
		cin >> temp[coutquize].name_quiz;
		cout << "enter questions->";
		for (int i = 0; i < 5; i++)
		{
			cout << "enter question->";
			cin >> temp[coutquize].question[i].question1;
			cout << "enter Answer ->";
			cin >> temp[coutquize].question[i].ansver1;
		}


		fout << temp[coutquize].name_quiz << endl;
		for (int i = 0; i < 5; i++)
		{
			fout << temp[coutquize].question[i].question1 << endl;
			fout << temp[coutquize].question[i].ansver1 << endl;
		}
		fout.close();
		coutquize++;
		delete [] quize;
		quize = temp;
		delete[] temp;
	}
	else
	{
		cout << "File not opened" << endl;
	}

}

void list()
{
	for (int i = 0; i < coutquize; i++)
	{
		cout << quize[i].name_quiz << endl;
	}

}

void pass()
{
	cout << "-----------------------------" << endl;
	list();
	string name;//назва екзамену
	string result;//відповідь на запитання
	int countResult = 0;//кількість правильних відповідей
	cout << "Enter name  pass\n";
	cin >> name;
	for (int i = 0; i < coutquize; i++)
	{
		if (quize[i].name_quiz == name)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << "questin" << " - ";
				cout << quize[i].question[j].question1 << endl;
				cout << "answer \n:";
				cin >> result;
				if (result == quize[i].question[j].ansver1)
				{
					countResult++;
				}

			}
			cout << "correct answers : " << countResult << endl;
		}

	}


}