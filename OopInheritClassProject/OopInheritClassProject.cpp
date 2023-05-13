#include <iostream>
#include <string>

class Base
{
protected:
    int value;
public:
    Base(int value = 0) : value{ value }
    {
        std::cout << this << " Base create\n";
    }

    ~Base()
    {
        std::cout << this << " Base destroy\n";
    }

    int& Value() { return value; }

    std::string ToString()
    {
        return "value = " + std::to_string(value);
    }
};

class Derived : public Base
{
    int code;
public:
    Derived(int value, int code) : Base(value), code{ code }
    {
        std::cout << this << " Derived create\n";
    }

    Derived() : Derived(0, 0) {}

    ~Derived()
    {
        std::cout << this << " Derived create\n";
    }

    std::string ToString()
    {
        return Base::ToString() + ", code = " + std::to_string(code);
    }

    int& Code() { return code; }
};


class Gadget
{
public:
    Gadget()
    {
        std::cout << this << " Gadget create\n";
    }

    void ToDo()
    {
        std::cout << this << " Gadget to do\n";
    }
};

class Printer : public Gadget
{
public:
    Printer()
    {
        std::cout << this << " Printer create\n";
    }

    void Print()
    {
        std::cout << this << " Print now\n";
    }

    void ToDo()
    {
        std::cout << this << " Print now\n";
    }
};

class Scanner : public Gadget
{
public:
    Scanner()
    {
        std::cout << this << " Scanner create\n";
    }

    void Scan()
    {
        std::cout << this << " Scan now\n";
    }

    void ToDo()
    {
        std::cout << this << " Scan now\n";
    }
};

class Mfu : public Printer, public Scanner
{
public:
    Mfu()
    {
        std::cout << this << " Mfu create\n";
    }

    void Print() = delete;
};

int main()
{
    //Base b;
    //b.Value() = 200;

    //Derived d(100, 200);
    //std::cout << d.ToString() << "\n";

    Mfu m;
    m.Print();
    m.Scan();
    m.Scanner::ToDo();
    m.Printer::ToDo();
}
