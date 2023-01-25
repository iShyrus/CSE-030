#ifndef SortedArray_h
#define SortedArray_h

#include <iostream>
#include <ostream>
#include <Array.h>


// The sorted array struct is similar to array.h but the void insert function is different. In this
// void insert function, it helps insert numbers in the beginning of the array, which is appending. Then
// after appending, it sorts it after to be numerically in order. The best case would it being having a small
// amount of numbers. It would be extremely fast being near 0ms. However, if we wanted to insert a number in a large
// array, it would have to shift everything to the right, taking longer than usual. For the sorting part of it, 
// it also depends on how everything is sorted. If everything is nearly sorted correctly, it would take a shorter time.
// If its sorted badly, then it would take a longer time. So, assuming that we have a badly sorted large array, the
// ms taken to be executed would take longer.


struct SortedArr{
    long* data;
    long capacity;
    long count;
    
    SortedArr(){
        data = new long[1];
        
        capacity = 1;
        
        count = 0;
    }

	SortedArr(const SortedArr& other){
        std::cout << "HELLO" << std::endl;
		capacity = other.capacity;
		count = other.count;
		data = new long[other.capacity];

		for (long i = 0; i < other.count; i++){
			data[i] = other.data[i];
		}
	}

    void operator=(const SortedArr& other){
        std::cout << "HI" << std::endl;
		capacity = other.capacity;
		count = other.count;
		data = new long[other.capacity];

		for (long i = 0; i < other.count; i++){
			data[i] = other.data[i];
		}
    }

    long& operator[](long index) const {
        return data[index];
    }




	bool operator==(const SortedArr rhs) const {
		if (capacity != rhs.capacity){
			return false;
		}
		if (count != rhs.count){
			return false;
		}

		bool same = true;

		for (long i = 0; i < count; i++){
			if (data[i] != rhs.data[i]){
				return false;
			}
		}
		
		return true;
	}



    void print(){
        for (long i = 0; i < count; i++){
            std::cout << data[i] << std::endl;
        }
    }
    
    int get(long index){
        return data[index];
    }
    
    void set(long index, long value){
        data[index] = value;
    }

	void insert(long number){
        data[count] = number;
        count++;
        if (count == capacity){
            long oldcapacity = capacity;
            capacity = capacity * 2;          
            long* newArr = new long[capacity];          
            for (long i = 0; i < oldcapacity; i++) {
                newArr[i] = data[i];
            }      

            delete[] data;       
            data = newArr;      
        }

        

    for (long i = 1; i < count; i++){
        long j = i;
        while (j > 0 && data[j-1] > data[j]){
            long temp = data[j];
            data[j] = data[j-1];
            data[j-1] = temp;
            j = j - 1;
        }
    }



    }



    
    
    

    void append(long value){

        data[count] = value;
        count++;
        

        if (count == capacity){
            long oldcapacity = capacity;
            
            capacity = capacity * 2;
            
            long* newArr = new long[capacity];
            

            for (long i = 0; i < oldcapacity; i++) {
                newArr[i] = data[i];
            }
            
            delete[] data;
            
            data = newArr;
            
        }
    }






	

	~SortedArr(){
		delete[] data;
	}
};

std::ostream& operator<<(std::ostream& os, const SortedArr& arr) {
    for (long i = 0; i < arr.count; i++){
		os << arr.data[i] << " ";
	}

    return os;
}


#endif