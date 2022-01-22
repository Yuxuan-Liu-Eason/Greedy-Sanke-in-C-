# A classical greedy snake game in command window by C++.

## This is a final project for course AERSP 424: advanced programming in C++ in Penn State University.

I am new to C++. So I did not use dynamic graphic packages to achieve the game. Instead, the game is achieved in the command window simply by repreating drawing(print) and deleting(system("cls")). 
More specifically, I first draw the map and snake. Then pause for 0.1 second(sleep(100)). Then draw the same map but the snake moving to the next cell. When repeating the above process,
it becomes "dynamic". And of course users can use up, down, left, right to control the snake to eat the food.

Some screenshots from the game:

![image](https://user-images.githubusercontent.com/76148884/150621502-2cc8e835-e8d9-437e-bcc7-c9e4f5f0e7f6.png)
![image](https://user-images.githubusercontent.com/76148884/150621435-ee59af04-6f71-449e-806f-3cdf502783f0.png)
![image](https://user-images.githubusercontent.com/76148884/150621464-19c519e6-a35e-4020-b8ba-45474329293f.png)
![image](https://user-images.githubusercontent.com/76148884/150621482-ababed00-0337-4ee9-89d3-45ac10c9d1e8.png)

The video explaining how the program works is:
https://psu.zoom.us/rec/share/5qALkkLyW8Bu1hRguU7nCzz99ec1Qvgz5dMrBx7ys1V-Bkx4LdvzEX4uFya55lHC.Dom_BO2WnGReKBxd?startTime=1639517698000

To run the codes, open a visualstudio project and load all files. Then it should be good to run!

After a game ends, a csv file will be created in the same fold as the project. The csv file contains the records of each player's scores from higest to lowest.
If you played multiple times, then there will be multiple records in the file and your highest score is at top.
