/* 
Do not use string class 
Do not use vectors 
No memory handling will remove you 10 points 
Uncompiling code will render your score to 0. 
Crashing code will decrease your score in 50% 
*/

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
