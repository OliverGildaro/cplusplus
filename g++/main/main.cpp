#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define A "\""
#define B "\\"

struct json_null
{
      string to_string()
      {
            return "null";
      }
};

struct json_number
{
      int n;

      string to_string()
      {
            return std::to_string(n);
      }
};

struct json_bool
{
      bool band;
      string aux_band;

      string to_string()
      {
            if(band == true)
            {
                  aux_band = "true";
            }
            else
                  aux_band = "false";
            return aux_band;
      }
};



struct node
{
      string word;
};


class f_array
{
private:
      size_t size_memory;
      size_t count;
      node* array;
      string res_string;
public:
      f_array(/* args */)
      :size_memory{4}, count{0}, array{new node[size_memory]} { }
      ~f_array() { }

      void push_back(string& new_word)
      {
            node* new_node = new node{new_word};
            array[count++] = *new_node;
      }

      string to_string()
      {
            size_t c_count=0;
            if(count>2)
            {

                  "my name is \"Michael\""
            }
            else
            {
                  res_string = A + array[c_count].word + ;
            }
      }
};

class json_string
{
private:
      string value;
      size_t len;
      f_array array;
      string real_value;
public:
      json_string(const char* p_value)
      : value{p_value} 
      {
            tokenizer(value);
      }
      ~json_string() { }

      void tokenizer(string value)
      {
            char * writable = new char[value.size() + 1];
            std::copy(value.begin(), value.end(), writable);
            writable[value.size()] = '\0';

            char* tok = strtok(writable, " \"\\");

            while(tok)
            {
                  real_value = tok;
                  array.push_back(real_value);
                  tok = strtok(nullptr, " \"\\");
            }
      }

      string to_string()
      {
            return array.to_string();
      }
};

bool test0()
{
    json_null j;
    return j.to_string() == "null";
}

bool test1()
{
    json_number j { 125 };
    return j.to_string() == "125";
}

bool test2()
{
    json_bool j { true };
    json_bool k { false };
    return j.to_string() == "true" && k.to_string() == "false";
}

bool test3()
{
    json_string j { "hello world" };
//     return j.to_string() == "\"hello world\""; 
}

// bool test4()
// {
//     json_string j = "my name is \"Michael\"";
//     return j.to_string() == "\"my name is \\\"Michael\\\"\"";
// }

// bool test5()
// {
//     json_object j;
//     return j.to_string() == "{ }";
// }

// bool test6()
// {
//     json_array ja;
//     ja.add(true);
//     ja.add("hello world"s);
//     ja.add(237);
//     return ja.to_string() == "[true, \"hello world\", 237]";
// }

// bool test7()
// {
//     json_object jo;
//     jo.add("first_name", "juan");
//     jo.add("last_name", "perez");
//     jo.add("birth_year", 1970);
//     return jo.to_string() == "{ \"first_name\" : \"juan\", \"last_name\" : \"perez\", \"birth_year\" : 1970 }";
// }

// bool test8()
// {
//     json_array ja;

//     json_object jo1;
//     jo1.add("first_name", "juan");
//     jo1.add("last_name", "perez");
//     jo1.add("birth_year", 1970);

//     json_object jo2;
//     jo2.add("first_name", "omar");
//     jo2.add("last_name", "vera");
//     jo2.add("birth_year", 1995);

//     ja.add(jo1).add(jo2);

//     return ja.to_string() == "[{ \"first_name\" : \"juan\", \"last_name\" : \"perez\", \"birth_year\" : 1970 }, { \"first_name\" : \"omar\", \"last_name\" : \"vera\", \"birth_year\" : 1995 }]";
// }

// bool test9()
// {
//     json_object jo;
//     jo.add("marca", "volkswagen");
//     jo.add("modelos", json_array {}.add("jetta").add("new beetle").add("golf"));
//     jo.add("descripcion", json_object {}.add("pais", "alemania").add("produccion_anual", 50000));
//     return jo.to_string() == "{ \"marca\" : \"volkswagen\", \"modelos\" : [\"jetta\", \"new beetle\", \"golf\"], \"descripcion\" : { \"pais\" : \"alemania\", \"produccion_anual\" : 50000 } }";
// }



int main()
{
    auto score = 0.0;

    score += 0.5 * static_cast<double>(test0());
    score += 0.5 * static_cast<double>(test1());
    score += 0.5 * static_cast<double>(test2());
    score += 0.5 * static_cast<double>(test3());
//     score += 0.5 * static_cast<double>(test4());
//     score += 0.5 * static_cast<double>(test5());
//     score += 1.6 * static_cast<double>(test6());
//     score += 1.7 * static_cast<double>(test7());
//     score += 1.8 * static_cast<double>(test8());
//     score += 1.9 * static_cast<double>(test9());

    cout << score * 10 << " / 100\n";

    return 0;
}