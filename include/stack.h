// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память

<<<<<<< HEAD
#include <iostream> 
using namespace std; 
 template<class sType> 
 class TStack 
 { 
 private: 
 	int Top;  
 	int Size;  
 	sType* StMem;  
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
 	sType Pop(); 
 	sType Peek(); 
 	TStack & operator=(const TStack &st); 
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
 	for (int i = 0; i < Top; i++) 
 		StMem[i] = s.StMem[i]; 
 } 
 template<class sType> 
 void TStack<sType>::Push(const sType &value) 
 { 
 	if (!IsFull()) 
 	{ 
 		StMem[Top++] = value; 
 	} 
 	else 
 	{ 
 		Size *= 2; 
 		sType* temp = new sType[Size]; 
 		for (int i = 0; i < Top; i++) 
 			temp[i] = StMem[i]; 
		delete[] StMem; 
 		StMem = temp; 
 		StMem[Top++] = value; 
 	} 
 } 
 template<class sType> 
 sType TStack<sType>::Pop() 
 { 
	if (!IsEmpty()) 
 		return StMem[--Top]; 
 	else 
 		throw "Stack is EMPTY"; 
 } 
 template<class sType> 
 sType TStack<sType>::Peek() 
 { 
 	if (!IsEmpty()) 
 		return StMem[Top - 1]; 
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
 } 
 template<class sType> 
 TStack<sType> & TStack<sType>::operator=(const TStack &st)  
 { 
 	if (this != &st) 
 	{ 
 		if (Size != st.Size) 
 		{ 
 			delete[] stMem; 
 			stMem = new sType[st.Size]; 
 		} 
 		Size = st.Size; 
 		Top = st.Top; 
 		for (int i = 0; i<Top; i++) 
 			stMem[i] = st.stMem[i]; 
 	} 
 	return *this; 
 } 
=======
#include <iostream>
using namespace std;
template<class sType>
class TStack
{
private:
	int Top; 
	int Size; 
	sType* StMem; 
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
	sType Pop();
	sType Peek();
	TStack & operator=(const TStack &st);

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
	for (int i = 0; i < Top; i++)
		StMem[i] = s.StMem[i];
}
template<class sType>
void TStack<sType>::Push(const sType &value)
{
	if (!IsFull())
	{
		StMem[Top++] = value;
	}
	else
	{
		Size *= 2;
		sType* temp = new sType[Size];
		for (int i = 0; i < Top; i++)
			temp[i] = StMem[i];
		delete[] StMem;
		StMem = temp;
		StMem[Top++] = value;
	}
}
template<class sType>
sType TStack<sType>::Pop()
{
	if (!IsEmpty())
		return StMem[--Top];
	else
		throw "Stack is EMPTY";
}
template<class sType>
sType TStack<sType>::Peek()
{
	if (!IsEmpty())
		return StMem[Top - 1];
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
}
template<class sType>
TStack<sType> & TStack<sType>::operator=(const TStack &st) 
{
	if (this != &st)
	{
		if (Size != st.Size)
		{
			delete[] stMem;
			stMem = new sType[st.Size];
		}
		Size = st.Size;
		Top = st.Top;
		for (int i = 0; i<Top; i++)
			stMem[i] = st.stMem[i];
	}
	return *this;
}
>>>>>>> 275806a7380edd64ead0df76ee970146e7cf3c5d
