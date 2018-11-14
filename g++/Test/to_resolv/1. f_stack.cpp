// Implement a f_stack<T> (LIFO) class.

// Implement a RPN evaluator class. (1 2 +) will push 1 and 2 in a stack, and the operator + will remove  them and push into them the result of adding them up. It will support the 4 basic operations.

// You can use everything seen at class, but no other stuff.

// Not compiling code will render your exam useless.

// Having memory leaks will subtract 10 points to your last score.

// Do not use inheritance, polymorphism or any virtual thing.

bool test0()

{
    f_stack<int> st;

    auto r1 = st.is_empty();

    st.push(10);

    auto r2 = st.is_empty();

    return r1 && !r2;
}

bool test1()

{
    f_stack<int> st;

    st.push(50);

    st.push(40);

    st.push(25);

    return st.pop() == 25 && st.pop() == 40; 
}

// bool test2()

// {
//     f_stack<string> s;

//     s.push("easy");
//     s.push("was");
//     s.push("exam");
//     s.push("second");

//     auto s4 = s.pop();
//     auto s3 = s.pop();
//     auto s2 = s.pop();
//     auto s1 = s.pop();

//     return s4 == "second" && s3 == "exam" && s2 == "was" && s1 == "easy" && s.is_empty(); 
//     return 0;
// }

// bool test3()

// {

//     f_stack<string> sd;

//     sd.push("devices");
//     sd.push("own");
//     sd.push("my");
//     sd.push("to");
//     sd.push("left");

//     string accum;

//     sd.iterate([&accum](auto& x)
//     {
//         accum += x + " ";
//     });

//     string accum2;

//     sd.iterate([&accum2](auto& x)
//     {
//         accum2 += x + " ";
//     });


//     return accum == accum2 && accum == "left to my own devices ";
//     return 0;
// }

// bool test4()
// {
//     try
//     {
//     cout << "entra" << endl;

//         f_stack<string> x;

//         x.push("hello");
//         x.push("world");

//         x.pop();
//         x.pop();
//         x.pop();

//         return false;
//     }

//     catch (const std::exception& ex)
//     {
//         return "Attempt to pop value from empty stack"s == ex.what();
//     }
// }



// bool test5()
// {

//     string result;

//     split_string(' ', "abc def ghi jkl", [&result](auto& s)

//     {
//         result += s + "; ";
//     });

//     return result == "abc; def; ghi; jkl; ";
//     return 0;
// }



// bool test6()

// {

//     evaluator m;

//     return m.evaluate("10 30 +") == 40;

// }



// bool test7()

// {

//     evaluator x;

//     return x.evaluate("10 20 50 + *") == 700; }



// bool test8()

// {

//     try

//     {

//         evaluator x;

//         x.evaluate("10 20 + +");

//         return false;

//     }

//     catch (const exception& x)

//     {

//         return "Operand not found"s == x.what();

//     }

// }



// bool test9()

// {

//     evaluator x;

//     x.add_operator("min", [](auto& x, auto& y)

//     {

//         return x < y ? x : y;

//     });



//     return x.evaluate("5 3 * 10 20 - min") == 15; }



using test = bool(*)();



auto main() -> int

{

    test tests[] = { test0,

                     test1,

                  //    test2,

                  //    test3,

                  //    test4,

                  //    test5,

                     // test6,

                     // test7,

                     // test8,

                     // test9

    };



    size_t score = 0;

    for (auto& t : tests)

    {

        score += t() * 10;

    }



    cout << "Score: " << score << " / 100\n";

    getchar();

    return 0;

}