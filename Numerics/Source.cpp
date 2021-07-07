#include <iostream>;
using namespace std;
using std::cout;
//#define DEC_TO_BIN
#define DEC_TO_HEX


void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef DEC_TO_BIN
	//dec - deimal - десятичная система счисления
//bin - binary - двоичная система счисления
	const int n = sizeof(unsigned long long int) * 8; //максимальная разрядность двоичного числа (8*8 байта = 64 бита)
	bool bin[n] = {}; //этот массив будет хранить разряды двоичного числа
	cout << "Двоичное число будет занимать " << sizeof(bin) << " байт памяти" << endl;//64 байта, 1 бит занимает 1 байт
	unsigned long long int decimal;
	cout << "Введите десятичное число: "; cin >> decimal;
	int i = 0;
	/*while (decimal)
	{
		bin[i] = decimal % 2;
		decimal /= 2;
		i++;

	}*/

	for (; decimal; decimal /= 2, i++) bin[i] = decimal % 2;//, - comma operator позволяет в то место, где ожидается 1 выр-е, поместить несколько
	//выводим остатки от деления в обратном порядке
	for (--i; i >= 0; i--) //убираем лишний 0 впереди, выводим только необходимое количество разрядов
	{
		cout << bin[i];
		if (i % 8 == 0) cout << "  ";
		if (i % 4 == 0) cout << "  ";
	}

	cout << endl;
#endif // DEC_TO_BIN


#ifdef DEC_TO_HEX
	const int m = sizeof(unsigned long long int) * 8;
	int hex[m] = {};
	cout << "Шестнадцатиричное число будет занимать " << sizeof(hex) << " байт памяти" << endl;
	unsigned long long int decimal_2;
	cout << "Введите десятичное число: "; cin >> decimal_2;
	int j = 0;
	for (; decimal_2; decimal_2 /= 16, j++) hex[j] = decimal_2 % 16;
	for (--j; j >= 0; j--)
	{
		if (hex[j] < 10) cout << hex[j];
		else switch (hex[j])
		{
		case 10: cout << 'A'; break;
		case 11: cout << 'B'; break;
		case 12: cout << 'C'; break;
		case 13: cout << 'D'; break;
		case 14: cout << 'E'; break;
		case 15: cout << 'F'; break;
		
		}

		if (j % 8 == 0)cout << "  ";
		if (j % 4 == 0) cout << "  ";

	}
#endif // DEC_TO_HEX




}

