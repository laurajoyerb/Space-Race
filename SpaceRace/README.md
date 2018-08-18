# PA4
This is the final assignment from EC327. It is the final version of the Space Race adventure game which adds error handling and other game functionality to the previous assignment. It also uses dynamic allocation, program organization, exceptions for error handling, and Standard Template Library, linked lists. It has a makefile.

The game consists objects located in a two-dimensional world that move around and behave in
various ways. The user enters commands to tell the objects what to do, and they behave in
simulated time. Simulated time advances one “tick” or unit at a time. Time is “frozen” while the
user enters commands. When the user commands the program to “go”, time will advance one
tick of time. When the user commands the program to “run”, time will advance several units of
time until some significant event happens.

You have a group of “Astronauts” that have been stranded on the Moon because their “Space
Stations” ran out of fuel before reaching Earth. Luckily, they can use “moon stones” to power
their stations. The astronauts need to collect moon stones from the surface of the Moon.
However, the astronauts’ suits run out of oxygen rather quickly, so while they are out collecting
moon stones they also have to make sure they are close enough to “Oxygen Depots” to refill
their oxygen. In order to escape the Moon and return to Earth, the astronauts have to collect 10
moon stones at each Space Station and all astronauts have to return to a Space Station before
takeoff. This is how the game is won!

There is now an Alien class that moves around and attacks astronauts. Astronauts can also attack aliens. The game can be run in computer mode (aliens are controlled by computer and will chase astronauts) or in regular mode (user will command aliens). Astronauts and aliens now have health and can die.

Gravity now changes randomly and affects astronaut and alien speed.

These are the commands:
a ID1 ID2
  "attack": command Alien ID1 to attack Astronaut ID2 (or vice versa)

n TYPE ID X Y
  "new": Creates new object ("d" for depot, "s" for station, "a" for astronaut, "x" for alien) at X,Y location

m ID x y
  "move": command Astronaut ID to move to location (x, y)

w ID1 ID2
  "work a depot": command Astronaut ID1 to start supplying at Oxygen_Depot

d ID1 ID2
  “deposit moon stones”: command Astronaut ID1 to start depositing moonstones
  at Space_Station ID2

s ID
  "stop": command Astronaut ID to stop doing whatever it is doing

l ID1 ID2
  “lock in at station”: command Astronaut ID1 to lock into station ID2

g
  "go": advance one time step by updating each object once

r
  "run": advance one time step and update each object, and repeat until an event occurs or 5 time steps have
been done

q
  "quit": terminate the program
