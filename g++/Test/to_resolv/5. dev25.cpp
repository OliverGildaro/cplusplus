
int test0()
{
dev25vm vm;
init_vm(&vm);

opcodes prog[] = { push, 5, push, 9, add };

int val;
int r = run_vm(&vm, prog, 5, &val);
end_vm(&vm);

return r && val == 14;
}

int test1()
{
dev25vm vm;
init_vm(&vm);

opcodes prog[] = { push, 5, push, 0, div }; // divide by zero should return error

int val;
int r = run_vm(&vm, prog, 5, &val);
end_vm(&vm);

return r == 0;
}

int test2()
{
dev25vm vm;
init_vm(&vm);

opcodes prog[] = { push, 5, nop, nop, push, 4, push, 6, add, mul }; // divide by zero should return error

int val;
int r = run_vm(&vm, prog, 10, &val);
end_vm(&vm);

return r && val == 50;
}

int test3()
{
dev25vm vm;
init_vm(&vm);

opcodes prog[] = { push, 1, inc, inc, inc };

int val;
int r = run_vm(&vm, prog, 5, &val);
end_vm(&vm);

return r && val == 4;
}

int test4()
{
dev25vm vm;
init_vm(&vm);

//x0 = 10;
//x1 = 20;
//if (x0 > x1) return x0 else x1;
opcodes prog[] = { load0, 10, load1, 20, push0, push1, jmp_if_greater, 10, push0, ret, push1 };

int val;
int r = run_vm(&vm, prog, 11, &val);
end_vm(&vm);

return r && val == 20;
}

int test5()
{
dev25vm vm;
init_vm(&vm);

//int i = 0
//int s = 0
//while (i < 5)
// s += i
// return s
opcodes prog[] = { load0, 0, load1, 0, push0, push, 5, jmp_if_greater_or_equal, 15, push1, push0, add, pop1, jmp, 4, push1 };

int val;
int r = run_vm(&vm, prog, 16, &val);
end_vm(&vm);

return r && val == 15;
}

int test6()
{
return test5();
}

int test7()
{
dev25vm vm;
init_vm(&vm);

//int n = 1
//for (int i = 2; i <= 6; i++)
// n *= i;
//return n
opcodes prog[] = {
load0, 1,
load1, 2,
push1,
push, 6,
jmp_if_greater, 18,
push0,
push1,
mul,
pop0,
push1,
inc,
pop1,
jmp, 4,
push0
};

int val;
int r = run_vm(&vm, prog, 19, &val);
end_vm(&vm);

return r && val == 720;
}

int test8()
{
return test7();
}

int test9()
{
dev25vm vm;
init_vm(&vm);

//x0 = 1
//x1 = 3
//if (x0 == 1 && x1 == 2)
// return 1000;
//else
// return x1 + 1;
opcodes prog[] = {
load0, 1,
load1, 3,
push0,
push, 1,
cmp_eq,
push1,
push, 2,
cmp_eq,
cmp_and,
push, 1,
jmp_if_not_equal, 20,
push, 1000,
ret,
push1,
inc
};

int val;
int r = run_vm(&vm, prog, 22, &val);
end_vm(&vm);

return r && val == 4;
}

