#pragma once

#include <utility>

namespace my {
	template<class T>
	class shared_ptr {
		T* ptr = nullptr;
		size_t* refCounter = nullptr;
	public:
		void assignPtrs(const shared_ptr& other) {
			this->ptr = other.ptr;
			this->refCounter = other.refCounter;
			if (this->refCounter) {
				++(*refCounter);
			}
		}
		shared_ptr() {}
		shared_ptr(T* _ptr)
			:ptr(_ptr), refCounter(new size_t(1)) {}

		shared_ptr(const shared_ptr& other) {
			assignPtrs(other);
		}
		shared_ptr& operator=(const shared_ptr& other) {
			if (this->ptr) {
				this->~shared_ptr();
			}
			assignPtrs(other);
			return *this;
		}
		shared_ptr& operator=(T* _ptr) {
			if (this->ptr) {
				this->~shared_ptr();
			}
			this->ptr = _ptr;
			this->refCounter = new size_t(1);
			return *this;
		}
		~shared_ptr() {
			if (*refCounter > 1) {
				--(*refCounter);
			} else {
				if (refCounter) {
					delete refCounter;
				}
				if (ptr) {
					delete ptr;
				}
			}
		}
		T& operator*() const { return *ptr; }
		T* operator->() const { return ptr; }
		T* get() const { return ptr; }
		size_t use_count() const { return *refCounter; }
		explicit operator bool() const { return ptr != nullptr; }
	};

	template<class T, class... Args>
	shared_ptr<T> make_shared(Args&&... args) {
		auto tmp = new T(std::forward<Args>(args)...);
		return shared_ptr<T>(tmp);
	}
}

