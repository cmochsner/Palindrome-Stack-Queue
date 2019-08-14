#include <iostream>
#include <string>

using namespace std;

template <class Type>
class queueType
{
	private:
	int max;
	int front;
	int rear;
	int size;
	Type* list;
	public:
	queueType(int max)
	{
		this->max = max;
		list = new Type[max];
		size = 0;
		front = 0;
		rear = 0;
	}
	void add(Type el);
	bool isFull();
	bool isEmpty();
	Type remove();
	~queueType()
	{
		delete[] list;
	}
};
template <class Type>
void queueType<Type>::add(Type el)
{
	if (isFull())
	{
		return;
	}
	list[rear] = el;
	rear++;
	size++;
}
template <class Type>
Type queueType<Type>::remove()
{
	if (isEmpty())
	{
		return ' ';
	}
	Type item = list[front];
	list[front] = NULL;

	/*for (int i = 0; i < rear; i++)
	{
		list[i] = list[i + 1];
	}
	list[rear] = 0;
	rear--;
	*/

	front++;
	size--;
	return item;
}
template <class Type>
bool queueType<Type>::isEmpty()
{
	if (size == 0)
	{
		return true;
	}
	return false;
}
template <class Type>
bool queueType<Type>::isFull()
{
	if (size == max-1)
	{
		return true;
	}
	return false;
}

template <class Type>
class stackType
{
	private:
	int max;
	int top;
	Type *list;
	public:
	stackType(int max)
	{
		this->max = max;
		top =-1;
		list=new Type[max];
	}
	bool isEmpty();
	bool isFull();
	void push(Type el);
	Type pop();
	void print();
	~stackType()
	{
		delete [] list;
	}

};
template <class Type>
void stackType<Type>::push(Type el)
{
	top++;
	list[top] = el;
}
template <class Type>
Type stackType<Type>::pop()
{
	Type item = list[top];
	list[top] = ' ';
	top--;
	return item;
}
template <class Type>
bool stackType<Type>::isEmpty()
{
	if (top == -1)
	{
		return true;
	}
	return false;
}
template <class Type>
bool stackType<Type>::isFull()
{
	if (top == max-1)
	{
		return true;
	}
	return false;
}
template <class Type>
void stackType<Type>::print()
{
	for (int i = 0; i <= top; i++)
	{
		cout << list[i] << endl;
	}
}

int main()
{
	string str;
	cout << "Welcome to the Palindrome Stack/Queue Program! Enter -1 to exit." << endl;
	while (str != "-1")
	{
		cout << "Enter a word to check if it's a palindrome." << endl;
		cin >> str;

		if (str == "-1")
		{
			cout << "Exiting..." << endl;
			return 0;
		}

		queueType<char> queue(str.length());
		stackType<char> stack(str.length());

		for (int i = 0; i < str.length()&&!stack.isFull(); i++)
		{
			stack.push(str[i]);
		}
		for (int j = 0; j < str.length()&&!queue.isFull(); j++)
		{
			queue.add(str[j]);
		}

		bool palindrome = true;

		while (!stack.isEmpty() && !queue.isEmpty())
		{
			if (stack.pop() != queue.remove())
			{
				palindrome = false;
				break;
			}
		}
		if (palindrome)
		{
			cout << "Yes, "<<str<<" is a palindrome!" << endl;
		}
		else
		{
			cout << "No, "<<str<<" is not a palindrome." << endl;
		}
	}

	//system("pause");
	return 0;
}