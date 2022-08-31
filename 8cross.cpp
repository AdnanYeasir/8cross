 
 #include <iostream>
 using namespace std;

 bool OK(int a[], int c){ //to test if the number is either adjacent or repeats

   int hA[8][5] = {{-1},// box 0
                {0, -1}, //box 1
                {0, -1},// box 2
                {0, 1, 2, -1},// box 3
                {0, 1, 3, -1}, //box 4
                {1, 4, -1}, //box 5
                {2, 3, 4, -1},// box 6
                {3, 4, 5, 6, -1}};// box 7
  // hA is to show what box we are checking 
   for(int i = 0; i < c; i++){ 
     if(a[i] == a[c]) // if the same number repeats returns false
       return false;
   }

   for (int i=0 ;  hA[c][i]!=-1 ; i++){
     // we are incrementing row while it's not -1 
       if (abs (a[c]- a[(hA[c][i])]) == 1) 
       //adjacent test, if its consecutive we return false
         return false;
   }
   return true;
 }
  void backtrack(int a[], int& c){
    c--; // we move back a column if we cant place a number
    if (c == -1) return; //we found all solutuon
    a[c]++;// increment row
    if (a[c] == 9) backtrack(a, c); // we can only place up to 8
  }

  void print(int a[]){
    static int solution =1;
    cout << "solution #" << solution++ << endl;
   cout<<" "<<a[0]<<a[1]<<endl; // we are printing like this to match the shape
   cout<<a[2]<<a[3]<<a[4]<<a[5]<<endl;
   cout<<" "<<a[6]<<a[7]<<endl;
   cout<<endl;
  }

  int main() {
    int q[8] = {0}; // we set row to 0
    int c = 0;   // set column to 0;
    q[0] = 1;   // we start with number 1 box 0

    while (c > -1) // while we are checking the appropriate boxes 
    {
      if (c == 8) // we found the solution
      {
       
        print(q);
        backtrack(q, c); // we go back to get the rest of soltion
      }
      else if (q[c] == 9) backtrack(q, c); // if we go past the boxes we gotta go backtrack
      else if (OK(q, c)) // we got the solutions
      {
        c++;
        if (c <= 8) q[c] = 1; // wemove on to next column
      }
      else q[c]++; // we move to next row
    }
  }