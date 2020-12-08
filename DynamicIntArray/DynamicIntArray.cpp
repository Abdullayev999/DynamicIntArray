#include <iostream>
#include<iomanip>

/* Задание 1:
		  Класс IntArray - обертка для динамического массива (int)
		  Реализуйте методы для:
		+ добавления элемента в конец массива
		+ получения доступа к конкретному элементу по заданному индексу
		+ получения количества элементов в массиве
		+ проверки является ли массив пустым
		+ все поля должны быть приватными
		+ заполните массив и распечатайте его данные в main
	*/
class IntArray
{
public:

	IntArray() {
		++m_count;
	}

	IntArray(const int number) {
		++m_count;
		SetElementEnd(number);
	}

	~IntArray() {
		delete[] m_arr;
		--m_count;
	}

	static int getCount() {
		return m_count;
	}

	bool arrayState() {
		if (m_index)
			return true;
		else
			return false;
	}


	int getElement(const int number) {
		return m_arr[number];
	}

	int getSize() {
		return m_index;
	}

	void SetElementStar(int number)
	{
		if (m_index == m_size)capacity();


		if (m_index) {
			int* tmp = new int[m_size];
			tmp[0] = number;

			for (int i = 0, b = 1; i < m_index; b++, i++)
				tmp[b] = m_arr[i];

			m_index++;
			delete[] m_arr;
			m_arr = tmp;
		}
		else {
			m_arr[m_index++] = number;
		}
	}

	void SetElementEnd(const int number)
	{
		if (m_index == m_size)capacity();

		m_arr[m_index++] = number;

	}

private:
	void capacity() {
		m_size += m_capacity;

		int* tmp = new int[m_size];

		for (int i = 0; i < m_index; i++)
			tmp[i] = m_arr[i];

		delete[] m_arr;
		m_arr = tmp;
	}


	size_t  m_size = 5;
	size_t m_index = 0;
	int* m_arr = new int[m_size];
	size_t m_capacity = 5;
	static unsigned int m_count;
};

unsigned int IntArray::m_count = 0;


int main()
{

	IntArray a;

	if (a.arrayState())
	{
		std::cout << "\nArrar # " << a.getCount() << "\n__________________\n                  |\n";
		for (int i = 0; i < a.getSize(); i++)
		{
			std::cout << " arr["
				<< std::right << std::setw(2) << std::setfill(' ') << i << "]  = "
				<< std::right << std::setw(5) << a.getElement(i) << " |\n";
		}
		std::cout << "__________________|\n\n";
	}
	else
	{
		std::cout << "\nNo data!!\n\n";
	}


	a.SetElementEnd(10);
	a.SetElementEnd(11);
	a.SetElementEnd(12345);
	a.SetElementEnd(13);
	a.SetElementEnd(14);
	a.SetElementEnd(10);
	a.SetElementEnd(11);
	a.SetElementEnd(12);
	a.SetElementEnd(13);

	if (a.arrayState()) {
		std::cout << "\nArrar # " << a.getCount() << "\n__________________\n                  |\n";
		for (int i = 0; i < a.getSize(); i++) {
			std::cout << " arr["
				<< std::right << std::setw(2) << std::setfill(' ') << i << "]  = "
				<< std::right << std::setw(5) << a.getElement(i) << " |\n";
		}
		std::cout << "__________________|\n\n";
	}
	else {
		std::cout << "\nNo data!!\n\n";
	}

	a.SetElementEnd(10);
	a.SetElementEnd(11);
	a.SetElementEnd(12);
	a.SetElementEnd(13);
	a.SetElementEnd(14);
	a.SetElementStar(9);
	a.SetElementStar(8);
	a.SetElementStar(7);
	a.SetElementStar(6);
	a.SetElementStar(5);
	a.SetElementStar(4);
	a.SetElementStar(3);
	a.SetElementStar(2);
	a.SetElementStar(1);

	if (a.arrayState())
	{
		std::cout << "\nArrar # " << a.getCount() << "\n__________________\n                  |\n";
		for (int i = 0; i < a.getSize(); i++)
		{
			std::cout << " arr["
				<< std::right << std::setw(2) << std::setfill(' ') << i << "]  = "
				<< std::right << std::setw(5) << a.getElement(i) << " |\n";
		}
		std::cout << "__________________|\n\n";
	}
	else
	{
		std::cout << "\nNo data!!\n\n";
	}

	std::cout << "\nArray size = " << a.getSize() << "\n\n";

	std::cout << "Array state : " << std::boolalpha << a.arrayState() << '\n';



	IntArray b(5);

	if (b.arrayState())
	{
		std::cout << "\nArrar # " << b.getCount() << "\n__________________\n                  |\n";
		for (int i = 0; i < b.getSize(); i++)
		{
			std::cout << " arr["
				<< std::right << std::setw(2) << std::setfill(' ') << i << "]  = "
				<< std::right << std::setw(5) << b.getElement(i) << " |\n";
		}
		std::cout << "__________________|\n\n";
	}
	else
	{
		std::cout << "\nNo data!!\n\n";
	}

	b.SetElementEnd(10);
	b.SetElementEnd(11);
	b.SetElementEnd(12);
	b.SetElementEnd(13);
	b.SetElementStar(999);


	if (b.arrayState())
	{
		std::cout << "\nArrar # " << b.getCount() << "\n__________________\n                  |\n";
		for (int i = 0; i < b.getSize(); i++)
		{
			std::cout << " arr["
				<< std::right << std::setw(2) << std::setfill(' ') << i << "]  = "
				<< std::right << std::setw(5) << b.getElement(i) << " |\n";
		}
		std::cout << "__________________|\n\n";
	}
	else {
		std::cout << "\nNo data!!\n\n";
	}


	std::cout << "\nArray size = " << b.getSize() << "\n\n";

	std::cout << "Array state : " << std::boolalpha << b.arrayState() << '\n';

	std::cout << "\nCount array = " << b.getCount();

}





