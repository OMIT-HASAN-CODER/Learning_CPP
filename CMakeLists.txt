cmake_minimum_required(VERSION 4.0)
project(Learning_CPP)

set(CMAKE_CXX_STANDARD 23)

add_executable(Learning_CPP main.cpp
        01_varconst/main.cpp
        02_primitives/data.cpp
        02_primitives/modifier.cpp
        02_primitives/casting.cpp
        02_primitives/myString.cpp
        02_primitives/userinput.cpp
        03_operators/arth.cpp
        03_operators/assign.cpp
        03_operators/relation.cpp
        03_operators/logical.cpp
        04_conditionals/if.cpp
        04_conditionals/ifElse.cpp
        04_conditionals/nestedIfElse.cpp
        04_conditionals/switchCase.cpp
        05_loops/whileLoop.cpp
        05_loops/doWhileLoop.cpp
        05_loops/forLoop.cpp
        05_loops/break.cpp
        05_loops/continue.cpp
        05_loops/nestedLoops.cpp
        06_function/myFunction.cpp
        06_function/myFunctionTwo.cpp
        06_function/myFunctionThree.cpp
        06_function/myFunctionFour.cpp
        07_array/one.cpp
        07_array/two.cpp
        07_array/three.cpp
        07_array/four.cpp
        07_array/five.cpp
        08_oop/myClass.cpp
        08_oop/defaultCons.cpp
        08_oop/parametCons.cpp
        08_oop/copyCons.cpp
        08_oop/getterSetter.cpp
        08_oop/delegationCons.cpp
        08_oop/myFriend.cpp
        08_oop/encp.cpp
        08_oop/abstr.cpp
        08_oop/inheritance.cpp
        09_stl/stl_store.cpp
        09_stl/stl_emp_manage.cpp
        09_stl/stl_pair.cpp
        09_stl/number_theory.cpp)
