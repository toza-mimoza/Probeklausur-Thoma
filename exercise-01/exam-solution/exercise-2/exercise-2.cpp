// 2.1)
// The method 'setName()' gives objects of other classes the ability to set the private member 'char *name' to a new value.
// The given implementation is problematic, because it does not handle a possible dangling pointer to freed memory after
// 'delete name;' and also doesn't account for a possible nullptr that could cause strlen to crash.

// 2.2) Leaving the line out leads to a memory leak, because the pointer of the member 'name' would be changed to the newly allocated memory in the following line without clearing the old memory. The old memory cannot be reached anymore afterwards.

// Better implementation:
void Fahrzeug::setName(const char *n) {
	if (name != nullptr) {
		delete[] name;
		name = nullptr; // handling dangling pointer to freed memory
	}

	if (n != nullptr) { // handling empty pointer as parameter, preventing strlen from crashing
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
}


// 2.3)
// The provided implementation of the standard constructor does not initialize the private attribute 'char *name', so it is not guaranteed, that it is a nullptr initially.
// The overloaded constructor does not need to handle this problem, since it uses the setName() method, assuming it is implemented correctly.
// The destructor is perfectly fine, but 'name = nullptr;' is not necessary, because the pointer belongs to the object that is being destructed and does not exist anymore
// after the execution of the destructor.

// 2.4)
// We need to implement the copy constructor and overwrite the assignment operator, because the class 'Fahrzeug' contains a member variable which is a pointer to memory
// outside of the object, so we have to manage the memory allocation manually.

// 2.5)
Fahrzeug& Fahrzeug::operator=(const Fahrzeug &other) {
	delete[] name;

	if (other.name != nullptr) { // handling empty pointer as parameter, preventing strlen from crashing
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
	}
	return *this;
}

// 2.6
// We could use std::string instead of *char. std::string handles memory allocation internally,
// so we wouldn't need to have a special copy constructor or overwrite the assignment operator.
