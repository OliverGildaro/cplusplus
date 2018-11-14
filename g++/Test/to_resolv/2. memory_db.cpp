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

// bool test2()
// {
//       memory_db db;

//       db.create_table("students");
//       bool r = db.add_object("courses", new course(1, "devint26"));
//       return r == false; // false because 'courses' table does not exist in this db object
// }

// bool test3()
// {
//       memory_db db;

//       db.create_table("students");
//       db.add_object("students", new student(123, "juan", "perez"));
//       db.add_object("students", new student(125, "gael", "garcia"));

//       auto st = (student*) db.find("students", 125);

//       return st != nullptr && st->get_last_name() == "garcia";
// }

// bool test4()
// {
//       memory_db db;

//       db.create_table("students");
//       db.create_table("courses");
//       db.add_object("students", new student(123, "juan", "perez"));
//       db.add_object("students", new student(125, "gael", "garcia"));
//       db.add_object("courses", new course(1, "math"));
//       db.add_object("students", new student(128, "luis", "miguel"));
//       db.add_object("courses", new course(2, "physics"));
//       db.add_object("students", new student(130, "marco", "peredo"));
//       db.add_object("courses", new course(3, "chemistry"));

//       auto list = db.get_all("friends");

//       return list.get_count() == 0; // because "friends" table does not exist in this memory_db
// }

// bool test5()
// {
//       memory_db db;

//       db.create_table("students");
//       db.create_table("courses");
//       db.add_object("students", new student(123, "juan", "perez"));
//       db.add_object("students", new student(125, "gael", "garcia"));
//       db.add_object("courses", new course(1, "math"));
//       db.add_object("students", new student(128, "luis", "miguel"));
//       db.add_object("courses", new course(2, "physics"));
//       db.add_object("students", new student(130, "marco", "peredo"));
//       db.add_object("courses", new course(3, "chemistry"));

//       auto list = db.get_all("courses");

//       return list.get_count() == 3 && list.get(0).get_id() == 1 && list.get(1).get_id() == 2 && list.get(2).get_id() == 3;
// }

// bool test6()
// {
//       memory_db db;

//       db.create_table("students");
//       db.add_object("students", new student(123, "juan", "perez"));
//       db.add_object("students", new student(125, "gael", "garcia"));
//       db.add_object("students", new student(128, "luis", "miguel"));
//       db.add_object("students", new student(130, "marco", "peredo"));

//       auto list = db.select_from("students", student_starts_with_pe);

//       return list.get_count() == 2 &&
//                   ((student&)list.get(0)).get_last_name() == "perez" &&
//                   ((student&)list.get(1)).get_last_name() == "peredo";
// }

// bool test7()
// {
//       return test6();
// }


// bool test8()
// {
//       memory_db db;

//       db.create_table("students");
//       db.add_object("students", new student(1, "jean michel", "jarre"));
//       db.add_object("students", new student(1, "armin", "van buuren"));
//       db.add_object("students", new student(1, "vince", "clarke"));
//       db.add_object("students", new student(1, "chris", "lowe"));

//       auto list = db.order_by("students", compare_by_first_name);

//       return list.get_count() == 4 &&
//                   ((student&)list.get(0)).get_first_name() == "armin" &&
//                   ((student&)list.get(1)).get_first_name() == "chris" &&
//                   ((student&)list.get(2)).get_first_name() == "jean michel" &&
//                   ((student&)list.get(3)).get_first_name() == "vince";
// }

// bool test9()
// {
//       return test8();
// }


int main()
{
      bool r[10];

      r[0] = test0();
      r[1] = test1();
      // r[2] = test2();
      // r[3] = test3();
      // r[4] = test4();
      // r[5] = test5();
      // r[6] = test6();
      // r[7] = test7();
      // r[8] = test8();
      // r[9] = test9();

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