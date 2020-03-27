#include"iostream"
#include"string"
#include "Header.h"
using namespace std;

int main()
{
    init();
    int a = 0;
    do
    {
    
        cout << "1 - Add new quiz" << endl;
        cout << "2 - show oll exam " << endl;
        cout << "3 - Pass the exam" << endl;
        cout << "0 - exit" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
        {   CLEAR
            cout << "Add new quiz" << endl;
            addquiz();
        }
        break;
        case 2:
        {   CLEAR
            cout << "Show oll exam" << endl;
            list();
        }
        break;
        case 3:
        {   CLEAR
            cout << "Pass the exam " << endl;
            pass();
        }
        case 0:
        {
            break;
        }
        }

    } while (a != 0);


    return 0;
}