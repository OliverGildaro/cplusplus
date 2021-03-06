/* 
Do not use string class 
Do not use vectors 
No memory handling will remove you 10 points 
Uncompiling code will render your score to 0. 
Crashing code will decrease your score in 50% 
*/
#include <iostream>
#include <cstring>

using namespace std;

struct node
{
      char* word;
      node* next;

      void print()
      {
            cout << word << "\n";
      }
};

class linked_list
{
private:
      node* first;
      node* last;
      size_t count;
public:
      linked_list(/* args */)
      :first{nullptr}, last{nullptr}, count{0} { }
      ~linked_list() { }

      void push_back(const char* tok)
      {
            char* real_word = new char[strlen(tok)+1];
            memcpy(real_word, tok, strlen(tok)+1);

            node* new_node = new node{real_word, nullptr};

            if(first == nullptr)
            {
                  first = last = new_node;
            }
            else
            {
                  last->next = new_node;
                  last = new_node;
            }
            count++;
      }

      node get_most_frequent_words()
      {
            node* cursor = first;
            node* aux_node = first;
            node* real_max = nullptr;
            size_t max_count = 0;

            for(size_t i = 0; i < count; i++)
            {
                  const char* aux_word = cursor->word;
                  size_t aux_count = 0;

                  while(cursor)
                  {
                        if(strcmp(cursor->word, aux_word)==0)
                        {
                              aux_count++;
                        }
                        cursor = cursor->next;
                  }
                  if(aux_count>max_count)
                  {
                        max_count = aux_count;
                        real_max = aux_node;
                  }
                  aux_node = aux_node->next;
                  cursor = aux_node;
            }
            return *real_max;
      }

      node get_least_frequent_words()
      {
            node* cursor = first;
            node* aux_node = first;
            node* real_min = nullptr;
            size_t min_count = 10;

            for(size_t i = 0; i < count; i++)
            {
                  const char* aux_word = cursor->word;
                  size_t aux_count = 0;

                  while(cursor)
                  {
                        if(strcmp(cursor->word, aux_word)==0)
                        {
                              aux_count++;
                        }
                        cursor = cursor->next;
                  }
                  if(aux_count<min_count)
                  {
                        min_count = aux_count;
                        real_min = aux_node;
                  }
                  aux_node = aux_node->next;
                  cursor = aux_node;
            }
            return *real_min;
      }

      size_t get_char_count()
      {
            node* cursor = first;
            char letter;

            char array[100];
            size_t j = 0;
            while(cursor)
            {
                  size_t i = 0;
                  while(i < strlen(cursor->word))
                  {
                        letter = cursor->word[i];
                        bool band = false;
                        
                        for(size_t k = 0; k < 100; k++)
                        {
                              if(letter == array[k])
                                    band = true;
                        }
                        if(band == false)
                              array[j++] = letter;
                        
                        i++;
                  }
                  cursor = cursor->next;
            }
            return j;
      }

      size_t count_caracter(const char* word)
      {
            size_t count_c =0;
            while(*word++)
            {
                  count_c++;
            }
            return count_c;
      }

      size_t get_letter_count(bool(*FUNCTION)(char))
      {
           node* cursor = first;
            
            size_t count_dig = 0;
            while(cursor){
                  size_t c = count_caracter(cursor->word);
                  size_t i=0;
                  do{
                        if(FUNCTION(cursor->word[i]))
                              count_dig++;
                        i++;
                  }while(i < c);
                  cursor = cursor->next;
            }
            return count_dig;           
      }

      size_t get_digit_count(bool(*FUNCTION)(char))
      {
            node* cursor = first;
            
            size_t count_dig = 0;
            while(cursor){
                  size_t c = count_caracter(cursor->word);
                  size_t i=0;
                  do{
                        if(FUNCTION(cursor->word[i]))
                              count_dig++;
                        i++;
                  }while(i < c);
                  cursor = cursor->next;
            }
            return count_dig;
      }

      size_t get_word_count()
      {
            return count;
      }

      size_t get_frequency_by_word(const char* word_name)
      {
            size_t len = strlen(word_name);
            char* aux_name = new char[len+1];
            memcpy(aux_name, word_name, len+1);

            node* cursor = first;
            size_t count_word = 0;
            while(cursor)
            {
                  if(strcmp(cursor->word, aux_name)==0)
                        count_word++;
                  cursor = cursor->next;
            }
            return count_word;
      }
      

      void print_all_frequencies()
      {
            node* cursor = first;

            while(cursor)
            {
                  size_t count_w = get_frequency_by_word(cursor->word);
                  cout << "Word: " << cursor->word << " -> " << "Count: " << count_w << "\n";
                  cursor = cursor->next;
            }
      }

      void add_word(const char* p_word)
      {
            size_t len = strlen(p_word);
            char* aux_word = new char[len+1];
            memcpy(aux_word, p_word, len+1);

            node* new_node = new node{aux_word, nullptr};

            if(first == nullptr)
            {
                  cout << "hola nullptr\n";
            }

      }
};


bool verif_digit(char digit)
{
      bool band = false;
      const char* abc = "0123456789";
      while(*abc)
      {
            if(*abc == digit)
            {
                  band = true;
                  return band;
            }
            abc++;
      }
      return band;
}

bool verif_letters(char letter)
{
      bool band = false;
      const char* abc = "abcdefghijklmnopqrstuvwxyz";
      while(*abc)
      {
            if(*abc == letter)
            {
                  band = true;
                  return band;
            }
            abc++;
      }
      return band;
}

class text_processor
{
private:
      char* text;
      size_t len;
      linked_list list;
public:
      text_processor(const char* text)
      :len{strlen(text)}  
      {
            this->text = new char[len+1];
            memcpy(this->text, text, len+1);
            tokenizer();
      }
      ~text_processor() { }

      void tokenizer()
      {
            char* tok = strtok(text, " -,.'");

            while(tok)
            {
                  list.push_back(tok);
                  tok = strtok(nullptr, " -,.'");
            }
      }

      node get_most_frequent_words()
      {
            return list.get_most_frequent_words();
      }

      node get_least_frequent_words()
      {
            return list.get_least_frequent_words();
      }

      size_t get_char_count()
      {
            return list.get_char_count();
      }

      size_t get_letter_count()
      {
            return list.get_letter_count(verif_letters);
      }

      size_t get_digit_count()
      {
            return list.get_digit_count(verif_digit);
      }

      size_t get_word_count()
      {
            return list.get_word_count();
      }

      size_t get_frequency_by_word(const char* word_name)
      {
            list.get_frequency_by_word(word_name);
      }

      void print_all_frequencies()
      {
            list.print_all_frequencies();
      }

      text_processor add_word(const char* p_word)
      {
            return text_processor{p_word};
      }
};

int main()
{
    text_processor ts { "hp and asus have announced the first windows 10 pcs running on arm - snapdragon 835 - and they're boasting about instant-on, 22 hour battery life, and gigabit lte. these machines run full windows 10 - so not some crippled windows rt nonsense - and support 32bit x86 applications. microsoft hasn't unveiled a whole lot just yet about their x86-on-arm emulation, but ars did compile some information. "
                    "the emulator runs in a just-in-time basis, converting blocks of x86 code to equivalent blocks of arm code. this conversion is cached both in memory (so each given part of a program only has to be translated once per run) and on disk (so subsequent uses of the program should be faster, as they can skip the translation). moreover, system libraries - the various dlls that applications load to make use of operating system feature - are all native arm code, including the libraries loaded by x86 programs. calling them compiled hybrid portable executables (or 'chippie' for short), these libraries are arm native code, compiled in such a way as to let them respond to x86 function calls."
                    "while processor-intensive applications are liable to suffer a significant performance hit from this emulation - photoshop will work in the emulator, but it won't be very fast - applications that spend a substantial amount of time waiting around for the user - such as word - should perform with adequate performance. as one might expect, this emulation isn't available in the kernel, so x86 device drivers won't work on these systems. it's also exclusively 32-bit; software that's available only in a 64-bit x86 version won't be compatible. " };
    
    ts.add_word("asus").add_word("asus").add_word("asus").add_word("asus").add_word("asus").add_word("asus");
    cout<<"-------------------------------------------------------------------------------------------------------\n";
    ts.print_all_frequencies();
    cout << "10 points\n\n";

    ts.get_most_frequent_words().print();//devolver la palabra que mas se repite          
    cout << "5 points\n\n";
    
    ts.get_least_frequent_words().print();//devolver la palabra que menos se repite
    cout << "5 points\n\n";

    cout << ts.get_char_count() << "\n";//contar cuantos tipos de caracteres existe en la lista
    cout << "10 points\n\n";

    cout << ts.get_letter_count() << "\n";//devolver la cantidad de letras del texto
    cout << "10 points\n\n";

    cout << ts.get_digit_count() << "\n";//devolver la cantidad de digitos del texto
    cout << "10 points\n\n";


    cout << ts.get_word_count() << "\n";//contar cuantas palabras hay en el texto
    cout << "10 points\n\n";

    cout << ts.get_frequency_by_word("emulator") << "\n";
    cout << "10 points\n\n";


    cout << ts.get_frequency_by_word("atari") << "\n";
    cout << "10 points\n\n";

    ts.print_all_frequencies();
    cout << "10 points\n\n";


    return 0;
}
