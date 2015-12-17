#include <iostream>

//example of nested classes

using namespace std;

class lst
{
	private:
		struct node
		{
		
			node() { this->next = NULL; }
			node(int d) { data = d; this->next = NULL; }
			int data;
			node* next;
		};
	
		node* head;
		node* tail;
		node* curr;

	public:
		lst(): head(new node()), tail(new node()), curr(new node()) {head->next = tail; tail->next = NULL;}
		void insert(int data)
		{
			if (head->next == tail)
			{
				node* temp = new node(data);
				temp->next = head->next;
				head->next = temp;
				curr = temp;
				curr->next = temp->next;
			}
			else
			{
				node* temp = new node(data);
				temp->next = curr->next;
				curr->next = temp;
				curr = temp;
				curr->next = temp->next;
			}
		}

		void prnt()
		{
			node* temp = head->next;
			while (temp != tail)
			{
				cout << temp->data <<endl;
				temp = temp->next;
			}
		}

};

int main()
{
	lst last;
	last.insert(5);
	last.insert(10);
	last.prnt();
	
	return 0;
}
