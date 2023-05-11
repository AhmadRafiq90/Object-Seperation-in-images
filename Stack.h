#pragma once
struct Pixel
{
	int row, col;
	Pixel(int r = 0, int c = 0) : row(r), col(c) {}
};

struct node1
{
	Pixel px;
	node1* next = nullptr;
	node1(int r = 0, int c = 0) : px(r, c) {}
};

class Queue
{
private:
	node1* front = nullptr, * rear = nullptr;

public:
	bool isEmpty() { return !front && !rear; }
	void push(int r, int c)
	{
		if (!front && !rear)
			front = new node1(r, c), rear = front;
		else
		{
			node1* temp = new node1(r, c);
			rear->next = temp, rear = rear->next;
		}
	}
	void pop()
	{
		if (front == rear)
		{
			delete front;
			front = rear = nullptr;
		}
		else
		{
			node1* deleted = front;
			front = front->next;
			delete deleted;
		}
	}
	Pixel top()
	{
		if (front)
			return front->px;
	}
};

class stack1
{
	node1* top = nullptr;
public:
	void push(int r, int c)
	{
		if (!top)
			top = new node1(r, c);
		else
		{
			node1* new_top = new node1(r, c);
			new_top->next = top;
			top = new_top;
		}
	}

	Pixel top()
	{
		if (top)
			return top->px;
	}

	bool isEmpty() { return !top; }
	void pop()
	{
		if (top)
		{
			node1* ret = top;
			top = top->next;
			delete ret;
		}
		else
			return;
	}
};