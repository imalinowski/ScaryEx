#pragma once

template <typename T>
class Mylist
{
private:
	struct Node
	{
		Node()
		{
		};

		Node(T temp) : data(temp)
		{
		};
		T data;
		Node* next;
		Node* previous;
	};

	Node* m_first;
	Node* m_last;
	size_t m_size;

public:
	Mylist();
	~Mylist();

	void add_back(T val);

	void add_front(T val);

	const T pop_back();

	const T pop_front();

	T back() const;

	T front() const;

	const T& operator[](size_t index) const;

	size_t size() const;

	class Marker
	{
	public:
		bool hasNext() const
		{
			return m_marker != nullptr && m_marker->next != nullptr && valid;
		}

		void next()
		{
			if (m_marker != nullptr)
				m_marker = m_marker->next;
		}

		T& getValue()
		{
			if (m_marker == nullptr)
				throw 0;

			return m_marker->data;
		}

		void remove()
		{
			m_marker->previous->next = m_marker->next;
			m_marker->next->previous = m_marker->previous;
			valid = false;
			--(*m_size);
		}

		void insert(T val)
		{
			Node* newNode = new Node(val);
			m_marker->previous->next = newNode;
			newNode->previous = m_marker->previous;
			newNode->next = m_marker;
			m_marker->previous = newNode;
			++(*m_size);

		}

		bool isValid()
		{
			return m_marker != nullptr && valid;
		}

		friend class Mylist;

	private:
		bool valid;
		Mylist<T>::Node* m_marker;
		size_t* m_size;
	};

	Marker& createMarker()
	{
		Marker* mk = new Marker;
		mk->valid = true;
		mk->m_marker = m_first;
		mk->m_size = &m_size;
		return *mk;
	}

};

template <typename T>
Mylist<T>::Mylist()
{
	m_first = nullptr;
	m_last = nullptr;
	m_size = 0;
}

template <typename T>
Mylist<T>::~Mylist()
{
	Node* runner = m_first;
	while (runner != m_last)
	{
		runner = runner->next;
		delete runner->previous;
	}
}


template <typename T>
void Mylist<T>::add_back(T val) {
	if (m_size == 0)
	{
		m_first = new Node(val);
		m_size = 1;
		m_last = m_first;
		m_first->data = val;
		m_first->next = nullptr;
		m_first->previous = nullptr;
	}
	else
	{
		Node* newNode = new Node(val);
		newNode->data = val;
		newNode->next = nullptr;
		m_last->next = newNode;
		newNode->previous = m_last;
		m_last = newNode;
		++m_size;
	}
}

template <typename T>
void Mylist<T>::add_front(T val) 
{
	if (m_size == 0)
	{
		m_first = new Node(val);
		m_size = 1;
		m_last = m_first;
		m_first->data = val;
		m_first->next = nullptr;
		m_first->previous = nullptr;
	}
	else
	{
		Node* newNode = new Node(val);
		newNode->data = val;
		newNode->next = m_first;
		m_first->previous = newNode;
		newNode->previous = nullptr;
		m_first = newNode;
		++m_size;
	}
}
template <typename T>
const T Mylist<T>::pop_back()
{
	if (m_size > 1)
	{
		T data = m_last->data;
		m_last = m_last->previous;
		delete m_last->next;
		m_last->next = nullptr;
		--m_size;
		return data;
	}
	else
	{
		T data = m_first->data;
		delete m_first;
		m_first = nullptr;
		m_last = nullptr;
		--m_size;
		return data;
	}
}

template <typename T>
const T Mylist<T>::pop_front()
{
	if (m_size > 1)
	{
		T data = m_first->data;
		m_first = m_first->next;
		delete m_first->previous;
		m_first->previous = nullptr;
		--m_size;
		return data;
	}
	else
	{
		T data = m_first->data;
		delete m_first;
		m_first = nullptr;
		m_last = nullptr;
		--m_size;
		return data;
	}
}
template<typename T>
T Mylist<T>::back() const
{
	return m_last->data;
}

template<typename T>
inline T Mylist<T>::front() const
{
	return m_first->data;
}

template <typename T>
const T& Mylist<T>::operator[](size_t index) const
{
	if (index < 0 || index >= m_size)
		throw 0;

	Node* runner = m_first;
	for (size_t i = 0; i < index; i++)
		runner = runner->next;

	return runner->data;
}

template <typename T>
size_t Mylist<T>::size() const
{
	return m_size;
}
