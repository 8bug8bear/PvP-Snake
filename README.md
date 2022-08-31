# PvP-Snake
## Preface
I decided to create this project because I wanted to test my game writing skills in bare c++. Before that, I had already created a lot of game projects, but they were all on a ready-made engine, so I wanted to try to write something completely from scratch
## Why exactly is the snake and why is it PvP
The snake seemed to me an interesting test. Compared to other classic games, this game has more complex algorithms, such as snake movement, in which the tail repeats all the actions of the head and the snake's interaction with the edges of the arena, fruits and its tail. Why are there two snakes in my version at once? Everything is simple. Firstly, this is an even bigger challenge in terms of creating an algorithm, and secondly, playing the game together is much more fun.
## Algorithmic features
In many educational materials, I saw how the snake was implemented through an array. I didn't really like this approach, because the array took up more memory during the game than the snakes actually needed, besides, to move the snake, it was necessary to overwrite the data in each of its cells, which, with a sufficiently long snake, was not the best solution in terms of the most efficient solution of the algorithm (still, it's ridiculous to talk about performance in as part of a console game). So I found my solution: a list. Through the list, I implemented the tail of the snake and when it moved, I simply deleted the last element of the list and added a new element to the beginning of the list in the coordinates in which the head was during the last iteration. Thus, regardless of the length of the snake, each of its movements requires only two actions.
## Screenshots
![2022-08-31_20-27-56](https://user-images.githubusercontent.com/67451613/187676946-f35d931d-21e7-4d9b-b4e0-ed88a6342c6b.png)

![2022-08-31_20-34-03](https://user-images.githubusercontent.com/67451613/187676984-6cba3f33-e851-4b70-aff1-2f04b7899e31.png)

If you are interested in learning more about this game, then just download and play it. The game was created on Visual Studio 2022, it uses only standard C++ libraries, and downloading and assembling it will not take much time. You can also customize the game by changing the constants in the Definitions file.
