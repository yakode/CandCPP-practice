#ifndef FUNCTION_H
#define FUNCTION_H
#include<cstddef>
#include<iosfwd>

namespace oj
{
	class Memory_leak_count	//check whether the process has memory leak
	{
		friend void memory_leak_count_check();
		static unsigned count_;
	public:
		Memory_leak_count();
		~Memory_leak_count();
	};

	struct Int	//you can treat Int as int
	{
		int val;	//store int in val, you this val
		Int();
		Int(int val);
		Int(const Int &);	//copy constructor
		operator int&()	//treat Int as int, conversion function
		{
			return val;
		}
		operator int() const	//treat Int as int, conversion function
		{
			return val;
		}
		Int& operator=(const Int &);	//copy constructor
	private:
		Memory_leak_count count_;	//you don't have to pay attention on this
	};

	typedef Int data_t;

	class Vector
	{
	public:
		typedef std::size_t size_type;
		typedef Int value_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
	private:
		pointer begin_;	//begin of array
		pointer end_;	//end of array
		pointer last_;	//end of current element
	public:
		Vector();
		inline size_type capacity() const
		{
			return end_-begin_;
		}
		inline size_type size() const
		{
			return last_-begin_;
		}
		//ignore the keyword "inline"
		//operator[] makes Vector like a C-array, for example
		//int a[2]{2,1};
		//Vector vec;
		//vec.push_back(1);
		//vec.push_back(2);
		//vec[0] is equal to a[1]
		//vec[1] is equal to a[0]
		inline reference operator[](const size_type pos)
		{
			return begin_[pos];
		}
		inline const_reference operator[](const size_type pos) const
		{
			return begin_[pos];
		}
		
		void pop_back();
		void push_back(value_type val);
		
		void reserve(size_type new_capacity);
		
		~Vector();
	};
	void Vector::pop_back(){
		if(last_ == begin_) return;
		last_--;
	}
	void Vector::push_back(value_type val){
		size_type capa = capacity();
		if(last_ == end_){
			if(capa+1 > capa*3){
				reserve(capa+1);
			}else{
				reserve(capa*3);
			}
		}
		*last_ = val;
		last_++;
	}
	void Vector::reserve(size_type new_capacity){
		size_type sz = size(), capa = capacity();
		if(new_capacity <= capa) return;
		value_type *new_arr = new value_type[new_capacity];
		end_ = new_arr + new_capacity;
		last_ = new_arr + sz;
		for(int i = 0; i < sz; i++)
			new_arr[i] = begin_[i];
		delete []begin_;
		begin_ = new_arr;
	}
	Vector::~Vector(){delete []begin_;}
	std::ostream& operator<<(std::ostream &os,const Vector &vec);	//for cout

	void memory_leak_count_check();	//you don't have to pay attention on this
}

#endif

