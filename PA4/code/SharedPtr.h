#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include <iostream>
#include <cassert>

template<typename ObjectType>
void Deallocator(ObjectType* ptr)
{
	std::cout << "Dealloc Object" << std::endl;
	delete ptr;
}

template<typename ObjectType>
void ArrayDeallocator(ObjectType* ptr)
{
	std::cout << "Dealloc Array" << std::endl;
	delete[] ptr;
}

template<typename T>
using DeallocatorFuncType = void(T*);

// SharedPtr
template<typename ObjectType, DeallocatorFuncType<ObjectType> Dealloc = Deallocator<ObjectType> >
class SharedPtr
{
private:
	ObjectType* m_object;
	int* m_ref_counter;	

	// ======= ADD CODE HERE IF NEEDED =========

public:
	////////////////////////////////////////////
	// Constructors & destructor
	////////////////////////////////////////////

	/*default constructor*/
	SharedPtr() :m_object(NULL), m_ref_counter(new int(0)) {}

	/*constructor*/
	SharedPtr(ObjectType* o_ptr) :m_object(o_ptr), m_ref_counter(new int(1)) {}

	/*같은 타입의 객체를 가리키는 다른 SharedPtr 객체로 초기화*/
	SharedPtr(const SharedPtr& ptr) :m_object(ptr.m_object), m_ref_counter(ptr.m_ref_counter) {
		if (ptr.m_object != NULL)
			(*m_ref_counter)++;
	}

	/*destructor*/
	~SharedPtr() {
		(*m_ref_counter)--;
		if (*m_ref_counter == 0) { //객체를 가리키는 포인터의 개수가 0인 경우 할당 해제
			if (m_object != NULL)
				Dealloc(m_object);
			delete m_ref_counter;
		}
	}

	////////////////////////////////////////////
	// Assignment operator
	////////////////////////////////////////////

	/*객체를 다른 객체에 대입*/
	SharedPtr& operator=(const SharedPtr& obj) {
		//기존의 객체를 먼저 비워주기
		(*m_ref_counter)--;
		if (*m_ref_counter == 0) { //객체를 가리키는 포인터의 개수가 0인 경우 할당 해제
			if (m_object != NULL)
				Dealloc(m_object);
			delete m_ref_counter;
		}
		//assign
		m_object = obj.m_object;
		m_ref_counter = new int;
		m_ref_counter = obj.m_ref_counter;
		if (obj.m_object != NULL)
			(*m_ref_counter)++;
		return *this;
	}

	////////////////////////////////////////////
	// Pointer operators
	////////////////////////////////////////////
	// operator->
	// operator*

	/*operator->*/
	ObjectType* operator->()  { return m_object; }
	const ObjectType* operator->() const { return m_object; }

	/*operator**/
	ObjectType& operator*()  { return *m_object; }
	const ObjectType& operator*() const { return *m_object; }

	////////////////////////////////////////////
	// Array element access operators
	////////////////////////////////////////////
	// operator[]

	ObjectType& operator[](int idx) { return m_object[idx]; }

	////////////////////////////////////////////
	// Array element access operators
	////////////////////////////////////////////
	// operator[]

	const ObjectType& operator[](int idx) const { return m_object[idx]; }

	////////////////////////////////////////////
	// Type casting operators
	////////////////////////////////////////////
	// operator ObjectType const*() const
	// operator ObjectType*()

	operator ObjectType const* () const { return static_cast<const ObjectType*> (m_object); }
	operator ObjectType* () { return static_cast<ObjectType*> (m_object); }
};

template<typename T>
using SharedArray = SharedPtr<T, ArrayDeallocator<T> >;

#endif
