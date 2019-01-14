/*
* Se les pide implementar una jerarquia de objetos DOM con soporte para documentos, elementos, texto y comentarios.
* La jerarquía debe ser capaz de serializarse.
* No utilizar colecciones ni la librería string de la librería estándar de C++.
* No usar la clase Object implementada en la clase ni la clase String.
* Programa con memory leaks tendrá 10 puntos menos.
* Programa con crashes tendrá 20 puntos menos.
* No enviar código que no compila. No se revisará.
*/


size_t test0()
{
    XmlDocument doc{ "SecondTest" };

    char aux[100]; *aux = 0;
    doc.Serialize(aux);
    return strcmp(aux, "<SecondTest />") == 0;
    // return 0;

}

size_t test1()
{
    // return 0;   
    XmlDocument doc{ "Carros" };

    char aux[100]; *aux = 0;
    doc.AppendChild(new XmlElement("Carro1"));
    doc.AppendChild(new XmlElement("Carro2"));
    doc.AppendChild(new XmlElement("Carro3"));
    doc.Serialize(aux);
    return strcmp(aux, "<Carros><Carro1 /><Carro2 /><Carro3 /></Carros>") == 0;

}

size_t test2()
{
    XmlDocument doc{ "Nombre" };
    char aux[100]; *aux = 0;
    doc.AppendChild(new XmlText("Trent Reznor"));
    doc.Serialize(aux);
    return strcmp(aux, "<Nombre>Trent Reznor</Nombre>") == 0;
    // return 0;

}

// size_t test3()
// {
//     // return 0;

//     XmlDocument doc{ "Carros" };

//     char aux[100]; *aux = 0;
//     doc.AppendChild(new XmlElement("Carro1"));

//     auto carro2 = new XmlElement("Carro2");
//     carro2->AppendChild(new XmlText("Ferrari"));
//     carro2->AppendChild(new XmlElement("Portofino"));

//     doc.AppendChild(carro2);
//     doc.AppendChild(new XmlElement("Carro3"));
//     doc.Serialize(aux);
//     return strcmp(aux, "<Carros><Carro1 /><Carro2>Ferrari<Portofino /></Carro2><Carro3 /></Carros>") == 0;

// }

// size_t test4()
// {
//     // return 0;

//     char aux[500]; *aux = 0;

//     XmlDocument doc{ "Alumnos" };

//     auto alumno = new XmlElement("Alumno");
//     auto nombre = new XmlElement("Nombre");
//     auto apellido = new XmlElement("Apellido");
//     nombre->AppendChild(new XmlText("Marilyn"));
//     apellido->AppendChild(new XmlText("Manson"));
//     alumno->AppendChild(nombre);
//     alumno->AppendChild(apellido);
//     doc.AppendChild(alumno);

//     alumno = new XmlElement("Alumno");
//     nombre = new XmlElement("Nombre");
//     apellido = new XmlElement("Apellido");
//     nombre->AppendChild(new XmlText("Jean Michel"));
//     apellido->AppendChild(new XmlText("Jarre"));
//     alumno->AppendChild(nombre);
//     alumno->AppendChild(apellido);
//     alumno->AppendChild(new XmlComment("This is the father of electronica music"));
//     doc.AppendChild(alumno);

//     doc.Serialize(aux);

//     return strcmp(aux, "<Alumnos><Alumno><Nombre>Marilyn</Nombre><Apellido>Manson</Apellido></Alumno><Alumno><Nombre>Jean Michel</Nombre><Apellido>Jarre</Apellido><!-- This is the father of electronica music --></Alumno></Alumnos>") == 0;

// }

// size_t test5()
// {
//     // return 0;
//     XmlDocument doc{ "Tests" };

//     char aux[200]; *aux = 0;

//     auto e1 = new XmlElement("Test1");
//     auto e2 = new XmlElement("Test2");
//     doc.AppendChild(e1);
//     doc.AppendChild(e2);

//     e1->AppendChild(new XmlText("Say \"Hello\""));
//     e2->AppendChild(new XmlText("C & C Music Factory <<<The music>>"));

//     doc.Serialize(aux);
//     return strcmp(aux, "<Tests><Test1>Say &quot;Hello&quot;</Test1><Test2>C &amp: C Music Factory &lt;&lt;The music&gt;&gt;</Test2><Tests>") == 0;

// }

// size_t test6()
// {
//     return test5();
// }

// size_t test7()
// {
//     char aux[500]; *aux = 0;

//     XmlDocument doc{ "Cantantes" };

//     auto cantante = new XmlElement("Cantante");
//     cantante->SetAttribute("nombre", "Taylor");
//     cantante->SetAttribute("apellido", "Swift");
//     doc.AppendChild(cantante);

//     cantante = new XmlElement("Cantante");
//     cantante->SetAttribute("nombre", "Justin");
//     cantante->SetAttribute("apellido", "Timberlake");
//     cantante->AppendChild(new XmlComment("Comment; elements"));
//     doc.AppendChild(cantante);

//     doc.Serialize(aux);

//     return strcmp(aux, "<Cantantes><Cantante nombre=\"Taylor\" apellido=\"Swift\" /><Cantante nombre=\"Justin\" apellido=\"Timberlake\"><!-- Comment; elements --></Cantante></Cantantes>") == 0;

// }


// size_t test8()
// {
//     char aux[500]; *aux = 0;

//     XmlDocument doc{ "Alumnos" };

//     auto alumno = new XmlElement("Alumno");
//     auto nombre = new XmlElement("Nombre");
//     auto apellido = new XmlElement("Apellido");
//     nombre->AppendChild(new XmlText("Marilyn"));
//     apellido->AppendChild(new XmlText("Manson"));
//     alumno->AppendChild(nombre);
//     alumno->AppendChild(apellido);
//     doc.AppendChild(alumno);

//     alumno = new XmlElement("Alumno");
//     nombre = new XmlElement("Nombre");
//     apellido = new XmlElement("Apellido");
//     nombre->AppendChild(new XmlText("Jean Michel"));
//     apellido->AppendChild(new XmlText("Jarre"));
//     alumno->AppendChild(nombre);
//     alumno->AppendChild(apellido);
//     alumno->AppendChild(new XmlComment("This is the father of electronica music"));
//     doc.AppendChild(alumno);

//     doc.Serialize(aux, true);

//     puts(aux);

//     return strcmp(aux,
//         "<Alumnos>\n"
//         "    <Alumno>\n"
//         "        <Nombre>\n"
//         "            Marilyn\n"
//         "        </Nombre>\n"
//         "        <Apellido>\n"
//         "            Manson\n"
//         "        </Apellido>\n"
//         "    </Alumno>\n"
//         "    <Alumno>\n"
//         "        <Nombre>\n"
//         "            Jean Michel\n"
//         "        </Nombre>\n"
//         "        <Apellido>\n"
//         "            Jarre\n"
//         "        </Apellido>\n"
//         "        <!-- This is the father of electronica music -->\n"
//         "    </Alumno>\n"
//         "</Alumnos>\n") == 0;
// }

// size_t test9()
// {
//         return test8();
// }


using test_type = size_t(*)();

auto main() -> int
{
        test_type ts[] = {
                            test0,
                            test1,
                            // test2,
                            // test3,
                            // test4,
                            // test5,
                            // test6,
                            // test7,
                            // test8,
                            // test9 
                         };

        auto score = 0U, i = 0U;
        for (auto& t : ts)
        {
                auto scoret = t();
                printf("Test %zu: %zu / 1\n", i++, scoret);
                score += scoret;
        }
        puts("-----------------");
        printf("SCORE: %zu / 10\n", score);
        return 0;
}

