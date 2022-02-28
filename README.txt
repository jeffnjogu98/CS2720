Jeff Njogu jmn27688@uga.edu
Tai Do td62447@uga.edu

Februrary 20, 2022

Roles
-----
For this project, we split the methods eventually. After doing our
designated method, we tested them to see if it was working. If we found any bugs,
we would come together to figure it out. This allowed us to both contribute to the
assignment all while learning from one another.

Pesudocode for swapAlt operation
-----
This function swap the elements in the list. First it checks
if it is empty or if there is only one item in the list.
If that is true, it just stops there. Afterward, it loops through
the loop. In this loop, it change the next
of the current as previous item. Then if next is NULL or if next is the last node, it
sets the previous's next to next. Afterward it changes the previous next to next of next.
Then it updates the previous and curr (place holder of head). Then it sets the head to the placeholer.
The swapAlternate operation has a time complexity of O(N). The while loop transverse through the list.

Pesudocode for deleteSubsection
-----
Here, we loop through the list using a while loop. At each position, we check if the value
is below the upper bound or above the lower bound. If it is, we delete that item from the list.
The deleteSubsection operation has a time complexity of O(N) because the while loop transverse through the list.

Pesudocode for mode
-----
The mode operation has a time complexity of O(N). The while loop transverse through the list.

To compile the code you must input:
$make compile
in the ~/assignment3/ directory

To run the code you must input:
$./main [input file]
in the ~/assignment3/ directory

To clean the code you must input
$make clean
in the ~/assignment3/ directory
