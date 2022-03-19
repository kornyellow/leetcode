class MyQueue {
private:
	int* queue;
	int size;
public:
	MyQueue() {
		queue = nullptr;
		size = 0;
	}

	void push(int x) {
		size ++;
		int* new_queue = new int[size];

		if (queue != nullptr) {
			for (int i = 0; i < size - 1; i++)
				new_queue[i] = queue[i];
			delete[] this->queue;
		}

		new_queue[size - 1] = x;
		this->queue = new_queue;
	}

	int pop() {
		int pop = queue[0];

		size --;
		int* new_queue = new int[size];
		for (int i = 0; i < size; i++)
			new_queue[i] = queue[i + 1];

		delete[] this->queue;
		this->queue = new_queue;

		return pop;
	}

	int peek() {
		return queue[0];
	}

	bool empty() {
		return this->size == 0;
	}
};