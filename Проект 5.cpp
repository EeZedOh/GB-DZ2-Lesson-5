#include <iostream>

using namespace std;

/*HOMEWORK1
Реализовать шаблон класса Pair1,
который позволяет пользователю передавать данные одного типа парами.
*/

template <class T>
class Pair1
{
private:
	T m_a;
	T m_b;

public:
	Pair1(const T& a, const T& b) : m_a(a), m_b(b) {}

	T& first() { return m_a; }
	const T& first() const { return m_a; }
	T& second() { return m_b; }
	const T& second() const { return m_b; }
};

/*HOMEWORK2
Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.
*/

template <class T, class S>
class Pair
{
private:
	T m_a;
	S m_b;

public:
	Pair(const T& a, const S& b) : m_a(a), m_b(b) {}

	T& first() { return m_a; }
	const T& first() const { return m_a; }
	S& second() { return m_b; }
	const S& second() const { return m_b; }
};

/*Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа.
Этот шаблон класса должен наследовать частично специализированный класс Pair, в котором первый параметр — string, а второй — любого типа данных.
*/

template <class S>
class StringValuePair : public Pair<string, S>
{
public:
	StringValuePair(const string& key, const S& value) : Pair<string, S>(key, value) {}
};



int main()
{
	{
		//dz1
		Pair1<int> p1(6, 9);
		cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
		const Pair1<double> p2(3.4, 7.8);
		cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	}

	{
		//dz2
		Pair<int, double> p1(6, 7.8);
		cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

		const Pair<double, int> p2(3.4, 5);
		cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	}

	{
		//dz3
		StringValuePair<int> svp("Amazing", 7);
		cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
	}
	return 0;
};