#pragma once

template <typename T>

class dynamic_array{
private:
	T* array;
	int size;
	int capacity;

public:
	dynamic_array(){
		this->size = 0;
		capacity = 3;
		array = new T[capacity];
	}

	dynamic_array(int size){
		this->size = size;
		capacity = size+3;
		array = new T[capacity];

		for(int i=0; i<size; i++){
			// generic default initialization
			*(array+i) = T{};
		}
	}

	dynamic_array(int size, T value){
		this->size = size;
		capacity = size+3;
		array = new T[capacity];

		for(int i=0; i<size; i++) *(array+i) = value;
	}

	~dynamic_array(){
		delete[] array;
	}

	int get_size(){
		return size;
	}

	int get_capacity(){
		return capacity;
	}

	T at(int idx){
		return array[idx];
	}

	bool empty(){
		return size == 0 ? true: false;
	}

	T *begin(){
		return array;
	}

	T *end(){
		return  array + size;
	}


	T front(){
		return array[0];
	}

	T back(){
		return array[size-1];
	}

	void clear(){
		size = 0;
		delete[] array;
		array = new T[capacity];
	}
	
	void push_back(T value){
		if (size > capacity){
			capacity *= 2;
			T new_array = new T[capacity];

			for(int i=0; i<size; i++) *(new_array+i) = (array+i);

			new_array[size++] = value;
			array = new_array;

			return;
		}

		array[size++] = value;
	}
};
