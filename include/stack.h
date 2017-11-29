// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память

#include <iostream>
using namespace std;
template<class sType>
class TStack
{
private:
	int Top; //Номер последнего занятого элемента стека
	int Size; //Размер стека
	sType* StMem; //Указатель на первый элемент стека
public:
	TStack(int s = 100);
	TStack(const TStack<sType>&s);
	~TStack();
	int GetSize() { return Size; }
	int GetTop() { return Top; }
	void Push(const sType& value);
	bool IsFull() const;
	bool IsEmpty() const;
	void Clean();

};
template<class sType> 
TStack<sType>::TStack(int s) 
{
	if (s > 0)
	{
		Size = s;
		Top = 0;
		StMem = new sType[Size];
	}
	else
		throw "WARNING! Negative Size";
}
template<class sType>
TStack<sType>::~TStack()
{
	delete[] StMem;
}
template<class sType>
TStack<sType>::TStack(const TStack<sType> &s)
{
	Size = s.Size;
	StMem = new sType[Size];
	for (int i = 0; i < Top + 1; i++)
		StMem[i] = s.StMem[i];
}
template<class sType>
void TStack<sType>::Push(const sType &value)
{
	if (!IsFull())
	{
		StMem[++Top] = value;
	}
	else
	{
		Size *= 1, 5;
		sType* temp = new sType[Size];
		for (int i = 0; i < Top + 1; i++)
			temp[i] = StMem[i];
		delete[] StMem;
		StMem = temp;
	}
}
template<class sType>
sType TStack<sType>::Pop()
{
	if (!IsEmpty())
		return StMem[Top--];
	else
		throw "Stack is EMPTY";
}
template<class sType>
sType TStack<sType>::Peek() const
{
	if (!IsEmpty())
		return StMem[Top];
	else
		throw "Stack is EMPTY";
}
template<class sType>
bool TStack<sType>::IsEmpty() const
{
	return Top == 0;
}
template<class sType>
bool TStack<sType>::IsFull() const
{
	return Top == Size;
}
template<class sType>
void TStack<sType>::Clean()
{
	Top = 0;
	for (int i = 0; i < Size; i++)
		StMem[i] = 0;
}