[Imgur](https://i.imgur.com/GzgoeHP.png)


# Ice Engine 2D
> A C++ 3D engine with OpenGL


# Description
This is a 3D game engine made from scratch for the CreativeJam 2018.
We had 46h to create a full game, and here is barely the engine :p .
There is a little demo though!
Run the given executable (Linux only) and test it.
You don't have much other goals than moving around.. (Best gamplay ever!)
But wait, everting was made from scratch!
(Or almost, we use OpenGL, glfw, and, fortunately, we were not required to create the computer by our own)
You may enjoy the beautiful handmade lighting (Phong Illumination algorithm).
The physic engine runs at 45fps, however, rendering loop appends as fast as possible.
This is good news if your living room is cold, since the engine will use 100% of one cpu to heat your computer
(And then the room).
After a while, you may be able to cook some bacon on your computer, but we didn't try in practice.


# Features
- Engine
    - Subsystems
        - TimeManager
        - MeshManager
        - TextureManager
        - InputManager
        - WindowGLFW
    - Camera
    - Game
    - Texture
    - Mesh
- Gameplay
    - GameObject
        - Update
        - FixedUpdate
    - GamePhysic
- Shaders
    - Phong Illumination (With PointLight)
- Demo (Move with AWDS)


# Engine built-in demo
- Move the light with A W D S
- Walls push you away
- Nothing more to do (It's only a demo)


# Dependencies
- OpenGL 3.3
- glfw3
- glm (Already in code)
- glad (Already in code)


# Build / Run with CMake (Linux only)
> Requires C++11.
> Requires "pragma once" support

```
mkdir build
cd build
cmake ..
make -j4
make run
```


# Screenshots
[Imgur](https://i.imgur.com/GzgoeHP.png)
[Imgur](https://i.imgur.com/wiPFirD.png)
[Imgur](https://i.imgur.com/yjSiouy.png)
[Imgur](https://i.imgur.com/jRAHB1Q.png)


# Authors
- Constantin Masson ([constantinmasson.com](http://constantinmasson.com/))
- Gaetan ([Ashijo](https://github.com/Ashijo))
