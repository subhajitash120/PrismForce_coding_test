//Find 

the algortithm in chakrabuhya.cpp file
testcases are in testcase.txt file

//Here I used recursion method to-

1.Handling all possible scenario for multiple decision point (can fight, can skip, can recharge)
2.simplifying the problem solving process
3.code readability

//base case

if Avimanyu standing on >11th number circle, then he won
if(current_circle>10) return true;  (0 indexing)


//used a flag IsSkipPrev to check previously skipped or not