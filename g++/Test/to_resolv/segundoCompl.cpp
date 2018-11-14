
# include <iostream>
# include <cstring>
# include <string>
# include <cmath>
# include <cctype>
using namespace std;

struct IOperator
{
    virtual float eval(float, float) const =0;
    virtual float eval(float) const =0;
    virtual const char* getOp() const =0;
    virtual bool operatorType() const =0;
};
struct Sum : public IOperator
{
    virtual float eval(const float a, const float b) const override
    {
        return a+b;
    }
    virtual const char* getOp() const override
    {
        return "+";        
    }
    virtual float eval(const float a)const override {}
    virtual bool operatorType() const override
    {
        return true;
    }

};
struct Res : public IOperator
{
    virtual float eval(const float a, const float b) const override
    {
        return a-b;
    }
    virtual const char* getOp() const override
    {
        return "-";        
    }
    virtual float eval(const float a) const override {}
    virtual bool operatorType() const override
    {
        return true;
    }

};
struct Mul : public IOperator
{
    virtual float eval(const float a, const float b) const override
    {
        return a*b;
    }
    virtual const char* getOp() const override
    {
        return "*";        
    }
    virtual float eval(const float a) const override {}
    virtual bool operatorType() const override
    {
        return true;
    }

};
struct Div : public IOperator
{
    virtual float eval(const float a, const float b) const override
    {
        return b/a;
    }
    virtual const char* getOp() const override
    {
        return "/";        
    }
    virtual float eval(const float a)const override {}
    virtual bool operatorType() const override
    {
        return true;
    }

};
struct IncOperator : public IOperator
{
    virtual float eval(const float a, const float b) const override {}
    virtual float eval(const float a) const override
    {
        return a+1;
    }
    virtual const char* getOp() const override
    {
        return "inc";        
    }
    virtual bool operatorType() const override
    {
        return false;
    }

};
struct MaxOperator : public IOperator
{
    virtual float eval(const float a, const float b) const override
    {
        return a>b ? a : b;
    }
    virtual const char* getOp() const override
    {
        return "max";        
    }
    virtual float eval(const float a) const override {}
    virtual bool operatorType() const override
    {
        return true;
    }

};
struct SqrtOperator : public IOperator
{
    virtual float eval(const float a, const float b) const override{}
    virtual float eval(const float a) const override
    {
        return sqrt(a);
    }
    virtual const char* getOp() const override
    {
        return "sqrt";        
    }
    virtual bool operatorType() const override
    {
        return false;
    }

};
struct NodeOperators
{
    const IOperator* ope;
    NodeOperators* next=nullptr;
    NodeOperators(const IOperator* a)
    {
        ope=a;
    } 
};

enum CalculatorType
{
    RPN,
    NORMAL
};

struct ICalculator
{
    virtual string eval(const char*) =0;
    virtual void add_operator(string, const IOperator*)=0;
    virtual ~ICalculator(){}
};
struct Node
{
    const float num;
    Node* next=nullptr;
    Node(const float a) : num{a} {}
};
struct Stack
{
    Node* first=nullptr;
    size_t cantidad=0;
    void add(const float a)
    {
        Node* nn = new Node(a);
        //cout << " nodo de numeros creado\n";
        cantidad++;
        if(first==nullptr)
        {
            first=nn;
            return;
        }
        nn->next=first;
        first=nn;
        return;
    }
    bool deleteNode()
    {
        if(first!=nullptr)
        {
            auto aux=first;
            first=first->next;
            delete aux;
            cantidad--;
            //cout << "nodo numeros eliminado\n";
            return true;
        }
        return false;
    }
    float getNum()
    {
        if(first==nullptr) return 0;
        auto aux = first->num;
        deleteNode();
        return aux;
    }
    ~Stack()
    {
        auto aux=first;
        while(aux)
        {
            auto next=aux->next;
            delete aux;
            aux=next;
            //cout << "node de numeros eliminado\n";
        }
    }
};

struct CalculatorRPN : public ICalculator
{
    NodeOperators* first=nullptr;
    Stack* numeros= nullptr; 
    CalculatorRPN()
    {
        add_operator("+", new Sum());
        add_operator("-", new Res());
        add_operator("*", new Mul());
        add_operator("/", new Div());
    }
    void evaluate(const char* s, string& result) 
    {
        if(first==nullptr) return;
        auto aux=first;
        float res=0;
        while(aux)
        {
            if(strcmp(aux->ope->getOp(), s)==0)
            {
                if(aux->ope->operatorType()==true && numeros->cantidad>=2)
                {
                    float a = numeros->getNum();
                    float b = numeros->getNum();
                    res=aux->ope->eval(a,b);
                    numeros->add(res);
                    result=to_string(res);
                    return;
                }
                else if(aux->ope->operatorType()==false && numeros->cantidad>=1)
                {
                    float a = numeros->getNum();
                    res = aux->ope->eval(a);
                    numeros->add(res);
                    result=to_string(res);
                    return;
                }
                else
                {
                    string aux = s;
                    result = "[Error: no operand found for '"+ aux +"']";
                    return;
                }
            }
            aux=aux->next;
        }
        
    }
    string eval(const char* s) override
    {
        if (numeros!=nullptr)
        {
            numeros->~Stack();
        }
        numeros = new Stack();
        size_t len= strlen(s);
        char m[len+1];
        memcpy(m,s,len+1);
        char* c = strtok(m, " ");
        string result="";
        while(c!=nullptr)
        {
            if(find(c))
            {
                evaluate(c, result);
            }
            else
            {
                try//manejar por consola
                {
                    const char* z = c;
                    bool isDigit=true;
                    while(*z)
                    {
                        if(!isdigit(*z))
                        {
                            if(*z=='.')
                            {
                                z++;
                                continue;
                            } 
                            result="[Error: syntax error]";
                            isDigit = false;
                            break;
                        }
                        z++;
                    }
                    if(isDigit==true)
                    {
                        string aux = c;
                        float a = stof(aux);
                        numeros->add(a);
                    }
                    else break;
                }
                catch(...)//manejo de excepciones
                {
                    string aux=c;
                    result="[Error: operator '"+aux+"' unknown]";
                }
            }
            c = strtok(nullptr," ");
        }
        return result;
    }
    void add_operator(string a, const IOperator* b) override
    {
        auto nn = new NodeOperators{b};
        //cout << "nodo operator creado\n";
        if(first==nullptr)
        {
            first = nn;
            return;
        }
        nn->next=first;
        first=nn;
    }
    bool find(const char* s) const
    {
        if (first==nullptr) return false;
        auto aux=first;
        while(aux)
        {
            if(strcmp(aux->ope->getOp(),s)==0)
            {
                return true;
            }
            aux=aux->next;
        }
        return false;
    }
    ~CalculatorRPN()
    {
        numeros->~Stack();
        auto aux = first;
        while(aux)
        {
            auto next = aux->next;
            delete aux;
            aux=next;
            //cout << "Nodo operator eliminado\n";
        }
    }

};


void show(string a)
{
    cout << a << endl;
}

struct CalculatorFactory 
{
    ICalculator* calculator;
    ICalculator* create_calculator(CalculatorType n)
    {
        if(n==CalculatorType::RPN)
        {
            calculator = new CalculatorRPN();
            return calculator;
        } 
    }
    ~CalculatorFactory()
    {
        delete calculator;
    }    
};

int main()
{
        CalculatorFactory cf;
        ICalculator* calc = cf.create_calculator(CalculatorType::RPN);

        show(calc->eval("2 3 +")); // 5
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
}