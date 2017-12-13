CC=g++

OBJS= Cart_Point.o Cart_Vector.o Game_Object.o Oxygen_Depot.o Space_Station.o Person.o Astronaut.o Model.o Game_Command.o View.o Alien.o main.o

default: PA4

PA4: $(OBJS)
	$(CC) -o PA4 $(OBJS) -g

Cart_Vector.o: Cart_Vector.cpp Cart_Vector.h
	$(CC) -c Cart_Vector.cpp -o Cart_Vector.o -g

Cart_Point.o: Cart_Point.cpp Cart_Point.h Cart_Vector.h
	$(CC) -c Cart_Point.cpp -o Cart_Point.o -g

Game_Object.o: Game_Object.cpp Game_Object.h Cart_Point.h Cart_Vector.h
	$(CC) -c Game_Object.cpp -o Game_Object.o -g

Oxygen_Depot.o: Oxygen_Depot.cpp Oxygen_Depot.h Game_Object.h Cart_Point.h Alien.h
	$(CC) -c Oxygen_Depot.cpp -o Oxygen_Depot.o -g

Space_Station.o: Space_Station.cpp Space_Station.h Game_Object.h Cart_Point.h Alien.h
	$(CC) -c Space_Station.cpp -o Space_Station.o -g

Person.o: Person.cpp Person.h Space_Station.h Game_Object.h Cart_Point.h Cart_Vector.h Oxygen_Depot.h Alien.h
	$(CC) -c Person.cpp -o Person.o -g

Astronaut.o: Astronaut.cpp Astronaut.h Person.h Space_Station.h Game_Object.h Cart_Point.h Cart_Vector.h Oxygen_Depot.h Alien.h
	$(CC) -c Astronaut.cpp -o Astronaut.o -g

Model.o: Model.cpp Model.h Game_Object.h Person.h Space_Station.h Oxygen_Depot.h Astronaut.h View.h Alien.h
	$(CC) -c Model.cpp -o Model.o -g

Game_Command.o: Game_Command.cpp Model.h Game_Object.h Person.h Space_Station.h Oxygen_Depot.h Astronaut.h Game_Command.h Alien.h
	$(CC) -c Game_Command.cpp -o Game_Command.o -g

View.o: View.cpp View.h Game_Object.h Cart_Point.h
	$(CC) -c View.cpp -o View.o -g

Alien.o: Alien.cpp Alien.h Game_Object.h Cart_Point.h Cart_Vector.h Person.h
	$(CC) -c Alien.cpp -o Alien.o -g

main.o: main.cpp Cart_Point.h Cart_Vector.h Game_Object.h Oxygen_Depot.h Space_Station.h Person.h Astronaut.h Model.h Game_Command.h View.h Alien.h
	$(CC) -c main.cpp -o main.o -g

clean:
	rm $(OBJS) PA4
