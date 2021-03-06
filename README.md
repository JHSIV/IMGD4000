# IMGD4000
Course Projects for IMGD 4000, a class offered at Worcester Polytechnic Institute

## Project: Boids
I attempted to implemented a simple game incorporating an agent-based simulation in Unreal Engine using a C++-based approach.

The intended objective of this game is to free all of the Boids as quickly as possible. Moving your Boids near the cages (spheres) would lower their health, with each nearby Boid doing a point of damage. When a cage's health is depleted, it breaks and releases more Boids that get added to your flock. Once all of the boids have been freed, the timer stops and the game ends.
### Unfortunately, I ran out of time (even with the extension) and was only able to implement basic flocking and steering.

Controls:
- A/Left: Steer the flock to the left
- D/Right: Steer the flock to the right

A video of this game in action can be found here: https://youtu.be/f42tNtvmmPY

The source code for this can be found under the Boids folder of this repository on the master branch.

## Project: A* Pathfinding
I implemented the A* pathfinding algorithm in Unreal Engine using a Blueprint-based approach. The specific implementation I used follows a grid-based system, where actors with specific tags indicating the type of ground or object they represent are placed in a scene with a specific spacing (in this case, every 400 units). When the game starts, the Ground objects in the room are analyzed to create a mapping of valid coordinate vectors to costs. If objects have multiple tags, they are treated as having the one with the highest cost. 
The tags that determine how the objects in the world are treated are as follows:
- Goal   : An object with Goal is treated as the endpoint. If multiple are present, only the first discovered is used. The goal object is represented as a light green cone.
- Ground : All objects to be considered as ground are tagged with this.
- Wall   : All objects tagged with this are ignored as options when finding a valid path. They are treated essentially as empty space. Wall objects are colored black.
- Normal : An ordinary piece of ground, mapped to a cost of 1.0. Normal tiles are green.
- Fast   : A piece of ground that is cheaper to move on, mapped to a cost of 0.5. Fast tiles are light blue.
- Slow   : A piece of ground that is more expensive to move on, mapped to a cost of 2.0. Slow tiles are sand-colored.
- Avoid  : A piece of ground with a very high cost of 5.0. Avoid tiles are red.

The cost mapping for each is handled entirely by the BP_AI_Pathfinder AIController blueprint, stored in its GroundCosts map. The set of valid ground tags to consider is likewise stored in its GroundTypes array. None of this data besides the tags themselves are applied to the scene objects.

Once the level has been analyzed, the program performs the A* pathfinding algorithm with the pawn actor, in this case the white sphere, starting from its initial position. If a successful path was generated, the pawn then moves along it tile by tile.

A video of this pathfinding system in action can be found here: https://youtu.be/UjdqR5xRZJY

The source code for this can be found under the Pathfinding folder of this repository on the master branch.
