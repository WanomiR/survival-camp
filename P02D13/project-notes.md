# The Game of life
## Functions
- Draw the plane:
  - Initialize the plane;
  - Update the plane;
- Initialize starting figures;
- Determine the number of neighbors;
- Apply trainsition based on the number of neighors;
- Interactive mode: change the simulation speed;

## Questions / pitfalls
- How to make intercative mode? 
  - [ ] look up materials from the previous project;
- How to implement field closure?


## Parameters
- `80 x 25` field closed on itself;
- 5 initializtion figure types;

## Transition rules
Depending on the number of living neighbours:
| N                | transition                           |
| ---------------- | :----------------------------------- |
| `N < 2`          | dies (underpopulation)               |
| `2 <= N <= 3`    | lives on to the next generation      |
| ` N > 3`         | dies (overpopulation)                |
| `died && N == 3` | prudces a living cell (reproduction) |

All other live cells die in the next generation.

## Resources
- [Python implementation](https://habr.com/ru/articles/532732/)
- [C++ implementation](https://kennycason.com/posts/2011-07-20-john-conways-game-of-life-windowsc-ascii.html)


![](https://repos.21-school.ru/students/P02D13.ID_239635/Team_21__TL__cypherka_student.21_school.ru_.XAkqbOoZT1_GxPIZ5rATug/P02D13-1/-/raw/master/materials/glider_emblem.gif)

![](https://upload.wikimedia.org/wikipedia/commons/thumb/8/86/CA-Moore.svg/400px-CA-Moore.svg.png)
