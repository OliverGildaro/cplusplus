/*segundo parcial dev24*/
#include <iostream>
#include <string>
# include <cmath>


using namespace std;

enum CalculatorType
{
    RPN,
    Normal,
    Basic       
};

class IOperator
{
public:
    virtual string getName()=0;
    virtual string setName(string name)=0;
};

class OneData:public IOperator
{
public:
    virtual double result(double a,double b)=0;
};

class Sum : public OneData
{
    string name;
public:
    Sum(){}


    string getName()
    {
        return name;
    }
    string setName(string name)
    {
        this->name=name;
    }
    double result(double a, double b)
    {
        return a+b;
    }
    ~Sum(){}
};

class Res : public OneData
{
    string name;
public:
    Res(){}


    string getName()
    {
        return name;
    }
    string setName(string name)
    {
        this->name=name;
    }
    double result(double a, double b)
    {
        return a-b;
    }
    ~Res(){}
};

class Mul : public OneData
{
    string name;
public:
    Mul(){}


    string getName()
    {
        return name;
    }
    string setName(string name)
    {
        this->name=name;
    }
    double result(double a, double b)
    {
        return a*b;
    }
    ~Mul(){}
};

class Div : public OneData
{
    string name;
public:
    Div(){}


    string getName()
    {
        return name;
    }
    string setName(string name)
    {
        this->name=name;
    }
    double result(double a, double b)
    {
        return a/b;
    }
    ~Div(){}
};

class MaxOperator : public OneData
{
    string name;
public:
    MaxOperator(){}


    string getName()
    {
        return name;
    }
    string setName(string name)
    {
        this->name=name;
    }
    double result(double a, double b)
    {
        return a+b;
    }
    ~MaxOperator(){}
};


class TwoData: public IOperator
{
public:
    virtual double result(double a)=0;
};

class IncOperator : public TwoData
{
    string name;
public:
    IncOperator(){}


    string getName()
    {
        return name;
    }
    string setName(string name)
    {
        this->name=name;
    }
    double result(double a)
    {
        a+=1;
        return a;
    }
    ~IncOperator(){}
};

class SqrtOperator : public TwoData
{
    string name;
public:
    SqrtOperator(){}


    string getName()
    {
        return name;
    }
    string setName(string name)
    {
        this->name=name;
    }
    double result(double a)
    {
        return sqrt(a);
    }
    ~SqrtOperator(){}
};

class ICalculator
{
public:
    virtual string eval(string a)=0;
    virtual void add_operator(string name, IOperator* op)=0;
};

class CalculatorRPN:public ICalculator
{
public:
    CalculatorRPN(){

    }
    string eval(string s)
    {
        return "hola";
    }
    void add_operator(string name ,IOperator* op){}
    ~CalculatorRPN()
    {

    }
    
};

class CalculatorFactory
{
    ICalculator* calculadora;
public:
    CalculatorFactory(){}
    ICalculator* create_calculator(CalculatorType n)
    {
        if(n==CalculatorType::RPN)
        {
            calculadora=new CalculatorRPN();
            return calculadora;
        }
    }
    ~CalculatorFactory(){
        delete calculadora;
    }
    
};

void show(string a)
{
    cout<<a<<endl;
}

int main()
{
    CalculatorFactory cf;
    ICalculator* calc = cf.create_calculator(CalculatorType::RPN);

    show(calc->eval("2 3 +")); // 5
    /*
    show(calc->eval("100 12.5 13.7 * -")); // 67.825
    show(calc->eval("5 6 7 8 + - * 5 +")); // 50
    show(calc->eval("6 inc")); // [Error: operator 'inc' unknown]
    show(calc->eval("7 2 max")); // [Error: operator 'max' unknown]
    show(calc->eval("7 *")); // [Error: no operand found for '*']
    show(calc->eval("+")); // [Error: no operand found for '+']
    show(calc->eval("abc")); // [Error: operator 'abc' unknown]
    show(calc->eval("12x6")); // [Error: syntax error]

    calc->add_operator("inc", new IncOperator());
    calc->add_operator("max", new MaxOperator());
    calc->add_operator("sqrt", new SqrtOperator());

    show(calc->eval("10 5 max inc")); // 11
    show(calc->eval("25.8 63 max inc sqrt")); // 8
    */
}