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
		
		size_type capacity() const;
		size_type size() const;
		
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
		void insert(size_type pos,size_type count,value_type val);
		
		void reserve(size_type new_capacity);
		void resize(size_type new_size);
		
		~Vector();
	};
	Vector::Vector(){
		begin_ = nullptr;
		last_ = nullptr;
		end_ = nullptr;
	}
	Vector::~Vector(){
		delete []begin_;
	}

	Vector::size_type Vector::capacity() const{
		return end_ - begin_;
	}
	Vector::size_type Vector::size() const{
		return last_ - begin_;
	}

	void Vector::pop_back(){
		last_--;
	}
	void Vector::push_back(value_type val){
		if(last_ == end_){
			//no space to push_back
			size_type old_capacity = capacity();
			if(old_capacity+1 > old_capacity*3)
				reserve(old_capacity+1);
			else
				reserve(old_capacity*3);
		}

		*last_ = val;
		++last_;
	}
	void Vector::insert(size_type pos,size_type count,value_type val){
		//check if capacity is enough
		size_type sz = size(), old_capacity = capacity();
		if(sz+count > old_capacity){
			if(old_capacity+old_capacity/2 > old_capacity+count)
				reserve(old_capacity + old_capacity/2);
			else
				reserve(old_capacity + count);
		}

		//there's element after pos
		if(begin_+pos < last_){
			//move
			for(size_type i = pos; i < sz; i++)
				begin_[i+count] = begin_[i];
			
			//insert
			for(size_type i = 0; i < count; i++)
				begin_[pos+i] = val;
			
			last_ += count;
		}else{
			for(size_type i = 0; i < count; i++)
				push_back(val);
		}
	}
		
	void Vector::reserve(size_type new_capacity){
		if(new_capacity <= capacity()) return; //do nothing

		data_t *tmp = new data_t[new_capacity];
		size_type sz = size();

		for(size_type i = 0; i < sz; i++)
			tmp[i] = begin_[i];
		last_ = tmp + sz;
		end_ = tmp + new_capacity;
		delete [] begin_;
		begin_ = tmp;
	}
	void Vector::resize(size_type new_size){
		size_type sz = size();
		reserve(new_size);

		if(sz < new_size){
			//bigger www
			//new elements are 0s
			for(;last_ < begin_+new_size; last_++)
				*last_ = 0;
		}else
			last_ = begin_ + new_size;
	}


	std::ostream& operator<<(std::ostream &os,const Vector &vec);	//for cout

	void memory_leak_count_check();	//you don't have to pay attention on this
}

