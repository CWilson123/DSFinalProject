MAKE SURE TO UNZIP "fixedshortened.csv.zip"


Windows instructions:

1.In cmd (with MinGW installed) navigate to the directory

2.Type in the command: 
g++ -o output.o Menu.cpp Airport.cpp Airline.cpp Flight.cpp AirportHeap.cpp AirportBST.cpp AirlineHeap.cpp AirlineBST.cpp
(This should create the file output.o)

3. Type in the command:
output.o
(This runs the program)


Mac instructions:

1.In terminal navigate to the directory

2.Type the command:
g++ Menu.cpp Airport.cpp Airline.cpp Flight.cpp AirportHeap.cpp AirportBST.cpp AirlineHeap.cpp AirlineBST.cpp -w
(-w hides warnings saying that range-based for loops are only available in C++ 11 and later)

3.Type command:
./a.out
(This runs the program)
