Task 1 <br>
Devise an algorithm for the following task: given a 2n × 2n <br>
(n > 1) board with one missing square, tile it with right <br>
trominoes of only three colors so that no pair of trominoes that share an edge have the same color. Recall that the <br> 
right tromino is an L-shaped tile formed by three adjacent squares. <br>
Use dynamic programing to solve this problem. <br>
Task 2 <br>
Is it possible for a chess knight to visit all the cells of an 8 × 8 chessboard exactly once, ending at a cell one knight’s <br> 
move away from the starting cell? (Such a tour is called closed or re-entrant. Note that a cell is considered visited only <br>
when the knight lands on it, not just passes over it on its move.) <br>
If it is possible design a greedy algorithm to find the minimum number of moves the chess knight needs. <br>
Task 3 <br>
There is a row of n security switches protecting a military installation entrance. The switches can be manipulated as 
follows: <br>
(i) The rightmost switch may be turned on or off at will. <br> 
(ii) Any other switch may be turned on or off only if the switch to its immediate right is on and all the other <br> 
switches to its right, if any, are off. <br>
(iii) Only one switch may be toggled at a time. <br> 
Design a Dynamic Programing algorithm to turn off all the switches, which are initially all on, in the minimum number of <br> 
moves. (Toggling one switch is considered one move.) Also find the minimum number of moves. <br>
Task 4 <br>
There are eight disks of different sizes and four pegs. Initially, all the disks are on the first peg in order of size, the largest <br> 
on the bottom and the smallest on the top. <br>
Use divide and conquer method to transfer all the disks to another peg by a sequence of moves. Only one disk can be <br> 
moved at a time, and it is forbidden to place a larger disk on top of a smaller one. <br>
Does the Dynamic Programing algorithm can solve the puzzle in 33 moves? If not then design an algorithm that <br>
solves the puzzle in 33 moves. <br>
Task 5 <br>
There are n coins placed in a row. The goal is to form n/2 pairs of them by a sequence of moves. On the first move a <br> 
single coin has to jump over one coin adjacent to it, on the second move a single coin has to jump over two adjacent <br>
coins, on the third move a single coin has to jump over three adjacent coins, and so on, until after n/2 moves n/2 coin <br>
pairs are formed. (On each move, a coin can jump right or left but it has to land on a single coin. Jumping over a coin <br>
pair counts as jumping over two coins. Any empty space between adjacent coins is ignored.) Determine all the values <br>
of n for which the problem has a solution and design an algorithm that solves it in the minimum number of moves for
those n’s. <br>
Design greedy algorithm to find the minimum number of moves. <br>
2 | 3 <br>
Task 6 <br>
There are six knights on a 3 × 4 chessboard: the three <br> 
white knights are at the bottom row, and the three black <br>
knights are at the top row. <br>
Design an iterative improvement algorithm to <br> 
exchange the knights to get the position shown on the <br> 
right of the figure in the minimum number of knights <br>
moves, not allowing more than one knight on a square 
at any time. <br>
Task 7 <br>
A computer game has a shooter and a moving target. The shooter can hit any of n > 1 hiding spot located along a <br> 
straight line in which the target can hide. The shooter can never see the target; all he knows is that the target moves <br> 
to an adjacent hiding spot between every two consecutive shots. Design a Dynamic Programing algorithm that <br>
guarantees hitting the target. <br>
Task 8 <br>
If you have 50 boxes that contains 50 pieces of metal all of the same known weight. one of these boxes contains fake <br> 
metal pieces that weigh 1 kilogram less than the pieces in the rest of the boxes. You can use a digital scale only once <br>
to find this fake box. Design a brute force algorithm to solve this problem. <br>
