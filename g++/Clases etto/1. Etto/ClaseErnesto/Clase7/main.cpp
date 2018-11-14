#include <iostream>
#include <string> //cstring y string.h son lo mismo y tienen strcpy, strlen...
//string -> basicstring
//los que no son tipo primitivos es buena practica pasarlos por referencia
using namespace std;
//CLASES ABSTRACTAS
class Employe
{
	string name;
	string role;

	public:
		Employe(const string& name, const string& role): name{name}, role{role}
		{

		}

		const string& get_name() const
		{
			return name;
		}

		const string& get_role() const //const significa que no se puede modificar el atributo
		{
			return role;
		}

		virtual void show_job() const = 0; //estamos diciendo que el metodo es abstracto, toda la clase se vuelve abstracta
									//debe ser implementado en la clase hija
		virtual ~Employe(){}//un virtual requiere su constructor

};

class Limpiador : public Employe
{
	public:
		Limpiador(const string& n) : Employe{n,"limpiando"}
		{
			//desde constructor nunca llamar a metodos virtuales
		}

		void show_job() const override
		{
			cout<<"limpiar"<<"\n";
		}


};

class Boss : public Employe
{
	public:
		Boss(const string& n) : Employe(n,"boss")
		{
			//desde constructor nunca llamar a metodos virtuales
		}

		void show_job() const override
		{
			cout<<"ZZZZ"<<"\n";
		}
};

void print(const Employe& e)
{
	cout<<e.get_name()<<"\n";
	cout<<e.get_role()<<"\n";

	e.show_job();

}

int main()
{
	Boss s{"juan perez"};
	s.show_job();

	print(s);
}