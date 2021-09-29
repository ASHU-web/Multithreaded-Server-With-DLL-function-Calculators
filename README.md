# Multithreaded-Server-With-DLL-function-Calculators

Start the Server in one terminal by the following commands in one terminal:

gcc client_server_socket.c -lpthread -ldl -o ipc_demo

./ipc_demo server ./myserver


After starting the server, Start the Client in other terminal by the following commands in one terminal:

gcc client_server_socket.c -lpthread -ldl -o ipc_demo


./ipc_demo client ./myserver "give_pathof_DLL_library name_of_function args_for_function"

eg. ./ipc_demo client ./myserver "/lib/x86_64-linux-gnu/libm.so.6 cos 2.0"

give_pathof_DLL_library: Any library path which you want to execute eg. "/lib/x86_64-linux-gnu/libm.so.6"

name_of_function: name of the function in the DLL library supplied e.g. commands

args_for_function: the positional arguments in specific order. Refer to the table provided below.

------------------------------------------------------------------------------------------------------------------------------------
Library path                        |  Function Name            |  Arguements in order
------------------------------------------------------------------------------------------------------------------------------------
/lib/x86_64-linux-gnu/libm.so.6     | cos                       | One int type in range->cos(X) where X is the input
------------------------------------------------------------------------------------------------------------------------------------
/lib/x86_64-linux-gnu/libm.so.6     | sin                       | One int type in range->sin(X) where X is the input
------------------------------------------------------------------------------------------------------------------------------------








