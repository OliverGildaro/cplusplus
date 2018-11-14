// This is a database in memory that can store objects.
// You can have several 'tables' (lists of objects) accessible by their name.
// Any "table" can have unlimited number of objects.
// You will be able to create tables, add objects to the tables, count number of tables and objects, filter, sort and find objects given an size_t ID.
// The memory_db will be in charge of releasing the objects stored into it.
//
// Restrictions:
// * Do not use anything we did not see in class. You can use std::string.
// * Memory leaks will cost you 10 points.
// * Program crashing will cost you 50 points.
// * Program not compiling will cost you 100% of your exam.
#include <iostream>
#include <string>

using namespace std;


class registry
{
private:
      size_t id;
      string name;
public:
      registry* next;
public:
      registry() { }
      registry(size_t id, const string& name)
      :id{id}, name{name} { }

      registry(const string& name)
      :name{name} { }

      virtual ~registry() { }

      string get_name() const
      {
            return name;
      }

      size_t get_id() const
      {
            return id;
      }
};

class linked_list
{
private:
      registry* first;
      registry* last;
      size_t count;
public:
      linked_list()
      :first{nullptr}, last{nullptr}, count{0} { }
      ~linked_list() { }

      void push_back(registry* new_regist)
      {
            if(first == nullptr)
            {
                  first = last = new_regist;
            }
            else{
                  last->next = new_regist;
                  last = new_regist;
            }
            count++;
      }

      size_t get_count()
      {
            return count;
      }

      registry* find(const string& name)
      {
            registry* cursor = first;

            while(cursor)
            {
                  if(cursor->get_name() == name)
                        return cursor;
                  cursor = cursor->next;
            }
            return nullptr;
      }

      registry* find(size_t id)
      {
            registry* cursor = first;

            while(cursor)
            {
                  if(cursor->get_id() == id)
                        return cursor;
                  cursor = cursor->next;
            }
            return nullptr;
      }

      registry* get(size_t pos)
      {
            registry* cursor = first;
            size_t aux_pos=0;
            while(cursor)
            {
                  if(aux_pos == pos)
                  {
                        return cursor;
                  }
                  aux_pos++;
                  cursor = cursor->next;
            }
            return nullptr;          
      }
};

class table : public registry
{
private:
      linked_list list;
public:
      table() { }
      table(const string& name)
      :registry{name} { }
      ~table() { }

      void  push_back(registry* new_regist)
      {
            list.push_back(new_regist);
      }

      size_t get_count()
      {
            return list.get_count();
      }

      registry* find(const string& name)
      {
            return list.find(name);
      }

      registry* find(size_t id)
      {
            return list.find(id);
      }

      registry& get(size_t pos)
      {
            registry* current = list.get(pos);
            return *current;
      }
};


class student : public registry
{
private:
      string last_name;
      registry regist;
public:
      student(size_t id, const string& name, const string& last_name)
      :registry{id, name}, last_name{last_name} { }
      ~student() { }

      string get_last_name()
      {
            return last_name;
      }

      string get_first_name()
      {
            return regist.get_name();
      }
};


class course : public registry
{
private:
      
public:
      course(size_t id, const string& name)
      :registry{id, name} { }
      ~course() { }
};

class memory_db
{
private:
      table tables;
public:
      memory_db() { }
      ~memory_db() { }

      void create_table(const string& table_name)
      {
            table* new_table = new table{table_name};
            tables.push_back(new_table);
      }    

      size_t get_table_count()
      {
            return tables.get_count();
      }

      bool add_object(const string& table_name, registry* new_regist)
      {
            table* current = static_cast<table*>(tables.find(table_name));

            if(current)
            {
                  current->push_back(new_regist);
                  return true;
            }
            else
                  return false;
      }

      size_t get_object_count(const string& table_name)
      {
            table* current = static_cast<table*>(tables.find(table_name));

            if(current)
            {
                  return current->get_count();
            }
            return 0;
      }

      registry* find(const string& table_name, size_t id)
      {
            table* current = static_cast<table*>(tables.find(table_name));

            if(current)
            {
                  return current->find(id);
            }
      }

      table get_all(const string& table_name)
      {
            table* current = static_cast<table*>(tables.find(table_name));

            if(current)
            {
                  return *current;
            }
            return table{table_name};           
      }

      table select_from(const string& table_name, bool(*function)(const string&))
      {
            table view{"my_table"};
            table* current = static_cast<table*>(tables.find(table_name));

            if(current)
            {
                  for(size_t i = 0; i < current->get_count(); i++)
                  {
                        student &current_student = static_cast<student&>(current->get(i));
                        if(function(current_student.get_last_name()))
                        {
                              view.push_back(new student{current_student});
                        }
                  }
            }
            return view;
      }

      table order_by(const string &tableName, bool (*FUNCION)(const string&, const string&))
      {
            registry* current_regist = (tables.find(tableName));
            if (current_regist)
            {
                  table result{"select"};
                  table *current_table = static_cast<table*>(current_regist);
                  size_t *arrayPos = new size_t[current_table->get_count()];
                  size_t arrayCount = 0;
                  for (size_t i = 0U; i < current_table->get_count(); ++i)
                  {
                        student &estudiante = (static_cast<student&>(current_table->get(i)));
                        bool flag = true;
                        if (i != 0)
                        {
                              for (int j = arrayCount-1; j >= 0; --j)
                              {
                                    if(FUNCION(estudiante.get_name(),current_table->get(arrayPos[j]).get_name()))
                                    {
                                          int aux = arrayPos[j];
                                          arrayPos[j] = i;
                                          arrayPos[j+1] = aux;
                                          flag = false;
                                    }
                              }
                        }
                        if (flag)
                        {
                              arrayPos[arrayCount] = i;
                        }
                        arrayCount++;
                  }
                  for (size_t i = 0; i < arrayCount; ++i)
                  {
                  result.push_back(new student{(static_cast<student&>(current_table->get(arrayPos[i])))});
                  }
                  return result;
            }
            return table{"Error"};
      }
};

bool student_starts_with_pe(const string& name)
{
      if(name[0] == 'p' && name[1] == 'e')
            return true;
      else
            return false;
}

bool compare_by_first_name(const string &current, const string& previous)
{
      return current<previous;
}



bool test0()
{
      memory_db db;
      db.create_table("students");
      db.create_table("courses");

      return db.get_table_count() == 2;
}

bool test1()
{
      memory_db db;

      db.create_table("students");
      db.create_table("courses");

      bool r = db.add_object("students", new student(123, "juan", "perez"));
      r = db.add_object("students", new student(125, "gael", "garcia"));

      return r && db.get_object_count("students") == 2 && db.get_object_count("courses") == 0;
}

bool test2()
{
      memory_db db;

      db.create_table("students");
      bool r = db.add_object("courses", new course(1, "devint26"));
      return r == false; // false because 'courses' table does not exist in this db object
}

bool test3()
{
      memory_db db;

      db.create_table("students");
      db.add_object("students", new student(123, "juan", "perez"));
      db.add_object("students", new student(125, "gael", "garcia"));

      auto st = (student*) db.find("students", 125);

      return st != nullptr && st->get_last_name() == "garcia";
}

bool test4()
{
      memory_db db;

      db.create_table("students");
      db.create_table("courses");
      db.add_object("students", new student(123, "juan", "perez"));
      db.add_object("students", new student(125, "gael", "garcia"));
      db.add_object("courses", new course(1, "math"));
      db.add_object("students", new student(128, "luis", "miguel"));
      db.add_object("courses", new course(2, "physics"));
      db.add_object("students", new student(130, "marco", "peredo"));
      db.add_object("courses", new course(3, "chemistry"));

      auto list = db.get_all("friends");

      return list.get_count() == 0; // because "friends" table does not exist in this memory_db
}

bool test5()
{
      memory_db db;

      db.create_table("students");
      db.create_table("courses");
      db.add_object("students", new student(123, "juan", "perez"));
      db.add_object("students", new student(125, "gael", "garcia"));
      db.add_object("courses", new course(1, "math"));
      db.add_object("students", new student(128, "luis", "miguel"));
      db.add_object("courses", new course(2, "physics"));
      db.add_object("students", new student(130, "marco", "peredo"));
      db.add_object("courses", new course(3, "chemistry"));

      auto list = db.get_all("courses");
      // cout << list.get(0).get_id() << "\n";

      return list.get_count() == 3 && list.get(0).get_id() == 1 && list.get(1).get_id() == 2 && list.get(2).get_id() == 3;
}

bool test6()
{
      memory_db db;

      db.create_table("students");
      db.add_object("students", new student(123, "juan", "perez"));
      db.add_object("students", new student(125, "gael", "garcia"));
      db.add_object("students", new student(128, "luis", "miguel"));
      db.add_object("students", new student(130, "marco", "peredo"));

      auto list = db.select_from("students", student_starts_with_pe);

      return list.get_count() == 2 &&
                  ((student&)list.get(0)).get_last_name() == "perez" &&
                  ((student&)list.get(1)).get_last_name() == "peredo";
}

bool test7()
{
      return test6();
}


bool test8()
{
      memory_db db;

      db.create_table("students");
      db.add_object("students", new student(1, "jean michel", "jarre"));
      db.add_object("students", new student(1, "armin", "van buuren"));
      db.add_object("students", new student(1, "vince", "clarke"));
      db.add_object("students", new student(1, "chris", "lowe"));

      auto list = db.order_by("students", compare_by_first_name);

      return list.get_count() == 4 &&
                  ((student&)list.get(0)).get_first_name() == "armin" &&
                  ((student&)list.get(1)).get_first_name() == "chris" &&
                  ((student&)list.get(2)).get_first_name() == "jean michel" &&
                  ((student&)list.get(3)).get_first_name() == "vince";
}

bool test9()
{
      return test8();
}


int main()
{
      bool r[10];

      r[0] = test0();
      r[1] = test1();
      r[2] = test2();
      r[3] = test3();
      r[4] = test4();
      r[5] = test5();
      r[6] = test6();
      r[7] = test7();
      r[8] = test8();
      r[9] = test9();

      auto score = 0;

      for (int i = 0; i < 10; i++)
      {
            int sc = r[i] * 10;
            cout << "TEST " << i << ": Result: " << sc << "\n";
            score += sc;
      }

      puts("**************");
      cout << "TOTAL SCORE: " << score << "\n";

      // getchar();
      return 0;
}