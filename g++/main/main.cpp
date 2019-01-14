#include <iostream>
#include <cstring>
using namespace std;

const char *abcd = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-*/.";

const char* SUM = "+";
const char* RES = "-";
const char* MUL = "*";
const char* DIV = "/";
#define o_sum "+"


enum class CalculatorType
{
    RPN
};

class f_array
{
private:
    char** objects;
    size_t len;
public:
    f_array()
    :objects{(char**) malloc(0)}, len{0} { }
    ~f_array() { }

    void add_caracter(char* obj)
    {
        objects = (char**) realloc(objects, (len+1)*sizeof(char*));
        objects[len++] = obj;
    }
    
    size_t size() const
    {
        return len;
    }

    const char* operator[](size_t position)
    {
        return objects[position];
    }
};

class f_tokenizer
{
private:
    size_t len;
    size_t len_abc;
    char* tok;
    size_t pos_init;
    f_array array_tokens;
public:
    f_tokenizer(/* args */) { }
    ~f_tokenizer() { }

    bool is_letter(char letter)
    {
        len_abc = strlen(abcd);

        for (size_t i = 0; i < len_abc; i++)
        {
            if (letter == abcd[i])
                return true;
        }
        return false;
    }

    void tokenizer(const char *txt)
    {
        len = strlen(txt);
        size_t count_letter = 0;
        for (size_t i = 0; i < len; i++)
        {
            if (is_letter(txt[i]) == true)
            {
                pos_init = i;
                do
                    count_letter++;
                while (is_letter(txt[++i]));

                tok = new char[count_letter + 1];

                for (size_t i = 0; i < count_letter; i++)
                    tok[i] = txt[pos_init++];
                tok[count_letter] = 0;
            }
            array_tokens.add_caracter(tok);
            count_letter = 0;
        }
    }
};

class ICalculator
{
private:
    f_tokenizer token;
    f_array array_tokens;
    double res;
public:
    ICalculator() {}
    ~ICalculator() {}

    void sumar(size_t position)
    {
        cout << array_tokens[position] << "\n";
    }

    double eval(const char* value)
    {
        token.tokenizer(value);
        
        for(size_t i = 0; i < array_tokens.size(); i++)
        {
                cout << array_tokens[i] << "\n";
            if(array_tokens[i] == o_sum)
            {
                sumar(i);
            }
        }
        
    }
};

class CalculatorFactory : public ICalculator
{
  private:
  public:
    CalculatorFactory() {}
    ~CalculatorFactory() {}

    ICalculator *create_calculator(const CalculatorType &op)
    {
        switch (op)
        {
        case CalculatorType::RPN:
            return new ICalculator{};
        default:
            break;
        }
        return nullptr;
    }
};

void show(double res)
{
    cout << res << "\n";
}

int main()
{
    CalculatorFactory cf;
    ICalculator *calc = cf.create_calculator(CalculatorType::RPN);

    show(calc->eval("2 3 +"));             // 5
    // show(calc->eval("100 12.5 13.7 * -")); // 67.825
    // show(calc->eval("5 6 7 8 + - * 5 +")); // 50
    // show(calc->eval("6 inc"));             // [Error: operator 'inc' unknown]
    // show(calc->eval("7 2 max"));           // [Error: operator 'max' unknown]
    // show(calc->eval("7 *"));               // [Error: no operand found for '*']
    // show(calc->eval("+"));                 // [Error: no operand found for '+']
    // show(calc->eval("abc"));               // [Error: operator 'abc' unknown]
    // show(calc->eval("12x6"));              // [Error: syntax error]

    // calc->add_operator("inc", new IncOperator());
    // calc->add_operator("max", new MaxOperator());
    // calc->add_operator("sqrt", new SqrtOperator());

    // show(calc->eval("10 5 max inc")); // 11
    // show(calc->eval("25.8 63 max inc sqrt")); // 8
}