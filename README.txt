Computer languages oftern required a way to dynamically allocate memory, which means that memory is acquired while program is running. This contrast to static memory allocation. The project simply is a simple memory manager, which allow the user to allocate and release memory, tracking of available memory, used and how much memory is used, the next memory available, etc.

Memory Management is initialize with 3 slot of 2-bit memory tracking known as memory system header: Next free memory index, In-use memory head, and Used memory head. Memory block structure that will be allocate after memory system structure included 3 section: first section hold memory size, second section hold the last memory header index, third section hold the next available memory index, and final fourth section will be amount of 2-bit block memory size.

Example of how the code operate for allocating memory:

-- Empty memory Table

     0    1    2    3   4   5   6   7   8   9   A   B   C    D   E   F

   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
0  |  3 |  0 |  0 |   |   |   |   |   |   |   |   |   |   |    |   |    |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
1  |    |    |    |   |   |   |   |   |   |   |   |   |   |    |   |    |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
2  |    |    |    |   |   |   |   |   |   |   |   |   |   |    |   |    |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
3  |    |    |    |   |   |   |   |   |   |   |   |   |   |    |   |    |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
4  |    |    |    |   |   |   |   |   |   |   |   |   |   |    |   |    |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
5  |    |    |    |   |   |   |   |   |   |   |   |   |   |    |   |    |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+


-- Allocating first memory block size of 7

     0    1    2    3   4   5   6   7   8   9   A   B   C    D   E   F

   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
0  | D  |  3 |  0 | 7 | 0 | D | / | / | / | / | / | / | / |    |   |    |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
1  |    |    |    |   |   |   |   |   |   |   |   |   |   |    |   |    |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
2  |    |    |    |   |   |   |   |   |   |   |   |   |   |    |   |    |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
3  |    |    |    |   |   |   |   |   |   |   |   |   |   |    |   |    |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
4  |    |    |    |   |   |   |   |   |   |   |   |   |   |    |   |    |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
5  |    |    |    |   |   |   |   |   |   |   |   |   |   |    |   |    |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+


-- Allocating second memory block size of 10

     0    1    2    3   4   5   6   7   8   9   A   B   C    D   E   F

   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
0  | 1A | 0D | 03 | 7 | 0 | D | / | / | / | / | / | / | / | 10 | 3 | 1A |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
1  | /  | /  | /  | / | / | / | / | / | / | / |   |   |   |    |   |    |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
2  |    |    |    |   |   |   |   |   |   |   |   |   |   |    |   |    |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
3  |    |    |    |   |   |   |   |   |   |   |   |   |   |    |   |    |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
4  |    |    |    |   |   |   |   |   |   |   |   |   |   |    |   |    |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+
5  |    |    |    |   |   |   |   |   |   |   |   |   |   |    |   |    |
   +----+----+----+---+---+---+---+---+---+---+---+---+---+----+---+----+


Project Completed Date: December 2017
