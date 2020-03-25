#include <iostream>
using namespace std;
struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};

template <typename T>
struct ValueHolder : ICloneable {
    ValueHolder(T const& value = 0)
        : data_(value) {}

    ICloneable* clone() const {
        return new ValueHolder(data_);
    }

    T data_;
};

class Any
{
public:
    Any()
        : object(0) {}

    template <typename T>
    Any(T value)
        : object(new ValueHolder<T>(value)) {}

    ~Any () { delete object; }

    Any(const Any& any)
        : object(any.object ? any.object->clone() : any.object) {}

    void swapper(Any & any){
        std::swap(object, any.object);
    }
    Any& operator=(Any const& any){
        Any(any).swapper(*this);
        return *this;
    }
    template<typename T>
    Any& operator=(T const& any){
        delete object;
        object = new ValueHolder<T>(any);
        return *this;
    }

    template <class T>
    T* cast(){
        ValueHolder<T> b;
        return ((*((void**)(&b))) == (*((void**)object)) ? &((ValueHolder<T>*)object)->data_ : 0);
        //ValueHolder<T>* ptr = dynamic_cast<ValueHolder<T>*>(object);
        //return (ptr ? &(ptr->data_) : NULL);
    }

private:
    ICloneable* object;
};

void test0()
{
	struct X
	{
		ICloneable *p;
	};
	cout << endl << "***** Empty ***" << " (" << __FUNCTION__ << ")" << endl;
	Any aEmpty(NULL);
	cout << *aEmpty.cast<int>() << endl;
	Any bEmpty;
	if (((X*)&bEmpty)->p == NULL) {
		cout << "Empty: OK";
	}
	else
	{
		cout << "Empty: Failed" << endl;
	}
	cout << endl;
	if (bEmpty.cast<string>()) { cout << *bEmpty.cast<string>() << endl; }
	Any  cEmpty;
	bEmpty = cEmpty;
	cout << "Address: " << &bEmpty << " Pointer value: " << (((X*)&bEmpty)->p) << endl;
}
void test1()
{
	cout << endl << "***** INT (Self = Self ) ***" << " (" << __FUNCTION__ << ")" << endl;
	int INT = 1;
	Any aINT(INT);
	cout << *aINT.cast<int>() << " == " << INT << endl;
	aINT = aINT;
	cout << *aINT.cast<int>() << " == " << INT << endl;
}

void test4()

{
	string  STR("Hello!");
	cout << endl << "***** STRING (empty, =, copy, cast) ***" << " (" << __FUNCTION__ << ")" << endl;
	{

		Any aINT(STR);
		cout << *aINT.cast<string>() << " == " << STR ;
	}
	cout << endl;
	{
		Any aINT(STR);
		Any aEmpty;
		aEmpty = aINT;
		cout << *aEmpty.cast<string>() << " == " << STR << endl;
	}
	cout << endl;
	{
		string sEmpty("");
		Any aEmpty(sEmpty);
		aEmpty = aEmpty;
		cout << *aEmpty.cast<string>() << " == " << STR << endl;
		aEmpty = aEmpty;
		cout << *aEmpty.cast<string>() << " == " << STR << endl;
		Any nEmpty(aEmpty);
		cout << *nEmpty.cast<string>() << " == " << STR << endl;
	}
	cout << endl;
	{
		int i = 10;
		ValueHolder<int>* intHolder = new ValueHolder<int>(i);
		ValueHolder<char>* charHolder = dynamic_cast<ValueHolder<char>*>(intHolder->clone());
		ValueHolder<int>* int2Holder = dynamic_cast<ValueHolder<int>*>(intHolder->clone());
		cout << "Char* 4 Int* " << (charHolder ? "Cast: OK" : "Cast: Failed") << endl;
		cout << "Int* 4 Int*" << (int2Holder ? "Cast: OK" : "Cast: Failed") ;
		delete intHolder;
		delete charHolder;
		delete int2Holder;
	}
	cout << endl;
}

int main(){
    test0();
    test1();
    test4();
}
