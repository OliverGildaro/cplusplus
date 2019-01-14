/*
* Se les pide implementar una jerarquia de objetos DOM con soporte para documentos, elementos, texto y comentarios.
* La jerarquía debe ser capaz de serializarse.
* No utilizar colecciones ni la librería string de la librería estándar de C++.
* No usar la clase Object implementada en la clase ni la clase String.
* Programa con memory leaks tendrá 10 puntos menos.
* Programa con crashes tendrá 20 puntos menos.
* No enviar código que no compila. No se revisará.
*/
#include <iostream>
#include <cstring>
#define OPENB "<"
#define CLOSEB ">"
#define SLASH "/"
#define SPACE " "
using namespace std;

void my_concat(char *result, const char *src)
{
    size_t len = strlen(src);
    size_t lenR = strlen(result);
    memcpy(result+lenR,src,len+1);
}

enum XmlType
{
    xmlDocument,
    xmlElement,
    xmlText,
    xmlComment,
    xmlAttribute
};
struct Node
{
    char *content;
    XmlType type;
    Node(const char *src)
    {
        size_t len = strlen(src);
        content = new char[len+50];
        for (size_t i = 0U; i < len; ++i)
        {
            switch(src[i])
            {
                case '\"':my_concat(content, "&quot;");break;
                case '<':my_concat(content, "&lt;");break;
                case '>':my_concat(content, "&gt;");break;
                case '&':my_concat(content, "&amp;");break;
                default:char aux[1]{0};aux[0]=src[i];my_concat(content,aux);break;
            }
        }
    }
    Node(const char *key, const char *value)
    {
        size_t lenKey = strlen(key);
        size_t lenValue = strlen(key);
        content = new char[lenKey + lenValue + 10];
        my_concat(content, key);
        my_concat(content, "=\"");
        my_concat(content, value);
        my_concat(content, "\"");
    }
    virtual ~Node()
    {
        delete [] content;
    }
};

class Array
{
private:
    size_t count;
    size_t size;
    Node **items;
public:
    Array()
    :count{0}, size{5}, items{new Node*[size]}
    {}
    ~Array()
    {
        delete [] items;
        size = 0;
        count = 0;
    }
    void resize()
    {
        if (count == size)
        {
            size *= 2;
            Node **aux = new Node*[size];
            for (size_t i = 0U; i < count; ++i)
            {
                aux[i] = items[i];
            }
            delete [] items;
            items = aux;
        }
    }
    void push_back(Node *node)
    {
        resize();
        items[count++] = node;
    }
    size_t get_count()const
    {
        return count;
    }
    Node* operator[](const size_t &position)
    {
        if (position>=count)
        {
            return nullptr;
        }
        return items[position];
    }
};

class ArrayNode : public Node
{
private:
    Array childs;
public:
    ArrayNode(const char *src)
    :Node{src},childs{Array{}}
    {}
    virtual ~ArrayNode()
    {}
    size_t get_count()const
    {
        return childs.get_count();
    }
    Node* get(const size_t &position)
    {
        if (position>=childs.get_count())
        {
            return nullptr;
        }
        return childs[position];
    }
    void AppendChild(Node *element)
    {
        childs.push_back(element);
    }
};

class XmlText : public Node
{
public:
    XmlText(const char *src)
    :Node{src}
    {
        type = xmlText;
    }
    ~XmlText()
    {}
};

class XmlComment : public Node
{
public:
    XmlComment(const char *src)
    :Node{src}
    {
        type = xmlComment;
    }
    ~XmlComment()
    {}
};

class XmlAttribute : public Node
{
public:
    XmlAttribute(const char *key, const char* value)
    :Node{key, value}
    {
        type = xmlAttribute;
    }
    ~XmlAttribute()
    {}
};

class XmlElement : public ArrayNode
{
private:
    Array attributes;
public:
    XmlElement(const char *src)
    :ArrayNode{src}, attributes{Array{}}
    {
        type = xmlElement;
    }
    ~XmlElement()
    {}
    void SetAttribute(const char *key, const char *value)
    {
        XmlAttribute *aux = new XmlAttribute{key, value};
        attributes.push_back(aux);
    }
    size_t GetAttributeCount() const
    {
        return attributes.get_count();
    }
    Node *getAttribute(const size_t &position)
    {
        return attributes[position];
    }
};

class XmlDocument : public ArrayNode
{
public:
    XmlDocument(const char *src)
    :ArrayNode{src}
    {
        type = xmlDocument;
    }
    ~XmlDocument()
    {
    }
    void Serialize(char *source, bool flag = false)
    {
        char tabs[10];*tabs=0;
        real_serialize(source, this, flag, tabs);
    }
    void real_serialize(char *source, Node *element, bool flag, char* tabs)
    {
        char breakLine[1];*breakLine=0;
        if (flag)
        {
            my_concat(breakLine,"\n");
        }
        switch(element->type)
        {
            case xmlElement:
            {
                XmlElement *aux = static_cast<XmlElement*>(element);
                char real[80];*real=0;
                my_concat(real, aux->content);
                for (size_t i = 0U; i < aux->GetAttributeCount(); ++i)
                {
                    my_concat(real, " ");
                    my_concat(real, aux->getAttribute(i)->content);
                }
                if (aux->get_count() == 0)
                {
                    my_concat(source, tabs);
                    emptyLabel(source, real);
                    my_concat(source, breakLine);
                }
                else
                {
                    my_concat(source, tabs);
                    char tabsAux[10];*tabsAux=0;
                    my_concat(tabsAux, tabs);
                    openLabel(source, real);
                    my_concat(source, breakLine);
                    for (size_t i = 0U; i < aux->get_count(); ++i)
                    {
                        if (flag)
                        {
                            my_concat(tabs, "\t");
                        }
                        Node *node = static_cast<Node*>(aux->get(i));
                        real_serialize(source, node, flag, tabs);
                    }
                    my_concat(source, tabsAux);
                    closingLabel(source, aux->content);
                    my_concat(source, breakLine);
                    *tabs = 0;
                    my_concat(tabs,tabsAux);
                }
            }
            break;
            case xmlDocument:
            {
                ArrayNode *aux = static_cast<ArrayNode*>(element);
                if (aux->get_count() == 0)
                {
                    my_concat(source,tabs);
                    emptyLabel(source, aux->content);
                    my_concat(source, breakLine);
                }
                else
                {
                    openLabel(source, aux->content);
                    my_concat(source, breakLine);
                    for (size_t i = 0U; i < aux->get_count(); ++i)
                    {
                        Node *node = static_cast<Node*>(aux->get(i));
                        real_serialize(source, node, flag, tabs);
                    }
                    if (flag)
                    {
                        my_concat(tabs, "\t");
                    }
                    closingLabel(source, aux->content);
                    my_concat(source, breakLine);
                }
            }
            break;
            case xmlText:
                my_concat(source,tabs);
                my_concat(source,element->content);
                my_concat(source, breakLine);
            break;
            case xmlComment:
                my_concat(source,tabs);
                my_concat(source,"<!-- ");
                my_concat(source,element->content);
                my_concat(source," -->");
                my_concat(source, breakLine);
            break;
            case xmlAttribute:
                my_concat(source, " ");
                my_concat(source, element->content);
                my_concat(source, " ");
            break;
        }
        
    }
    void closingLabel(char* result, const char *source) const
    {
        my_concat(result, OPENB);
        my_concat(result, SLASH);
        my_concat(result, source);
        my_concat(result, CLOSEB);
    }
    void openLabel(char* result, const char *source) const
    {
        my_concat(result, OPENB);
        my_concat(result, source);
        my_concat(result, CLOSEB);
    }
    void emptyLabel(char* result, const char *source) const
    {
        my_concat(result, OPENB);
        my_concat(result, source);
        my_concat(result, SPACE);
        my_concat(result, SLASH);
        my_concat(result, CLOSEB);
    }
};

size_t test0()
{
    XmlDocument doc{ "SecondTest" };

    char aux[100]; *aux = 0;
    doc.Serialize(aux);
    return strcmp(aux, "<SecondTest />") == 0;
}

size_t test1()
{
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
}

size_t test3()
{
    XmlDocument doc{ "Carros" };

    char aux[100]; *aux = 0;
    doc.AppendChild(new XmlElement("Carro1"));

    auto carro2 = new XmlElement("Carro2");
    carro2->AppendChild(new XmlText("Ferrari"));
    carro2->AppendChild(new XmlElement("Portofino"));

    doc.AppendChild(carro2);
    doc.AppendChild(new XmlElement("Carro3"));
    doc.Serialize(aux);
    return strcmp(aux, "<Carros><Carro1 /><Carro2>Ferrari<Portofino /></Carro2><Carro3 /></Carros>") == 0;
}

size_t test4()
{
    char aux[500]; *aux = 0;

    XmlDocument doc{ "Alumnos" };

    auto alumno = new XmlElement("Alumno");
    auto nombre = new XmlElement("Nombre");
    auto apellido = new XmlElement("Apellido");
    nombre->AppendChild(new XmlText("Marilyn"));
    apellido->AppendChild(new XmlText("Manson"));
    alumno->AppendChild(nombre);
    alumno->AppendChild(apellido);
    doc.AppendChild(alumno);

    alumno = new XmlElement("Alumno");
    nombre = new XmlElement("Nombre");
    apellido = new XmlElement("Apellido");
    nombre->AppendChild(new XmlText("Jean Michel"));
    apellido->AppendChild(new XmlText("Jarre"));
    alumno->AppendChild(nombre);
    alumno->AppendChild(apellido);
    alumno->AppendChild(new XmlComment("This is the father of electronica music"));
    doc.AppendChild(alumno);

    doc.Serialize(aux);
    return strcmp(aux, "<Alumnos><Alumno><Nombre>Marilyn</Nombre><Apellido>Manson</Apellido></Alumno><Alumno><Nombre>Jean Michel</Nombre><Apellido>Jarre</Apellido><!-- This is the father of electronica music --></Alumno></Alumnos>") == 0;
}

size_t test5()
{
    XmlDocument doc{ "Tests" };

    char aux[200]; *aux = 0;

    auto e1 = new XmlElement("Test1");
    auto e2 = new XmlElement("Test2");
    doc.AppendChild(e1);
    doc.AppendChild(e2);

    e1->AppendChild(new XmlText("Say \"Hello\""));
    e2->AppendChild(new XmlText("C & C Music Factory <<<The music>>"));

    doc.Serialize(aux);
    return strcmp(aux, "<Tests><Test1>Say &quot;Hello&quot;</Test1><Test2>C &amp; C Music Factory &lt;&lt;&lt;The music&gt;&gt;</Test2></Tests>") == 0;
}

size_t test6()
{
    return test5();
}

size_t test7()
{
    char aux[500]; *aux = 0;

    XmlDocument doc{ "Cantantes" };

    auto cantante = new XmlElement("Cantante");
    cantante->SetAttribute("nombre", "Taylor");
    cantante->SetAttribute("apellido", "Swift");
    doc.AppendChild(cantante);

    cantante = new XmlElement("Cantante");
    cantante->SetAttribute("nombre", "Justin");
    cantante->SetAttribute("apellido", "Timberlake");
    cantante->AppendChild(new XmlComment("Comment; elements"));
    doc.AppendChild(cantante);

    doc.Serialize(aux);
    return strcmp(aux, "<Cantantes><Cantante nombre=\"Taylor\" apellido=\"Swift\" /><Cantante nombre=\"Justin\" apellido=\"Timberlake\"><!-- Comment; elements --></Cantante></Cantantes>") == 0;
}


size_t test8()
{
    char aux[500]; *aux = 0;

    XmlDocument doc{ "Alumnos" };

    auto alumno = new XmlElement("Alumno");
    auto nombre = new XmlElement("Nombre");
    auto apellido = new XmlElement("Apellido");
    nombre->AppendChild(new XmlText("Marilyn"));
    apellido->AppendChild(new XmlText("Manson"));
    alumno->AppendChild(nombre);
    alumno->AppendChild(apellido);
    doc.AppendChild(alumno);

    alumno = new XmlElement("Alumno");
    nombre = new XmlElement("Nombre");
    apellido = new XmlElement("Apellido");
    nombre->AppendChild(new XmlText("Jean Michel"));
    apellido->AppendChild(new XmlText("Jarre"));
    alumno->AppendChild(nombre);
    alumno->AppendChild(apellido);
    alumno->AppendChild(new XmlComment("This is the father of electronica music"));
    doc.AppendChild(alumno);

    doc.Serialize(aux, true);

    puts(aux);

    return strcmp(aux,
        "<Alumnos>\n"
        "    <Alumno>\n"
        "        <Nombre>\n"
        "            Marilyn\n"
        "        </Nombre>\n"
        "        <Apellido>\n"
        "            Manson\n"
        "        </Apellido>\n"
        "    </Alumno>\n"
        "    <Alumno>\n"
        "        <Nombre>\n"
        "            Jean Michel\n"
        "        </Nombre>\n"
        "        <Apellido>\n"
        "            Jarre\n"
        "        </Apellido>\n"
        "        <!-- This is the father of electronica music -->\n"
        "    </Alumno>\n"
        "</Alumnos>\n") == 0;
}

size_t test9()
{
    return false;
    // return test8();
}


using test_type = size_t(*)();

auto main() -> int
{
        test_type ts[] = {
                test0, test1, test2, test3, test4,
                test5, test6, test7, test8, test9 };

        size_t score = 0U, i = 0U;
        for (auto& t : ts)
        {
                auto scoret = t();
                printf("Test %zu: %zu / 1\n", i++, scoret);
                score += scoret;
        }
        puts("-----------------");
        printf("SCORE: %zu / 10\n", score);
        getchar();
        return 0;
}