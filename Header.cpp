#include "Header.h"
#include"iostream"
#include"fstream"
#include"string"
using namespace std;
string fileName = "Quiz.txt";//���� ��� ������� ����� ������ �����
quiz* quize;//�������� ����� �������� quiz
int coutquize = 0;

void init()
{
	ifstream fin;//��������� ���� ��� ���������� � ����
	fin.open(fileName);// ��������� ����
	bool isOpen = fin.is_open(); //��������� ���� ��� �������� �� ���� ��������
	string data1;//���� � ��� ���� ������������ ���������� � ����� 
	int num = 0;// ������� ��������
	int currentString = 0; //�������� ����� � ����� 
	if (isOpen == false)//�������� �� ���� ��������
	{
		cout << "Error" << endl;//������ ���� ���� ����������
	}
	else
	{
		while (!fin.eof())//��������� ������ �� ������ �����
		{
			getline(fin, data1);
			num++;//���� ������� �����
		}
		coutquize = (num - 1) / 11;//������ ������� ��������
	}
	fin.close();//��������� ����
	if (coutquize > 0)//���������� �� ������� �������� �� ����� 0
	{
		fin.open(fileName);//��������� ����
		quiz* new1quiz = new quiz[coutquize];//��������� ���������� �����
		bool isOpen1 = fin.is_open();//��������� ���� ��� �������� �� ���� ��������
		if (isOpen1 == false)//�������� �� ���� ��������
		{
			cout << "Error" << endl;//������ ���� ���� ����������
		}
		else {
			int i = 0;//���� ��� �������� �� �������� (�����)
			int k = 0;//���� ��� ���� �������� (�����)
			while (!fin.eof())//��������� ������ �� ������ �����
			{
				currentString++;//�������� ������� �����
				getline(fin, data1);
				for (int j = k; j < coutquize;)//��� ��������� ��� ��������
				{
					if (currentString == 1)//�������� ��� ���� ������
					{
						new1quiz[k].question = new Answer[5];//��������� ����� ��� ����������� ��� ���� ��� ��������� ������ �� ������
						new1quiz[k].name_quiz = data1;//���������� ����� ������ � ������ �������� � ������� ����� 0
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
		fin.close();//��������� ����
		quize = new1quiz; //�������������� ���������� ����� � �������� 
		delete[] new1quiz;//�������� ������ ����������� ������
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
	string name;//����� ��������
	string result;//������� �� ���������
	int countResult = 0;//������� ���������� ��������
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