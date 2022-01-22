A classical greedy snake game in command window by C++.

This is a final project for course AERSP 424: advanced programming in C++ in Penn State University.
I am new to C++. So I did not use dynamic graphic packages to achieve the game. Instead, the game is achieved in the command window simply by repreating drawing(print) and deleting(system("cls")). 
More specifically, I first draw the map and snake. Then pause for 0.1 second(sleep(100)). Then draw the same map but the snake moving to the next cell. When repeating the above process,
it becomes "dynamic". And of course users can use up, down, left, right to control the snake to eat the food.

The video explaining how the program works is:
https://psu.zoom.us/rec/share/5qALkkLyW8Bu1hRguU7nCzz99ec1Qvgz5dMrBx7ys1V-Bkx4LdvzEX4uFya55lHC.Dom_BO2WnGReKBxd?startTime=1639517698000

After a game ends, a csv file will be created in the same fold as the project. The csv file contains the records of each player's scores from higest to lowest.
If you played multiple times, then there will be multiple records in the file and your highest score is at top.
