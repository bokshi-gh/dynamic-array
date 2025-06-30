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

		for(int i=0; i<size; i++){
			*(array+i) = value;
		}
	}
	void push_back(T value){

	}
	~dynamic_array(){
		delete[] array;
	}
};
