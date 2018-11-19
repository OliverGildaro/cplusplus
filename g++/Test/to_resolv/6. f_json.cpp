
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

// bool test3()
// {
//     json_string j { "hello world" };
//     return j.to_string() == "\"hello world\""; }

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
//     score += 0.5 * static_cast<double>(test3());
//     score += 0.5 * static_cast<double>(test4());
//     score += 0.5 * static_cast<double>(test5());
//     score += 1.6 * static_cast<double>(test6());
//     score += 1.7 * static_cast<double>(test7());
//     score += 1.8 * static_cast<double>(test8());
//     score += 1.9 * static_cast<double>(test9());

    cout << score * 10 << " / 100\n";

    return 0;
}